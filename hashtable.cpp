//
//  hashtable.cpp
//  Exercise 3
//
//  Created by Gonsalves on 3/22/15.
//
//

#include "hashtable.h"
using namespace std;

Hash::Hash(int table_size)
{
    array = new string[table_size];
    M = table_size;
}

Hash::Hash()
{
    //Arbitrarily large array to start out with
    M=1021;
    array = new string[M];
}

void Hash::grow()
{
    //the front stays the same
    string *temp;
    //crappy band aid for the 'for' loop below
    int old_table_size = M;
    int new_table_size = (getSize() * 2) + 1;
    //Have to set M equal to the new_table_size because when we rehash in the for statement, hash relies on the value of M.
    M = new_table_size;
    try {
        
        temp = new string[new_table_size];
        
    } catch (bad_alloc& ba) {
        cerr << "bad_alloc caught: " << ba.what() << endl;
    }
    //Have to only loop through the old_table_size
    for (int a = 0; a != old_table_size; ++a)
    {
        //Search through the old array for anything that has a hit
        if (array[a] != "")
        {
            //Rehash the old string with the M changed above
            int original_hash_value = hash(array[a]);
            
//            //Cherk for collisions
//            //Duplicates checking first
//            if (temp[original_hash_value] == array[a])
//            {
//                cerr<<"grow Duplicate found and not inserted"<<array[a]<<endl;
//                return;
//            }
            //Keep looking until the next available
            //TO SOLVE FOR WRAP AROUND, ADD INTO MODULE SIZE or else we get SEG FAULT!
            while (temp[original_hash_value % getSize()] != "")
            {
                ++original_hash_value;
            }
            
            //Put in the string input at index location h
            //SMUST HAVE THE % SIZE when we add back in
            temp[original_hash_value % getSize()]=array[a];
        }
    }
    delete[] array;
    array = temp;
    cout<<"I grew"<<endl;
    cout<<"New size is: "<< M<<endl;
    cout<<"Number of elements: "<<num_elements<<endl;
}

//Hash function is the Universal Hash Function from Sedgewick 1-4 on p  498
void Hash::insert(string input)
{
    if (isFull())
    {
        grow();
    }
    int original_hash_value = hash(input);
    //Cherk for collisions
    //Duplicates checking first
    if (array[original_hash_value] == input)
    {
        cerr<<"insert Duplicate found and not inserted"<< input<<endl;
        return;
    }
    //Keep looking until the next available
    //TO SOLVE FOR WRAP AROUND, ADD INTO MODULE SIZE or else we get SEG FAULT!
    while (array[original_hash_value % getSize()] != "")
    {
        //We have to check again. say the hash of joe is 2 and cathy is 2. in the first check above with == input we checked at 2 and no cathy != joe. cathy could have been put at 3 and the empty space is at 4. without this next IF check, then we would say 'yes, 3 is full but we wont check it and will just look for an empty space coming up'. this is a problem is SMALL arrays and not so much in large arrays with a small ratio of num of elements
        if (array[original_hash_value] == input)
        {
            cerr<<"insert Duplicate found and not inserted"<< input<<endl;
            return;
        }
        ++original_hash_value;
    }

    //Put in the string input at index location h
    //SMUST HAVE THE % SIZE when we add back in
    array[original_hash_value % getSize()]=input;
    //Update number of elements
    ++num_elements;
    cout<<"Current size: "<<M<<endl;
    cout<<"Number of elements: "<<num_elements<<endl;

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

bool Hash::isFull()
{
    bool rbool = false;
    if (getNumElements() == getSize())
    {
        rbool = true;
    }
    return rbool;
}

//'global' hash function that encodes the hash value for insert and finds the hash value for decoding for search
int Hash::hash(string input)
{
    cout<<"value of M: "<<M<<endl;
    const char* v = 0;
    v = input.c_str();
    int h, a = 31415, b = 27183;
    for (h = 0; *v != 0; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    h = (h < 0) ? (h + M) : h;
    cout<<"hash value: "<<h<<endl;
    return h;
}

//returns the size of the hashtable
int Hash::getSize()
{
    return M;
}

int Hash::getNumElements()
{
    return num_elements;
}