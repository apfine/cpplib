#include <iostream>

using namespace std;

int main(){
    while(true){
        int* p= new int[50];
        delete []p;              //This line will prevent memory overflow
    }
    return 0 ;
}
//Dont run on older vesions , On newer versions without line 8
//You will get : terminate called recursively


//The benefit of using the dynamic memory allocation is that we remove the compile time dependency or stack dependency of our program and thus 
//creating a more resilient program which can be more better than the stack memory which is allocated at the time of memory allocation.
//Generally the heap memory which is used in the dynamic memory allocation is larger than the stack memory.