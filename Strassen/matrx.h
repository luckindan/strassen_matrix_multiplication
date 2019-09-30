/*
The matrix class where we are going to do the computation
matrx 
*/

#ifndef _MATRX_H_
#define _MATRX_H_

#include <iostream>
#include <string>

using namespace std;

class matrx{
    public:
        matrx(){
            space_use = 0;
            run_time = 0;
            m_data = NULL;
            m_ans = NULL;
        }

        matrx(int* (*compute)(int *data)){
        	space_use = 0;
            run_time = 0;
            m_data = NULL;
            m_ans = NULL;
            m_compute = compute;
        }
        //matrx(function_pointer);
        void retrieve_data(string filename); //reads the data into *m_data which is a 2D array 
        
        bool run(); //computes the
        bool set_function(int* (*compute)(int *data)); //sets the computing methods 
        int get_space(){return space_use;}  //return the space use
        int get_time(){return run_time;}  //returns the run time use
        
    private:
        int space_use;
        int run_time;
        int *m_data;
        int *m_ans;
        int* (*m_compute)(int *data);
            // we will implment each function in a separate file
 };


#endif


