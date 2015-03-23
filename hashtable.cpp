//
//  hashtable.cpp
//  Exercise 3
//
//  Created by Gonsalves on 3/22/15.
//
//

#include "hashtable.h"
using namespace std;

Hash::Hash (int table_size)
{
    array = new string[table_size];
    M = table_size;
}

//Hash function is the Universal Hash Function from Sedgewick 1-4 on p  498
void Hash::insert(string input)
{
    const char* v = 0;
    v = input.c_str();
    int h, a = 31415, b = 27183;
    for (h = 0; *v != 0; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    h = (h < 0) ? (h + M) : h;
    cout<<"Value of h: "<<h<<endl;
    cout<<"input: "<<input<<endl;
    //Put in the string input at index location h
    array[h]=input;
    cout<<"Array [h]: "<<array[h]<<endl;
}

int Hash::getSize()
{
    return M;
}