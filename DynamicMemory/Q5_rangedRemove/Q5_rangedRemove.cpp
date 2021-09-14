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

int minBST(BinaryTreeNode* a) {
    if (a == nullptr)
        return -1000;
    if (a->right == nullptr)
        return a->data;

    //else,
    return minBST(a->left);
}

void remove(BinaryTreeNode* a, int val) {
    if (a == nullptr) {
        cout << "nothing to remove";
        return;
    }

    else if (val > a->data)
        remove(a->right, val);

    else if (val < a->data)
        remove(a->left, val);

    else 
    {
        //condition  4: both left and right are nullpointers
        if (a->left == nullptr && a->right == nullptr) {
            a = nullptr;
        }
        
        //condition 3: at least left is nullpointer
        else if ( a->left == nullptr ){
            a = a->right;
        }
        
        //condition 2: at least right is nullpointer
        else if ( a->right == nullptr) {
            a = a->right;
        }

        //condition 1: neither left nor right is nullptr
        //"right niyei chinta kori."
        else {
            int minVal = minBST(a->right);
            a->data = minVal;

            //remove the min value from the right (larger) side
            remove(a->right, minVal);

        }

        //remove process:
        //1. REPLACE val node with minBST (a->right)
        //2. now that we have two DUPLICATES nodes (a and a-right),
        //   we call REMOVE on (a->right so that that subtree
        //   recurses again, going through all the above 
        //   4 CONDITION CHECKS)

    }

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

void range(BinaryTreeNode* a, int min, int max) {

    if (a == nullptr) {
        cout << ".nullpointer reached. Returning..." << endl;
        //do nothing. Just...
        return;
    }

    //else...
    if (
        ((a->data) >= min)
        &&
        ((a->data) <= max)
        )
    {
        cout << "[X] nodeval " << a->data << " is within range (inclusive). Removing..." << endl << endl;
        remove(a, a->data);
    }

    cout << "<-recursing left" << endl;
    range(a->left, min, max);

    cout << "recursing right->" << endl;
    range(a->right, min, max);

}

int main() {
    cout << "hello world!" << endl;

    BinaryTreeNode* root1 = nullptr;
    insert(root1, 10);
    insert(root1, 11);
    insert(root1, 5);
    //insert(root1, 16);
    //insert(root1, 12);
    //insert(root1, 8);
    //insert(root1, 4);

    //before
    int val = 10;
    cout << "does the val " << val << " exist in this subtree? Ans:" << foundelement(root1, val) << endl;

    //entering the range surrounding val
    range(root1, 5, 11);
    cout << "value " << val << "Removed successfully." << endl;

    //after
    cout << "does the val " << val << " exist in this subtree? Ans:" << foundelement(root1, val) << endl;
    cout << "does the val " << 5 << " exist in this subtree? Ans:" << foundelement(root1, val) << endl;
    cout << "does the val " << 11 << " exist in this subtree? Ans:" << foundelement(root1, val) << endl;

    //results
    if (!foundelement(root1, val)) {
        cout << "ranged deletion successful.";
    }

}