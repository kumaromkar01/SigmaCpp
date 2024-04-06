#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* build() {
    cout << "Enter data (-1 for NULL): ";
    int data; 
    cin >> data;
    if (data == -1) return NULL;
    
    Node* root = new Node(data);
    cout << "Enter left of " << data << endl;
    root->left = build();
    cout << "Enter right of " << data << endl;
    root->right = build();
    
    return root;
}

void levelorderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

int height(Node* root) {
    if (root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
//calculate diameter using height function
int diameter(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}
//calculate diameter optimised code
pair<int, int> diam(Node* root){
    if(root==NULL) return make_pair(0,0);
    pair<int,int> left = diam(root->left);
    pair<int,int> right = diam(root->right);
    int op1 = left.first; //case 1 diameter is in left comp.
    int op2 = right.first;// case 2 diameter is in right comp.
    int op3 = left.second + right.second +1; //case 3 is diametr = height o f left+right
    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;
    return ans;
}

int main() {
    Node* root = build();
    cout << "Tree is: ";
    levelorderTraversal(root);
    cout << endl;
    // cout << "Diameter is: " << diameter(root) << endl;
    pair<int, int> diameterInfo = diam(root);
    cout << "Diameter is: " << diameterInfo.first << endl;
    return 0;
}
