#ifndef sets
#define sets

#include <iostream>
#include <vector>

using namespace std;

class set{
    private:
        vector <int> member;
        vector <int> parent;
        vector <int> rank;
        vector <int> size;
        int n;

          int index(int n){
            for(int i = 0 ; i<n ; i++){
                if(member[i]==n){
                    return i;
                }
            }
            return -1;
        }

        int findi(int n){                                               //This method is useful in union by size or rank.
            if(parent[n] == member[n]){
                return member[n];
            }
            return parent[n] = findi(index(parent[n]));                //This is the step of path compression.
        }

        int findi2(int n){                                              //This can be used in the union by height as path compression not so helpful.
            if(parent[n] == member[n]){
                return member[n];
            }
            return findi(index(parent[n]));                            //Here it do not contains path compression means the all elements are not connected to root. Hence it is inefficient.
        }
        void printi(vector <int> a){
            cout<<"\n";
            for(int i : a){
                cout<<" "<<i;
            }
            cout<<"\n";
        }

    public:
        set(){
            cout<<"\nPlease enter the number of elements : ";
            cin>>n;
            int m;
            cout<<"\nPlease enter the members: ";
            for(int i = 1 ; i<=n ; i++){
                cin>>m;
                member.push_back(m);
                parent.push_back(m);
                rank.push_back(0);
            }
        }
        
        int find(int x){
            for(int i = 0 ; i <n ; i++){
                if(member[i]==x){
                    return findi(i);
                }
            }
            return -1;
        }

        void Union(int x , int y){
            x = find(x);
            y = find(y);        
            int m = index(x) , n = index(y);
            if(rank[m]>rank[n]){
                parent[n] = x;
            }
            else if(rank[n]>rank[m]){
                parent[m] = y ;
            }
            else{
                parent[n] = x;
                rank[m] = rank[m]+1;
            }
        }

        void print(){
            cout<<"\nMembers: ";
            printi(member);
            cout<<"\nParents: ";
            printi(parent);
            cout<<"\nRanks: ";
            printi(rank);
        }


};

#endif