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

Node* minValue(Node* root){
    
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxValue(Node* root){
    
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
Node* deletioninBST(Node* root, int val){
    if(root == NULL)return NULL;

    if(root->data == val){

        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        // Left child
        if(root->right == NULL && root->left != NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //Right child
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->right != NULL && root->left != NULL){
           int mini = minValue(root->right)->data;
           root->data = mini;
           root->right = deletioninBST(root->right,mini);
           return root;
        }
    }
    else if(root->data > val){
        root->left = deletioninBST(root->left,val);
    }
    else{
        root->right = deletioninBST(root->right,val);
    }
}

                     
int main(){            

    return 0;          
}                      