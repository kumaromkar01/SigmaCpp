
#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right=NULL;
    }
};
Node* build(Node* root){

    cout<<"enter data (-1 for NULL)"<<endl;
    int data; cin>>data;
    root = new Node(data);
    if(data==-1) return NULL;
    cout<<"enter left of "<<data;
    root->left = build(root->left);
    cout<<"enter right of "<<data;
    root->right = build(root->right);
    return root;
}
int height(Node* root){
    if(root==NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right)+1;
    return ans;
}
bool isBalanced(Node* root){
    if(root==NULL) return true;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left)-height(root->right))<=1;
    if(left&&right&&diff) return 1;
    return 0;
}
//optimised
pair<bool, int> isBalancedop(Node* root) {
    if(root == NULL) return make_pair(true, 0);
    pair<bool, int> leftp = isBalancedop(root->left);
    pair<bool, int> rightp = isBalancedop(root->right);
    bool leftres = leftp.first;
    bool rightres = rightp.first;
    bool diff = abs(leftp.second - rightp.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(leftp.second, rightp.second) + 1;
    if(leftres && rightres && diff) 
        ans.first = true;
    else 
        ans.first = false;
    return ans;
}
main(){
    Node* root = NULL;
    root = build(root);
    cout<<"height;"<<height(root)<<"\n";
    cout<<endl<<"is tree balanced : "<<isBalanced(root);
}
