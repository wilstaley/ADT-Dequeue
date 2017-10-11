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
        size_t length();
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



template <typename T>
Bounded_Dequeue<T>::~Bounded_Dequeue(){
	delete [] data;
}

//=====================================================================// 
//Operations

// --------- push_front()
template <typename T>
void Bounded_Dequeue<T>::push_front(T element){
    if( is_full() )
        throw runtime_error( "Bounded_Dequeue<T>.push_front(): full dequeue");
    
    else if( is_empty() && tail == size-1 ){
        tail = 0;
        data[head] = element;
    }
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
    if( is_full() )
        throw runtime_error( "Bounded_Dequeue<T>.push_back(): full dequeue");
    
    else if( is_empty() ) push_front(element); 
    else if( tail == (size - 1)){
        data[tail] = element;
        tail = 0;
    }
    else data[tail++] = element;
}

// --------- pop_front()
template <typename T>
void Bounded_Dequeue<T>::pop_front(){
    if( is_empty() )
        throw runtime_error( "Bounded_Dequeue<T>.pop_front(): empty dequeue");
    
    else if( head == (size - 1)) head = 0;
    else head++;
}

// --------- pop_back()
template <typename T>
void Bounded_Dequeue<T>::pop_back(){
    if( is_empty() )
        throw runtime_error( "Bounded_Dequeue<T>.pop_back(): empty dequeue");
    
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

// --------- length()
template <typename T>
size_t Bounded_Dequeue<T>::length(){
    if ( head <= tail )
        return ( tail - head );
    else
        return ( (tail) + (size - head) );
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

