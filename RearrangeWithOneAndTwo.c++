#include <iostream>
#include <vector>
#include <ctime>

using namespace std ;

void arrayPrinter(vector <int> array){
    for(int i =0 ; i<array.size() ; i++){
        cout<<"  "<<array[i];
    }
}

void A(vector <int> array){
    cout<<"\nThe initial array is : ";
    arrayPrinter(array);
    vector <int> copy;

    int a = array.size()/2;
    int b  = a;
    int d ,e ;
    int f ,g ;
    d = (array.size()*2)/3;
    e = array.size()/3;
    f = array.size()/4;
    g = (array.size()*3)/4;
    int c = array.size()-1;
    for(int i = 0 ; i<array.size() ; i++){
        if(i<(array.size()/2)){
            if(array[i]>array[c]){
                swap(array[i],array[c]);
             }
             else if(array[i]>array[i+1]){
                swap(array[i],array[i+1]);
             }
             else if(array[c]<array[c-1]){
                swap(array[c] ,array[c-1]);
             }
            if(array[a]>array[b]){
                swap(array[a],array[b]);
             }
             else if(array[a]>array[a+1]){
                swap(array[a],array[a+1]);
             }
             else if(array[b]<array[b-1]){
                swap(array[b],array[b-1]);
             }
            if(d<array.size()){  
                if(array[d]<array[d-1]){
                    swap(array[d],array[d-1]);
                }
            }
            if(e>=0){
                if(array[e]>array[e+1]){
                    swap(array[e],array[e+1]);
                }
            }    
            if(g<array.size()){  
                if(array[g]<array[g-1]){
                    swap(array[g],array[g-1]);
                }
            }
            if(f>=0){
                if(array[f]>array[f+1]){  //////////////////////////////////////////////////////////
                    swap(array[f],array[f+1]);
                }
            }    
        }
        if(copy==array){
            break;
        }
    
        a--;
        b++;
        c--;
        d++;
        e--;
        f++;
        g++;
        cout<<"\nThe changed array is : ";
        arrayPrinter(array);
        copy = array ;
    }
}

int main(){
    clock_t start, end;
    start = clock();

    vector <int> array = {0,1,2,2,1,0,2,1,0,2,0,0,1,1,2,1,2,0};
    A(array);

    end = clock();
    cout<<"\n\nThe time taken to run the program is : "<<end-start<<" ms.";
    return 0 ;
}