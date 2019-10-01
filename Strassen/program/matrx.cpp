#include "matrx.h"

bool matrx::run(){
	//if(!matrx::m_data)
	//	throw "No data loaded, please load the data first";
	m_ans = m_compute(m_data);
	//use the function pointer to run the and get the result
	/*	
	try:{
		init_time = now()
		m_ans = function(m_data)
		m_space = sizeof(m_ans)
		m_time = now() - init_time
	}
	catch(Exception E){
		std::cout << E << std::endl;	
		return false;
	}
	*/
	return true;
}

void matrx::retrieve_data(std::string filename){

	std::cout<< "retrieve_data" << std::endl;
}

void matrx::dump(){
	std::cout << "Run" << std::endl;

}