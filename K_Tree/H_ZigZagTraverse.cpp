#inlcude<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    //gfg zig-zag traversAl
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	bool LTr = true;
    	vector<int> result;
    	if(root==NULL) return result;
    	queue<Node*>q;
    	q.push(root);
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> ans(size);
    	    for(int i=0;i<size;i++){
    	        Node* frontNode = q.front();
    	        q.pop();
    	        int indx = LTr?i:size-i-1;
    	        ans[indx] = frontNode->data;
    	         if(frontNode->left) q.push(frontNode->left);
    	        if(frontNode->right) q.push(frontNode->right);
    	    }
    	    LTr = !LTr;
    	    for(auto i: ans){
    	        result.push_back(i);
    	    }   
    	}
    	return result;
    }
};