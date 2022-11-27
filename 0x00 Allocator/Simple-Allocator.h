/**
 * @file Simple-Allocator.h
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief 
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef _l3vi4th4n_SIMPLE_ALLOCATOR_H
#define _l3vi4th4n _SIMPLE_ALLOCATOR_H

#include "ALL_CONFIG.h"
#include <new>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <climits>

__BEGIN__NAMESPACE_

template <class T>
inline T* _allocate(ptrdiff_t size, T*)
{
    
    T* tmp = (T*) (operator new((size_t)(size * sizeof(T))));

    if(tmp == 0)
    {
        std::cerr << "Out of memory!" << std::endl;
        exit(1);
    }
    return tmp;
    
}

template <class T>
void _deallocate(T* buffer)
{
    operator delete(buffer);
}

template <class T1, class T2>
inline void _construct (T1* p, const T2& value)
{
    new(p) T1(value);
}

template <class T>
inline void _destory(T* ptr)
{
    ptr -> ~T();
}

template <class T>
class allocator 
{
public:
    typedef T           value_type;
    typedef T*          pointer;
    typedef const T*    const_pointer;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;

    template <class U>
    struct rebind
    {
        typedef allocator<U> other;
    };

    pointer allocate(size_type n, const void* hint=0)
    {
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n)
    {
        _deallocate(p);
    }

    void construct(pointer p, const T& value)
    {
        _construct(p, value);
    }

    void destory(pointer p)
    {
        _destory(p);
    }

    pointer address(reference x)
    {
        return (pointer)&x;
    }

    const_pointer const_address(const_reference &x)
    {
        return (const_pointer)&x;
    }

    size_type max_size() const
    {
        return size_type(UINT_MAX/sizeof(T));
    }


};
__END__NAMESPACE_

#endif
