#include <iostream>
#include "matrx.h"
#include "strassen.cpp"
#include "reg_compute.cpp"
using namespace std;

int main(int argc, char *argv[]){

	if(argc != 3){
		cout << "Wrong Arguments\n\t./out filename1 filename2\n";
	}
	else{
		string filename1 = argv[1];
		string filename2 = argv[2];
		
		matrx *reg = new matrx(reg_compute, "Regular Computation");
	

		reg->retrieve_data(filename1, reg->m_data_1);
		reg->retrieve_data(filename2, reg->m_data_2);
		//pass the function to each matrix

		reg->run();
		reg->dump();

		delete reg;

		matrx *strass = new matrx(strassen, "Strassen Theory");


	 	strass->retrieve_data(filename1, strass->m_data_1);
		strass->retrieve_data(filename2, strass->m_data_2);

		strass->run();
		strass->dump();

		delete strass;
		//report the results
	}

	return 0;
}