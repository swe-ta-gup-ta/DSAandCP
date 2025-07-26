#include <bits/stdc++.h>

using namespace std;

class Node{
public: 
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
    data = data1;
    next = next1;
    back = back1;
    }

    Node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
    }
};

Node* convertArrTo2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node* head){
    while(head != nullptr){
        cout << head->data<< " ";
        head = head->next;
    }
}

Node* insertAtTail(Node* head, int k) {
    Node* newNode = new Node(k);
    if(head == nullptr) return newNode;

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->back = tail;

    return head;
}

Node* deleteHead(Node* head) {
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node* prev = head;
    head  = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* tail = head;
    while(tail -> next != nullptr){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;
    delete tail;
    return head;
}

int main(){
    vector<int> arr{10, 4, 7, 54};
    Node* head = convertArrTo2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    printDLL(head);
    head = deleteTail(head);

    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
    head = insertAtTail(head, 10);
    
    printDLL(head);
}