
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

	if(argc != 3){
		cout << "Wrong Arguments\n\t./out filename1 filename2\n";
	}
	else{
		try{
			string filename1 = argv[1];
			string filename2 = argv[2];

			matrx *reg = new matrx(reg->reg_compute, "Regular Computation");
		
			reg->retrieve_data(filename1, reg->m_data_1);
			reg->retrieve_data(filename2, reg->m_data_2);

			if(reg->m_data_1[0].size()!= reg->m_data_2.size())
				throw "Invalid Matrices";
			//pass the function to each matrix

			reg->run(1);
			//reg->dump();
			log_time(reg);	
			delete reg;


		}//report the results
		catch(char const *e){
			cout << e << endl;
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}

