#pragma once
#include <iostream>

template <class T>
class Array
{
private:
    int size;
    int used;
    T *list;

public:
    Array(int sz = 50);
    Array(const Array<T> &array);
    ~Array();

    // Override =
    Array<T> &operator=(const Array<T> &array);

    // Override ==
    bool operator==(const Array<T> &array);

    // Override !=
    bool operator!=(const Array<T> &array);

    // Override []
    T &operator[](int i);

        // Override const []
    const T &operator[](int i) const;

    // Override T* type transfer to any types
    operator T *();

    // Override T* type transfer to const
    operator const T *() const;

    int getSize() const;

    // modify the array size
    void resize(int size);

    // Show array
    void showArray();
};

template <class T>
inline Array<T>::Array(int sz)
{

    if (sz < 0)
    {
        std::cout << "The sz is less than 0" << std::endl;
    }
    else
    {
        size = sz;
        list = new T[sz];
    }
}

template <class T>
inline Array<T>::Array(const Array<T> &array)
{

    this->size = array.size;
    list = new T[size];
    if (list == NULL)
    {
        std::cout << "ALLOC ERROR!" << std::endl;
        exit(-1);
    }
    for (int i = 0; i < size; i++)
    {
        list[i] = array.list[i];
    }
}

template <class T>
inline Array<T>::~Array()
{
    delete[] list;
    list = NULL;
}

template <class T>
inline Array<T> &Array<T>::operator=(const Array<T> &array)
{

    if (&array != this)
    {
        if (this->size != array.size)
        {
            delete[] list;
            this->size = array.size;
            list = new T[this->size];
        }
        for (int i = 0; i < this->size; i++)
        {
            list[i] = array.list[i];
        }
    }

    return *this;
}

template<class T>
inline bool Array<T>::operator==(const Array<T>& array){

    if(this->size != array.size){
        return false;
    }

    for(int i = 0; i<this->size;i++){
        if(this->list[i] != array.list[i]){
            return false;
        }
    }

    return true;
}

template<class T>
inline bool Array<T>::operator!=(const Array<T>& array){
    return !(*this == array);
}

template<class T>
inline T & Array<T>::operator[](int i)
{
    if(i < 0 && i>=size){
        std::cout << "Index Error!" << std::endl;
        exit(-1);
    }
	return list[i];
}

template<class T>
inline Array<T>::operator const T*() const{
    return list;
}

template<class T>
inline Array<T>::operator T *(){
    return list;
}

template<class T>
inline int Array<T>::getSize() const
{
    return size;
}

template<class T>
inline void Array<T>::resize(int size){
    
    if(size < 0){
        std::cout << "The size is less than 0" << std::endl;
        exit(-1);
    }

    if(this -> size == size){
        return;
    }

    T* newList = new T[size];
    
    if(newList == NULL){
        std::cout << "ALLOC ERROR!" << std::endl;
        exit(-1);
    }

    int n = (size > this->size)? this->size:size;

    for(int i = 0 ; i< n; i++){
        newList[i] = list[i];
    }

    delete[] list;
    list = newList;
   
    
    this -> size = size;
}

template<class T>
inline void Array<T>::showArray(){

    std::cout << "showArray Function" << std::endl;
    for(int i = 0 ; i< size; i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}
