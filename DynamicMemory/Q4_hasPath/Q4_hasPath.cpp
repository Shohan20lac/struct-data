#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int data = 0;
    BinaryTreeNode* left = nullptr;
    BinaryTreeNode* right = nullptr;

    BinaryTreeNode(int n) {
        data = n;
    }
};

void insert(BinaryTreeNode*& a, int x) {
    BinaryTreeNode* current = a;
    if (current == nullptr) {
        a = new BinaryTreeNode(x);
        return;
    }
    //else

    if (x > (current->data)) {
        insert(current->right, x);
        return;
    }

    if (x < (current->data)) {
        insert(current->left, x);
        return;
    }
}

int getLevel(BinaryTreeNode* a, int val, int i) {
    //i has to start at 1

    if (a == nullptr)
        return 0;
    if (a->data == val)
        return i;

    int leftval = getLevel(a->left, val, i + 1);
    int rightval = getLevel(a->right, val, i + 1);

    return (max(leftval, rightval));
}

bool foundelement(BinaryTreeNode* a, int val) {
    if (a == nullptr) return false;

    if (a->data == val)
        return true;

    if (a->data > val)
        return foundelement(a->left, val);    // if val < thisBinaryTreeNodeval, that's our cue to go left;
    else
        return foundelement(a->right, val);
}

bool hasPath(BinaryTreeNode* a, int start, int end) {
    if (a == nullptr) {
        cout << "list is empty! Terminating..." << endl;
        return false;
    }

    if ((foundelement(a, start) || foundelement(a, end)) == false) {
        cout << "one or more nodes don't exist in this tree. Terminating..." << endl;
        return false;
    }

    if (getLevel(a, end, 1) < (getLevel(a, start, 1))) {
        cout << "one or two of these nodes exist, but they are in the wrong order. Terminating..." << endl;
        return false;
    }


    //if we've made it this far down,
    return true;

}

int main() {
    BinaryTreeNode* root1 = nullptr;
    insert(root1, 10);
    insert(root1, 11);
    insert(root1, 5);
    insert(root1, 16);
    insert(root1, 12);
    insert(root1, 8);
    insert(root1, 4);

    int start = 10;
    int end = 16;
    bool haspath = hasPath(root1, start, end);

    if (haspath == true)
        cout << "Node " << start << " has a path to node " << end << endl;


}