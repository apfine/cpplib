/*In this file I implememnt grphs and its algorithms with the help of different methods and their respective methods.*/
#pragma once

#include <iostream>
#include <vector>



struct graphs {
    int vertices; // Fixed typo
    int edges;
    int* adj;

    graphs() : vertices(0), edges(0), adj(nullptr) {}
    graphs(int ver , int*dat ):vertices(ver) , edges(0) , adj(dat){}
};


class graph{
    private:
        graphs* g;
    public:
        graph(){

        }
        

};
