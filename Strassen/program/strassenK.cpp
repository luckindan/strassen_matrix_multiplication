
#include <iostream>
#include "matrx.h"
//#include "strassen.cpp"
//#include "reg_compute.cpp"


using namespace std;



void log_time(matrx *mtx){
	std::ofstream log_file;
	log_file.open("../Log/memory_limit_report.csv", std::ios_base::app);
	log_file << mtx->run_time.count() << ',';
	log_file.close();
}

int main(int argc, char *argv[]){

	if(argc != 4){
		cout << "Wrong Arguments\n\t./out filename1 filename2 K\n";
	}
	else{
		try{
			string filename1 = argv[1];
			string filename2 = argv[2];
			int k = stoi(argv[3]);

			matrx *strassK = new matrx(strassK->strassen, "SAMK");

			strassK->retrieve_data(filename1, strassK->m_data_1);
			strassK->retrieve_data(filename2, strassK->m_data_2);

			strassK->run(k);
			//strassK->dump();
			log_time(strassK);
			delete strassK;


		}//report the results
		catch(char const *e){
			cout << e << endl;
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}

