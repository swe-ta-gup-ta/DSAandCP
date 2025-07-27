#include <iostream>

using namespace std;

class Stack {
    int size;
    int *arr;
    int top;
    public:
     Stack() {
        top = -1;
        size = 1000;
        arr = new int(size);
     }
    void push(int x) {
        top++;
        arr[top] = x;
    }
    int pop() {
        int x = arr[top];
        top--;
        return x;
    }
    int Top() {
        if(top != -1)
        return arr[top];
        return -1;
    }
    int Size() {
        return top + 1;
    }
};

int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}