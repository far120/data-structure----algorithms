#include <iostream>
using namespace std;
// this code is written by the author of the project Mostafa ElFar 29/9/2024
struct nodeType
{
    int info;
    nodeType *next;
};

class linkedList
{
private:
    nodeType *first, *last;
    int count = 0;

public:
    linkedList() : first(NULL), last(NULL) {}
    
    ~linkedList() // Destructor to clear memory
    {
        clear();
    }

    bool isEmpty()
    {
        return first == NULL && last == NULL && count == 0;
    }

    int size()
    {
        return count;
    }

    void insertAtBeginning(int value)
    {
        nodeType *newNode = new nodeType;
        newNode->info = value;
        if (isEmpty())
        {
            first = newNode;
            last = newNode;
            last->next = first;  // Circular reference
            count++;
            cout << "Added at first because no elements: " << value << endl;
        }
        else
        {
            newNode->next = first;
            first = newNode;
            last->next = first;  // Maintain circular reference
            count++;
            cout << "Added at beginning: " << value << endl;
        }
    }

    void insertAtEnd(int value)
    {
        nodeType *newNode = new nodeType;
        newNode->info = value;
        if (isEmpty())
        {
            first = newNode;
            last = newNode;
            last->next = first;  // Circular reference
            count++;
            cout << "Added at first because no elements: " << value << endl;
        }
        else
        {
            last->next = newNode;
            last = newNode;
            last->next = first;  // Maintain circular reference
            count++;
            cout << "Added at end: " << value << endl;
        }
    }

    void insertAt(int value, int position)
    {
        nodeType *newNode = new nodeType;

        newNode->info = value;
        if (isEmpty() || position < 1 || position > size() + 1)
        {
            cout << "Invalid position";
            return;
        }
        else if (position == 1)
        {
            insertAtBeginning(value);
        }
        else if (position == count)
        {
            insertAtEnd(value);
        }
        else
        {
            nodeType *curent = first;
            for (int i = 1; i < position-1; i++)
            {
                curent = curent->next;
            }
            newNode->next = curent->next;
            curent->next = newNode;
            count++;
            cout<< "added at position "<< position  <<" : "<<value<<endl;
        }
    }
    void update(int value, int position)
    {
        if (isEmpty() || position < 1 || position > size())
        {
            cout << "Invalid position" << endl;
            return;
        }
        else
        {
            nodeType *current = first;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }
            current->info = value;
            cout << "Updated at position " << position << ": " << value << endl;
        }
    }

    void deleteAtBeginning()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        else if (size() == 1)
        {
            delete first;
            first = last = NULL;
            count = 0;
            cout << "Deleted first element and list is empty" << endl;
        }
        else
        {
            nodeType *current = first;
            first = first->next;
            last->next = first;  // Maintain circular reference
            delete current;
            count--;
            cout << "Deleted first element" << endl;
        }
    }

   void deleteAtEnd()
    {
        if(isEmpty()){
            cout << "List is empty" << endl;
            return;
        }
        else if(size() == 1){
            delete first;
            first = NULL;
            last = NULL;
            count = 0;
            cout<< "delete last element and  List is empty" << endl;
        }
        else{
            nodeType *curent = first;
             nodeType *lastcurent = last;
            while(curent->next!= last){
                curent = curent->next;
            }
            delete lastcurent;
            last = curent;
            last->next = first;  // Maintain circular reference
            count--;
            cout<< "delete last element" << endl;
        }
    }

    void deleteAt(int position)
    {
        if (isEmpty() || position < 1 || position > size())
        {
            cout << "Invalid position" << endl;
            return;
        }
        else if (position == 1)
        {
            deleteAtBeginning();
        }
        else if (position == size())
        {
            deleteAtEnd();
        }
        else
        {
            nodeType *current = first;
            nodeType *previous = NULL;
            for (int i = 1; i < position; i++)
            {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
            count--;
            cout << "Deleted at position " << position << endl;
        }
    }

    void clear()
    {
        while (!isEmpty())
        {
            deleteAtBeginning();
        }
        cout << "List is cleared" << endl;
    }

    void search(int value)
    {
        bool found = false;
        nodeType *current = first;

        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        do
        {
            if (current->info == value)
            {
                found = true;
                break;
            }
            current = current->next;
        } while (current != first);

        if (found)
            cout << "Found: " << value << endl;
        else
            cout << "Not found: " << value << endl;
    }

    void swap(int i, int j){
        if(i < 1 || j < 1 || i > size() || j > size() || i == j){
            cout<<"Invalid swap position"<<endl;
            return;
        }
        nodeType *current = first;
        nodeType *another = first ;
        for(int k = 1; k < i; k++){
            current = current->next;
        }
        for(int k = 1; k < j; k++){
            another = another->next;
        }
        int temp = current->info;
        current->info = another->info;
        another->info = temp;
       cout<<"after swap: ";
        display();
    }
    
    void display()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        nodeType *current = first;
        cout << "Display list of nodes: ";
        do
        {
            cout << current->info << " ";
            current = current->next;
        } while (current != first);
        cout << endl;
    }
};

int main()
{
    linkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.display();
    list.insertAt(40, 2);
    list.display();
    list.insertAt(60, 3);
    list.display();
    list.insertAtBeginning(5);
    list.display();
    list.update(50, 2);
    list.display();
    list.deleteAtBeginning();
    list.display();
    list.deleteAtEnd();
    list.display();
    list.insertAtBeginning(60);
    list.insertAt(70, 3);
    list.display();
    list.deleteAt(2);
    list.display();
    list.swap(1, 3);
    list.display();
    list.deleteAtEnd();
    list.display();
    list.search(20);
    list.search(60);
    cout << "Size of linked list: " << list.size() << endl;
    list.clear();
    list.display();

    return 0;
}