#include <iostream>
#include <vector>

using namespace std;

void print(vector <int> array){
    cout<<endl<<"The array is :" ;
    for(int i = 0 ; i<array.size() ; i++){
        cout<<" "<<array[i];
    }
    cout<<endl;
}

void InsertionSort(vector <int>& array){
    int n = array.size();
    for (int i = 1; i < n; i++)
    {   int key  = array[i];
        int j = i-1;

        while(array[j]>key&& j>=0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key ;
    }
}


int BinarySearch(vector <int> array , int start , int end , int search){
    int n = array.size();
    if (start > end) {
        return -1; 
    }
    int key = (start+end)/2;
    if(array[key]==search){
        return key ;
    }else if(search>array[key]){
        start = key+1;
    }else if(search<array[key]){
        end = key-1;
    } 
    return BinarySearch(array,start , end,search);
}


int main(){
    vector <int> array = {1 , 4 , 6 , 8 , 789 , 56 , 654 , 8989 , 78 , 9 ,6 };
    InsertionSort(array);
    print(array);
    int k = BinarySearch(array , 0 , array.size()-1, 78);
    cout<<"\nThe index of the element is :" <<k;
}