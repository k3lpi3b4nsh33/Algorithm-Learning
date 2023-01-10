/**
 * @file STL_Allocator.h
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef l3vi4th4n_STL_Allocator_H
#define l3vi4th4n_STL_Allocator_H

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include "STL_Config.h"
#include "STL_Construct.h"

__STL_BEGIN_NAMESPACE

template <int __inst>
class __MALLOC_ALLOC_TEMPLATE
{

public:
    int EXIT_STATUS_CODE = 0;
    static void *allocate(size_t __n)
    {
        void *__result = malloc(__n);
        if (__result == 0)
        {
            fprintf(stderr, "OUT OF MEMORY!");
            EXIT_STATUS_CODE = 1;
            exit(EXIT_STATUS_CODE);
        }
        return __result;
    }

    static void deallocate(void *__p)
    {
        free(__p);
    }

    static void *reallocate(void *__p, size_t __new_sz)
    {
        void *__result = realloc(__p, __new_sz);
        if (__result == 0)
        {
            fprintf(stderr, "OUT OF MEMORY!");
            EXIT_STATUS_CODE = 1;
            exit(EXIT_STATUS_CODE);
        }
        return __result;
    }
};

typedef __MALLOC_ALLOC_TEMPLATE<0> MALLOC_ALLOC;

template <class _Tp, class _Alloc>
class SIMPLE_ALLOC
{
public:
    static _Tp *allocate(size_t __n)
    {
        return 0 == __n ? 0 : (_Tp *)_Alloc::allocate(__n * sizeof(_Tp));
    }

    static _Tp *allocate(void)
    {
        return (_Tp *)_Alloc::allocate(sizeof(_Tp));
    }

    static void deallocate(_Tp *__p, size_t __n)
    {
        if (0 != __n)
        {
            _Alloc::deallocate(__p, __n * sizeof(_Tp));
        }
    }

    static void deallocate(_Tp *__p)
    {
        _Alloc::deallocate(__p, sizeof(_Tp));
    }
};

__STL_END_NAMESPACE

#endif