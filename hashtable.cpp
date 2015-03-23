//
//  hashtable.cpp
//  Exercise 3
//
//  Created by Gonsalves on 3/22/15.
//
//

#include "hashtable.h"

Hash::Hash (int table_size)
{
    M = table_size;
}

int Hash::hashU(char *v, int M)
{
    int h, a = 31415, b = 27183;
    for (h = 0; *v != 0; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    return (h < 0) ? (h + M) : h;
}

int Hash::getSize()
{
    return M;
}