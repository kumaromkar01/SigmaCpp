#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* right;
    Node* left;

    Node(int data) : val(data), left(nullptr), right(nullptr) {}
};

Node* build() {
    cout << "enter data: ";
    int d;
    cin >> d;
    if (d == -1) return nullptr;
    Node* root = new Node(d);
    cout << "Enter left child of " << d << ":\n";
    root->left = build();
    cout << "Enter right child of " << d << ":\n";
    root->right = build();
    return root;
}

pair<bool, int> isSumTree(Node* root) {
    if (root == nullptr) return make_pair(true, 0);
    if (root->left == nullptr && root->right == nullptr) return make_pair(true, root->val);

    pair<bool, int> leftAns = isSumTree(root->left);
    pair<bool, int> rightAns = isSumTree(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condn = root->val == leftAns.second + rightAns.second;

    pair<bool, int> ans;
    if (left && right && condn) {
        ans.first = true;
        ans.second = root->val + leftAns.second + rightAns.second;
    }
    else {
        ans.first = false;
    }
    return ans;
}

int main() {
    Node* root = build();
    pair<bool, int> result = isSumTree(root);
    if (result.first) {
        cout << "The tree is a sum tree.\n";
    }
    else {
        cout << "The tree is not a sum tree.\n";
    }
    return 0;
}
