#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* buildtree(Node *root){
    int data;
    cout<<"enter data :"<<endl;
    cin>>data;
    root = new Node(data);
    if(data==-1) return NULL;
    cout<<"enter value left to the "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"enter value right to the "<<data<<endl;
    root->right = buildtree(root->right);
    return root;
}
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
            cout<<temp->data<<" ";
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
void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"  ";
}
int main(){
    Node* root = NULL;
    root = buildtree(root);
    levelorderTraversal(root);
    cout<<"inorder traversal : " ;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal : " ;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal : " ;
    postorder(root);
    cout<<endl;
    return 0;
}