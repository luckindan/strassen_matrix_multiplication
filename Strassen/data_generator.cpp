#include <random>

/*asoidufhoasidfhoasjfdhasjfhk*/
//Class description:
/*
    This class is used to generate the random int from 0 to less than 2^16
    and writes into a csv file
*/
class data_generator{
    public:
    //default constructor, it dones't do anything
    data_generator(){

    }


    //m : amount of data you want to generate
    data_generator(int num){
        m_num = num;
    }

    data_generator(int x, int y){
        m_x = x;
        m_y = y;
        m_num = x*y;
    }

    data_generator(int x, int y, string filename){
        m_x = x;
        m_y = y;
        m_filename = filename;
        m_num = x*y;

    }

    string find_filename(){
        return "";
    }


    string m_filename;
    int m_x;
    int m_y;
    int m_num;
};
