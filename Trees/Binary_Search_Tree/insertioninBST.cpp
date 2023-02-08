#include<bits/stdc++.h>
using namespace std;   
class Node{
    //Visibility
    public:
    int data;
    Node* left;
    Node* right;
    // Constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//Inorder Traversal
void Inorder(Node* root){
    if(root == NULL)return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

Node* insertinBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    else if(root->data > d){
        root->left = insertinBST(root->left,d);
    }
    else if(root->data < d){
        root->right = insertinBST(root->right,d);
    }
}
Node* createBST(Node* root){
    int d;
    cout<<"Enter the data for the BST: "<<endl;
    cin>>d;
    while(d != -1){
        root = insertinBST(root,d);
        cout<<"Enter the data for the BST: "<<endl;
        cin>>d;
    }
    return root;
}

int main(){            
    Node* root = NULL;
    root = createBST(root);
    cout<<"Your Inorder Traversal of this BST is: "<<endl;
    Inorder(root);
    return 0;          
}                      