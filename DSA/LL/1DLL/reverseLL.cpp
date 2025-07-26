#include <iostream>

using namespace std;

class Node{
    public: 
      int data;
      Node* next;
    
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp= temp->next;
    }
}

int main(){
    return 0;
}