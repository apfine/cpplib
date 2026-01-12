#include <iostream>

using namespace std;
void arrayPrint(int a[] , int row , int col){
    cout<<endl;
    for(int i=0 ; i<row ; i++){
        cout<<" "<<a[i];
    }
    cout<<endl;
}



int main(){
    int row , col ;
    cin>>row;
    cin>>col;
    int** array = new int*[row];
    cout<<endl<<"Size of array"<<sizeof(array);
    //Creating the second layer
    for(int i = 0 ; i< row; i++){
        array[i] = new int[col];
    }

    //Taking the inputs in the array ;
    for(int i = 0 ; i<row ; i++){
        for(int j = 0 ; j< col ; j++){
            cin>>array[i][j];
        }
    }
    for(int i = 0 ; i<row ; i++){
        arrayPrint(array[i] , row , col);
    }

    cout<<endl<<"size: "<<sizeof(array)/4;
    //Freeing the memory from the array 
    for(int i = 0  ; i< row ; i++){
        delete []array[i];
    }
    cout<<endl<<"size : "<<sizeof(array)/4;
    delete []array;
}