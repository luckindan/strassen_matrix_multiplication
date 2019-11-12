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
#include <ctime>
#include "log.cpp"

using namespace std;

typedef vector<vector<int>> vec;


class matrx{
    public:
        matrx(){
            m_space = pair<int,int>(0,0);
            run_time = chrono::duration<double>();
            m_name = "matrix";
        }

        matrx(vec (*compute)(vec &data1, vec &data2, pair<int,int> &space)){
        	m_space = pair<int,int>(0,0);
             run_time = chrono::duration<double>();
            m_name = "matrix";       
            m_compute = compute;
        }
        matrx(vec (*compute)(vec &data1, vec &data2, pair<int, int> &space), string name){
            m_space = pair<int,int>(0,0);
            run_time = chrono::duration<double>();
            m_name = name;
            m_compute = compute;
        }

        ~matrx(){
            run_time = chrono::duration<double>();
        }
        //matrx(function_pointer);
        void retrieve_data(string filename, vec& data); //reads the data into *m_data which is a 2D array 
        
        bool run(); //computes the
        bool set_function(vec (*compute)(vec &data1, vec &data2, pair<int,int> &space)); //sets the computing methods 
        chrono::duration<double> get_time(){return run_time;}  //returns the run time use
        void dump();
        void log(string message, vec data);

        vec m_data_1;
        vec m_data_2;
        vec m_ans;   
        pair<int,int> m_space;
        std::chrono::duration<double> run_time;
        
    private:
      
 
        vec (*m_compute)(vec &data1, vec &data2, pair<int,int> &space);
        string m_name;
        int m_row;
        int m_col;
        // we will implment each function in a separate file
};


#endif


