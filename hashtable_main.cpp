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
using namespace std;

int main(int argc, char **argv)
{
//    int NE;  // number of elements
//    int NS;  // number of element to search
//    //Testing only, looking at 4th element of command line for a 1 - testing or 0 - input
//    int exe_type;
//    
//    //changed for testing
//    //TWO types of inputs. Input for testing: ./search 10 5 1
//    //Input for taking in values: ./search 10 5 0
//    if (argc != 3)
//    {
//        printf("<usage>: parameters.\n");
//        return 1;
//    }
//    else
//    {
//        NE = atoi(argv[1]);
//        NS = atoi(argv[2]);
//        //printf("Number of elements = %d\nNumber of elements to search = %d\n", NE, NS);
//        exe_type = 0;
////        exe_type = atoi(argv[3]);
//        
//    }

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




