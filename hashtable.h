//
//  hashtable.h
//  Exercise 3
//
//  Created by Gonsalves on 3/22/15.
//
//

#ifndef __Exercise_3__hashtable__
#define __Exercise_3__hashtable__

#include <iostream>
#include <string>
using namespace std;

#endif /* defined(__Exercise_3__hashtable__) */

class Hash
{
public:
    Hash(int table_size);
    //Universal has function implemention p498
    void insert(string input);
    string search();
    int getSize();
private:
    int M;
    string *array;

};