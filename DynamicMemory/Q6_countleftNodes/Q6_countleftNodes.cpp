
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

int countleftNodes(BinaryTreeNode* a, int& lncount) {
    if (a == nullptr)
        return 0;

    if (a->left != nullptr)
        lncount++;


    int temp1 = countleftNodes(a->left, lncount);
    int temp2 = countleftNodes(a->right, lncount);

    return lncount;
}


int main()
{
    BinaryTreeNode* root1 = nullptr;
    insert(root1, 10);
    insert(root1, 11);
    insert(root1, 5);
    //insert(root1, 16);
    //insert(root1, 12);
    //insert(root1, 8);
    //insert(root1, 4);

    int count = 0;
    int val = 10;
    int* arr = new int[7];

    //cout << sumcousins(root1, val, arr, 1, count);

    //cout << arr[0] << endl;
    int lncount = 0;
    cout << countleftNodes(root1, lncount);


}