//
//  hashtable_main.cpp
//  Exercise3
//
//  Created by Gonsalves on 3/22/15.
//
//


#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

#include "hashtable.h"
using namespace std;

int main(int argc, char **argv)
{
    //Created random table size of prime number 1021 for testing per page 496
    //int table_size = 1021;
    //Hash manager = Hash(table_size);
    string input;
    int number;
    string name;
    //Read in first line as the size of table
    std::getline(std::cin,input);
    int table_size = atoi(input.c_str());
    //cout<<"table size: "<<table_size<<endl;
    Hash manager = Hash(table_size);
    
    
    while (getline(cin, input))
    {
        stringstream ss(input);
        ss>>number;
        if (number == 0)
        {
            break;
        }
        //This commands adding
        else if (number == 1)
        {
            //Error handling for size
//            if (manager.isFull())
//            {
//                cerr<<"Hash Table Size Reached."<<endl;
//                break;
//            }
            ss>>name;
            manager.insert(name);
        }
        //This commands search
        else if (number == 2)
        {
            ss>>name;
            cout<<manager.search(name)<<endl;
        }
        //This is for taking in the intial size of the array
        else if (number > 2)
        {
            table_size = number;
        }
        

//        cout<<number<<endl;
//        cout<<name<<endl;
    }
    //cout<<manager.getNumElements()<<endl;
    return 0;
    
}




