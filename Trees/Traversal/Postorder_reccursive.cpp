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

//Postorder Traversal
void Postorder(Node* root){
    if(root == NULL)return;
    
    //Reccursive left
    Postorder(root->left);
    //Reccursive right
    Postorder(root->right);
    //Print Node
    cout<<root->data<<" ";
}     

int main(){            
                               
    return 0;          
}