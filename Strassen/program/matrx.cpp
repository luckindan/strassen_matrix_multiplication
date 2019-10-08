#include "matrx.h"




bool matrx::run(){
	using namespace std::chrono;
	try
	{
		if(m_data_1.empty() || m_data_2.empty())
			throw "No data loaded, please load the data first";

		m_ans = m_compute(m_data_1, m_data_2);

		return true;
	}
	catch(char *e){
		return false;
	}

}

void matrx::retrieve_data(std::string filename, vec& myvec){

	ifstream myfile(filename);
	string line;
	while(getline(myfile,line)){
		std::vector<int> v;
		string s;
		stringstream ss(line);
		while(ss >> s){
			v.push_back(stoi(s));
		}
		myvec.push_back(v);
	}


}

void matrx::dump(){
	cout << "Data 1:\n";
	for (auto i : m_data_1){
		for(auto j: i){
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	cout << "Data 2:\n";
	for (auto i : m_data_2){
		for(auto j: i){
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	cout << "Answer :\n";
	for (auto i : m_ans){
		for(auto j: i){
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}

	cout << "Time used " << run_time << endl;
	cout << "Space used " << space_use << endl;
}
