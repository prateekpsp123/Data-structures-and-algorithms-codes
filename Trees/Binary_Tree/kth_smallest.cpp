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
/*
what we will do is just do the Inorder traversal and just at reaching every Node we will increment the count
when the count will be equal to the K then we will return that Node

[for the question Kth Largest -> (n-K-1) n will be the number of Nodes]

*/
int Kth_smallest(Node* root, int &count, int K){
    //Base Case
    if(root == NULL){
        return -1;
    }
    int left = Kth_smallest(root->left,count,K);
    if(left != -1){
        return left;
    }
    count++;
    if(count == K){
        return root->data;
    }
    return Kth_smallest(root->right,count,K);
}
                      
int main(){            
                       
                       
    return 0;          
}                      