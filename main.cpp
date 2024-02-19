#include "bool_vec.hpp"
#include <iostream>



int main() {

    vector<bool> bv;

    // std::cout << "start\n";

    
    bv.push_back(false);
    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(true);

    bv.push_back(true);
    bv.push_back(true);
    bv.push_back(true);


    bv.insert(2, true);
    bv.erase(0);


    for (uint32 i = 0; i < bv.size(); ++i) {
        if (i % 8 == 0 && i) std::cout << ' ';
        std::cout << bv[i];
    }
    std::cout << '\n';

}