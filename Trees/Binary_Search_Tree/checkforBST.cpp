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

class Solution
{
    private:
    bool checkBST(int left_range, int right_range, Node* root){
        
        if(root==NULL)return true;
        
        bool condition_1 = checkBST(left_range,root->data-1,root->left);
        bool condition_2 = checkBST(root->data+1,right_range,root->right);
        
        bool condition_3 = false;
        
        if(left_range <= root->data && root->data <= right_range){
            condition_3 = true;
        }
        
        if(condition_1 && condition_2 && condition_3){
            return true;
        }
        
        return false;
    }
    
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return checkBST(INT_MIN,INT_MAX,root);
    }
};                       
int main(){            
                       
                       
    return 0;          
}                      