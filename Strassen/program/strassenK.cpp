#include "matrx.h"
#include <exception>
//#include "reg_compute.cpp"



//strassen's recursion
vec recurseK(vec data1, vec data2, pair<int,int> &space, int k) {
	
	space.first++;
	space.second = space.first > space.second ? space.first:space.second;
	//cout << "Added 1 :"<<space.first << endl;

	if (data1.size() <= k) {

		space.first--;
	//	cout << "Freed one: " <<  space.first << endl;
        pair<int,int> dummy;
		return reg_compute(data1, data2, dummy);
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
	vec p1 = recurseK(a, subtract(f,h), space, k);
	vec p2 = recurseK(add(a,b), h, space, k);
	vec p3 = recurseK(add(c,d), e, space, k);
	vec p4 = recurseK(d, subtract(g,e), space, k);
	vec p5 = recurseK(add(a,d), add(e,h), space, k);
	vec p6 = recurseK(subtract(b,d), add(g,h), space, k);
	vec p7 = recurseK(subtract(a,c), add(e,f), space, k);

	//create the matrices for the result
	vec index1 = subtract(add(add(p6,p5), p4), p2);
	vec index2 = add(p1, p2);
	vec index3 = add(p3, p4);
	vec index4 = subtract(subtract(add(p1, p5), p3), p7);

	//create final result
	ans = combine(index1, index2, index3, index4);

	space.first--;
	//cout << "Freed one: " <<  space.first << endl;
	return ans;
}

//main
vec strassenK(vec &data1, vec &data2, pair<int,int> &space) {
    vec ans;
	int row = data1.size();
	int col = data2[0].size();
	fill_matx(data1);
	fill_matx(data2);

    int k = data1.size();

    vec temp = recurseK(data1, data2, space, k);

    for(int i=0; i<row;i++){
		ans.push_back(vector<int>(temp[i].begin(), temp[i].begin()+col));
	}

	return ans;
}