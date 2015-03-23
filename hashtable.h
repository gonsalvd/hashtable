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
    //Constructor for creating hash table
    Hash(int table_size);
    
    //Inserts a string into the hash table
    void insert(string input);
    
    //Searches for an existing string in the hash table
    string search(string input);
    
    //Checks full
    bool isFull();
    
    //Returns number of elements in table
    int getNumElements();
    
private:
    
    //Size of the hash table
    int M;
    //Number of elements
    int num_elements;
    //Array storing the string values
    string *array;
    
    //Universal has function implemention p498
    int hash(string input);
    
    //Returns the size of the hash table
    int getSize();
    
    

};