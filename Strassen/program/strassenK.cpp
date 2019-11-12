#include "matrx.h"
//#include "reg_compute.cpp"
vec reg_compute(vec &data1, vec &data2, pair<int,int>  &space_use){

	vec ans;
	int temp;

	try{
		for (int i=0; i<data1.size();i++){
			vector<int> tempV;
			for(int j=0; j<data2[0].size();j++){
				temp=0;
				for(int k=0;k<data1[0].size();k++){
					temp+=(data1[i][k]*data2[k][j]);
				}
				tempV.push_back(temp);
			}
			ans.push_back(tempV);
		}
	}
	catch(string err){
		cout << err << endl;
		exit(1);
	}


	return ans;
}
//multiply a 2x2 matrix using strassen's method
vec matrix2x2K(vec &data1, vec &data2) {
	vec ans(2, vector<int>(2, 0));

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

	ans[0][0] = p5 + p4 -p2 + p6;

	ans[0][1] = p1 + p2;

	ans[1][0] = p3 + p4;

	ans[1][1] = p1 + p5 - p7 - p3;

	return ans;
}

//add two matrices
vec addK(vec data1, vec data2) {
	vec ans(data1.size(), vector<int>(data1.size(), 0));
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			ans[i][j] = (data1[i][j] + data2[i][j]);
		}
	}
	return ans;
}

//subtract two matrices
vec subtractK(vec data1, vec data2) {
	vec ans(data1.size(), vector<int>(data1.size(), 0));
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			ans[i][j] = (data1[i][j] - data2[i][j]);
		}
	}
	return ans;
}

//create submatrix based on wanted index
vec submatrixK(vec data1, int index) {
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

vec combineK(vec index1, vec index2, vec index3, vec index4) {

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
vec recurseK(vec data1, vec data2, pair<int,int> &space, int k) {
	
	space.first++;
	space.second = space.first > space.second ? space.first:space.second;
	//cout << "Added 1 :"<<space.first << endl;

	if (data1.size() < k) {

		space.first--;
	//	cout << "Freed one: " <<  space.first << endl;
        pair<int,int> dummy;
		return reg_compute(data1, data2, dummy);
	}



	vec ans;
	int halfSize = data1.size()/2;
	//create the submatrices needed
	vec a = submatrixK(data1, 1);
	vec b = submatrixK(data1, 2);
	vec c = submatrixK(data1, 3);
	vec d = submatrixK(data1, 4);
	vec e = submatrixK(data2, 1);
	vec f = submatrixK(data2, 2);
	vec g = submatrixK(data2, 3);
	vec h = submatrixK(data2, 4);

	//compute the 7 matrices needed
	vec p1 = recurseK(a, subtractK(f,h), space, k);
	vec p2 = recurseK(addK(a,b), h, space, k);
	vec p3 = recurseK(addK(c,d), e, space, k);
	vec p4 = recurseK(d, subtractK(g,e), space, k);
	vec p5 = recurseK(addK(a,d), addK(e,h), space, k);
	vec p6 = recurseK(subtractK(b,d), addK(g,h), space, k);
	vec p7 = recurseK(subtractK(a,c), addK(e,f), space, k);

	//create the matrices for the result
	vec index1 = subtractK(addK(addK(p6,p5), p4), p2);
	vec index2 = addK(p1, p2);
	vec index3 = addK(p3, p4);
	vec index4 = subtractK(subtractK(addK(p1, p5), p3), p7);

	//create final result
	ans = combineK(index1, index2, index3, index4);

	space.first--;
	//cout << "Freed one: " <<  space.first << endl;
	return ans;
}

void fill_matxK(vec &data){

	
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
vec strassenK(vec &data1, vec &data2, pair<int,int> &space) {
    vec ans;
	int row = data1.size();
	int col = data2[0].size();
	fill_matxK(data1);
	fill_matxK(data2);

    int k = data1.size();

    vec temp = recurseK(data1, data2, space, k);
}