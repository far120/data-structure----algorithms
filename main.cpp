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
class QueuelinkedList
{
private:
    nodeType<T> *first;
    nodeType<T> *last;
    int top = 0;

public:
   QueuelinkedList() : first(NULL) {}
    

    
    bool isEmpty() {
        return first == NULL & top == 0; 
    }

    int size() {
        return top;
    }
    void Enqueue(T value) {
        nodeType<T> *newNode = new nodeType<T>;
        newNode->info = value;
        if (isEmpty())
        {
            first = newNode;
            last = newNode;
            newNode->next = NULL;
            top++;
            cout << "Pushed element: " << value << endl;
        }
        else{
            last->next = newNode;
            last = newNode;
            newNode->next = NULL;
            top++;
        cout << "Pushed element: " << value << endl;
        }
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot pop." << endl;
            return;
        }
        nodeType<T> *curent = first;
        cout << "Popped element: " << curent->info << endl;
        first = first->next;
        delete curent;
        top--;
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot front." << endl;
            return 0;   
        }
        return first->info;
    }
    T back() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot back." << endl;
            return 0;
        }
        return last->info;
    }
    void clear() {
        while (!isEmpty()) {
           Dequeue();
        }
        cout << "Queue cleared." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        nodeType<T> *curent = first;
        cout << "Queue contents: ";
        while (curent != nullptr) {
            cout << curent->info << " ";
            curent = curent->next;
        }
        cout << endl;
    }
};

int main()
{
    cout << "Queue Linked List Implementation" << endl;
    QueuelinkedList<int>Queue;
    Queue.Enqueue(1);
    Queue.Enqueue(2);
    Queue.Enqueue(3);
    cout << "Queue size: " << Queue.size() << endl;
    Queue.display();
    cout << "front element is: " << Queue.front() << endl;
    cout << "last element is: " << Queue.back() << endl;
    Queue.Dequeue();
    Queue.display();
    cout << "front element is: " << Queue.front() << endl;
    Queue.clear();
    Queue.display();
    cout << "Queue size: " << Queue.size() << endl;
    cout << "-------------------------" << endl;
   

    QueuelinkedList<string> Queue2;
    Queue2.Enqueue("apple");
    Queue2.Enqueue("banana");
    Queue2.Enqueue("cherry");
    cout << "Queue size: " << Queue2.size() << endl;
    Queue2.display();
    cout << "front element is: " << Queue2.front() << endl;
    cout << "last element is: " << Queue2.back() << endl;
    Queue2.Dequeue();
    Queue2.display();
    cout << "front element is: " << Queue2.front() << endl;
    Queue2.clear();
    Queue2.display();
    cout << "Queue size: " << Queue2.size() << endl;
   
    return 0;
}