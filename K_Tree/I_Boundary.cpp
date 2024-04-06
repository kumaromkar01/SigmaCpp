#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans){
        if(root==NULL) return ;
        if(root->left ==NULL&&root->right==NULL) return ;//exclude leaf nodes
        ans.push_back(root->data);
        if(root->left) traverseLeft(root->left,ans); //check if leaf is there store it
        else traverseLeft(root->right,ans); //if left is not there means store right;
    }
    void traverseLeaf(Node* root, vector<int> &ans){
        //traverse entire tree like inorder ans store leaf nodes
        if(root==NULL ) return;
        traverseLeaf(root->left,ans);// store the leaf nodes from left to right
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->right,ans);
    }
    void traverseRight(Node* root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left == NULL && root-> right ==  NULL) return;
        if(root->right) traverseRight(root->right,ans);
        else traverseRight(root->left,ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> ans;
        if(root==NULL) return ans;
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        traverseRight(root->right,ans);
        return ans;
    }
};