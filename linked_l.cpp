#include <string>
#include <iostream>
#include "root.h"

template <class T>
class __node
{
    public:
        T car;
        __node * cdr;

        __node()
        {
            this->cdr = nullptr;
        };

        __node(T value)
        {
            this->car = value;
            this->cdr = nullptr;
        }
};

template <class T>
class LinkedList : PushPopCont<T>, InsCont<T>
{

    public:
        __node<T> *head; //FIX
        __node<T> *tail; //FIX
        LinkedList();

        //cont
        int size() const;
        bool isEmpty() const;
        std::string toString() const;

        //push-pop
        bool push(T value);
        T pop();
        T peek() const;

        //deq
        bool pushFront(T value);
        bool pushBack(T value);
        T popFront();
        T popBack();
        T peekFront() const;
        T peekBack() const;

        //ind-cont
        T get(int index) const;
        void set(int index,T value);

        //ins-cont
        bool insertAt(int index,int value);
        T removeAt(int index);
};

template <class T>
LinkedList<T>::LinkedList(): head(nullptr),tail(nullptr){};

template <class T>
int LinkedList<T>::size() const
{
    int i=0;
    for(auto n = this->head;n;n=n->cdr) ++i;
    return i;
};

template <class T>
bool LinkedList<T>::isEmpty() const
{
    return this->head == nullptr;
}

template <class T>
std::string LinkedList<T>::toString() const
{
    std::string result("");
    if(size()==0) return result;
    for(auto n=head;n;n=n->cdr)
    {
        std::cout<<n->car<<" "; //FIX
        result+=n->car;
        result+="";
    }
    return result;
}
template <class T>
bool LinkedList<T>::push(T value) //Deque::pushBack origin
{
    if(isEmpty())
    {
        tail = (head = new __node<T>(value));
    }
    else
    {
        tail->cdr = new __node<T>(value);
        tail = tail->cdr;
    }
    //??? return true/false in what case 
}

template <class T>
T LinkedList<T>::pop() //Deque popBack origin
{
    for(auto prelast=head;prelast;prelast = prelast->cdr)
    {
        if(prelast->cdr == tail)
        {
            auto result = tail->car;
            delete tail;
            tail = prelast;
            tail->cdr = nullptr;
            return result;
        }
    }
    if(size()==1)
    {
        auto result = head->car;
        delete head;
        head = (tail = nullptr);
        return result;
    }
    throw 0xBAD1157;
}

template <class T>
T LinkedList<T>::peek() const //Deque peekBack origin
{
    return tail->car;
}

template <class T>
T LinkedList<T>::get(int index) const
{
    for(auto result=head;result;result=result->cdr)
    {
        if(not index--) return result->car;
    }
    throw 0xBAD1DEC5;
}

template <class T>
void LinkedList<T>::set(int index,T value)
{
    for(auto n=head;n;n=n->cdr)
        if(not index--)
        {
            n->car = value;
            return;
        }
    throw 0xBAD1DEC5;
}

template <class T>
bool LinkedList<T>::insertAt(int index, int value)
{
    for(auto target=head;target;target=target->cdr)
    {
        if(not index--)
        {
            auto next_node = target->cdr;
            target->cdr = new __node<T>(target->car);
            target->cdr->cdr = next_node;
            target->car = value;
            return true;
        }
    }
    if(index = size())
    {
        push(value);
        return true;
    }
    return false;
};

template <class T>
T LinkedList<T>::removeAt(int index) //pop=removeAt(size-1)?
{
    if(index == 0) 
    {
        return popFront();
    }
    auto prev_ind = index - 1;
    for(auto n=head;n;n=n->cdr)
    {
        if(not prev_ind--)
        {
            auto to_del = n->cdr,
                 result = to_del->car;
            n->cdr = n->cdr->cdr;
            delete to_del;
            return result;
        }
    }
    throw 0xBAD1DEC5;
};

template <class T>
bool LinkedList<T>::pushFront(T value)
{
    auto new_head = new __node<T>(value);
    auto old_head = head;
    head = new_head;
    new_head->cdr = old_head;
}

template <class T>
bool LinkedList<T>::pushBack(T value) //push-pop push pseudename
{
    return push(value);
}

template <class T>
T LinkedList<T>::popFront()
{
    auto result = head->car;
    auto new_head = head->cdr;
    delete head;
    head = new_head;
    return result;
}

template <class T>
T LinkedList<T>::popBack() //push-pop pop pseudoname
{
    return pop();
}

template <class T>
T LinkedList<T>::peekFront() const
{
    return head->car;
}

template <class T>
T LinkedList<T>::peekBack() const
{
    return tail->car;
}

int
main()
{
    auto ll = LinkedList<int>();
    int command = 0;
    int buff1 = 0;
    int buff2 = 0;
    while(1)
    {
        std::cout<<  "0 - size\
                    \n1 - isEmpty\
                    \n2 - push\
                    \n3 - pop\
                    \n4 - peek\
                    \n5 - push front\
                    \n6 - pop front\
                    \n7 - peek front\
                    \n8 - get\
                    \n9 - set\
                    \n10 - insert at\
                    \n11 - remove at\
                    \ninput command number:";
        std::cin>>command;
        switch(command)
        {
            case 0:
                std::cout<<ll.size()<<std::endl;
                break;
            case 1:
                std::cout<<ll.isEmpty()<<std::endl;
                break;
            case 2:
                std::cin>>buff1;
                ll.push(buff1);
                break;
            case 3:
                std::cout<<"pop: "<<ll.pop()<<std::endl;
                break;
            case 4:
                std::cout<<"peek: "<<ll.peek()<<std::endl;
                break;
            case 5:
                std::cin>>buff1;
                ll.pushFront(buff1);
                break;
            case 6:
                std::cout<<"pop:"<<ll.popFront()<<std::endl;
                break;
            case 7:
                std::cout<<"peekfront:"<<ll.peekFront()<<std::endl;
                break;
            case 8:
                std::cin>>buff1;
                std::cout<<"get:"<<ll.get(buff1)<<std::endl;
                break;
            case 9:
                std::cin>>buff1>>buff2;
                ll.set(buff1,buff2);
                break;
            case 10:
                std::cin>>buff1>>buff2;
                ll.insertAt(buff1,buff2);
                break;
            case 11:
                std::cin>>buff1;
                ll.removeAt(buff1);
                break;
        }
        std::cout<<"ll:";
        ll.toString();
        std::cout<<std::endl;
    }
    return 0;
}
