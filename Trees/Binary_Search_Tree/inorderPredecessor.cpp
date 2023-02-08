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
Node* inorderPredecessor(Node* root){
    if(root->left == NULL){
        return NULL;
    }
    Node* temp = root->left;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}                   
int main(){            
                       
                       
    return 0;          
}                      