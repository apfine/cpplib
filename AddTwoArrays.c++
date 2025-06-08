//The problem statement is to add two numbers represented by two arrays which are being implemented using deques.
/*!!!IMPORTANT : If you alter the array size to greater than 10 you will see that the limit of int is crossed and hence you will switch to arrays to solve
bigger numbers because arrays can store infinite number of values.*/

#include <iostream>
#include <deque>
#include <ctime>
int DEF =INT32_MAX;

using namespace std;

int p10(int n ){   //Returns the ten power multiplier of a specefic int
    int64_t k = 1 ;
    for(int i = n ; n>0 ; n--){
        k *=10;
    }
    return k;
}

void arrayPrinter(deque <int> a){  //Taking an array and printing each element of it .
    cout<<endl;
    for(int i : a){
        cout<<"  "<<i;
    }
    cout<<endl;
}

deque <int> add(deque <int> a1 , deque <int> a2){  //This is the function which adds two numbers represented by arrays.
    deque <int> ans;
    int64_t z , an1,l,m , count;
    int64_t b1  = 0;
    int64_t b2 = 0;
    int64_t p1 = 1;
    int64_t p2 = 1;
    int64_t an ;
    //Converting the two numbers to integers ;
    for(int i = a1.size()-1 ; i>=0 ; i--){      
        b1= b1+ p1*a1[i];
        p1*=10; 
     }
    for(int i = a2.size()-1 ; i>=0 ; i--){       
        b2 = b2 + p2*a2[i];
        p2*=10;
    }
    an  = b1+b2;
    if(signed(an)==true ){
        exit;
    }
    an1 = an;
    for(int i = 1; i<11 ; i++){
        l = p10(i);
        m = p10(i-1);
        if(an1%m==an1){
            break;
        }    
        z = (an%l - an%m)/m;       
        if(an % 10  != 0 && count ==1){
            ans.push_front(0);
            count++;
        }
        ans.push_front(z);
    } 
    return ans ;

}

int main(){
    clock_t start , end ;
    start = clock();
    deque <int> a1 = {9,2,3,4,5,5,7,8,9,9};
    deque <int> a2 = {9,7,4,9,7,9,1,3,4,6,8,9,5,6};
    deque <int> ans ;
    ans = add(a1,a2);
    if(ans.size()<a1.size()||ans[0]==0){
        cout<<"\nError ! You crossed the limit of  an integer .\n";
    }else{
        cout<<"\nThe resultant array after addition is : ";
        arrayPrinter(ans);
    }
    end = clock();
    cout<<"\nThe time taken to run the program is : "<<end - start <<" ms.";
    return 0;
}