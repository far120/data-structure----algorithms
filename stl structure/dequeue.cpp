#include<iostream>
using namespace std;
const int SIZE = 100;
template<class T>
class dequeue {
    int front;
    int top;
    T arr[SIZE];
public:
    dequeue() {
        front = -1;
        top = -1;
    }

    bool is_empty() {
        return top < 0;
    }

    int size() {
        return top + 1;
    }
    void clear(){
        if (is_empty())
        {
            cout << "dequeue is empty ";
        } else{
            for (int i = top; i >= 0 ; --i) {
                pop_top();
            }
        }
    }
    void push_top(T e) {
        if (top >= SIZE - 1) {
            cout << "dequeue is full ";
        } else {
            top++;
            arr[top] = e;
        }
    }

    void pop_top() {
        if (is_empty()) {
            cout << "dequeue is empty ";
        } else {
            top--;
        }
    }

    void pop_element_top() {
        if (is_empty())
            cout << "dequeue empty on pop";
        else {
            cout << arr[top] << endl;
            top--;
        }
    }

    void print_top() {
        if (is_empty()) {
            cout << "dequeue is empty ";
        } else {
            cout << arr[top] << endl;
        }
    }
    ////////////front/////////////////////
    void push_front(T e) {
        if (top >= SIZE - 1) {
            cout << "dequeue is full ";
        } else {
            top++;
            for (int i = top; i >0 ; --i) {
                arr[i] = arr[i-1];
            }
            arr[0]=e;
        }
    }

    void pop_front() {
        if (is_empty()) {
            cout << "dequeue is empty ";
        } else {
            for (int i = 0; i <top ; ++i) {
                arr[i] = arr[i+1];
            }
            top--;
        }
    }

    void pop_element_front() {
        if (is_empty())
            cout << "dequeue empty on pop";
        else {
            cout << arr[0] << endl;
            pop_front();
        }
    }
    void print_front() {
        if (is_empty()) {
            cout << "dequeue is empty ";
        } else {
            cout << arr[0] << endl;
        }
    }

    void print() {
        if (is_empty()) {
            cout << "dequeue is empty ";
        } else {
            cout << "[";
            for (int i = 0; i <=top ; ++i) {
                cout << arr[i];
                cout << " ";
            }
            cout << "]" << endl;
        }
    }
};
int main() {
    dequeue<string>q;
    q.push_front("b");
    q.push_top("a");
    q.push_top("c");
    q.push_front("d");
    q.print();
    q.pop_front();
    q.pop_top();
    q.print();
    q.print_front();
    q.print_top();
    q.clear();
    q.print();









}