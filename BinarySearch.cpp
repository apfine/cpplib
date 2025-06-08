//Question - Sort the array and perform binary search for a key value .

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//An array printer function .
void arrayPrinter(vector <int> array ){
    for(int i = 0 ; i< array.size() ; i++){
            cout<<"  "<<array[i];
    }
}
vector <int> bubbleSort (vector <int> array){
    
    for(int i = 0 ; i<array.size()-1; i++){
        for(int j =0 ; j<array.size()-i-1; j++){
            if(array[j]>array[j+1]){
                swap(array[j] , array[j+1]);
            }
        }
    }                             
    //Sorting the array before using binary search as it only works over monotonous cases.
    //I have included the bubble sort with the binary search function to indicate that its a mandatory thing to sort the members of an array.
    return array;

}


/*Using the bubble sort algorithm for the sake of simplicity but it significantly demeans the (log n) time
complexity of the binary search thus leaving no difference between binary search and linear search but you
can use a different sort algo and it will significantly reduce the time .
for example if we consider n = 128 for an array then linear search will takes searching 128 times in the worst case
but in the case of binary search it will only search 7 times which is a significantly lesser time , just one thing you 
need to take care of is the sorting algorithm.*/


int binarySearch(vector <int> array , int key){
    int mid , start , end ;
    start = 0;
    end = array.size()-1;
    mid = (start+end)/2;

    cout<<"\n\nThe sorted array is : ";
    arrayPrinter(array);                    //Printing the sorted array.

    //This below is  the binary search function.
    
    while(start<=end){
        
        if(key==array[mid]){
            cout<<"\n\nThe "<<key<<" lies at index "<<mid<<" position , starting the index from zero in the ascending sorted array.";
            return mid;
        }
        else{                                          //If the value lies in left half
            if(key<array[mid]){
                end = mid-1;
            }                                          //If the value lies in the right half
            else{
                start = mid+1;
            }
            mid = (start+end)/2;
        }
    }
}

int main(){
    clock_t start , end;
    start = clock();
    
    vector <int> array ={1,2,5,6,7,8,34,67,54,231,28,56};
    int key = 28;
    array = bubbleSort(array);
    binarySearch(array, key);
    
    end = clock();
    cout<<"\n\nThe time taken to run the program is : "<<end - start <<" ms."<<endl<<endl;
    return 0 ;
}