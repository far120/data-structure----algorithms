#include<iostream>
using namespace std;
#include <string>
using namespace std ;
// this code is written by the author of the project Mostafa ElFar 29/9/2024
static const int SIZE = 10;
template<class T>
class Queue{
    private:
    T arr[SIZE];
    int front, last;
    int count;
    public:
    Queue(){
        front = 0;
        last = -1;
        count = 0;
    }
    bool isFull(){
        return count == SIZE;
    }
    bool isEmpty(){
        return count == 0;
    }
     int size(){
        return count;
    }
    int capacity(){
        return SIZE;
    }
    void enqueue(T value){
        if(isFull()){
            cout << "Queue is full. Cannot enqueue element.\n";
            return;
        }
        arr[++last] = value;
        count++;
        cout << "Enqueued: " << value << endl;
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty. Cannot dequeue element.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
        count--;
    }
    T frontElement(){
        if(isEmpty()){
            cout << "Queue is empty. Cannot return front element.\n";
            return 0;
        }
        return arr[front];
    }
    T lastElement(){
        if(isEmpty()){
            cout << "Queue is empty. Cannot return last element.\n";
            return 0;
        }
        return arr[last];
    }
    void clear(){
        front = 0;
        last = -1;
        count = 0;
        cout << "Queue cleared successfully." << endl;
    }
    bool search(T value){
        for(int i = front; i <= last; i++){
            if(arr[i] == value){
                return true;
            }
        }
        return false;
    }
    void display(){
        cout << "Queue elements are: ";
        if(isEmpty()){
            cout << "Empty" << endl;
            return;
        }
        for(int i = front; i <= last; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Queue<string> qs;
    qs.enqueue("Apple");
    qs.enqueue("Banana");
    qs.enqueue("Cherry");
    qs.enqueue("Date");
    qs.enqueue("Elderberry");
    qs.enqueue("Fig");
    qs.enqueue("Grape");
    qs.enqueue("Honeydew");
    qs.enqueue("Iced Tea");
    qs.enqueue("Jackfruit");
    qs.enqueue("Kiwi");

    cout << "Queue size: " << qs.size() << endl;
    cout << "Queue capacity: " << qs.capacity() << endl;
    qs.display();
    
    qs.dequeue();
    qs.display();
    
    cout << "Front element: " << qs.frontElement() << endl;
    cout << "Last element: " << qs.lastElement() << endl;
    
    cout << "Search Banana: " << (qs.search("Banana")? "Found" : "Not Found") << endl;
    cout << "Search egg: " << (qs.search("egg")? "Found" : "Not Found") << endl;
    
    qs.clear();
    cout << "Queue size: " << qs.size() << endl;
    cout << "Queue capacity: " << qs.capacity() << endl;
    qs.display();
    

    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue capacity: " << q.capacity() << endl;
    q.display();
    
    q.dequeue();
    q.display();
    
    cout << "Front element: " << q.frontElement() << endl;
    cout << "Last element: " << q.lastElement() << endl;
    
    cout << "Search 30: " << (q.search(30)? "Found" : "Not Found") << endl;
    cout << "Search 60: " << (q.search(60)? "Found" : "Not Found") << endl;
    
    q.clear();
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue capacity: " << q.capacity() << endl;
    q.display();
    
    return 0;


}