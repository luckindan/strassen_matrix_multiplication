
#include <iostream>
#include "matrx.h"
#include "strassen.cpp"
//#include "reg_compute.cpp"


using namespace std;



void log_time(matrx *mtx){
	std::ofstream log_file;
	log_file.open("../Log/memory_limit_report.csv", std::ios_base::app);
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

			reg->run(1);
			//reg->dump();
			log_time(reg);	
			delete reg;


			int k;
			for(int i = 1; i<=11;i++){
				matrx *strassK = new matrx(strassen, "SAMK");

				strassK->retrieve_data(filename1, strassK->m_data_1);
				strassK->retrieve_data(filename2, strassK->m_data_2);

				k = pow(2, i);
				strassK->run(k);
				//strassK->dump();
				log_time(strassK);
				delete strassK;
			}

			matrx *strassK_half = new matrx(strassen, "SAMK_half");

			strassK_half->retrieve_data(filename1, strassK_half->m_data_1);
			strassK_half->retrieve_data(filename2, strassK_half->m_data_2);

			k = (int) strassK_half->m_row/2;
			strassK_half->run(k);
			//strassK_half->dump();
			log_time(strassK_half);
			delete strassK_half;
			

			matrx *strassK_log = new matrx(strassen, "SAMK_log");

			strassK_log->retrieve_data(filename1, strassK_log->m_data_1);
			strassK_log->retrieve_data(filename2, strassK_log->m_data_2);
			k = (int) log2(strassK_half->m_row);
		
			strassK_log->run(k);
			//strassK_log->dump();
			log_time(strassK_log);
			delete strassK_log;

			matrx *strassK_sqrt = new matrx(strassen, "SAMK_sqrt");

			strassK_sqrt->retrieve_data(filename1, strassK_sqrt->m_data_1);
			strassK_sqrt->retrieve_data(filename2, strassK_sqrt->m_data_2);
			k = (int) log2(strassK_sqrt->m_row);
		
			strassK_sqrt->run(k);
			//strassK_sqrt->dump();
			log_time(strassK_sqrt);
			delete strassK_sqrt;

		}//report the results
		catch(char const *e){
			cout << e << endl;
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}

