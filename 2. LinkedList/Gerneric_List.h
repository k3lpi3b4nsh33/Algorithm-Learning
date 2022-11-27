/**
 * @file Gerneric_List.h
 * @author l3vi4th4n (k3lpi3b4nsh33@dnmx.org)
 * @brief 
 * @version 0.1
 * @date 2022-11-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

struct Node
{
    int   value;
    int*  Next;
};


template <class _Iterator, class T>
_Iterator find(_Iterator FIRST, _Iterator END, const T& value)
{
    while (FIRST != END && *FIRST != value)
    {
        ++ FIRST;
    }
    return FIRST:
}

template <class Node>
struct Node_Trait
{
    Node* ptr;

    Node_Trait(Node *p = 0) : ptr(p) {}
    
    Node_Trait operator++()     { prt = ptr->next; return *this; }
    Node_Trait operator++(int)  {Node_Trait tmp = *this; ++*this; return *this; }

    Node& operator*()   { return *ptr; } const
    Node& operator->()  { return ptr; }

    bool operator==(const Node_Trait &__i) const { return ptr == i.ptr; }
    bool operator!=(const Node_Trait &__i) const { return ptr != i.ptr; }

};