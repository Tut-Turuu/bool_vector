#include "bool_vec.hpp"
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <bitset>


inline char get_left_bits(char c, char num) {
    char mask = ((1 << num) - 1) << (8 - num);
    return mask & c;
}

inline char get_right_bits(char c, char num) {
    char mask = (1 << num) - 1;
    return mask & c;
}

vector<bool>::reference::reference(char* byte_ptr, char offset): byte_ptr(byte_ptr), offset(offset) {}

vector<bool>::reference& vector<bool>::reference::operator=(bool x) {

    *byte_ptr = (x ? *byte_ptr | (1 << (7 - offset)) : *byte_ptr & ~(1 << (7 - offset)));
    return *this;
}

vector<bool>::reference::operator bool() const {
    char mask = 1;
    return static_cast<bool>(*byte_ptr & (mask << (7 - offset)));
}


void vector<bool>::reserve(uint32 new_cap) {
    std::cout << "reserve\n";

    if (new_cap <= cap) return;

    decltype(data) new_data = new char[new_cap];

    if (data != nullptr) memcpy(new_data, data, sz*8);

    delete[] data;

    cap = new_cap;

    data = new_data;
}

vector<bool>::vector(): data(nullptr), sz(0), cap(0) {}

vector<bool>::~vector() {
    delete[] data;
}

void vector<bool>::push_back(bool x) {
    if (sz == cap*8) reserve(cap*2+1);
    char* byte_ptr = data + sz / 8;
    char offset = sz % 8;
    *byte_ptr = (x ? *byte_ptr | (1 << (7 - offset)) : *byte_ptr & ~(1 << (7 - offset)));
    ++sz;

}

vector<bool>::reference vector<bool>::operator[](uint32 index) {
    return vector<bool>::reference(data + index / 8, index % 8);

}

const vector<bool>::reference vector<bool>::operator[](uint32 index) const {
    return vector<bool>::reference(data + index / 8, index % 8);
}

vector<bool>::reference vector<bool>::at(uint32 index) {
    if (index >= sz) throw std::out_of_range("Out of range vector<bool>");
    return vector<bool>::reference(data + index / 8, index % 8);
}

const vector<bool>::reference vector<bool>::at(uint32 index) const {
    if (index >= sz) throw std::out_of_range("Out of range vector<bool>");
    return vector<bool>::reference(data + index / 8, index % 8);
}

uint32 vector<bool>::size() {return sz;}

void vector<bool>::insert(uint32 index, bool x) {
    if (sz == cap) reserve(2*cap);

    char* byte_ptr = data + index / 8;
    char offset = index % 8;

    // std::cout << std::bitset<8>(get_left_bits(*byte_ptr, offset)) << '\n';
    // std::cout << std::bitset<8>(x << (7 - offset)) << '\n';
    // std::cout << std::bitset<8>(get_right_bits(*byte_ptr, 7 - offset) >> 1) << '\n';
    

    bool carry = (*byte_ptr) & 1;
    *byte_ptr = get_left_bits(*byte_ptr, offset) + (x << (7 - offset)) + (get_right_bits(*byte_ptr, 7 - offset) >> 1);

    ++byte_ptr;
    ++sz;


    for (; byte_ptr != data + (sz % 8 ? sz / 8 + 1 : sz / 8); ++byte_ptr) {
        bool new_carry = *byte_ptr & 1;

        *byte_ptr = ((*byte_ptr >> 1) & 0b01111111 ) + (carry << 7);
        carry = new_carry;
    }
}

void vector<bool>::erase(uint32 index) {
    char* byte_ptr = data + index / 8;
    char offset = index % 8;

    *byte_ptr = get_left_bits(*byte_ptr, offset) + (get_right_bits(*byte_ptr, 8 - offset) << 1);

    for (; byte_ptr != data + (sz % 8 ? sz / 8 + 1 : sz / 8) - 1; ++byte_ptr) {
        *byte_ptr += (byte_ptr[1] & 0b10000000) >> 7;
        byte_ptr[1] = byte_ptr[1] << 1;
    }
    --sz;
}