
#include <iostream>
#include "matrx.h"
#include "strassen.cpp"
#include "strassenK.cpp"
//#include "strassenK2.cpp"
//#include "strassenK3.cpp"
//#include "strassenK4.cpp"
#include "reg_compute.cpp"
using namespace std;

int main(int argc, char *argv[]){

	if(argc != 3){
		cout << "Wrong Arguments\n\t./out filename1 filename2\n";
	}
	else{
		try{
			string filename1 = argv[1];
			string filename2 = argv[2];
			
			matrx *reg = new matrx(reg_compute, "Regular Computation");
			reg->retrieve_data(filename1, reg->m_data_1);
			reg->retrieve_data(filename2, reg->m_data_2);
			if(reg->m_data_1[0].size()!= reg->m_data_2.size())
				throw "Invalid Matrices";
			//pass the function to each matrix
			reg->run();
			reg->dump();

			matrx *strass = new matrx(strassen, "Strassen Theory");
		 	strass->retrieve_data(filename1, strass->m_data_1);
			strass->retrieve_data(filename2, strass->m_data_2);
			strass->run();
			strass->dump();

			matrx *strassK = new matrx(strassenK, "Strassen Theory");
		 	strassK->retrieve_data(filename1, strassK->m_data_1);
			strassK->retrieve_data(filename2, strassK->m_data_2);
			strassK->run();
			strassK->dump();

			if(strass->m_ans.size() != reg->m_ans.size()){
				cout << "Wrong answer, different size\n";
			}
			else{
				int err = 0;
				for(int i=0;i<strass->m_ans.size();i++){
					for(int j=0;j<strass->m_ans[0].size();j++){
						if(reg->m_ans[i][j] != strass->m_ans[i][j])
							err++;
					}
				}
				cout <<"There are " << err << " differences\n";
			}
			delete reg;
			delete strass;
		}//report the results
		catch(char const *e){
			cout << e << endl;
			return 0;
		}
		

	}

	return 0;
}

