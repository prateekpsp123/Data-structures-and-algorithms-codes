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
    
    //Reccursive left
    Inorder(root->left);
    //Print Node
    cout<<root->data<<" ";
    //Reccursive right
    Inorder(root->right);
}     

int main(){            
                               
    return 0;          
}                      