//Question : Sort the array using selection sort method.

#include <iostream>
#include <vector>
#include <chrono>

using namespace std ;
using namespace chrono;                      //Instead of <ctime> we are gonna use the chrono inorder to calculate the time taken.

void arrayPrinter(vector <int> array){
    cout<<endl;
    for(int i = 0 ; i<array.size() ; i++){
        cout<<"  "<<array[i];
    }
    cout<<endl;
}

vector <int> selectionSort(vector <int> array){
    int min;
    int n = array.size();
    for(int i = 0 ; i<n-1 ; i++){
        min = i;
        for(int j = i+1 ; j<n ; j++){
            if(array[j]<array[min]){
                min =j;
            }
        }
        if(min != i){
            swap(array[i] , array[min]);
        }
    }
    
    return array;
}

int main(){
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();

    vector <int> array  = {0,2,6,89,65,34,90,65,2,67};

    array =  selectionSort(array);                                            //Performing the selection sort method on the given array.
    
    cout<<"\nThe sorted array through selection sort method is : ";
    arrayPrinter(array);

    auto dur  = duration_cast<milliseconds>(end-start);
    cout<<"\nThe time taken to run the program is : "<<dur.count()<<" ms\n\n";
    return 0;
}