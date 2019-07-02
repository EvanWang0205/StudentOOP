#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
//    for (int i = 0; i < v.size(); i++)
//        cout << v[i] << " ";
    for (int i : v) cout << i << " ";
    cout << endl;
}

MyVec::MyVec(int sz, int val) : sz(sz) {
    int real_sz = max(DEF_CAPACITY, sz);
    data = new int[real_sz];
    capacity = real_sz*2;
    for (int i = 0; i < real_sz; i++)
        data[i]  = val;
}



MyVec::MyVec() {
    data = new int[DEF_CAPACITY];
    sz = 0;
    capacity = DEF_CAPACITY;
}

MyVec::MyVec(const MyVec& v2) {
    sz  = v2.sz;
    capacity = v2.capacity;
    data = new int[capacity];
    for (int i = 0; i <sz; i++)
        data[i] = v2.data[i];
}

MyVec::~MyVec() {
    if (data != nullptr)
        delete[]  data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
    if (&v2 != this){
        if (data != nullptr)
            delete[] data;
        sz = v2.sz;
        capacity = v2.capacity;
        data = new int[capacity];
        for (int i = 0; i <sz; i++)
            data[i] = v2.data[i];
        
    }
    return *this;
}

 MyVec::Iterator MyVec::begin() const {
     return MyVec::Iterator(data);
 }
 
 MyVec::Iterator MyVec::end() const {
     return MyVec::Iterator(data + sz);
 }
 
/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */

bool operator==(MyVec& v1, MyVec& v2) {
    if (v1.size() != v2.size())
        return false;
    else
        for (int i = 0; i < v1.size(); i++){
            if (v1[i] != v2[i])
                return false;
        }
    return true;
}

/*
 * Puts an element at the back of a vector.
 * */

void MyVec::push_back(int val) {
    if (sz == capacity){
        int* oldData = data;
        capacity *= 2;
        data = new int[capacity];
        for (int i = 0; i < sz; i++)
            data[i] = oldData[i];
        delete[] oldData;
        data[sz ++ ] = val;
    }
    else
        data[sz ++ ] = val;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */

int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */

int& MyVec::operator[](int i) {
    return data[i];
}

