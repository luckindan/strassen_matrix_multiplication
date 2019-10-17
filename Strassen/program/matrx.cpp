#include "matrx.h"




bool matrx::run(){
	
	try
	{
		if(m_data_1.empty() || m_data_2.empty())
			throw "No data loaded, please load the data first";

		auto start = std::chrono::system_clock::now();
		m_ans = m_compute(m_data_1, m_data_2);
		auto end = std::chrono::system_clock::now();
		run_time = end -start;
	//	m_ans.clear();
	//	for (int i =0;i<m_row;i++){
	//		m_ans.push_back(vector<int>(ans[i].begin(), ans[i].begin()+m_col));
	//	}

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
/*
	m_row = m_row == 0 ? row : (row > m_row ? m_row : row);
	m_col = m_col == 0 ? col : (col > m_col ? m_col : col);
	int myRow = 2;
	int myCol = 2;


	while(row > myRow){
		myRow *= 2;
	}
	while(col > myCol){
		myCol *= 2;
	}
	int q = myRow > myCol ? myRow : myCol;


	for(int i =0;i<row;i++){
		for(int j = 0;j< (q-col); j++)
			myvec[i].push_back(0);
	}

	for(int i=0; i<q-row;i++){
		myvec.push_back(vector<int> (q, 0));
	}*/

}

void matrx::dump(){
	cout << "Data 1:\n";
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
	cout << "Space used " << space_use << endl;
}

void matrx::log(string message, vec data){

	
}