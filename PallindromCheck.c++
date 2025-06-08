#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std ;

void pallindromCheck(string str){
    int c = 0;
    for(int i = 0 ; i<str.length()/2 ; i++){
        if(str[i]==str[str.length()-1-i]){
            c++;
        }
    }
    if(c*2==str.length()||c*2==str.length()-1){
        cout<<"\nThe word is a pallindrom!";
        for(auto i : str){
            cout<<" "<<i;
        }
    }
}

int main(){
    string str;
    cin>>str;
    transform(str.begin() , str.end() ,str.begin() , ::tolower);
    
    str;
    pallindromCheck(str);
    return 0;

}