/**
 * @file Simpler-Allocate-Test.cpp
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief 
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Simple-Allocator.h"
#include <vector>
#include <iostream>

int main()
{
    int ia[5] = {0,1,2,3,4};
    unsigned int i;

    std::vector<int, l3vi4th4n::allocator<int>> iv(ia, ia+5);
    for(i=0; i<iv.size(); i++)
    {
        std::cout << iv[i] << " ";
    }
    return 0;
}

