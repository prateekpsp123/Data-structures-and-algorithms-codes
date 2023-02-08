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

//Preorder Traversal
void Preorder(Node* root){
    if(root == NULL)return;
    
    //Print Node
    cout<<root->data<<" ";
    //Reccursive left
    Preorder(root->left);
    //Reccursive right
    Preorder(root->right);
}     

int main(){            
                               
    return 0;          
}