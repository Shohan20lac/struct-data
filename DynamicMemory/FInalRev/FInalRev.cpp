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

bool foundelement(BinaryTreeNode* a, int val) {
    if (a == nullptr) return false;

    if (a->data == val)
        return true;

    if (a->data > val)
        return foundelement(a->left, val);    // if val < thisBinaryTreeNodeval, that's our cue to go left;
    else
        return foundelement(a->right, val);
}

int distanceTo(BinaryTreeNode* a, int val, int length) {  //returns the distance from root BinaryTreeNode to destination BinaryTreeNodeS
    if (a == nullptr)
        return 0;

    if (a->data == val)
        return length;

    int leftdist = distanceTo(a->left, val, length + 1);
    int rightdist = distanceTo(a->right, val, length + 1);

    return (leftdist + rightdist);
}

int getDistance(BinaryTreeNode* a, int val1, int val2, int length) {

    if (!foundelement(a, val1) && !foundelement(a, val2)) {
        cout << "one of the elements is missing! aborting operation..." << endl;
    }

    //base case: target value reached.
    if ((a->data == val1) || (a->data == val2)) {
        return length;
    }

    //case 1: both val1 and val2 are on the left side of current subtree
    if ((val1 < a->data) && (val2 < a->data)) {
        return getDistance(a->left, val1, val2, length);
    }
    //case 2: both val1 and val2 are on the right side of current subtree
    if ((val1 > a->data) && (val2 > a->data)) {
        return getDistance(a->right, val1, val2, length);
    }
    //case 3: val1 is to the left, val2 is to the right
    if ((val1 < a->data) && (val2 > a->data)) {

        int leftdist = distanceTo(a, val1, length);
        int rightdist = distanceTo(a, val2, length);

        return leftdist + rightdist;
    }
}

void printRoottoA(BinaryTreeNode* root, BinaryTreeNode* A) {
    int targetval = A->data;

    if (!hasPath(root, root->data, targetval)) {
        cout << "path doesn't exist. returnning..." << endl;
        return;
    }


    //else, the path exists and we just have to print it.

    cout << root->data << "--";
    while (root->data != targetval) {

        if (targetval < root->data)
            root = root->left;
        else
            root = root->right;

        cout << root->data << "--" << endl;

    }

}

void printAtoB (BinaryTreeNode* root, BinaryTreeNode* A, BinaryTreeNode* B) {
    
    if (getLevel(root, A->data, 1) < (getLevel(root, B->data, 1)) ) {   //no path.
        cout << "--" << endl;
        return;
    }


    cout << A->data;
    
    if (A->data == B->data)
        return;

    //now that we've confirmed that B is under A...
    printRoottoA(A, B);
    
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

    //distance between nodes
    int length = 0;
    cout << getDistance(root1, 8, 16, 0);
}