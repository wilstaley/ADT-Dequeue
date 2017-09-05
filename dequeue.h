//Dequeue Class
//defines the ADT Dequeue
//Abstract base class with pure, virtual functions
//
//by Wilson Staley

#ifndef DEQUEUE_H
#define DEQUEUE_H

using namespace std;

//======================= Base Class Dequeue =======================// 

template <typename T>
class Dequeue{
    public:
        virtual void push_front(T element) = 0;
        virtual void push_back(T element) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual T peek_front() = 0;
        virtual T peek_back() = 0;
        virtual bool is_empty() = 0;
        virtual bool is_full() = 0;
        virtual size_t length() = 0;
        virtual void clear() = 0;
        virtual void print() = 0;
        virtual ~Dequeue() {};
};

#endif

