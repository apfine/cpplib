//I wrote a program which moves all the zeros of an integer array to the last of the array .
//The edge case may be when a value of array is equal to DEF
#include <iostream>
#include <vector>
#include <algorithm>
int DEF = INT32_MAX;

using namespace std;

void arrayPrinter(vector <int> array){
    cout<<endl;
    for(auto i : array){
        cout<<"  "<< i;
    }
    cout<<endl;
}

vector <int> ZeroMove(vector <int> a){
   int n  = a.size()-1;
    vector <int> array(n+1) ;
    
    for(int i = 0 ; i<a.size() ; i++){
        if(a[i]==0){
            array[n] = a[i];
            n--;  
            a[i] = DEF ;
        }
    }
    n--;
    int j =0 ;
    for(int i : a){
        if(i!=DEF&& j<=n+1){
        array[j] = i;
        j++;
        }
    }

    return array;
}

int main(){
    vector <int> a = {0,3,4,6,2,0,5,2,0,8,9,6,8,9,0,0,4,5};
    arrayPrinter(a);
    a = ZeroMove(a);
    cout<<"\nCame out of the function.\n";
    arrayPrinter(a);
    return 0;
}