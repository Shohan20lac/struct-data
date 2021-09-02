#include <iostream>
using namespace std;

struct node {
    int data = 0;
    node* left = nullptr;
    node* right = nullptr;
};

void printNumber(int x) {
    //peculiar recursion example. Observe wisely!
    if (x > 10) return;
    
    cout << x << endl;
    
    printNumber( ++x );

    //think about all the variations:
    //printNumber( x + 1 )
    //printNumber( ++x + 1 )
    //printNumber( x++ )

    //what happens if you define function as &x?
}

void insert (node*& a, int x) {

}

int minBST(node* a) {
    if (a == nullptr)
        return -1000;
    if (a->right == nullptr)
        return a->data;

    //else,
    return minBST(a->left);
}

void remove(node*& a, int x) {
    if (a == nullptr) return;
    else if (x > a->data) remove(a->right, x);
    else if (x < a->data) remove(a->left, x);
    else {
        if (a->right == nullptr && a->left) {
            a = nullptr;
        }
        else if (a->right == nullptr) {
            a = a->left;
        }
        else if (a->left == nullptr) {
            a = a->right; 
        }
        else {
            int minVal = minBST(a->right);
            a->data = minVal;
            remove(a->right, minVal);
        }
    }
}

int main()
{

}