// C++ program for different tree traversals
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
/////depth treverse ///////////////

void printInorder(struct Node* node) //lvr
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);
}
void printpreorder(struct Node* node) //vlr
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    printpreorder(node->left);

    printpreorder(node->right);
}
void printpostorder(struct Node* node) //lrv
{
    if (node == NULL)
        return;

    printpostorder(node->left);

    printpostorder(node->right);

    cout << node->data << " ";
}

void printdifforder(struct Node* node) //rlv
{
    if (node == NULL)
        return;

    printdifforder(node->right);

    printdifforder(node->left);

    cout << node->data << " ";
}

// Driver code
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);


    // Function call
    cout << "Inorder traversal of binary tree is \n";
    printInorder(root);
    cout<<endl;
    printpreorder(root);
    cout<<endl;
    printpostorder(root);
    cout<<endl;
    printdifforder(root);
    return 0;
}
//                        1
//                2               3
//            4       5       6          7