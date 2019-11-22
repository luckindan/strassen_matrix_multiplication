#include "matrx.h"




bool matrx::run(int k){
	
	try
	{
		if(m_data_1.empty() || m_data_2.empty())
			throw "No data loaded, please load the data first";

		auto start = std::chrono::system_clock::now();
		m_ans = m_compute(m_data_1, m_data_2, k);
		auto end = std::chrono::system_clock::now();
		run_time = end -start;

		return true;
	}
	catch(char *e){
		return false;
	}

}

void matrx::retrieve_data(std::string filename, vec& myvec){

	ifstream myfile(filename);
	string line;
	int row = 0;
	int col = 0;
	while(getline(myfile,line)){
		std::vector<int> v;
		string s;
		stringstream ss(line);
		col = 0;
		while(ss >> s){
			v.push_back(stoi(s));
			col +=1;
		}
		myvec.push_back(v);
		row+=1;
	}
	m_col = col;
	m_row = row;
}

void matrx::dump(){

	cout << m_name << ":\nData 1:\n";
	if(m_data_1.size() > 20){
		std::cout << "\tData is too big to display\n";
	}
	else{
		for (auto i : m_data_1){
			for(auto j: i){
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
	}
	cout << "Data 2:\n";
	if(m_data_2.size() > 20){
		std::cout << "\tData is too big to display\n";
	}
	else{
		for (auto i : m_data_2){
			for(auto j: i){
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
	}
	cout << "Answer :\n";
	if(m_ans.size() > 20){
		std::cout << "\tData is too big to display\n";
	}
	else
	{
		
		for (auto i : m_ans){
			for(auto j: i){
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
	}

	cout << "Time used " << run_time.count() << "s\n";
	
}

void matrx::log(string message, vec data){

	
}