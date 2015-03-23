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
    int original_hash_value = hash(input);
    //Cherk for collisions
    while (array[original_hash_value] != "")
    {
        ++original_hash_value;
    }
    //cout<<"Value of h: "<<h<<endl;
    //cout<<"input: "<<input<<endl;
    //Put in the string input at index location h
    array[original_hash_value]=input;
    //cout<<"Array [h]: "<<array[h]<<endl;
}

//'global' hash function that encodes the hash value for insert and finds the hash value for decoding for search
int Hash::hash(string input)
{
    const char* v = 0;
    v = input.c_str();
    int h, a = 31415, b = 27183;
    for (h = 0; *v != 0; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    h = (h < 0) ? (h + M) : h;
    return h;
}

string Hash::search(string input)
{
    //Print yes or no if that searched string is in the input
    //Iterate through until empty slot
    int original_hash_value = hash(input);
    string sreturn = "False";
    
    //Checking for strings already in that spot. check to see if empty or if collison
    while ((array[original_hash_value] != input) && (array[original_hash_value] != ""))
    {
        ++original_hash_value;
    }
    //when we get here we have searched either all the elements pass the array{orig hash value} and if we havent seen the input then we know it is not there
    if (array[original_hash_value] == "")
    {
        sreturn = "No";
    }
    //this means we found the input value before we found an empty spot
    else if (array[original_hash_value] == input)
    {
        sreturn = "Yes";
    }
    return sreturn;
}

//returns the size of the hashtable
int Hash::getSize()
{
    return M;
}