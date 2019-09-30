#include <iostream>
#include "matrx.h"
#include "strassen.cpp"
#include "reg_compute.cpp"
using namespace std;

int main(){

	matrx *reg = new matrx(reg_compute);
	matrx *strass = new matrx(strassen);

	
	//pass the function to each matrix

	reg->run();
	strass->run();
	//matrx.run()
	delete reg;
	delete strass;
	//report the results

	return 0;
}