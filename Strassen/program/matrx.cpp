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
		checkRam();
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
	cout << "Ram used " << m_ramuse << endl;
}


vec matrx::add(vec data1, vec data2) {
	vec ans(data1.size(), vector<int>(data1.size(), 0));
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			ans[i][j] = (data1[i][j] + data2[i][j]);
		}
	}
	return ans;
}

//subtract two matrices
vec matrx::subtract(vec data1, vec data2) {
	vec ans(data1.size(), vector<int>(data1.size(), 0));
	for (int i = 0; i < data1.size(); i++) {
		for (int j = 0; j < data1.size(); j++) {
			ans[i][j] = (data1[i][j] - data2[i][j]);
		}
	}
	return ans;
}

//create submatrix based on wanted index
vec matrx::submatrix(vec data1, int index) {
	int size = data1.size() / 2;
	vec ans(size, vector<int>(size, 0));

	int i = 0; //default if index = 1
	int j = 0;
	if (index == 2) {
		i = 0;
		j = size;
	}
	else if (index == 3) {
		i = size;
		j = 0;
	}
	else if (index == 4) {
		i = size;
		j = size;
	}
	int t = 0;
	for (int k = 0; k < size ; k++) {
		for (int l = 0; l < size; l++) {
			ans[k][l] = data1[k+i][l+j];
		}
	}
	return ans;
}

vec matrx::combine(vec index1, vec index2, vec index3, vec index4) {

	int size = index1.size();

	vec tempV(size*2, vector<int>(size*2, 0));


	for(int i=0; i<size;i++){
		for(int j=0; j<size;j++){
			tempV[i][j] = index1[i][j]; //add index 1
			tempV[i][j+size] = index2[i][j]; //add index2
			tempV[i+size][j] = index3[i][j]; // add index3
			tempV[i+size][j+size] = index4[i][j]; //add index4
		}
	}

	return tempV;
}

//strassen's recursion
vec matrx::recurse(vec data1, vec data2,  int k) {
	
	//cout << "Added 1 :".first << endl;


	if (data1.size() <= k) {


	//	cout << "Freed one: " <<.first << endl;
		return reg_compute(data1, data2,  k);
	}



	vec ans;
	int halfSize = data1.size()/2;
	//create the submatrices needed
	vec a = submatrix(data1, 1);
	vec b = submatrix(data1, 2);
	vec c = submatrix(data1, 3);
	vec d = submatrix(data1, 4);
	vec e = submatrix(data2, 1);
	vec f = submatrix(data2, 2);
	vec g = submatrix(data2, 3);
	vec h = submatrix(data2, 4);

	//compute the 7 matrices needed
	vec p1 = recurse(a, subtract(f,h), k);
	vec p2 = recurse(add(a,b), h, k);
	vec p3 = recurse(add(c,d), e, k);
	vec p4 = recurse(d, subtract(g,e), k);
	vec p5 = recurse(add(a,d), add(e,h), k);
	vec p6 = recurse(subtract(b,d), add(g,h), k);
	vec p7 = recurse(subtract(a,c), add(e,f), k);

	//create the matrices for the result
	vec index1 = subtract(add(add(p6,p5), p4), p2);
	vec index2 = add(p1, p2);
	vec index3 = add(p3, p4);
	vec index4 = subtract(subtract(add(p1, p5), p3), p7);

	//create final result
	ans = combine(index1, index2, index3, index4);
	//checkRam();
	//cout << "Freed one: " <<.first << endl;
	return ans;
}


void matrx::fill_matx(vec &data){

	
	int myRow = 2, myCol = 2, row = data.size(), col = data[0].size();


	while(row > myRow){
		myRow *= 2;
	}
	while(col > myCol){
		myCol *= 2;
	}
	int q = myRow > myCol ? myRow : myCol;


	for(int i =0;i<row;i++){
		for(int j = 0;j< (q-col); j++)
			data[i].push_back(0);
	}

	for(int i=0; i<q-row;i++){
		data.push_back(vector<int> (q, 0));
	}
}
//main
vec matrx::strassen(vec &data1, vec &data2,  int k){
	vec ans;
	int row = data1.size();
	int col = data2[0].size();
	fill_matx(data1);
	fill_matx(data2);

	
	ans = recurse(data1, data2, k);

	return ans;
}


vec matrx::reg_compute(vec &data1, vec &data2, int k){

	//long long cur = memInfo.totalram - memInfo.freeram;
	//cur *= memInfo.mem_unit;
	//m_ramuse = cur - m_init_ram;
	//cout << "m_init_ram " << m_init_ram;
	//cout << "\ncur " << cur << endl;

	vec ans;
	int temp;

	try{
		for (int i=0; i<data1.size();i++){
			vector<int> tempV;
			for(int j=0; j<data2[0].size();j++){
				temp=0;
				for(int k=0;k<data1[0].size();k++){
					temp+=(data1[i][k]*data2[k][j]);
					//checkRam();
				}
				tempV.push_back(temp);
			}
			ans.push_back(tempV);
		}
	}
	catch(string err){
		cout << err << endl;
		exit(1);
	}


	return ans;
}

long long matrx::getRam(){
	long long cur = memInfo.totalram - memInfo.freeram;
	cur *= memInfo.mem_unit;
	return cur;
}

void matrx::checkRam(){
	sysinfo(&memInfo);
	long long cur = getRam() - m_init_ram;
	m_ramuse = m_ramuse > cur ? m_ramuse : cur;
}