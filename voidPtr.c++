#include <iostream>

using namespace std;

int main(){
    int n = 0 ;
    string a = "whatever";

    void* ptr;

    ptr = &n;
    ptr = &a;

    cout<<endl<<*(static_cast<int*>(ptr));
    cout<<endl<<*(static_cast<string*>(ptr));
    //The utility of the void ptr is that same pointer cann point to different places at the same time
    return 0;
}