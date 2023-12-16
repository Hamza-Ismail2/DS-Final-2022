#include<iostream>
#include<queue>
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

class BT {
public:
    Node* root;

    BT() {
        root = NULL;
    }

//    int levelorder(Node* temp) {
//        if (temp == NULL) {
//            return 0;
//        }
//        queue<Node> q;
//        q.push(root);
//        q.push(NULL);
//        Node curr;
//
//        while (q.size() > 1) {
//            curr = q.front();
//            q.pop();
//
//            if (curr == NULL) {
//                q.push(NULL);
//            }
//            else {
//                if (curr->left) {
//                    q.push(curr->left);
//                }
//                if (curr->right) {
//                    q.push(curr->right);
//                }
//            }
//        }
//        return curr->data;
//    }

    int count(Node *temp,int k,int sum)
    {
        if(temp==NULL)
        {
            return 0;
        }
        int countleft = count(temp->left,k,sum+temp->data);
        int countright = count(temp->right,k,sum+temp->data);

    }

    void print(vector<int>& temp) {

        for(auto i : temp) {
            cout << i << " ";
        }
        cout << endl;
        }

    void recurse(Node* ptr, int sum, int k, vector<int> v) {

        if(ptr == NULL) {
            return;
        } else if((sum + ptr->data) == k) {
            v.push_back(ptr->data);
            print(v);
        } else {
            v.push_back(ptr->data);
            recurse(ptr->left, sum + ptr->data, k, v);
            recurse(ptr->right, sum + ptr->data, k, v);
        }
        
    }

    void helper(Node * ptr, int k) {
        if(ptr == NULL) {
            return;
        } else {
            vector<int> temp;
            recurse(ptr, 0, k, temp);
            helper(ptr->left, k);
            helper(ptr->right, k);
        }
    }
};

int main() {
    BT b;
    b.root = new Node(1);
    b.root->left = new Node(3);
    b.root->right = new Node(-1);
    b.root->left->left = new Node(2);
    b.root->left->right = new Node(1);
    b.root->left->right->right = new Node(1);
    b.root->right->left = new Node(4);
    b.root->right->right = new Node(5);
    b.root->right->left->left = new Node(1);
    b.root->right->left->right = new Node(2);
    b.root->right->right->right = new Node(6);

    //b.levelorder(b.root);
    //b.calc(b.root, 5);
    vector<int> temp;
    b.helper(b.root, 5);

    return 0;
}