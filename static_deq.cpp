#include <string>
#include <root>

template <class T>
class StaticDeque : Deque<T>
{
  T* arr;
  int sz,head,tail;
  T null_el;

  StaticDeque(int sz,T null_element)
  {
    this->arr = new T[sz];
    for(int i=0;i<sz;i++) this->arr[i] = null_element;
    this->null_el = null_element;
    this->sz = sz;
    this->head = (this->tail = (int)sz/2) - 1;
  }

  int size()
  {
    return this->sz;
  }
  
  bool isEmpty()
  {
    return this->head == this->tail;
  };

  std::string toString() const;

  bool pushFront(T value)
  {
    if(this->head == 0)
    {
      int diff = this->sz - this->tail;
      diff = (diff % 2 == 0)? diff/2 : diff/2 + 1;
      for(int i=tail+diff;i>diff;i--)
      {
        this->arr[i] = this->arr[i-diff];
      }
      for(int i=0;i<diff;i++) this->arr[i] = this->null_el;
    }
    this->tail+=diff;
    this->arr[(this->head=diff)] = value;
  }

  bool pushBack(T value)
  {
    if(this->tail == this->sz)
    {

    }
    this->arr[this->tail++] = value;
  }
}
