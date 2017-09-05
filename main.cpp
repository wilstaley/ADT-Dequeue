//main.cpp
//Implementing and Testing the Dequeue
//
//by Wilson Staley

#include <iostream>
#include "bounded_dequeue.h"

using namespace std;

int main(){
    //=================== Testing the Bounded Dequeue ===================//
    
    int flag = 0; // flag to count errors
    
    //test size 0 dequeue
    cout << "==========================" << endl;
    cout << "Testing size 0 Dequeue" << endl;
    Bounded_Dequeue<char> myDeq(0);
    if(! myDeq.is_empty()) flag++;
    if(! myDeq.is_full()) flag++;
    //these will throw an error
    /*
    myDeq.peek_front();
    myDeq.peek_back();
    myDeq.pop_front();
    myDeq.pop_back();
    myDeq.push_front();
    myDeq.push_back();
     */
    if(myDeq.length() != 0) flag++;
    myDeq.print();
    myDeq.clear();
    myDeq.print();
    cout << "==========================" << endl;
    
    
    //test size 1 dequeue
    cout << "Testing size 1 Dequeue" << endl;
    Bounded_Dequeue<int> myDeq2(1);
    if(! myDeq2.is_empty()) flag++;
    if( myDeq2.is_full()) flag++;
    //these will throw an error
    /*
    myDeq2.peek_front();
    myDeq2.peek_back();
    myDeq2.pop_front();
    myDeq2.pop_back();
     */
    myDeq2.push_back(1);
    cout << "length: " << myDeq2.length() << endl;
    myDeq2.print();
    //these will throw an error
    /*
    myDeq2.push_front();
    myDeq2.push_back();
     */
    myDeq2.pop_back();
    cout << "length: " << myDeq2.length() << endl;
    myDeq2.print();
    myDeq2.push_front(30);
    myDeq2.print();
    myDeq2.pop_front();
    myDeq2.print();
    myDeq2.push_front(30);
    myDeq2.print();
    myDeq2.pop_back();
    cout << "==========================" << endl;
    
    
    //test size 5 dequeue
    cout << "Testing size 5 Dequeue" << endl;
    Bounded_Dequeue<char> myDeq3(5);
    if(! myDeq2.is_empty()) flag++;
    if( myDeq2.is_full()) flag++;
    //these will throw an error
    /*
    myDeq2.peek_front();
    myDeq2.peek_back();
    myDeq2.pop_front();
    myDeq2.pop_back();
     */
    myDeq3.push_front('A');
    cout << "length: " << myDeq3.length() << endl;
    myDeq3.print();
    myDeq3.push_back('B');
    cout << "length: " << myDeq3.length() << endl;
    myDeq3.print();
    myDeq3.push_back('C');
    cout << "length: " << myDeq3.length() << endl;
    myDeq3.print();
    myDeq3.push_front('D');
    cout << "length: " << myDeq3.length() << endl;
    myDeq3.print();
    myDeq3.push_back('E');
    cout << "length: " << myDeq3.length() << endl;
    myDeq3.print();
    //these will throw an error
    /*
    myDeq3.push_front();
    myDeq3.push_back();
    */
    if(myDeq3.is_empty()) flag++;
    if(! myDeq3.is_full()) flag++;
    myDeq3.pop_back();
    cout << "length: " << myDeq3.length() << endl;
    myDeq3.print();
    myDeq3.pop_front();
    cout << "length: " << myDeq3.length() << endl;
    myDeq3.print();
    myDeq3.clear();
    cout << "length: " << myDeq3.length() << endl;
    myDeq3.print();
    
    
    cout << "==========================" << endl;
    cout << "==========================" << endl;
    
    
    cout << "FLAGS: " << flag << endl;
    if(flag == 0) cout << "**** ALL TESTS PASSED ****" << endl;
    
    return 0;
}

