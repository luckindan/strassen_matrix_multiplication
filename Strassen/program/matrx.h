/*
The matrix class where we are going to do the computation
matrx 
*/

#ifndef _MATRX_H_
#define _MATRX_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
#include <exception>
#include <chrono>
#include "log.cpp"

using namespace std;

typedef vector<vector<int>> vec;

class matrx{
    public:
        matrx(){
            space_use = 0;
            run_time = 0;
            m_name = "matrix";
        }

        matrx(vec (*compute)(vec &data1, vec &data2)){
        	space_use = 0;
            run_time = 0;
            m_name = "matrix";       
            m_compute = compute;
        }
        matrx(vec (*compute)(vec &data1, vec &data2), string name){
            space_use = 0;
            run_time = 0;
            m_name = name;
            m_compute = compute;
        }

        ~matrx(){
            space_use = 0;
            run_time = 0;
        }
        //matrx(function_pointer);
        void retrieve_data(string filename, vec& data); //reads the data into *m_data which is a 2D array 
        
        bool run(); //computes the
        bool set_function(vec (*compute)(vec &data1, vec &data2)); //sets the computing methods 
        int get_space(){return space_use;}  //return the space use
        int get_time(){return run_time;}  //returns the run time use
        void dump();

        vec m_data_1;
        vec m_data_2;
        vec m_ans;    
    private:
        int space_use;
        long run_time;

        vec (*m_compute)(vec &data1, vec &data2);
        string m_name;
        // we will implment each function in a separate file
};


#endif


