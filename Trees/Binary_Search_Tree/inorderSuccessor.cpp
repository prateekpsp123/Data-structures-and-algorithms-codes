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
Node* inorderSuccessor(Node* root){
    if(root->right == NULL){
        return NULL;
    }
    Node* temp = root->right;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}                   
int main(){            
                       
                       
    return 0;          
}                      