
#include <iostream>
#include "matrx.h"
#include "strassen.cpp"
#include "reg_compute.cpp"
#include "strassenK.cpp"
#include "strassenK2.cpp"
#include "strassenK3.cpp"
#include "strassenK4.cpp"
using namespace std;



void log_time(matrx *mtx){
	std::ofstream log_file;
	log_file.open("../Log/memory_limit_report.txt", std::ios_base::app);
	log_file << mtx->run_time.count() << ',';
	log_file.close();
}

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
			//reg->dump();
			log_time(reg);	
			delete reg;


			matrx *strass = new matrx(strassen, "Strassen Theory");


		 	strass->retrieve_data(filename1, strass->m_data_1);
			strass->retrieve_data(filename2, strass->m_data_2);

			strass->run();
			//strass->dump();
			log_time(strass);
			delete strass;

	
			matrx *strassK = new matrx(strassenK, "SAMK = K");

			strassK->retrieve_data(filename1, strassK->m_data_1);
			strassK->retrieve_data(filename2, strassK->m_data_2);

			strassK->run();
			//strassK->dump();
			log_time(strassK);
			delete strassK;

			matrx *strassK2 = new matrx(strassenK2, "SAMK2 = K/2");

			strassK2->retrieve_data(filename1, strassK2->m_data_1);
			strassK2->retrieve_data(filename2, strassK2->m_data_2);

			strassK2->run();
			//strassK2->dump();
			log_time(strassK2);
			delete strassK2;

			matrx *strassK3 = new matrx(strassenK3, "SAMK = sqrt(k)");

			strassK3->retrieve_data(filename1, strassK3->m_data_1);
			strassK3->retrieve_data(filename2, strassK3->m_data_2);

			strassK3->run();
			//strassK3->dump();
			log_time(strassK3);
			delete strassK3;

			matrx *strassK4 = new matrx(strassenK, "SAMK = log2(k)");

			strassK4->retrieve_data(filename1, strassK4->m_data_1);
			strassK4->retrieve_data(filename2, strassK4->m_data_2);

			strassK4->run();
			//strassK4->dump();
			log_time(strassK4);
			delete strassK4;

		}//report the results
		catch(char const *e){
			cout << e << endl;
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}

