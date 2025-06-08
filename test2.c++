#include<iostream>


typedef struct Node
{
    int key;
    Node* prev;
    Node* next ;
    Node(int val) : key(val) , prev(nullptr) , next(nullptr){}
};

class linked{
    private:
        Node* head ;
        Node* tail ;

    public :
        
        linked(): head(nullptr) , tail(nullptr){}

        void add(int value){
            Node* newNode = new Node(value);
            newNode->next= nullptr;
            if(!head){
                head=tail=newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            delete newNode;
        }

        void show(){
            Node* current = head;
            while(current!=tail){
               
                std::cout<<current->key<<"->";
                current = current->next;
    
            }
            std::cout<<"\n";
        }

        Node* getHead(){
            return head;
        }

        Node* getTail(){
            return tail;
        }

        void  del (Node* pre , Node* nex){
            pre->next = nex;
            nex->prev = pre;
        }
    
};

int main(){
    linked list;
    list.add(5);
    list.add(7);
    list.add(8);
    list.add(12);
    list.add(90);
    list.show();
}