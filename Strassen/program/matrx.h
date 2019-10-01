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

        matrx(vec (*compute)(vec data)){
        	space_use = 0;
            run_time = 0;
            m_name = "matrix";       
            m_compute = compute;
        }
        matrx(vec (*compute)(vec data), string name){
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
        void retrieve_data(string filename); //reads the data into *m_data which is a 2D array 
        
        bool run(); //computes the
        bool set_function(int* (*compute)(int *data)); //sets the computing methods 
        int get_space(){return space_use;}  //return the space use
        int get_time(){return run_time;}  //returns the run time use
        void dump();
        
    private:
        int space_use;
        int run_time;
        vec m_data;
        vec m_ans;
        vec (*m_compute)(vec data);
        string m_name;
        // we will implment each function in a separate file
 };


#endif


