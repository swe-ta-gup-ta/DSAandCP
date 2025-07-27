#include <iostream>

using namespace std;

struct stackNode {
    int data;
    stackNode* next;
    int size;
    stackNode(int d) {
        data = d;
        next = NULL;
    }
};

class stack {
    public:
    stackNode * top;
    int size;
    stack() {
        top = NULL;
        size = 0;
    }
    
    void push(int x) {
        stackNode* ele = new stackNode(x);
        ele->next = top;
        top = ele;
        cout <<"Element pushed" << "\n";
        size++;
    }

    int pop() {
        if(top == NULL) return -1;
        int topData = top->data;
        stackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }
    int Size(){
        return size;
    }
    int isEmpty(){
        return top == NULL;
    }
    int peek() {
        if(top == NULL) return -1;
        return top->data;
    }
    void print(){
        stackNode* curr = top;
        while(curr != NULL){
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};

int main() {
  stack s;
  s.push(10);
  cout << "Element popped: " << s.pop() << "\n";
  cout << "Stack size: " << s.Size() << "\n";
  cout <<"Stack empty or not? "<<s.isEmpty()<<"\n";
  cout << "stack's top element: " << s.peek() << "\n";
  return 0;
}