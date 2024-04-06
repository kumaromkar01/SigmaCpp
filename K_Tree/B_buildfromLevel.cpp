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
Node* buildFromLevel(Node* root){
    //step1: queue banao
    //step2: data input lo aur root banao
    //step 3: jab tak queue empty n ho pop aur print karate raho
    //step 4: pop karate hi left aur right ke input lekar queue me push bhi kar dena
    //loop tab tak chale jab tak queue khali n ho jaye
    queue<Node*> q;
    cout<<"Enter data : "<<endl;
    int data; cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        //left node ka kam
        cout<<"enter leftNode of : "<<temp->data<<endl; 
        int leftdata; cin>>leftdata;
        if(leftdata!=-1){
            temp-> left = new Node(leftdata);
            q.push(temp->left);
        } 
        //right ka kam
        cout<<"enter right node of : "<<temp->data<<endl; int rightData; cin>>rightData;
        if(rightData!=-1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}
void printLevelTraversal(Node* root){
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
int main(){
    Node* root = NULL;
    root=buildFromLevel(root);
    printLevelTraversal(root);
    return 1;
}