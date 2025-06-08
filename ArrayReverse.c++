#include <iostream>
#include <vector>

using namespace std;

void arrayPrinter(vector <int> array){
    cout<<endl;
    for(int i =0 ; i<array.size() ; i++){
        cout<<"  "<<array[i];
    }
    cout<<endl;
}

vector <int> reverse(vector <int> array){
    int s , b;
    cout<<"\nInitialize the reverse : ";
    cin>>s;
    cout<<"\nPlease end the reverse : ";
    cin>>b; 
    while(s<=b){
        swap(array[s],array[b]);
        s++;
        b--;
    }
    return array;
}

int main(){
    vector<int> array;
    array.push_back(6);
    array.push_back(7);
    array.push_back(7);
    array.push_back(4);
    arrayPrinter(array);
    array = reverse(array);
    arrayPrinter(array);
    
    return 0;
}