#include "root.h"
#include <iostream>

#define ceil_div_2(x) (((x)%2==0)? (x)/2 : (x)/2+1)

template <class T>
class StaticDeque : Deq<T>
{
    T *arr;
    int sz,head,tail;

    public:
        StaticDeque(int size);
        void r_shift();
        void l_shift();

        //cont
        int size() const;
        bool isEmpty() const;
        std::string toString() const;

        //deque
        bool pushFront(T value);
        bool pushBack(T value);
        T popFront();
        T popBack();
        T peekFront() const;
        T peekBack() const;
};

template <class T>
StaticDeque<T>::StaticDeque(int size) : sz(size)
{
    head = (tail = sz/2) - 1;
    arr = new T[sz];
}

template <class T>
void StaticDeque<T>::r_shift()
{
    int shift = ceil_div_2(sz - tail); //FIX?
    for(auto i=tail;i>head;i--)
    {
        auto tmp = arr[i+shift];
        arr[i+shift] = arr[i];
        arr[i] = tmp;
    }
    head = shift - 1;
    tail += shift;
}

template <class T>
void StaticDeque<T>::l_shift()
{
    int shift = (head==0)? 1 : ceil_div_2(head); //FIX?
    for(auto i=head;i<tail;i++)
    {
        auto tmp = arr[i+shift];
        arr[i+shift] = arr[i];
        arr[i] = tmp;
    }
    head = (head==0)? -1 : (shift - 1);
    tail = tail - shift;
}

template <class T>
int StaticDeque<T>::size() const
{
    return sz;
}

template <class T>
bool StaticDeque<T>::isEmpty() const
{
    return head==tail;
}

template <class T>
std::string StaticDeque<T>::toString() const
{
    for(auto i=0;i<sz;i++) std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
    std::cout<<"head: "<<head<<" tail: "<<tail<<std::endl;
    return std::string(""); //FIX
}

template <class T>
bool StaticDeque<T>::pushFront(T value)
{
    if(head==-1)
    { 
        if(tail!=sz) { r_shift(); }
        else { return false; }
    }
    arr[head--] = value;
    return true;
}

template <class T>
bool StaticDeque<T>::pushBack(T value)
{
    if(tail==sz)
    {
        if(head!=-1) { l_shift(); }
        else { return false; }
    }
    arr[tail++] = value;
    return true;
}

template <class T>
T StaticDeque<T>::popFront()
{
    if(tail<head) throw 0xBAD;
    return arr[++head];
}

template <class T>
T StaticDeque<T>::popBack()
{
    if(tail<head) throw 0xBAD;
    return arr[--tail];
}

template <class T>
T StaticDeque<T>::peekFront() const
{
    return arr[head];
}

template <class T>
T StaticDeque<T>::peekBack() const
{
    return arr[tail];
}

int
main()
{
    auto sd = StaticDeque<int>(4);
    return 0;
}
