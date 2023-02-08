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

//Function to return a list containing the bottom view of the given tree.
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root == NULL)return ans;
        map<int,int>bottomNode;
        
        queue<pair<int,Node*>>q;
        q.push(make_pair(0,root));
        
        while(!q.empty()){

            pair<int,Node*>front_pair = q.front();
            Node* temp = front_pair.second;
            int hd = front_pair.first;
            q.pop();
            bottomNode[hd] = temp->data;
            
            if(temp->left){
                q.push(make_pair(hd-1,temp->left));
            }
            if(temp->right){
                q.push(make_pair(hd+1,temp->right));
            }
        }
        
        for(auto i:bottomNode){
            ans.push_back(i.second);
        }
        return ans;
    }
};                       
int main(){            
                       
                       
    return 0;          
}                      