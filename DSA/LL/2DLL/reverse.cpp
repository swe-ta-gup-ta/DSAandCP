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

// BRute force way (using stack)
Node* reverseDLL(Node* head) {
    if(head == nullptr || head -> next == nullptr) return head;

    stack<int> st;
    Node* temp = head;

    while(temp != NULL){
        st.push(temp->data);
        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL){
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }
    return head;
}


//optimised way
Node* reverseDLL(Node* head) {
    if(head == nullptr || head -> next == nullptr) return head;

    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        prev = curr->back;
        curr->back = curr->next;
        curr->next = prev;
        curr = curr->back;
    }
    return prev->back;
}

int main(){
    vector<int> arr{10, 4, 7, 54};
    Node* head = convertArrTo2DLL(arr);
    
    printDLL(head);
    head = reverseDLL(head);
    cout << endl;
    printDLL(head);
}