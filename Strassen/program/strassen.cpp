#include "matrx.h"
#include "log.cpp"
//multiply a 2x2 matrix using strassen's method
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
	int p6 = (b - d) * (g + h);
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

//add two matrices
vec add(vec &data1, vec &data2) {
	vec ans;
	vector<int> tempA;
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			tempA.push_back(data1[i][j] + data2[i][j]);
		}
		ans.push_back(tempA);
		tempA.clear();
	}
	return ans;
}

//subtract two matrices
vec subtract(vec &data1, vec &data2) {
	vec ans;
	vector<int> tempA;
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			tempA.push_back(data1[i][j] - data2[i][j]);
		}
		ans.push_back(tempA);
		tempA.clear();
	}
	return ans;
}

//create submatrix based on wanted index
vec submatrix(vec &data1, int index) {
	vec ans;
	int size = data1.size() / 2;
	vector<int> tempA;
	int i = 0; //default if index = 1
	int j = 0;
	if (index == 2) {
		i = 0;
		j = size;
	}
	else if (index == 3) {
		i = size;
		j = 0;
	}
	else if (index == 4) {
		i = size;
		j = size;
	}
	int t = 0;
	for (int k = i; k < size + i; k++) {
		for (int l = j; l < size + j; l++) {
			tempA.push_back(data1[k][l]);
		}
		ans.push_back(tempA);
		tempA.clear();
	}
	return ans;
}

vector<int> combine(vec index1, vec index2, int i) {
	vector<int> tempV;
	for (int j = 0; j < index1.size(); j++) {
		tempV.push_back(index1[i][j]);
	}
	for (int j = 0; j < index2.size(); j++) {
		tempV.push_back(index2[i][j]);
	}
	return tempV;
}

//strassen's recursion
vec recurse(vec &data1, vec &data2) {
	if (data1.size() == 2) {
		return matrix2x2(data1, data2);
	}
	vec ans;
	
	//create the submatrices needed
	vec a = submatrix(data1, 1);
	vec b = submatrix(data1, 2);
	vec c = submatrix(data1, 3);
	vec d = submatrix(data1, 4);
	vec e = submatrix(data2, 1);
	vec f = submatrix(data2, 2);
	vec g = submatrix(data2, 3);
	vec h = submatrix(data2, 4);

	//compute the 7 matrices needed
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
	temp2 = add(g, h);
	vec p6 = recurse(temp1, temp2);
	temp1 = subtract(a, c);
	temp2 = add(e, f);
	vec p7 = recurse(temp1, temp2);

	//create the matrices for the result
	temp1 = add(p6, p5);
	temp2 = add(temp1, p4);
	vec index1 = subtract(temp2, p2);
	vec index2 = add(p1, p2);
	vec index3 = add(p3, p4);
	temp1 = add(p1, p5);
	temp2 = subtract(temp1, p3);
	vec index4 = subtract(temp2, p7);

	//create final result
	vector<int> tempV;
	tempV = combine(index1, index2, 0);
	ans.push_back(tempV);
	tempV = combine(index1, index2, 1);
	ans.push_back(tempV);
	tempV = combine(index3, index4, 0);
	ans.push_back(tempV);
	tempV = combine(index3, index4, 1);
	ans.push_back(tempV);

	return ans;
}

//main
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