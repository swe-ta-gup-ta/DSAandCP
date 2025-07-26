#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
       int data;
       Node* next;

       Node(int data1, Node* next1){
        data = data1;
        next = next1;
       }

       Node(int data1){
        data = data1;
        next = nullptr;
       }
};


void printLL(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* reverseUsingStack(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* reverse(Node* head){
    Node* temp = head;
    
}

int main(){
    vector<int> arr = {2, 4, 6, 8};
    int val = 100;

    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    head = insertHead(head, val);

    printLL(head);
    cout << endl;

    // deleteTail(head);
    // deleteTail(head);
    reverseUsingStack(head);

    printLL(head);
    return 0;
    
}