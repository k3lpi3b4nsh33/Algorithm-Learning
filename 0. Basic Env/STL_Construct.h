/**
 * @file STL_Construct.h
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief 
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef l3vi4th4n_STL_CONSTRUCT_H
#define l3vi4th4n_STL_CONSTRUCT_H

#include <new>
#include "STL_Config.h"
#include "type_traits.h"
#include "STL_Iterator_Base.h"


__STL_BEGIN_NAMESPACE

    template<class _T1, class _T2>
    inline void _Constuct(_T1* __p, _T2* __value)
    {
        new((void * __p)) _T1(__value);
    }

    template<class _T1>
    inline void _Constuct(_T1* __p)
    {
        new((void *) __p) _T1();
    }

    template<class _Tp>
    void destory_one(_Tp *pointer, _S_true_type) {}

    template<class _Tp>
    void destroy_one(_Tp *pointer, _S_false_type)
    {
        if(pointer != nullptr)
        {
            pointer->~Tp();
        }
    }
    


__STL_END_NAMESPACE

#endif