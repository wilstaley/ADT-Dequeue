//main.cpp
//Implementing and Testing the Dequeue
//
//by Wilson Staley

#include <iostream>
#include "bounded_dequeue.h"

using namespace std;

int main(){
    //======================= Testing the Bounded Dequeue =======================//
    
    int flag = 0; // flag to count errors
    
    //test size 0 dequeue
    Bounded_Dequeue<char> myDeq(0);
    if(! myDeq.is_empty()) flag++;
    if(! myDeq.is_full()) flag++;
    //these should each throw an error
    //myDeq.peek_front();
    //myDeq.peek_back();
	myDeq.pop_front();
	myDeq.pop_back();
    
    cout << flag << endl;
    
    return 0;
}
