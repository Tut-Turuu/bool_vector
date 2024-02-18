#include "bool_vec.hpp"
#include <iostream>



int main() {

    vector<bool> bv;


    bv.push_back(false);
    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(true);
    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(false);
    bv.push_back(false);
    bv.push_back(true);





    for (uint32 i = 0; i < bv.size(); ++i) {
        std::cout << bv[i];
    }
    std::cout << '\n';

}