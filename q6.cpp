#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int num) {
        data = num;
        left = NULL;
        right = NULL;
    }
};

bool check(Node* ptr) {
    
    if(ptr == NULL) {
        return false;
    }
    if(ptr->left && ptr->right) {
        if(ptr->data < ptr->right->data && ptr->data < ptr->left->data) {
            return true;
        }
    } else if (ptr->left && ptr->right == NULL) {
        if(ptr->left->data > ptr->data) {
            return true;
        }
    } else if(ptr->right && ptr->left == NULL) {
        if(ptr->right->data > ptr->data) {
            return true;
        }
    } else {
        return true;
    }

    return false;
}

int height = 0;
void recurse(Node* ptr) {
    if(ptr == NULL) {
        return;
    } else {
        if(check(ptr->left) && check(ptr->right)) {
            recurse(ptr->left);
            recurse(ptr->right);
            height++;
        }
        
    }
}

int main() {

    Node *root = new Node(14);
    root->right = new Node(27);
    root->left = new Node(34);
    root->left->left = new Node(40);
    root->left->right = new Node(37);
    root->left->left->left = new Node(13);
    root->left->left->right = new Node(50);
    root->left->right->left = new Node(21);
    root->left->right->right = new Node(39);
    root->right->left = new Node(54);
    root->right->right = new Node(30);
    root->right->left->left = new Node(56);
    root->right->left->right = new Node(89);

    recurse(root);
    cout << height;

    return 0;
}