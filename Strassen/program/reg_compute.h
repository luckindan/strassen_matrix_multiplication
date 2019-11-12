#ifndef _REG_COMPUTE_H_
#define _REG_COMPUTE_H_
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
typedef vector<vector<int>> vec;

class reg_compute {
    public:
        reg_compute(vec &data1, vec &data2, pair<int,int>  &space_use);
};

#endif