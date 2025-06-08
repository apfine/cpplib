#include <iostream>
#include "sets.h++"

using namespace std;

int main(){
    set s1;
    s1.print();
    s1.Union(1,2);
    cout<<"\nDone";

    s1.Union(5,4);
    s1.print();
    s1.Union(4,3);
    cout<<endl;
    int p = s1.find(4);
    s1.print();
    cout<<"\nThe parent of the node is : "<<p<<" .";
}