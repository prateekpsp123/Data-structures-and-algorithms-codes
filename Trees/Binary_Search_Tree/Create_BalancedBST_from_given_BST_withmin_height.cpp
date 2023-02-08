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
void inorder(Node* root, vector<int>&temp){
    //Base Case
    if(root == NULL)
    {
        return;
    }
    //Left Call                   L
    inorder(root->left,temp);
    //pushing the Node data       N
    temp.push_back(root->data);
    //Right call                  R
    inorder(root->right,temp);

}
Node* createBST_Balanced(Node* root, vector<int>in, int s, int e){
    //Base Case
    if(s>e){
        return NULL;
    }
    //finding the middle element
    int mid = s + (e-s)/2;
    int element = in[mid];
    //New Node Creation
    Node* root = new Node(element);
    //Create left SubTree
    root->left = createBST_Balanced(root->left,in,s,mid-1);
    //Create Right SubTree
    root->right = createBST_Balanced(root->left,in,mid+1,e);
    // we will return the Tree Now
    return root;
}
                      
int main(){            
                       
                       
    return 0;          
}                      