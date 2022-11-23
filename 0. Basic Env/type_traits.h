/**
 * @file type_traits.h
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief Init STL Env Part2 type_traits.h
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef l3vi4th4n_STL_TYPE_TRAITS_H
#define l3vi4th4n_STL_TYPE_TRAITS_H

#include "STL_Config.h"
#include <type_traits>

__STL_BEGIN_NAMESPACE

template <class T, T v>
struct  S_integral_constant
{
    static constexpr T value = v;
};

template <bool b>
using _S_BOOL_CONSTANT = S_integral_constant<bool, b>;

typedef _S_BOOL_CONSTANT<true>  _S_true_type;
typedef _S_BOOL_CONSTANT<false> _S_false_type;


// IS PAIR?

template<class __T1, class __T2>
struct pair{};

template <class __T>
struct is_pair :mystl::_S_false_type {};

template<class __T1, class __T2>
struct is_pair<mystl::pair<__T1, __T2>>:mystl::_S_true_type{};


__STL_END_NAMESPACE
#endif
