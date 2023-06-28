#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value) {

    }
};

bool IsSubTree(Node* parent, Node* child) {
    if (!parent && child) {
        return false;
    }

     if (parent && !child) {
        return true;
    }

    if (!parent && !child) {
        return true;
    }

    if (parent->value == child->value) {
        return IsSubTree(parent->left, child->left) && IsSubTree(parent->right, child->right);
    } else {
        return IsSubTree(parent->left, child) || IsSubTree(parent->right, child);
    }
}

int main(int argc, char* argv[]) {

    // parent 
    //  1
    // / \
    // 2  3

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Node* child = new Node(2);
    // child->left = new Node(2);

    std::cout << IsSubTree(root, child) << std::endl;

    return 0;
}