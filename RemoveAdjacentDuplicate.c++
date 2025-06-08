/*I wrote a program to remove the adjacent duplicate pair substrings like removing bb from abbabac
I have not used the standard <algorithm> in ordetr to show implementation*/
#include <iostream>
#include <string>
#include <ctime>

using namespace std ;

class STR{
    private: 
        string str;
    public:
        STR(const string& ini = ""):str(ini){}      //This is the constructor of the class.

        void in(){
            cout<<"\nPlease enter the string : ";
            cin>>str;
        }

        void print(){
            cout<<endl;
            cout<<"The string after being manipulated is : ";
            cout<<str;
            cout<<endl;
        }

        string rem(){
            clock_t start , end ;
            start = clock();
            int c1 = 0 ;
            int si = str.length();
            for(int i = 0 ; i< si; i++){   
                if(str[i]==str[i+1]){
                    c1++;
                }
                if(c1>0){          
                    str[i] = '_';
                    str[i+1] = '_';
                    c1--;
                }
            }
            end = clock();
            cout<<"\nThe time taken to run the program is : "<<end-start<<" ms.";
            return str;
        }

};

int main(){
    STR str ;
    str.in();
    str.rem();
    str.print();
    return 0;
}