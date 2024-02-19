#pragma once 

using uint32 = unsigned int;


inline char get_left_bits(char c, char num);

inline char get_right_bits(char c, char num);

template <typename T>
class vector {};

template <>
class vector<bool> {

    char* data;
    uint32 sz;
    uint32 cap;

    class reference {
        char* byte_ptr;
        char offset;

    public:
        reference(char* byte_ptr, char offset);

        reference& operator=(bool x);

        operator bool() const;
    };

public:

    void reserve(uint32 new_cap);

    vector();

    ~vector();

    void push_back(bool x);

    reference operator[](uint32 index);

    const reference operator[](uint32 index) const;

    reference at(uint32 index);

    const reference at(uint32 index) const;

    uint32 size();

    void insert(uint32 index, bool x);

    void erase(uint32 index);


};