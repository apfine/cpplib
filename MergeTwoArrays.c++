//Lets make a program that merges two integral arrays and then sorts them in the ascending order.
#include <iostream>
#include <vector>

using namespace std ;

void ArrayPrinter(vector <int> a){
    cout<<endl;
    for(auto i : a){
        cout<<"  "<<i;
    }
    cout<<endl;
}

vector <int> ArrayMerge(vector <int> a1 , vector <int> a2){
    vector <int> array;
    for(auto i : a1){
        array.push_back(i);
    }
    for(auto i : a2){
        array.push_back(i);
    }
    for(int i = 1 ; i<array.size()-1 ; i++){
        int key = array[i];             //Using the insertion sort algorithm 
        int j = i-1;
        while(array[j] > key){
            array[j+1] = array[j] ;
            j--;
            }
        array[j+1] = key;
        }

    return array;
}

int main(){
    vector <int> array1 ;
    vector <int> array2 ;
    array1.push_back(1);
    array1.push_back(4);
    array1.push_back(6);
    array2.push_back(2);
    array2.push_back(3);
    array2.push_back(6);
    ArrayPrinter(array1);
    ArrayPrinter(array2);
    vector <int> array = ArrayMerge(array1 , array2);
    ArrayPrinter(array);
    return 0;
}