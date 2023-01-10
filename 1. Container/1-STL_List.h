/**
 * @file 1-STL_List.h
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef l3vi4th4n_STL_Algobase_H
#define l3vi4th4n_STL_Algobase_H

#include <cstddef>
#include "STL_Config.h"
#include "STL_Iterator.h"
#include "STL_Iterator_Base.h"
#include "STL_Allocator.h"
#include "STL_Algobase.h"

__STL_BEGIN_NAMESPACE
struct _List_node_base
{
    _List_node_base *_M_next;
    _List_node_base *_M_prev;
};

template <class _Tp>
struct _List_node : public _List_node_base
{
    _Tp _M_data;
};

struct _List_ITERATOR_BASE
{
    typedef size_t                      size_type;
    typedef ptrdiff_t                   difference_type;
    typedef BIDIRECTIONAL_Iterator_tag  Iterator_CATEGORY;
    _List_node_base *_M_node;

    _List_ITERATOR_BASE(_List_node_base *__x) : _M_node(__x) {}
    _List_ITERATOR_BASE() {}

    void _M_incr()
    {
        _M_node = _M_node->_M_next;
    }

    void _M_decr()
    {
        _M_node = _M_node->_M_prev;
    }

    bool operator==(const _List_ITERATOR_BASE &__x) const
    {
        return _M_node == __x._M_node;
    }

    bool operator !=(const _List_ITERATOR_BASE &__x) const
    {
        return _M_node != __x._M_node;
    }

};

 template<class _Tp, class _Ref, class _Ptr>
 struct _List_ITERATOR : public _List_ITERATOR_BASE
 {
    typedef _List_ITERATOR<_Tp, _Tp &, _Tp *> iterator;
    typedef _List_ITERATOR<_Tp, const _Tp &, const _Tp *>   const_iterator;
    typedef _List_ITERATOR<_Tp, _Ref, _Ptr>                 _Self;
        
    typedef _Tp                 value_type;
    typedef _Ref                reference;
    typedef _Ptr                pointer;
    typedef _List_node<_Tp>     _Node;

    _List_ITERATOR(_Node *__x) : _List_ITERATOR_BASE(__x) {}
    _List_ITERATOR() {}
    _List_ITERATOR(const iterator &__x) : _List_ITERATOR_BASE(__x._M_node) {}

    reference operator*() const
    {
        return ((_Node *)_M_node)->_M_data;
    }

    _Self &operator++()
    {
        this->_M_incr();
        return *this;
    }

    _Self &operator--()
    {
        _Self __tmp = *this;
        this -> _M_decr;
        return __tmp;
    }

    _Self operator--(int)
    {
        _Self __tmp = *this;
        this->_M_decr();
        return *this;
    }
 };

 template<class _Tp, class _Alloc>
 class _List_BASE
 {
public:
    typedef _Alloc allocator_type;
    allocator_type get_allocator() const
    {
        return allocator_type();
    }

    _List_BASE(const allocator_type &)
    {
        _M_node = _M_get_node();
        _M_node->_M_next = _M_node;
        _M_node->_M_prev = _M_node;
    }

    ~_List_BASE()
    {
        clear();
        _M_put_node(_M_node);
    }

    void clear();

protected:
    typedef SIMPLE_ALLOC<_List_node<_Tp>, _Alloc> _Alloc_type;
    _List_node<_Tp> *_M_get_node()
    {
        return _Alloc_type:allocate(1);
    }

    void _M_put_node(_List_node<_Tp> *__p)
    {
        _Alloc_type::deallocate(__p,1);
    }

    _List_node<_Tp> *_M_node;
 };
 
template<class _Tp, class _Alloc>
void _List_BASE<_Tp, _Alloc>::clear()
{
    _List_node<_Tp> *__cur = (_List_node<_Tp> *)  _M_node->_M_next;
    while(__cur != _M_node)
    {
        _List_node<_Tp> *__tmp = __cur;
        __cur = (_List_node<_Tp> *) __cur->_M_next;
        _Destory(&__tmp->_M_data);
        _M_put_node(__tmp);
    }

    _M_node->_M_next = _M_node;
    _M_node->_M_prev = _M_node;
}

template<class _Tp, class _Alloc=alloc>
class list : protected _List_BASE<_Tp, _Alloc>
{

};

__STL_END_NAMESPACE

#endif