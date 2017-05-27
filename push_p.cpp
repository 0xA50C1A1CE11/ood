#include "root.h"
#include <iostream>
#define STD_CAP 10
#define STD_FACT 0.75

template <class T>
class Stack : PushPopCont<T>
{
    T *arr,*poi,*poi_cap;
    int cap,factor;

    public:
        Stack();
        void extend();

        //cont
        int size() const;
        bool isEmpty() const;
        std::string toString() const;

        //push-pop
        bool push(T value);
        T pop();
        T peek() const;
};

template <class T>
Stack<T>::Stack():cap(STD_CAP),factor(STD_FACT)
{
    arr = new T[cap];
    poi = arr;
    poi_cap = &(arr[cap-1]);

}

template <class T>
void Stack<T>::extend()
{
    auto new_arr = new T[cap*2];
    auto p1=arr,p2=new_arr;
    while(p1!=poi_cap)
        *p2++ = *p1++;
    *poi = *++p2;
    poi_cap = &(new_arr[cap*2-1]);
    cap*=2;
    delete arr;
    arr = new_arr;
}

template <class T>
int Stack<T>::size() const
{
    return poi - arr;
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return poi==arr;
}

template <class T>
std::string Stack<T>::toString() const
{
    return std::string("");
}

template <class T>
bool Stack<T>::push(T value)
{
    if(poi == poi_cap) extend();
    *poi++ = value;
    return true; //FIX?
}

template <class T>
T Stack<T>::pop()
{
    return *--poi;
}

template <class T>
T Stack<T>::peek() const
{
    return *poi;
}


template <class T>
class Queue : PushPopCont<T>
{
    Stack<T> *buffer,*container;

    public:
        Queue();

        //cont
        int size() const;
        bool isEmpty() const;
        std::string toString() const;

        //push-pop
        bool push(T value);
        T pop();
        T peek() const;
};

template <class T>
Queue<T>::Queue()
{
    buffer = new Stack<T>();
    container = new Stack<T>();
}

template <class T>
int Queue<T>::size() const
{
    return buffer->size() + container->size();
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return buffer->isEmpty() and container->isEmpty();
}

template <class T>
std::string Queue<T>::toString() const
{
    return std::string(""); //FIX
}

template <class T>
bool Queue<T>::push(T value)
{
    return buffer->push(value);
}

template <class T>
T Queue<T>::pop()
{
    if(isEmpty()) throw 0xBAD;
    while(not buffer->isEmpty())
        container->push(buffer->pop());
    return container->pop();
}

template <class T>
T Queue<T>::peek() const
{
    if(buffer->isEmpty())
    {
        while(not container->isEmpty())
            buffer->push(container->pop());
        const auto result = buffer->peek();
        return result;
    }
    else
    {
        while(not buffer->isEmpty())
            container->push(buffer->pop());
        const auto result = container->peek();
        return result;
    }
}

int
main()
{
    auto st = Stack<int>();
    auto qu = Queue<int>();
    st.push(1);
    st.push(2);
    st.push(3);
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!\n";
    qu.push(1);
    qu.push(2);
    qu.push(3);
    std::cout<<qu.pop()<<std::endl;
    std::cout<<qu.pop()<<std::endl;
    std::cout<<qu.pop()<<std::endl;
    return 0;
}
