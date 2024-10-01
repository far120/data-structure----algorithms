#include <iostream>
using namespace std;
using namespace std;
// this code is written by the author of the project Mostafa ElFar 29/9/2024
struct Nodetype {
    int data;
   Nodetype *left, *right;
};
class Binarysearchtree{
private:
    Nodetype* root;
     Nodetype* fakeroot;

public:
    Binarysearchtree(){
        root = NULL;
    }
    bool isEmpty(){
        return root == NULL;
    }
    int treeheight(){
        return height(root);
    }
    int height(Nodetype* node) {
        if(node == NULL)
            return 0;
        else
            return 1 + max(height(node->left), height(node->right));
    }
    int treenodecount() {
        return nodeCount(root);
    }
    int nodeCount(Nodetype* node) {
        if(node == NULL)
            return 0;
        else
            return 1 + nodeCount(node->left) + nodeCount(node->right);
    }
    void insert(int data) {
        Nodetype *newnode = new Nodetype;
        Nodetype * curent=root;
        Nodetype * trailcurent = NULL;
        if(isEmpty()) {
            root = newnode;
            root->data = data;
            root->left = root->right = NULL;
            cout<<"insert root of data " << data << endl;
        }else{
            while(curent != NULL)
            {
                trailcurent = curent;
                if(data <= curent->data){
                    curent=curent->left;
                }else{
                    curent=curent->right;
                }
            }
            if(trailcurent->data >= data){
                trailcurent->left = newnode;
                newnode->left = newnode->right = NULL;
                newnode->data = data;
            }else{
                 trailcurent->right = newnode;
                newnode->left = newnode->right = NULL;
                newnode->data = data;
            }
            cout<<"insert data " << data << endl;
        }
    }
 void remove(int data) {
        Nodetype* current = root;
        Nodetype* trailCurrent = NULL;

        if (isEmpty()) {
            cout << "Cannot delete from an empty tree." << endl;
            return;
        }
        while (current != NULL && current->data != data) {
            trailCurrent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (current == NULL) {
            cout << "The data to delete is not in the tree." << endl;
            return;
        }
        cout<<"the data is deleted : "<< data <<endl;
        if (current->data == root->data) {
            deleteFromTree(root);
        } else if (trailCurrent->left == current) {
            deleteFromTree(trailCurrent->left);
        } else {
            deleteFromTree(trailCurrent->right);
        }
    }

    void deleteFromTree(Nodetype*& p) {
        Nodetype* current;
        Nodetype* trailCurrent;
        if (p->left == NULL && p->right == NULL) {
            delete p;
            p = NULL;
        }
        else if (p->right != NULL) {
            current = p->right;
            trailCurrent = NULL;
            while (current->left!= NULL) {
                trailCurrent = current;
                current = current->left;
            }
            p->data = current->data;
            if (trailCurrent == NULL) {
                p->right = current->right;
            } else {
                trailCurrent->left = current->right;
            }
            delete current;
        }
         else {
            current = p->left;
            trailCurrent = NULL;

            while (current->right != NULL) {
                trailCurrent = current;
                current = current->right;
            }

            p->data = current->data;

            if (trailCurrent == NULL) {
                p->left = current->left;
            } else {
                trailCurrent->right = current->left;
            }

            delete current;
        }
    }
    // clear 
    void clear() {
       clear(root->right);
       clear(root->left);
       root = NULL;
        cout << "tree cleared" << endl;
    }
    void clear(Nodetype*& p){
        if(p!=NULL){
            clear(p->left);
            clear(p->right);
            delete p;
            p = NULL;
        }
    }

    //search 
    void search (int data){
        if(root==NULL){
            cout<<"Tree is empty"<<endl;
            return;
    }
    else{
    Nodetype * current = root;
    Nodetype * trailcurent = NULL;
    while(current!=NULL){
       trailcurent = current;
        if(data < current->data){
            current = current->left;
        }
        else if(data > current->data){
            current = current->right;
        }
        else{
            cout<<"Data found: "<<data<<endl;
            break;
        }
    }
    if(current== NULL){
        cout<<"Data not found: "<<data<<endl;
    }
    }
}

    // preorder traversal
  void preorder() {
    if (isEmpty()) {
        cout << "tree is empty" << endl;
        return;
    } else {
        cout<< "preorder: "<< endl;
        preorder(root); 
        cout<<endl; 
    }
}

void preorder(Nodetype* node) {
    if (node == NULL) return; 
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Inorder traversal
void inorder() {
    if (isEmpty()) {
        cout << "tree is empty" << endl;
        return;
    } else {
        cout<< "inorder: "<< endl;
        inorder(root); 
        cout<<endl; 
    }
}

void inorder(Nodetype* node)  {
    if (node == NULL) return; 
    inorder(node->left);
    cout << node->data << " "; 
    inorder(node->right);
}

// Postorder traversal
void postorder() {
    if (isEmpty()) {
      cout << "tree is empty" << endl;
        return;
    } else {
        cout<< "postorder: "<< endl;
        postorder(root);  
        cout<<endl;
    }
}

void postorder(Nodetype* node) {
    if (node == NULL) return; 
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " "; 
}

};


int main()
{
    Binarysearchtree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(80);
    bst.insert(40);
    bst.remove(30);
    bst.insert(70);
    bst.insert(90);
    bst.search(80);
    bst.search(100);
    bst.preorder();
    bst.inorder();
    bst.postorder();
    bst.remove(20);
    bst.preorder();
    bst.inorder();
    bst.postorder();
    cout<<"treehight: "<<bst.treeheight()<<endl;
    cout<<"treenodecount: "<<bst.treenodecount()<<endl;
    bst.clear();
    bst.preorder();
    bst.inorder();
    bst.postorder();



    

    return 0;
}