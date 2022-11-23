/**
 * @file    STL_Iterator_Base.h
 * @author  l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief   Init STL Env Part3 STL_ITERATOR_BASE
 * @version 0.1
 * @date    2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef l3vi4th4n_STL_ITERATOR_BASE_H
#define l3vi4th4n_STL_ITERATOR_BASE_H

#include "STL_Config.h"
#include <stddef.h>

__STL_BEGIN_NAMESPACE

    struct INPUT_Iterator_tag {};
    struct OUTPUT_Iterator_tag {};

    struct FORWARD_Iterator_tag :       public INPUT_Iterator_tag{};
    struct BIDIRECTIONAL_Iterator_tag : public FORWARD_Iterator_tag{};
    struct RANDOM_ACCESS_Iterator_tag : public BIDIRECTIONAL_Iterator_tag{};

    template<class _T, class _Distance>
    struct INPUT_Iterator
    {
        typedef INPUT_Iterator_tag  Iterator_CATEGORY;
        typedef _T                  value_type;
        typedef _Distance           difference_type;
        typedef _T*                 *pointer;
        typedef _T&                 *reference;
    };

    struct OUTPUT_Iterator
    {
        typedef OUTPUT_Iterator_tag Iterator_CATEGORY;
        typedef void                value_type;
        typedef void                difference_type;
        typedef void                pointer;
        typedef void                reference;
    };

    template<class _T, class _Distance>
    struct FORWARD_Iterator 
    {
        typedef FORWARD_Iterator_tag    Iterator_CATEGORY;
        typedef _T                      value_type;
        typedef _Distance               difference_type;
        typedef _T*                     pointer;
        typedef _T&                     reference;
    };

    template<class _T, class _Distance>
    struct BIDIRECTIONAL_Iterator
    {
        typedef BIDIRECTIONAL_Iterator_tag  Iterator_CATEGORY;
        typedef _T                          value;
        typedef _Distance                   difference_type;
        typedef _T*                         pointer;
        typedef _T&                         reference;
    };

    template<class _T, class _Distance>
    struct RANDOM_ACCESS_Iterator
    {
        typedef RANDOM_ACCESS_Iterator_tag  Iterator_CATEGORY;
        typedef _T                          value_type;
        typedef _Distance                   difference_type;
        typedef _T*                         pointer;
        typedef _T&                         reference;
    };

    template<class _Category, class _T, class _Distance = ptrdiff_t, class _Pointer = _T*, class _Reference = _T&>
    struct iterator
    {
        typedef _Category   Iterator_CATEGORY;
        typedef _T          value_type;
        typedef _Distance   difference_type;
        typedef _Pointer    pointer;
        typedef _Reference  reference;
    };
    
    template<class _Iterator>
    struct Iterator_traits
    {
        typedef typename _Iterator::Iterator_CATEGORY   Iterator_CATEGORY;
        typedef typename _Iterator::value_type          value_type;
        typedef typename _Iterator::difference_type     difference_type;
        typedef typename _Iterator::pointer             pointer;
        typedef typename _Iterator::reference           reference; 
    };
    
    template<class _T>
    struct Iterator_traits<_T *>
    {
        typedef RANDOM_ACCESS_Iterator_tag  Iterator_CATEGORY;
        typedef _T                          value_type;
        typedef ptrdiff_t                   difference_type;
        typedef _T*                         pointer;
        typedef _T&                         reference;
    };

    template<class _T>
    struct Iterator_traits<const _T *>
    {
        typedef RANDOM_ACCESS_Iterator_tag  Iterator_CATEGORY;
        typedef _T                          value_type;
        typedef ptrdiff_t                   difference_type;
        typedef const _T*                   pointer;
        typedef const _T&                   reference;
    };

    template<class _Iter>
    inline typename Iterator_traits<_Iter>::Iterator_CATEGORY __Iterator_CATEGORY(const _Iter&)
    {
        typedef typename Iterator_traits<_Iter>::Iterator_CATEGORY _CATEGORY;
        return _CATEGORY();
    }

    template<class _Iter>
    inline typename Iterator_traits<_Iter>::Iterator_CATEGORY Iterator_CATEGORY(const _Iter &__x)
    {
        return __Iterator_CATEGORY(__x);
    }

    template<class _Iter>
    inline typename Iterator_traits<_Iter>::differnece_type *__Distance_type(const _Iter &)
    {
        return static_cast<typename Iterator_traits<_Iter>::differnece_type *>(0);
    }

    template<class _Iter>
    inline typename Iterator_traits<_Iter>::differnece_type *__Distance_type(const _Iter & __x)
    {
        return __Distance_type(__x);
    }

    template<class _Iter>
    inline typename Iterator_traits<_Iter>::value_type *__value_type(const _Iter &)
    {
        return static_cast<typename Iterator_traits<_Iter>::value_type *>(0);
    }

    template<class _Iter>
    inline typename Iterator_traits<_Iter>::value_type *__value_type(const _Iter & __x)
    {
        return __value_type(__x);
    }

#define __ITERATOR_CATEGORY(__i)    __Iterator_CATEGORY(__i)
#define __DISTANCE_TYPE(__i)        __DISTANCE_TYPE(__i)
#define __VALUE_TYPE(__i)           __value_type(__i)

    template<class _INPUT_Iterator, class _Distance>
    inline void __Distance(_INPUT_Iterator __FIRST, _INPUT_Iterator __LAST, _Distance & __n, INPUT_Iterator_tag)
    {
        while(__FIRST != __LAST)
        {
            ++ __FIRST;
            ++ __n;
        }
    }

    template<class _RANDOM_ACCESS_Iterator, class _Distance>
    inline void __Distance(_RANDOM_ACCESS_Iterator __FIRST, _RANDOM_ACCESS_Iterator __LAST, _Distance & __n, RANDOM_ACCESS_Iterator_tag)
    {
        __n = __LAST - __FIRST;
    }

    template<class _INPUT_Iterator, class _Distance>
    inline void distance(_INPUT_Iterator __FIRST, _INPUT_Iterator __LAST, _Distance & __n)
    {
        __Distance(__FIRST, __LAST, __n, Iterator_CATEGORY(__FIRST));
    }

#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION

    template<class _INPUT_Iterator>
    inline typename Iterator_traits<_INPUT_Iterator>::difference_type __distance(_INPUT_Iterator __FIRST, _INPUT_Iterator __LAST, INPUT_Iterator_tag)
    {
        typename Iterator_traits<_INPUT_Iterator>::differnce_type __n = 0;
        while(__FIRST != __LAST)
        {
            ++ __FIRST;
            ++ __n;
        }
        return __n;
    }

    template<class _RANDOM_ACCESS_Iterator>
    inline typename Iterator_traits<_RANDOM_ACCESS_Iterator>::difference_type __distance(_RANDOM_ACCESS_Iterator __FIRST, _RANDOM_ACCESS_Iterator __LAST, RANDOM_ACCESS_Iteratorg_tag)
    {
        return __LAST - __FIRST;
    }

    template<class _INPUT_Iterator, class _Distance>
    inline typename Iterator_traits<_INPUT_Iterator>::difference_type distance(_INPUT_Iterator __FIRST, _INPUT_Iterator __LAST, _Distance & __n)
    {
        typename Iterator_traits<_INPUT_Iterator>::Iterator_CATEGORY _CATEGORY;
        __Distance(__FIRST, __LAST, Iterator_CATEGORY());
    }
#endif // __STL_CLASS_PARTIAL_SPECIALIZATION

    template<class _BIDIRECTIONAL_Iterator, class _Distance>
    inline void __advance(_BIDIRECTIONAL_Iterator &__i, _Distance __n, BIDIRECTIONAL_Iterator_tag) 
    {
        if (__n > 0) 
        {
            while (__n--) 
            {
                ++__i;
            }
        } 
        else 
        {
            while (__n++) 
            {
                --__i;
            }
        }
    }

    template<class _RANDOM_ACCESS_Iterator, class _Distance>
    inline void __advance(_RANDOM_ACCESS_Iterator &__i, _Distance __n, RANDOM_ACCESS_Iterator_tag) 
    {
        __i += __n;
    }

    template<class _INPUT_ACCESS_Iterator, class _Distance>
    inline void advance(_INPUT_ACCESS_Iterator &__i, _Distance __n) 
    {
        __advance(__i, __n, __iterator_category(__i));
    }


__STL_END_NAMESPACE
#endif