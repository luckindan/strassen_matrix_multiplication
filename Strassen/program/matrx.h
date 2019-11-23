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
#include "sys/types.h"
#include "sys/sysinfo.h"
//#include "log.cpp"




using namespace std;

typedef vector<vector<int>> vec;


class matrx{
    public:
        matrx(){
        	sysinfo(&memInfo);
            run_time = chrono::duration<double>();
            m_name = "matrix";
            m_ramuse = 0;
            m_init_ram = memInfo.totalram - memInfo.freeram;
            m_init_ram *= memInfo.mem_unit;

        }

        matrx(vec (*compute)(vec &data1, vec &data2, int k)){
        	sysinfo(&memInfo);
        
             run_time = chrono::duration<double>();
            m_name = "matrix";       
            m_compute = compute;
            m_ramuse = 0;
            m_init_ram = memInfo.totalram - memInfo.freeram;
            m_init_ram *= memInfo.mem_unit;

        }
        matrx(vec (*compute)(vec &data1, vec &data2,  int k), string name){
   
   			sysinfo(&memInfo);
            run_time = chrono::duration<double>();
            m_name = name;
            m_compute = compute;
            m_ramuse = 0;
            m_init_ram = memInfo.totalram - memInfo.freeram;
            m_init_ram *= memInfo.mem_unit;
        }

        ~matrx(){
            //run_time = chrono::duration<double>();
        }
        //matrx(function_pointer);
        void retrieve_data(string filename, vec& data); //reads the data into *m_data which is a 2D array 
        
        bool run(int k); //computes the
        bool set_function(vec (*compute)(vec &data1, vec &data2, int k)); //sets the computing methods 
        chrono::duration<double> get_time(){return run_time;}  //returns the run time use
        void dump();
        void log(string message, vec data);
        long long getRam();
        void checkRam();
        static vec reg_compute(vec &data1, vec &data2, int k=0);
        static vec strassen(vec &data1, vec &data2, int k);
        static vec add(vec data1, vec data2);
        static vec subtract(vec data1, vec data2);
        static vec submatrix(vec data1, int index);
        static vec combine(vec index1, vec index2, vec index3, vec index4);
        static vec recurse(vec data1, vec data2, int k);
        static void fill_matx(vec &data);



        vec m_data_1;
        vec m_data_2;
        vec m_ans;   
        std::chrono::duration<double> run_time;
        int m_row;
        int m_col;
        long long m_ramuse;
        long long m_init_ram;
        struct sysinfo memInfo;

    private:
      
 
        vec (*m_compute)(vec &data1, vec &data2,  int k);
        string m_name;
};


#endif


