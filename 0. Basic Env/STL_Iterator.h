/**
 * @file STL_Iterator.h
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief BASIC STL Env PART4 STL_INTERATOR.h
 * @version 0.1
 * @date 2022-11-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef l3vi4th4n_STL_INTERATOR_H
#define l3vi4th4n_STL_INTERATOR_H

#include "STL_Config.h"
#include "STL_Iterator_Base.h"

__STL_BEGIN_NAMESPACE

template <class _Container>
class BACK_INSERT_Iterator
{
protected:
    _Container *CONTAINER;

public:
    typedef _Container              container_type;
    typedef OUTPUT_Interator_tag    Iterator_CATEGORY;

    typedef void    value_type;
    typedef void    difference_type;
    typedef void    pointer;
    typedef void    reference;

    explicit BACK_INSERT_Iterator(_Container &__x) : CONTAINER(&__x) {}

    BACK_INSERT_Iterator<_Container> &operator=(const typename _Container::value_type &__value)
    {
        CONTAINER->push_back(__value);
        return *this;
    }

    BACK_INSERT_Iterator<_Container> &operator*() { return *this; }
    BACK_INSERT_Iterator<_Container> &operator++() { return *this; }
    BACK_INSERT_Iterator<_Container> &operator++(int) { return *this; }

};

template <class _Container>
inline BACK_INSERT_Iterator<_Container> BACK_INSERTER(_Container &__x)
{
    return BACK_INSERT_Iterator<_Container>(__x);
}


template<class _Container>
class FRONT_INSERT_Iterator
{
protected:
    _Container *CONTAINER;

public:
    typedef _Container              container_type;
    typedef OUTPUT_Iterator_tag     Iterator_CATEGORY;

    typedef void    value_type;
    typedef void    difference_type;
    typedef void    pointer;
    typedef void    reference;

    explicit FRONT_INSERT_Iterator(_Container &__x) : CONTAINER(&__x) {}

    FRONT_INSERT_Iterator<_Container> &operator=(const typename _Container::value_type &__value)
    {
        CONTAINER -> push_front(__value);
        return *this;
    }

    FRONT_INSERT_Iterator<_Container> &operator*() { return *this; }
    FRONT_INSERT_Iterator<_Container> &operator++() { return *this; }
    FRONT_INSERT_Iterator<_Container> &operator++(int) { return *this; }

};

template<class _Container>
inline FRONT_INSERT_Iterator<_Container> FRONT_INSERTER(_Container &__x)
{
    return FRONT_INSERT_Iterator<_Container>(__x);
}


template<class T>
class INSERT_Iterator
{
protected:
    _Container *CONTAINER;
    typename _Container::ITERATOR ITER;

public:
    typedef _Container              container_type;
    typedef OUTPUT_Iterator_tag     Iterator_CATEGORY;

    typedef void    value_type;
    typedef void    difference_type;
    typedef void    pointer;
    typedef void    reference;

    INSERT_Iterator(_Container &__x, typename _Container::ITERAOTR __i) : CONTAINER(&__x), ITER(__i) {}

    INSERT_Iterator<_Container> &operator=(const typename _Container::value_type &__value)
    {
        ITER = CONTAINER -> insert(ITER, __value);
        ++ ITER;
        return *this;
    }
};
__STL_END_NAMESPACE

#endif