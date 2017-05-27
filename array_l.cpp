#include "root.h"
#define STD_CAPACITY 20
#define STD_EXTEND_FACTOR 0.75
#define ceil_div_2(x) (((x)%2==0)? (x)/2 : (x)/2+1)

template <class T>
class ArrayList : PushPopCont<T>, InsCont<T>
{

    public:

        T *arr;
        int cap,head,tail;

        void r_shift();
        void l_shift();
        void extend();

        ArrayList();

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
ArrayList<T>::ArrayList() : cap(STD_CAPACITY)
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

int
main()
{
    return 0;
}
