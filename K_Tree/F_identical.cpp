#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *left;
    Node* right;
    Node(int d){
        val = d;
        left=right=NULL;
    }
};
bool identical(Node* r1, Node *r2){
    if(r1==NULL&&r2==NULL) return true;
    if(r1!=NULL&&r2==NULL) return false;
    if(r1==NULL&&r2!=NULL) return false;
    bool leftp = identical(r1->left,r2->left);
    bool rightp = identical(r1->right,r2->right);
    bool value = r1->val==r2->val;
    if(leftp&&rightp&&value) return true;
    return false;
}
Node* build(Node* root){
    cout<<"enter data";
    int d; cin>>d;
    if(d==-1) return NULL;
    root = new Node(d);
    root->left = build(root->left);
    root->right = build(root->right);
    return root;
}
main(){
    cout<<"enter data of tree1 "<<endl;
    Node* root = build (root);
    cout<<"enter data of tree2 "<<endl;
    Node* root1 = build(root1);
    cout<<"is Identical "<<identical(root1,root);
}