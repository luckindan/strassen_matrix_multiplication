
#include "matrx.h"

vec reg_compute(vec &data1, vec &data2){

	vec ans;
	int temp;
	std::cout << "reg_compute" << std::endl;

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
	/*
		Implementation goes here
	*/


	return ans;
}