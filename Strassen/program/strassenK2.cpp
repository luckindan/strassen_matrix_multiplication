#include "matrx.h"
#include <exception>

//main
vec strassenK2(vec &data1, vec &data2, pair<int,int> &space) {
    vec ans;
	int row = data1.size();
	int col = data2[0].size();
	fill_matx(data1);
	fill_matx(data2);

    int k = data1.size()/2;

    vec temp = recurseK(data1, data2, space, k);

    for(int i=0; i<row;i++){
		ans.push_back(vector<int>(temp[i].begin(), temp[i].begin()+col));
	}

	return ans;
}