#include <string>
#include "root.h"

template <class T>
class __node
{
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
    __node<T>* head;
    __node<T>* tail;
    
};

int
main()
{
  auto l = LinkedList<int>();
  return 0;
}
