#include <bits/stdc++.h>
using namespace std;
bool asc=0;
template<class T>
class node_avl{
public:
    node_avl<T>*left;
    node_avl<T>*right;
    T data;
    int height;
    int balance_factor;
public:
    node_avl(T data){
        left=right=NULL;
        height=balance_factor=0;
        this->data=data;
    }
};
template<class T>
class avl{
private:
    node_avl<T>* root;

    node_avl<T>*Insert(node_avl<T>*r,T x){
        if(r==NULL){
            node_avl<T>*n=new node_avl(x);
            n->height=1;

            r=n;
        }else if(x<r->data){
            r->left=Insert(r->left,x);
            if(r->right!=NULL){
                r->height=max(r->left->height,r->right->height)+1;
            }
            else{
                r->height=r->left->height+1;
            }
        }else {
            r->right= Insert(r->right,x);
            if(r->left!=NULL){
                r->height=max(r->right->height,r->left->height)+1;
            }
            else{
                r->height=r->right->height+1;
            }
        }
        return r;
    }
    node_avl<T>* is_balanced(node_avl<T>* r){
        if(r->right==NULL&&r->left==NULL){
            r->balance_factor=0;
        }
        else{
                if (r->left == NULL) {
                    r->right= is_balanced(r->right);
                    r->balance_factor = 0- r->right->height;
                } else if (r->right == NULL) {
                    r->left= is_balanced(r->left);
                    r->balance_factor = r->left->height;

                } else {
                    r->left=is_balanced(r->left);
                    r->right=is_balanced(r->right);
                    r->balance_factor = r->left->height - r->right->height;
                }
            }
        if(r->balance_factor>=2){
            if(r->left->balance_factor>0){
                r=right_rotation(r);
                r=heigh(r);
                r=is_balanced(r);
            }else{
                r=left_right_rotation(r);
                r=heigh(r);
                r=is_balanced(r);
            }
        }
        else if(r->balance_factor==-2){
            if(r->right->balance_factor<0){
                r=left_rotation(r);
                r= heigh(r);
                r= is_balanced(r);
            }else{
                r=right_left_rotation(r);
                r= heigh(r);
                r= is_balanced(r);
            }
        }
        return r;
    }
    node_avl<T>* right_rotation(node_avl<T>* r){
        node_avl<T>*newnode_avl=r,*temp=r->left->right;
        r=r->left;
        r->right=newnode_avl;
        r->right->left=temp;
        r= heigh(r);
        return r;
    }
    node_avl<T>*heigh(node_avl<T>*r){
        if(r->right==NULL&&r->left==NULL){
            r->height=1;
        }else {
            if(r->right==NULL){
                r->left= heigh(r->left);
                r->height=r->left->height+1;
            }else if(r->left==NULL){
                r->right= heigh(r->right);
                r->height-r->right->height+1;
            }else{
                r->left= heigh(r->left);
                r->right= heigh(r->right);
                r->height=max(r->left->height,r->right->height)+1;
            }
        }
        return r;
    }
    node_avl<T>* left_right_rotation(node_avl<T>* r){
        node_avl<T>*newnode_avl =r->left,*temp=r->left->right->left;
        r->left=r->left->right;
        r->left->left=newnode_avl;
        r->left->left->right=temp;
        r=heigh(r);
        return right_rotation(r);

    }
    node_avl<T>* left_rotation(node_avl<T>* r){
        node_avl<T>*newnode_avl=r,*temp=r->right->left;
        r=r->right;
        r->left=newnode_avl;
        r->left->right=temp;
        r= heigh(r);
        return r;
    }
    node_avl<T>* right_left_rotation(node_avl<T>* r){
        node_avl<T>* newnode_avl=r->right,*temp=r->right->left->right;
        r->right=r->right->left;
        r->right->right=newnode_avl;
        r->right->right->left=temp;
        r= heigh(r);
        return left_rotation(r);
    }
    void print_ascending(node_avl<T>* r)
    {
        if(r==NULL)return ;
        print_ascending(r->left);
        cout<<r->data<<'\t';
        print_ascending(r->right);
    }
    void print_descending(node_avl<T>* r)
    {
        if(r==NULL)return ;
        print_descending(r->right);
        cout<<r->data<<'\t';
        print_descending(r->left);
    }
    node_avl<T>* findmax(node_avl<T>* r){
        if(r->right== nullptr){
            return r;
        }else{
            return findmax(r->right);
        }
    }
    node_avl<T>* remove(T item,node_avl<T>*r){
        if(r==NULL){
            return NULL;
        }else if(r->data>item){
            r->left= remove(item,r->left);
        }else if(r->data<item){
            r->right= remove(item,r->right);
        }
        else{
            if(r->right==NULL&&r->left==NULL){
                r=NULL;
            }else if(r->right==NULL&&r->left!=NULL){
                node_avl<T>*temp=r;
                r=r->left;
                delete temp;
            }else if(r->right!=NULL&&r->left==NULL){
                node_avl<T>*temp=r;
                r=r->right;
                delete temp;
            }else{
                node_avl<T>* temp= findmax(r->left);
                r->data=temp->data;
                r->left= remove(r->data,r->left);
                delete temp;
            }
        }
        return r;
    }
public:
    avl(){
        root=NULL;
    }
    void insert(T x){
        root= Insert(root,x);
        root= is_balanced(root);
    }
    void removeitem(T item){
        root=remove(item,root);
        root= is_balanced(root);

    }
    void print(){
        if(asc){
            print_descending(root);
        }
        else{
            print_ascending(root);
        }
    }


};

int main(){
    avl<string> a;
    a.insert("AA");
    a.insert("CC");
    a.insert("BB");
    a.insert("DD");
//    a.removeitem("BB");
    a.print();

}
