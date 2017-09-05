//Bounded_Dequeue
//implements Dequeue using a fixed-sized array as backing store
//
//by Wilson Staley

#ifndef BOUNDED_DEQUEUE_H
#define BOUNDED_DEQUEUE_H
#include <iostream>
#include "dequeue.h"

using namespace std;

//======================= Bounded_Dequeue Class =======================// 

template <typename T>
class Bounded_Dequeue : public Dequeue<T>{
    public:
        Bounded_Dequeue( size_t cap );
        ~Bounded_Dequeue();

        void push_front(T element);
        void push_back(T element);
        void pop_front();
        void pop_back();
        T peek_front();
        T peek_back();
        bool is_empty();
        bool is_full();
        void clear();
        void print();
		
    private:
        size_t size;
        T * const data;
        size_t head;
        size_t tail;
};


//=====================================================================// 
//Constructor and Destructor

template <typename T>
Bounded_Dequeue<T>::Bounded_Dequeue(size_t cap)
: size( cap + 1 ), data( new T[cap + 1] ), head(0), tail(0) {}

//{
//    size = ++cap;
//    data = new T[size];
//    head = 0;
//    tail = 0;
//}


template <typename T>
Bounded_Dequeue<T>::~Bounded_Dequeue(){
	delete [] data;
}

//=====================================================================// 
//Operations

// --------- push_front()
template <typename T>
void Bounded_Dequeue<T>::push_front(T element){
    if( is_full() ) cout << "The Dequeue is full!" << endl;
    else if( is_empty() ) data[tail++] = element;
    else if( head == 0 ){ 
        head = (size - 1);
        data[head] = element;
    }
    else data[--head] = element;
}

// --------- push_back()
template <typename T>
void Bounded_Dequeue<T>::push_back(T element){
    if( is_full() ) cout << "The Dequeue is full!" << endl;
    else if( is_empty() ) push_front(element); // If the dequeue is empty, pushing to the front does the same thing as pushing to the back. PUSH TO FRONT TO AVOID HEAD AND TAIL DISRUPTION
    else if( tail == (size - 1)){
        data[tail] = element;
        tail = 0;
    }
    else data[tail++] = element;
}

// --------- pop_front()
template <typename T>
void Bounded_Dequeue<T>::pop_front(){
    if( is_empty() ) cout << "The Dequeue is empty!" << endl;
    else if( head == (size - 1)) head = 0;
    else head++;
}

// --------- pop_back()
template <typename T>
void Bounded_Dequeue<T>::pop_back(){
    if( is_empty() ) cout << "The Dequeue is empty!" << endl;
    else if( tail == 0 ) tail = (size - 1); 
    else tail--; 
}

// --------- peek_front()
template <typename T>
T Bounded_Dequeue<T>::peek_front(){
    if( is_empty() )
        throw runtime_error( "Bounded_Dequeue<T>.peek_front(): empty dequeue");
    
    return data[head];
}

// --------- peek_back()
template <typename T>
T Bounded_Dequeue<T>::peek_back(){
    if( is_empty() )
        throw runtime_error( "Bounded_Dequeue<T>.peek_back(): empty dequeue");
    
    if( tail == 0 ) return data[size-1];
    return data[tail-1];
}

// --------- is_empty()
template <typename T>
bool Bounded_Dequeue<T>::is_empty(){
	return head == tail ? true:false;
}

// --------- is_full()
template <typename T>
bool Bounded_Dequeue<T>::is_full(){
	if((tail + 1) == head) return true;
        else if (tail == (size-1) && head == 0) return true;
	else return false;
}

// --------- clear()
template <typename T>
void Bounded_Dequeue<T>::clear(){
    head = tail = 0;
}

// --------- print()
template <typename T>
void Bounded_Dequeue<T>::print(){
    cout << "Dequeue: [_";
    for(int i=head; i!=tail; i++){
        if(i == (size - 1)){
            cout << data[i] << "_";
            i = -1;
        }
        else{ cout << data[i] << "_"; }
    }
    cout << "]"<< endl;
}

#endif