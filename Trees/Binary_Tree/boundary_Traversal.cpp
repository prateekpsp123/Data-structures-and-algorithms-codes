#include<bits/stdc++.h>
using namespace std;   

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //Constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void leftTraversal(Node* root, vector<int>&ans){
    if(root == NULL)return;
    //Leaf Node return we do not have to consider it 
    // it will be seperatly consider
    if(root->left == NULL && root->right == NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftTraversal(root->left,ans);
    }
    else{
        leftTraversal(root->right,ans);
    }
}
void leafNodeTraverse(Node* root, vector<int>&ans){
    if(root == NULL)return;
    if(root->right == NULL && root->left == NULL){
        ans.push_back(root->data);
        return;
    }
    leafNodeTraverse(root->left,ans);
    leafNodeTraverse(root->right,ans);
}

void rightTraversal(Node *root, vector<int>&ans){
    if(root == NULL)return;
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->right){
        leftTraversal(root->right,ans);
    }
    else{
        leftTraversal(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    //left side Traversal
    leftTraversal(root->left,ans);
    //leafNode traversal
    leafNodeTraverse(root->left,ans);
    leafNodeTraverse(root->right,ans);
    //right side Traversal
    rightTraversal(root->right,ans);
    return ans;
}                    
int main(){
    Node* root = NULL;
    return 0;          
}                      