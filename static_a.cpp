#include "root.h"
template <class T>
class StaticArray: IndCont<T>
{
    int sz;
    T *arr;

    public:
        StaticArray(int size);

        //cont
        int size() const;
        bool isEmpty() const;
        std::string toString() const;

        //ind-cont
        T get(int index) const;
        void set(int index,T value);
};

template <class T>
StaticArray<T>::StaticArray(int size)
{
    sz = size;
    arr = new T[sz];
}

template <class T>
int StaticArray<T>::size() const
{
    return sz;
}

template <class T>
bool StaticArray<T>::isEmpty() const
{
    return false; //FIX?
}

template <class T>
std::string StaticArray<T>::toString() const
{
    return std::string(""); //FIX
}

template <class T>
T StaticArray<T>::get(int index) const
{
    return arr[index];
}

template <class T>
void StaticArray<T>::set(int index,T value)
{
    arr[index] = value;
}
int
main()
{
    auto arr = StaticArray<int>(10);
    return 0;
}
