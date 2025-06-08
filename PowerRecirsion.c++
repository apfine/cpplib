#include <iostream>

using namespace std;

int pow(int base , int power){

    if(base==1 || base==0){
        return base;
    }
    if(power==1){
        return base;
    }

    int ans = pow(base , power/2);

    if(power%2==0){
        return ans*ans;
    }
    else if(power%2!=0){
        return  base * ans*ans;
    }
}
int main(){
    int a = 4 , b =5 ;
    int ans = pow(a,b);
    cout<<"\nThe answer is : "<<ans;

}
