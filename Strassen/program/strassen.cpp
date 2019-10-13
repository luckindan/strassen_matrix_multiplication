#include "matrx.h"
vec matrix2x2(vec &data1, vec &data2) {
	vec ans;

	int a = data1[0][0];
	int b = data1[0][1];
	int c = data1[1][0];
	int d = data1[1][1];
	int e = data2[0][0];
	int f = data2[0][1];
	int g = data2[1][0];
	int h = data2[1][1];
	int p1 = a * (f - h);
	int p2 = (a + b) * h;
	int p3 = (c + d) * e;
	int p4 = d * (g - e);
	int p5 = (a + d) * (e + h);
	int p6 = (b - d) * (f - h);
	int p7 = (a - c) * (e + f);
	vector<int> tempA;
	vector<int> tempB;
	tempA.push_back(p5 + p4 - p2 + p6);
	tempA.push_back(p1 + p2);
	ans.push_back(tempA);
	tempB.push_back(p3 + p4);
	tempB.push_back(p1 + p5 - p7 - p3);
	ans.push_back(tempB);

	return ans;
}

vec add(vec &data1, vec &data2) {
	vec ans;
	vector<int> tempA;
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			tempA.push_back(data1[i][j] + data2[i][j]);
		}
		ans.push_back(tempA);
	}
	return ans;
}

vec subtract(vec &data1, vec &data2) {
	vec ans;
	vector<int> tempA;
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			tempA.push_back(data1[i][j] - data2[i][j]);
		}
		ans.push_back(tempA);
	}
	return ans;
}

vec submatrix(vec &data1, int index) {
	vec ans;
	int size = data1.size() / 2;
	vector<int> tempA;
	int i = 0; //default if index = 1
	int j = 0;
	if (index == 2) {
		i = size;
		j = 0;
	}
	else if (index == 3) {
		i = 0;
		j = size;
	}
	else if (index == 4) {
		i = size;
		j = size;
	}
	int t = 0;
	std::cout << data1[0][0] << std::endl;
	for (int k = i; i < size + i; k++) {
		for (int l = j; j < size + j; l++) {
			t = data1[k][l];
			std::cout << t << std::endl;
			tempA.push_back(t);
		}
		std::cout << tempA[0] << std::endl;
		ans.push_back(tempA);
	}
	std::cout << ans[0][0] << std::endl;
	return ans;
}

vec recurse(vec &data1, vec &data2) {
	if (data1.size() == 2) {
		return matrix2x2(data1, data2);
	}
	vec ans;
	vec a = submatrix(data1, 1);
	vec b = submatrix(data1, 2);
	vec c = submatrix(data1, 3);
	vec d = submatrix(data1, 4);
	vec e = submatrix(data2, 1);
	vec f = submatrix(data2, 2);
	vec g = submatrix(data2, 3);
	vec h = submatrix(data2, 4);
	vec temp1 = subtract(f, h);
	vec p1 = recurse(a, temp1);
	temp1 = add(a, b);
	vec p2 = recurse(temp1, h);
	temp1 = add(c, d);
	vec p3 = recurse(temp1, e);
	temp1 = subtract(g, e);
	vec p4 = recurse(d, temp1);
	temp1 = add(a, d);
	vec temp2 = add(e, h);
	vec p5 = recurse(temp1, temp2);
	temp1 = subtract(b, d);
	temp2 = subtract(f, h);
	vec p6 = recurse(temp1, temp2);
	temp1 = subtract(a, b);
	temp2 = add(e, f);
	vec p7 = recurse(temp1, temp2);

	temp1 = add(p6, p5);
	temp2 = add(temp1, p4);
	vec index1 = subtract(temp2, p2);
	vec index2 = add(p1, p2);
	vec index3 = add(p3, p4);
	temp1 = add(p1, p5);
	temp2 = subtract(temp1, p3);
	vec index4 = subtract(temp2, p7);

	for (int i = 0; i < index1.size(); i++) {
		ans.push_back(index1[i]);
		ans.push_back(index2[i]);
	}
	for (int i = 0; i < index3.size(); i++) {
		ans.push_back(index3[i]);
		ans.push_back(index4[i]);
	}
	return ans;
}

vec strassen(vec &data1, vec &data2){
	vec ans;

	//if 2x2 matrix
	/*if (data1.size() == 2) {
		ans = matrix2x2(data1, data2);
	}*/

	//if nxn matrix
	std::cout << "strassen" << std::endl;
	
	ans = recurse(data1, data2);

	return ans;
}
/*
vec recursive(vec &data1, vec &data2, vec &letter) {
	if (letter.size == 2) {
		return matrix2x2(data1, data2);
	}
	vec a;
	vec b;
	vec c;
	vec d;
	vector<int> tempA;
	vector<int> tempB;
	vector<int> tempC;
	vector<int> tempD;
	for (int i = 0; i < data1.size() / 2; i++) {
		for (int j = 0; j < data1.size() / 2; j++) {
			tempA.push_back(data1[i][j]);
			tempB.push_back(data1[i][(data1.size() / 2) + j]);
			tempC.push_back(data1[data1.size() / 2][j]);
			tempD.push_back(data1[(data1.size() / 2) + i][(data1.size() / 2) + i]);
		}
		a.push_back(tempA);
		b.push_back(tempB);
		c.push_back(tempC);
		d.push_back(tempD);
	}
	int p1 = recursive(data1, data2, a) * recursive(data1, data2, f) - recursive(data1, data2, h);
	int p2 = (a + b) * h;
	int p3 = (c + d) * e;
	int p4 = d * (g - e);
	int p5 = (a + d) * (e + h);
	int p6 = (b - d) * (f - h);
	int p7 = (a - c) * (e + f);
}*/