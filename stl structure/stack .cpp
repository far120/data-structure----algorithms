#include <iostream>
using namespace std;
#include <string>
using namespace std;
// this code is written by the author of the project Mostafa ElFar 29/9/2024
static const int SIZE = 10;
template <class T>
class stack
{
private:
    int top = -1;
    T arr[SIZE];

public:
    stack() {}
    bool isFull()
    {
        return top == SIZE - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int size()
    {
        return top+1;
    }
    int capacity(){
        return SIZE;
    }
    void push(T value)
    {
        if (isFull())
            cout << "Stack is full. Cannot push " << value << endl;
        else
        {

            arr[++top] = value;
            cout << value << " pushed to stack" << endl;
        }
    }
    T pop()
    {
        if(isEmpty())
            cout << "Stack is empty. Cannot pop." << endl;
        else
        {
            T value = arr[top--];
            cout << value << " popped from stack" << endl;
            return value;
        }
    }
    void clear()
    {
        top = -1;
        cout << "Stack cleared." << endl;
    }
    void TOP()
    {
        if (isEmpty())
            cout << "Stack is empty." << endl;
        else
            cout << "last element is:  " << arr[top] << endl;
    }
    void display()
    {
        if (isEmpty())
            cout << "Stack is empty." << endl;
        else
        {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    stack<int> s1;
    stack<string> s2;

    cout << "Stack 1 (integer):" << endl;
    cout << "Is stack full? " << (s1.isFull()? "Yes" : "No") << endl;
    cout << "Is stack empty? " << (s1.isEmpty()? "Yes" : "No") << endl;
    cout << "Stack capacity: " << s1.capacity() << endl;    
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.display();
    cout<<"size of stack: "<<s1.size()<<endl;


 cout << "Stack 2 (string):" << endl;
    cout << "Is stack full? " << (s1.isFull()? "Yes" : "No") << endl;
    cout << "Is stack empty? " << (s1.isEmpty()? "Yes" : "No") << endl;
    cout << "Stack capacity: " << s1.capacity() << endl;    
    s2.push("one");
    s2.push("two");
    s2.push("three");
    s2.display();
    cout<<"size of stack: "<<s2.size()<<endl;

    s1.pop();
    s1.TOP();
    s2.pop();
    s2.TOP();

    s1.display();
    s2.display();

    s1.clear();
    s2.clear();

    s1.display();
    s2.display();

    s1.push(4);
    s2.push("four");

    s1.display();
    s2.display();

    s1.TOP();
    s2.TOP();

    return 0;
}