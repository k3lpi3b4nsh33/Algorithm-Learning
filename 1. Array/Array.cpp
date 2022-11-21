/**
 * @file Array.cpp
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief
 * @version 0.1
 * @date 2022-11-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "Array.h"

int main()
{

    Array<int> arr(10);
    int cnt = 0;

    int upperBound;
    std::cout << "Enter the upperBound for prime number which is >= 2" << std::endl;

    std::cin >> upperBound;

    for (int i = 2; i <= upperBound; i++)
    {
        bool isPrime = true;

        // Check if prime
        for (int j = 0; j < cnt; j++)
        {
            if (i % arr[j] == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            if (cnt == arr.getSize())
            {
                arr.resize(cnt * 2);
            }
            arr[cnt++] = i;
        }
    }

    arr.showArray();
    return 0;
}