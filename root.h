#include <string>

template <class T>
class Cont
{
  virtual int size() const = 0;
  virtual bool isEmpty() const;
  virtual std::string toString() const;
};

template <class T>
class PushPopCont : Cont<T>
{
  virtual bool push(T value) = 0;
  virtual int pop();
  virtual int peek() const;
};

template <class T>
class Deq : Cont<T>
{
  virtual bool pushFront(T value) = 0;
  virtual bool pushBack(T value);
  virtual int popFront();
  virtual int popBack();
  virtual int peekFront() const;
  virtual int peekBack() const;
};

template <class T>
class IndCont : Cont<T>
{
  virtual int get(int index) const = 0;
  virtual void set(int index,T value);
};

template <class T>
class InsCont : IndCont<T>,Deq<T>
{
  virtual bool insertAt(int index,T value) = 0;
  virtual T removeAt(int index);
};
