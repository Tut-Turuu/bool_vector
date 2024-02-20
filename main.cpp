#include "bool_vec.hpp"
#include <iostream>



int main() {

    vector<bool> bv("10101010");
    bv[0] = 0;
    
    const vector<bool> cbv("10111011");

    for (uint32 i = 0; i < cbv.size(); ++i) {
        if (i % 8 == 0 && i) std::cout << ' ';
        std::cout << cbv[i];
    }
    std::cout << '\n';



    for (uint32 i = 0; i < bv.size(); ++i) {
        if (i % 8 == 0 && i) std::cout << ' ';
        std::cout << bv[i];
    }
    std::cout << '\n';

}