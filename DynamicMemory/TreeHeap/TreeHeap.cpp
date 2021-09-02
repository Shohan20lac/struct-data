#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void insert(node* &n , int element ) {
    if (n == nullptr) {
        cout << "Node is empty. Adding..." << endl;
        n = new node;
        n->data = element;
        return;
    }

    if (element > (n->data)) {
        insert(n->right, element);
    }
    else
        insert(n->right, element);
    n->data = element;
    
}

int main(){

    node* a = nullptr;
    insert(a, 10);
    insert(a, 20);
    insert(a, 30);
    cout << a
}