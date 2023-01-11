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
    typedef _Container container_type;
    typedef OUTPUT_Interator_tag Iterator_CATEGORY;

    typedef void value_type;
    typedef void difference_type;
    typedef void pointer;
    typedef void reference;

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

template <class _Container>
class FRONT_INSERT_Iterator
{
protected:
    _Container *CONTAINER;

public:
    typedef _Container container_type;
    typedef OUTPUT_Iterator_tag Iterator_CATEGORY;

    typedef void value_type;
    typedef void difference_type;
    typedef void pointer;
    typedef void reference;

    explicit FRONT_INSERT_Iterator(_Container &__x) : CONTAINER(&__x) {}

    FRONT_INSERT_Iterator<_Container> &operator=(const typename _Container::value_type &__value)
    {
        CONTAINER->push_front(__value);
        return *this;
    }

    FRONT_INSERT_Iterator<_Container> &operator*() { return *this; }
    FRONT_INSERT_Iterator<_Container> &operator++() { return *this; }
    FRONT_INSERT_Iterator<_Container> &operator++(int) { return *this; }
};

template <class _Container>
inline FRONT_INSERT_Iterator<_Container> FRONT_INSERTER(_Container &__x)
{
    return FRONT_INSERT_Iterator<_Container>(__x);
}

template <class T>
class INSERT_Iterator
{
protected:
    _Container *CONTAINER;
    typename _Container::ITERATOR ITER;

public:
    typedef _Container container_type;
    typedef OUTPUT_Iterator_tag Iterator_CATEGORY;

    typedef void value_type;
    typedef void difference_type;
    typedef void pointer;
    typedef void reference;

    INSERT_Iterator(_Container &__x, typename _Container::ITERAOTR __i) : CONTAINER(&__x), ITER(__i) {}

    INSERT_Iterator<_Container> &operator=(const typename _Container::value_type &__value)
    {
        ITER = CONTAINER->insert(ITER, __value);
        ++ITER;
        return *this;
    }
};

template <class _Iterator>
class reverse_iterator
{
protected:
    _Iterator current;

public:
    typedef typename iterator_traits<_Iterator>::iterator_category
        iterator_category;
    typedef typename iterator_traits<_Iterator>::value_type
        value_type;
    typedef typename iterator_traits<_Iterator>::difference_type
        difference_type;
    typedef typename iterator_traits<_Iterator>::pointer
        pointer;
    typedef typename iterator_traits<_Iterator>::reference
        reference;

    typedef _Iterator iterator_type;
    typedef reverse_iterator<_Iterator> _Self;

public:
    reverse_iterator() {}

    explicit reverse_iterator(iterator_type __x) : current(__x) {}

    reverse_iterator(const _Self &__x) : current(__x.current) {}

    template <class _Iter>
    reverse_iterator(const reverse_iterator<_Iter> &__other) : current(__other.base()) {}

    iterator_type base() const
    {
        return current;
    }

    reference operator*() const
    {
        _Iterator __tmp = current;
        return *--__tmp;
    }

    pointer operator->() const
    {
        return &(operator*());
    }

    _Self &operator++()
    {
        --current;
        return *this;
    }

    _Self operator++(int)
    {
        _Self __tmp = *this;
        --current;
        return __tmp;
    }

    _Self &operator--()
    {
        ++current;
        return *this;
    }

    _Self operator--(int)
    {
        _Self __tmp = *this;
        ++current;
        return __tmp;
    }

    _Self operator+(difference_type __n) const
    {
        return _Self(current - __n);
    }

    _Self operator-(difference_type __n) const
    {
        return _Self(current + __n);
    }

    _Self &operator+=(difference_type __n)
    {
        current -= __n;
        return *this;
    }

    _Self &operator-=(difference_type __n)
    {
        current += __n;
        return *this;
    }

    reference operator[](difference_type __n) const
    {
        //        base()[-n-1]
        return *(*this + __n);
    }
};

template <class _Iterator>
inline bool operator==(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs)
{
    return __lhs.base() == __rhs.base();
}

template <class _Iterator>
inline bool operator!=(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs)
{
    return !(__lhs == __rhs);
}

template <class _Iterator>
inline bool operator<(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs)
{
    return __rhs.base() < __lhs.base();
}

template <class _Iterator>
inline bool operator>(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs)
{
    return __rhs < __lhs;
}

template <class _Iterator>
inline bool operator<=(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs)
{
    return !(__rhs < __lhs);
}

template <class _Iterator>
inline bool operator>=(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs)
{
    return !(__lhs < __rhs);
}

template <class _Iterator>
reverse_iterator<_Iterator>
operator+(typename reverse_iterator<_Iterator>::difference_type __n,
          const reverse_iterator<_Iterator> &__x)
{
    //    return it + n;
    return reverse_iterator<_Iterator>(__x.base() - __n);
}

template <class _Iterator>
typename reverse_iterator<_Iterator>::difference_type
operator-(const reverse_iterator<_Iterator> &__lhs, const reverse_iterator<_Iterator> &__rhs)
{
    return __rhs.base() - __lhs.base();
}
__STL_END_NAMESPACE

#endif