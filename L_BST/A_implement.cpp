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
        right = left = NULL;
    }
};
Node* insertBst(Node* root,int d){
    if(root==NULL){
        Node* newNode = new Node(d);
        root = newNode;
        return root;
    }
    if(root->data>d){
        root->left = insertBst(root->left,d);
    }
    else {
        root->right = insertBst(root->right,d);
    }
    return root;

}
void takeIn(Node* &root){ // pass root by reference
    int d;
    cin>>d;
    while(d!=-1){
        root=insertBst(root,d);
        cin>>d;
    }
}
void  levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

    }
    return ;
}
void inorder(Node* root){ //always in ascending order 
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// bool searchBst(Node* root,int x){
//     //recursive approach
//     if(root == NULL) return false;
//     if(root->data==x) return true;
//     if(root->data>x) searchBst(root->left,x);
//     if(root->data<x) searchBst(root->right,x);
// }

bool searchBst(Node* root, int x){
    //iterative approach is better than recursive one
    Node* temp = root;
    while(temp!=NULL){
        if(temp->data==x) return true;
        if(temp->data>x) {
            temp= temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}
int minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
int maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}
int InorderPre(Node* root, int x){
    Node* temp = root;
    if(searchBst(root,x)==false) return -1;
    while(temp->data!=x){
        if(temp->data<x){
            temp = temp->right;
        }
        if(temp->data>x){
            temp = temp ->left;
        }
    }
    if(temp->left==NULL) return -1;
    temp = temp ->left;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}
int InorderSuc(Node* root, int x){
    Node* temp = root;
    if(searchBst(root,x)==false) return -1;
    while(temp->data!=x){
        if(temp->data<x){
            temp = temp->right;
        }
        if(temp->data>x){
            temp = temp ->left;
        }
    }
    if(temp->right==NULL) return -1;
    temp = temp ->right;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}

Node* deleteNode(Node* root,int x){
    if(root==NULL) return NULL;
    if(root->data==x){
        //0child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(root->left!=NULL&&root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL&&root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL&&root->right!=NULL){
           int mini = minVal(root->right)->data; //INORDER SUCCESSOR
           root->right = mini;
           root->right = deleteNode(root->right,mini);
        }
    }
    else if(root->data>x){
        root->left=deleteNode(root->left,x);
        return root;
    }
    else {
        root->right=deleteNode(root->right,x);
        return root;
    }
}
int main(){
    Node* root =NULL;
    takeIn(root);


    cout<<"inorder traversal : "<<endl;
    inorder(root);


    cout<<"\n levelOrder: "<<endl;
    levelOrder(root);


    searchBst(root,7)?cout<<" 7 exist in tree : True ": cout<<"7 is in tree : false";

    cout<<"\nmin value in tree : "<<minVal(root);
    cout<<"\nmax value in tree : "<<maxVal(root);

    cout<<"\nInorder predecessor of 10 is : "<<InorderPre(root,10);
    cout<<"\nInorder successor of 10 is : "<<InorderSuc(root,10)<<endl;;

    root= deleteNode(root,5);
    inorder(root);
    return 0;
}