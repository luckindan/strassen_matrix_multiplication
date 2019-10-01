#ifndef _LOG_H_
#define _LOG_H_

#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;


const string path = "../Log/";

class log
{
public:
	log(){
		time_t now = time(0);
		auto *local_time = localtime(&now);

		auto year = to_string(1900 + local_time->tm_year);
		auto month = to_string(1 + local_time->tm_mon);
		auto day = to_string(local_time->tm_mday);

		m_filename = path + year + "-" + month + "-" + day + ".txt";
	}
	log(string filename){
		m_filename = path + filename;
	}
	~log(){
		m_filename = ""; 
	}
	void write(string log_msg){
		if(log_msg == "") throw "No message given";

		std::ofstream outfile;
		outfile.open(m_filename, std::ios_base::app);

		time_t now = time(0);
		char *dt = ctime(&now);
		outfile << dt;
		outfile << ": " +  log_msg + "\n";
		outfile.close();
	}
	
private:
	string m_filename;

};





#endif