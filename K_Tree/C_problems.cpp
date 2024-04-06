#include<iostream>
#include<queue>
using namespace std;
class Node{
    public : 
    int val;
    Node* left;
    Node* right;
};
void levelorderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp-> right){
                q.push(temp->right);
            }
        }
    }
    return ;

}
int height(Node* root){
    if(root==NULL)  return 0;
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right)+1;
    return ans;
}
int main() {
    Node* root = new Node(); 
    root->val = 1;
    root->left = new Node(); 
    root->left->val = 3;
    root->right = new Node(); 
    root->right->val = 5;
    root->left->left = new Node(); 
    root->left->left->val = 7;
    root->left->right = new Node(); 
    root->left->right->val = 11;
    root->right->right = new Node();
    root->right->right->val = 17;
    levelorderTraversal(root);
    cout<<"height : "<<height(root);
    return 0;
}
