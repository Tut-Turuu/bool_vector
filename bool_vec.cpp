#include "bool_vec.hpp"
#include <cstring>
#include <cmath>
#include <stdexcept>


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
    char* byte_ptr = data + index / 8;
    char offset = index % 8;
    char new_byte = *byte_ptr / (7 - index / 8) << (7 - index / 8) + x << ();

    for (; byte_ptr != data + (sz % 8 != 0 ? sz / 8 + 1 : sz / 8); ++byte_ptr) {

    }
}

void vector<bool>::erase(uint32 index) {

}