#include <iostream>
#include "matrx.h"
#include "strassen.cpp"
#include "reg_compute.cpp"
using namespace std;

int main(){

	matrx *reg = new matrx(reg_compute, "Regular Computation");
	matrx *strass = new matrx(strassen, "Strassen Theory");

	
	//pass the function to each matrix

	reg->run();
	reg->dump();
	strass->run();
	strass->dump();
	//matrx.run()
	delete reg;
	delete strass;
	//report the results

	return 0;
}