#include <iostream>
#include <vector>
int DEF = INT32_MAX;
using namespace std;

int isPrime(int n ){
    int count ;
    for(int i = 2 ; i<n ;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==0){
        return 0;
    }
    else{
        return 1;
    }
}

void print(vector <int> array){
    int n = array.size();
    cout<<endl;
    cout<<"The array is :";
    for(int i = 0 ; i< n ; i++){
        cout<<" "<<array[i];
    }
    cout<<endl;
}

vector <int> seive(int n){
    vector <int> array;
    vector<int> a;

    //Creating the array 
    for(int i = 0 ; i<n ; i++){
        a.push_back(i+1);
    }

    //Travesing on each element
    for(int i = 1 ; i< n ; i++){
        //Checking for each of the element
        if(a[i]!=DEF){
            if(isPrime(a[i])){
                array.push_back(a[i]);

                //Running the code on remaining array to find the multiples
                for(int j = i+1 ; j<=n ; j++){
                    if(a[j]%a[i]==0){
                        a[j]= DEF;
                    }
                }
                a[i]=DEF;
            }
        }
    }
    return array;
}

int main(){
    cout<<"Please enter the number : ";
    int n  ;
    cin>>n;
    if(n<DEF){
    vector <int> ans = seive(n);
    print(ans);
    }
    else{
        cout<<"! This number could not be checked.";
    }
  
    return 0 ;
}


/*The mechanism of the program is that the program gets a prime number throungh the isPrime function and then tries to get all of its composites
and sets them to DEF which is INT32_MAX or 2^31 which is the limiting case here.*/