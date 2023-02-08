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
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};   
info largest_BST(Node* root, int &ans){
    //Base Case
    if(root == NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = largest_BST(root->left,ans);
    info right = largest_BST(root->right,ans);

    info currNode;
    currNode.maxi = max(root->data,left.maxi);
    currNode.mini = min(root->data,right.mini);
    currNode.size = left.size + right.size + 1;

    if(left.isBST && right.isBST && (left.maxi < root->data && right.mini > root->data))
    {
        currNode.isBST = true;
    }
    else
    {
         currNode.isBST = false;
    }
    if(currNode.isBST){
        ans = max(ans,currNode.size);
    }
    return currNode;
}            
int main(){    
    Node* root = NULL; // suppose it is a tree           
    int maxSize = 0;
    info temp = largest_BST(root,maxSize);
    cout<<"Your Largest BST is :"<<maxSize<<endl;        
    return 0;          
}                      