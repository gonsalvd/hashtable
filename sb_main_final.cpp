//
//  sb_main.cpp
//  Exercise2
//
//  Created by Gonsalves on 3/17/15.
//
//


#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "binary.cpp"
#include "linear.cpp"
#include <ctime>
#include <vector>
using namespace std;

void linearSearch (int NE, int NS, int all[], int search[]);
void binarySearch (int left, int right, int search_value);

int global_binary=0;
vector<int> all_vector;

int main(int argc, char **argv)
{
    int NE;  // number of elements
    int NS;  // number of element to search
    //Testing only, looking at 4th element of command line for a 1 - testing or 0 - input
    int exe_type;
    
    //changed for testing
    //TWO types of inputs. Input for testing: ./search 10 5 1
    //Input for taking in values: ./search 10 5 0
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
    
    clock_t start = 0;
    clock_t finish = 0;
    double elapsed_time = 0;
    
    if(exe_type == 0)
    {
        //Here we are reading in from a file in the format of example-io.txt. We know the structure
        cin>>NE;
        cin>>NS;
//        cout<<NE<<endl;
//        cout<<NS<<endl;
        
        //Created holders for the elements
        int all_holder[NE];
        int search_holder[NS];
        
        //we know the next elements in the list all have to do with NE
        for (int a = 0;a < NE; a++)
        {
            cin>>all_holder[a];
            //cout<<"all holder:"<<all_holder[a]<<endl;
        }
        //we know the next elements in the list all have to do with NS
        for (int b = 0; b < NS; b++)
        {
            cin>>search_holder[b];
            //cout<<"search holder:"<<search_holder[b]<<endl;
        }
        
        //LINEAR SEARCH TIMING
        cout<<"Linear Search: "<<endl;
        start = clock();
        linearSearch(NE,NS,all_holder,search_holder);
        finish = clock();
        elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
//        cout<<"Time for LinearSearch: "<<elapsed_time<<endl;
        
        //BINARY SEARCH TIMING
        cout<<"Binary Search: "<<endl;
        //Put all array values into a vector for easy sorting BUT dont include in timing
        //Put all array values into a vector for easy sorting BUT dont include in timing
        for (int i = 0; i < NE; i++)
        {
            all_vector.push_back(all_holder[i]);
        }
        //vector<int> all_vector (all_holder, all_holder+NE);
        sort(all_vector.begin(), all_vector.begin()+NE);
        start = clock();
        //Do a binary search on each of the elements we are searching for
        for (int a=0; a<NS; a++)
        {
            //Pasing all these variables is pretty poor programming. BinarySearch COULD just reference global variables, etc. Well maybe this isnt too bad and could be reused a little easier.
            binarySearch(0, NE-1, search_holder[a]);
        }
        finish = clock();
        elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
        //cout<<"Value of N: "<<NE<<endl;
        //cout<<"Value of S: "<<NS<<endl;
//        cout<<"Time for BinarySearch: "<<elapsed_time<<endl;
        
        return 0;
        
    }
    
    if(exe_type == 1)
    {
        //Created holders for the elements
        int all_holder[NE];
        int search_holder[NS];
        
        // Initializing seed for pseudo-random sequence
        srand(time(NULL));
        
//        printf("%d %d\n", NE, NS);
        for (int i=0; i<NE; i++)
        {
            int number;
            
            number = rand();
            // coin toss
            double r = ((double) rand() / (RAND_MAX));
            
            if (r < 0.05)           // Introducing neg. numbers with 5% probability
                number = - number;
            //printf("%d ", number);
            
            //added number to set
            all_holder[i] = number;
        }
        
//        printf("\n");
        for (int i=0; i<NS; i++)
        {
            int number;
            
            number = rand();
            // coin toss
            double r = ((double) rand() / (RAND_MAX));
            
            if (r < 0.05)           // Introducing neg. numbers with 5% probability
                number = - number;
            //printf("%d ", number);
            
            //added
            search_holder[i] = number;
        }
        
        //LINEAR SEARCH TIMING
        cout<<"Linear Search: "<<endl;
        start = clock();
        linearSearch(NE,NS,all_holder,search_holder);
        finish = clock();
        elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
        cout<<"Time for LinearSearch: "<<elapsed_time<<endl;
        
        //BINARY SEARCH TIMING
        cout<<"Binary Search: "<<endl;
        //Put all array values into a vector for easy sorting BUT dont include in timing
        for (int i = 0; i < NE; i++)
        {
            all_vector.push_back(all_holder[i]);
        }
        //vector<int> all_vector (all_holder, all_holder+NE);
        sort(all_vector.begin(), all_vector.begin()+NE);
        
        start = clock();
        //Do a binary search on each of the elements we are searching for
        for (int a=0; a<NS; a++)
        {
            //Pasing all these variables is pretty poor programming. BinarySearch COULD just reference global variables, etc. Well maybe this isnt too bad and could be reused a little easier.
            binarySearch(0, NE-1, search_holder[a]);
        }
        finish = clock();
        elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
//        cout<<"Value of N: "<<NE<<endl;
//        cout<<"Value of S: "<<NS<<endl;
//        cout<<"Time for BinarySearch: "<<elapsed_time<<endl;
        
        return 0;
    }
    
    return 0;
    
}

//this is going to be RECURSIVE
//search CAN remain an array, does not need to be sorted in order to search through the venctor elementally
void binarySearch (int left, int right, int search_value)
{
    //Test variable
    //global_binary++;
    
    //this catches and stops the sequence
    //secondary catch and not finding something
    if (left > right)
    {
        cout<<"No"<<endl;
        return;
    }
    //eg 9/2 = 4 (due to 4.5 being casted as int to 4)
    //left side will be from 0 to 4 and right side from 5 to 9
    int middle = (left + right) / 2;
    
    if (search_value == all_vector.at(middle))
    {
        cout<<"Yes"<<endl;
        return;
    }
    //Equivalent to not finding it
    if (left == right)
    {
        cout<<"No"<<endl;
        return;
    }
    //search less than
    if (search_value < all_vector.at(middle))
    {
        binarySearch(left, middle - 1, search_value);
    }
    //searches greater than
    else
    {
        binarySearch(middle + 1, right, search_value);
    }
    
}

//Linear search for searching for each element in the search array, by looking through all the elements of all
void linearSearch (int NE, int NS, int all[], int search[])
{
    int counter;
    int search_value = 0;
    int all_value = 0;
    //This will provide us a way to say "no" only once
    bool flag = false;
    
    //loop through the number of elements that we are searching for
    for (int i = 0; i < NS; i++)
    {
        flag = false;
        search_value = search[i];
        
        //loop through the total number of elements EACH TIME for each value in NS
        for(int j = 0; j<NE; j++)
        {
            ++counter;
            all_value = all[j];
            if(search_value == all_value)
            {
                cout<<"Yes"<<endl;
                flag = true;
                //This will break us from the for loop
                break;
            }
        }
        //crappy implementation where we have to always check this variable (time costing and stupid)
        //how could i have gotten rid of this flag?
        if (flag == false)
        {
            cout<<"No"<<endl;
        }
    }
}




