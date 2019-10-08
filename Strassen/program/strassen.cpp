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

vec strassen(vec &data1, vec &data2){
	vec ans;

	//if 2x2 matrix
	if (data1.size() == 2) {
		ans = matrix2x2(data1, data2);
	}

	//if nxn matrix
	vec a;
	vec b;
	vec c;
	vec d;
	vec e;
	vec f;
	vec g;
	vec h;
	vec letter;

	std::cout << "strassen" << std::endl;
	
	//recursive(data1, data2, letter);

	return ans;
}

/*int recursive(vec &data1, vec &data2, vec &letter) {
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

