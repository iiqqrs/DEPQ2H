#include <iostream>
#include "depq.cpp"
using namespace std;

int main() {
   //Create a class called DEPQ which implements 
   // (at least) three methods:
   // void DEPQ::insert(n)
   // int DEPQ::pop_max();
   // int DEPQ::pop_min();
   // All three operations should take O(log(n)) time
  
   DEPQ dePQ;
   
   dePQ.insert(11);
   dePQ.insert(3);
   dePQ.insert(7);
   dePQ.insert(13);
   dePQ.insert(2);
   dePQ.insert(17);
   dePQ.insert(5);
   dePQ.insert(19);
   
   //We should see the commented values in that order
   cout << dePQ.pop_min() << endl; //2
   cout << dePQ.pop_max() << endl; //19
   cout << dePQ.pop_min() << endl; //3
   cout << dePQ.pop_max() << endl; //17
   cout << dePQ.pop_min() << endl; //5
   cout << dePQ.pop_max() << endl; //13
   cout << dePQ.pop_min() << endl; //7
   cout << dePQ.pop_max() << endl; //11  
}