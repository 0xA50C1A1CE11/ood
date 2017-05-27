#include <string>

template <class T>
class Cont
{
  virtual int size() const = 0;
  virtual bool isEmpty() const = 0;
  virtual std::string toString() const = 0;
};

template <class T>
class PushPopCont : Cont<T>
{
  virtual bool push(T value) = 0;
  virtual int pop() = 0;
  virtual int peek() const = 0;
};

template <class T>
class Deq : Cont<T>
{
  virtual bool pushFront(T value) = 0;
  virtual bool pushBack(T value) = 0;
  virtual int popFront() = 0;
  virtual int popBack() = 0;
  virtual int peekFront() const = 0;
  virtual int peekBack() const = 0;
};

template <class T>
class IndCont : Cont<T>
{
  virtual int get(int index) const = 0;
  virtual void set(int index,T value) = 0;
};

template <class T>
class InsCont : IndCont<T>,Deq<T>
{
  virtual bool insertAt(int index,T value) = 0;
  virtual T removeAt(int index) = 0;
};
