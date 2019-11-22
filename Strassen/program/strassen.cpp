#include "matrx.h"
#include "log.cpp"
#include "reg_compute.cpp"
//add two matrices
vec add(vec data1, vec data2) {
	vec ans(data1.size(), vector<int>(data1.size(), 0));
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			ans[i][j] = (data1[i][j] + data2[i][j]);
		}
	}
	return ans;
}

//subtract two matrices
vec subtract(vec data1, vec data2) {
	vec ans(data1.size(), vector<int>(data1.size(), 0));
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			ans[i][j] = (data1[i][j] - data2[i][j]);
		}
	}
	return ans;
}

//create submatrix based on wanted index
vec submatrix(vec data1, int index) {
	int size = data1.size() / 2;
	vec ans(size, vector<int>(size, 0));

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
	for (int k = 0; k < size ; k++) {
		for (int l = 0; l < size; l++) {
			ans[k][l] = data1[k+i][l+j];
		}
	}
	return ans;
}

vec combine(vec index1, vec index2, vec index3, vec index4) {

	int size = index1.size();

	vec tempV(size*2, vector<int>(size*2, 0));


	for(int i=0; i<size;i++){
		for(int j=0; j<size;j++){
			tempV[i][j] = index1[i][j]; //add index 1
			tempV[i][j+size] = index2[i][j]; //add index2
			tempV[i+size][j] = index3[i][j]; // add index3
			tempV[i+size][j+size] = index4[i][j]; //add index4
		}
	}

	return tempV;
}

//strassen's recursion
vec recurse(vec data1, vec data2,  int k) {
	
	//cout << "Added 1 :".first << endl;


	if (data1.size() <= k) {


	//	cout << "Freed one: " <<.first << endl;
		return reg_compute(data1, data2,  k);
	}



	vec ans;
	int halfSize = data1.size()/2;
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
	vec p1 = recurse(a, subtract(f,h), k);
	vec p2 = recurse(add(a,b), h, k);
	vec p3 = recurse(add(c,d), e, k);
	vec p4 = recurse(d, subtract(g,e), k);
	vec p5 = recurse(add(a,d), add(e,h), k);
	vec p6 = recurse(subtract(b,d), add(g,h), k);
	vec p7 = recurse(subtract(a,c), add(e,f), k);

	//create the matrices for the result
	vec index1 = subtract(add(add(p6,p5), p4), p2);
	vec index2 = add(p1, p2);
	vec index3 = add(p3, p4);
	vec index4 = subtract(subtract(add(p1, p5), p3), p7);

	//create final result
	ans = combine(index1, index2, index3, index4);

	//cout << "Freed one: " <<.first << endl;
	return ans;
}


void fill_matx(vec &data){

	
	int myRow = 2, myCol = 2, row = data.size(), col = data[0].size();


	while(row > myRow){
		myRow *= 2;
	}
	while(col > myCol){
		myCol *= 2;
	}
	int q = myRow > myCol ? myRow : myCol;


	for(int i =0;i<row;i++){
		for(int j = 0;j< (q-col); j++)
			data[i].push_back(0);
	}

	for(int i=0; i<q-row;i++){
		data.push_back(vector<int> (q, 0));
	}
}
//main
vec strassen(vec &data1, vec &data2,  int k){
	vec ans;
	int row = data1.size();
	int col = data2[0].size();
	fill_matx(data1);
	fill_matx(data2);

	
	ans = recurse(data1, data2, k);

	return ans;
}