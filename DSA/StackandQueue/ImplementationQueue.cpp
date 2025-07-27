#include <iostream>

using namespace std;

class Queue {
    int size = 1000;
    int currSize;
    int *arr;
    int start, end;
    public:
     Queue() {
        start = -1, end = -1;
        currSize = 0;
        size = 1000;
        arr = new int(size);
     }
    void push(int x) {
        if (currSize == size) {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if(end == -1) {
            start = 0, end = 0;
        }
        else {
            end = (end + 1) % size;
        }
        currSize++;
        arr[end] = x;
        cout << "The element pushed is " << x << endl;
    }
    int pop() {
        if (start == -1) {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int popped = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else
            start = (start + 1) % size;
            currSize--;
        return popped;
    }
    int top() {
        if(start == -1){
            cout << "Queue is empty" << endl;
            exit(0);
        }
        return arr[start];
    }
    int Size() {
        return currSize;   
    }
};

int main() {
  Queue q;
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.Size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The Size of the queue after deleting an element " << q.Size() << endl;
  return 0;
}