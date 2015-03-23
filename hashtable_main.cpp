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
    //Created random table size for testing per page 496
    int table_size = 1021;
    Hash manager(table_size);
    int return2;
    string testinput = "drew";
    return2 = manager.hashU(&testinput[0],manager.getSize());
    cout<<return2<<endl;
    int number;
    string name;
    string input;
    
    while (getline(cin, input))
    {
        stringstream ss(input);
        ss>>number;
        if (number == 0)
        {
            break;
        }
        if (number == 1 || number == 2)
        {
            ss>>name;
        }
        cout<<number<<endl;
        cout<<name<<endl;
    }
    
    
}




