#include <iostream>
using namespace std;
#include <string>
using namespace std;
// this code is written by the author of the project Mostafa ElFar 29/9/2024
template <class T>
struct nodeType
{
    T info;
    nodeType *next;
};

template <class T>
class StacklinkedList
{
private:
    nodeType<T> *first;
    int top = 0;

public:
    StacklinkedList() : first(NULL) {}
    

    
    bool isEmpty() {
        return first == NULL & top == 0; 
    }

    int size() {
        return top;
    }
    void push(T value) {
        nodeType<T> *newNode = new nodeType<T>;
        newNode->info = value;
        newNode->next = first;
        first = newNode;
        top++;
        cout << "Pushed element: " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        nodeType<T> *curent = first;
        cout << "Popped element: " << curent->info << endl;
        first = first->next;
        delete curent;
        top--;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return 0;   
        }
        return first->info;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack cleared." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        nodeType<T> *curent = first;
        cout << "Stack contents: ";
        while (curent != nullptr) {
            cout << curent->info << " ";
            curent = curent->next;
        }
        cout << endl;
    }
};

int main()
{
    cout << "Stack Linked List Implementation" << endl;
    StacklinkedList<int>stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack size: " << stack.size() << endl;
    stack.display();
    cout << "Top element is: " << stack.peek() << endl;
    stack.pop();
    stack.display();
    cout << "Top element is: " << stack.peek() << endl;
    stack.display();
    stack.clear();
    stack.display();
    cout << "Stack size: " << stack.size() << endl;

StacklinkedList<string> stack2;
    stack2.push("Apple");
    stack2.push("Banana");
    stack2.push("Cherry");
    cout << "Stack size: " << stack2.size() << endl;
    stack2.display();
    cout << "Top element is: " << stack2.peek() << endl;
    stack2.pop();
    stack2.display();
    cout << "Top element is: " << stack2.peek() << endl;
    stack2.display();
    stack2.clear();
    stack2.display();
    cout << "Stack size: " << stack2.size() << endl;
    return 0;
}