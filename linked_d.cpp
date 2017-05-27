#include "root.h"
#include <iostream>

template <class T>
class __dlnode
{
    public:
        T content;
        __dlnode *next,*prev;
        
        __dlnode() : next(nullptr),prev(nullptr){};
        __dlnode(T elem) : next(nullptr),prev(nullptr)
        {
            content = elem;
        }
        __dlnode(__dlnode *p,T elem,__dlnode* n)
        {
            prev = p;
            next = n;
            content = elem;
        }
};

template <class T>
class LinkedDeque : Deq<T>
{
    __dlnode<T> *head,*tail;
    int sz;

    public:
        LinkedDeque();

        //cont
        int size() const;
        bool isEmpty() const;
        std::string toString() const;

        //deq
        bool pushFront(T value);
        bool pushBack(T value);
        T popFront();
        T popBack();
        T peekFront() const;
        T peekBack() const;
};

template <class T>
LinkedDeque<T>::LinkedDeque()
{
    head = (tail = new __dlnode<T>());
    sz=0;
}

template <class T>
int LinkedDeque<T>::size() const
{
    return sz;
}

template <class T>
bool LinkedDeque<T>::isEmpty() const
{
    return sz==0;
}

template <class T>
std::string LinkedDeque<T>::toString() const
{
    return std::string("");
}

template <class T>
bool LinkedDeque<T>::pushFront(T value)
{
    head->content = value;
    head = (head->prev = new __dlnode<T>());
    sz++;
    return true;
}

template <class T>
bool LinkedDeque<T>::pushBack(T value)
{
    //tail = new __dlnode<T>(tail,value,nullptr);
    tail->content = value;
    tail = (tail->prev = new __dlnode<T>());
    sz++;
    return true;
}

template <class T>
T LinkedDeque<T>::popFront()
{
    auto result = head->content,
         to_del = head;
    head = head->next;
    delete to_del;
    sz--;
    return result;
}

template <class T>
T LinkedDeque<T>::popBack()
{
    auto result = tail->content,
         to_del = tail;
    tail = tail->prev;
    delete to_del;
    sz--;
    return result;
}

template <class T>
T LinkedDeque<T>::peekFront() const
{
    return head->content;
}

template <class T>
T LinkedDeque<T>::peekBack() const
{
    return tail->content;
}

int
main()
{
    auto ld = LinkedDeque<int>();
    ld.pushFront(100);
    ld.pushFront(100);
    ld.pushFront(100);
    std::cout<<ld.popBack();
    std::cout<<ld.popBack();
    std::cout<<ld.popBack();
    return 0;
}

