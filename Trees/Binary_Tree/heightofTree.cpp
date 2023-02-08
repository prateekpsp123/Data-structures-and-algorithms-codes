#include<bits/stdc++.h>
using namespace std;   
class Node
{
    public:

    int data;
    struct Node* left;
    struct Node* right;

    Node(int data){
       this->data = data;
       this->left = NULL;
       this->right = NULL;
    }
}; 

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node == NULL){
            return 0;
        }
        int left = height(node->left);            
        int right = height(node->right);    
        
        return max(left,right)+1;
    }
};                       
int main(){            
                       
                       
    return 0;          
}                      