/*
The matrix class where we are going to do the computation
matrx 
*/

class matrix{
    public:
        matrx(){
            space_use = 0;
            run_time = 0;
            m_data = NULL;
            m_ans = NULL;
        };
        //matrx(function_pointer);
        void retrieve_data(string filename); //reads the data into *m_data which is a 2D array 
        
        bool run(); //computes the
        bool set_function(/*a function pointer*/); //sets the computing methods 
        int get_space()return space_use;  //return the space use
        int get_time()return run_time;  //returns the run time use
        
    private:
        int space_use;
        int run_time;
        int *m_data;
        int *m_ans;
        //int *(matrix::*)(int*); funciton pointer
            // we will implment each function in a separate file
  };



