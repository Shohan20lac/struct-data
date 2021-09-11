#include <iostream>
using namespace std;

struct node {
    int data = 0;
    node* left = nullptr;
    node* right = nullptr;

    node(int n) {
        data = n;
    }
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
    node* current = a; 
    if (current == nullptr) {
        a = new node(x);
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

void countLevelsVoid (node* a, int levelcount) {
    if (a == nullptr) {
        cout << "End of list reached. level count:" << levelcount << ". Returning..." << endl;
        return;
    }

    if (a != nullptr) {
        levelcount++;
        cout << "Node found at level "<< levelcount <<". Value: "<< (a->data) << endl;

        cout << "\ntraversing left: " << endl;
        countLevelsVoid(a->left, levelcount);

        cout << "\ntraversing right: " << endl;
        countLevelsVoid(a->right, levelcount);
        return;
    }

    while (levelcount !=0){
        cout << "Showing data for level " << levelcount << endl;
        countLevelsVoid(a->right, ++levelcount);
        countLevelsVoid(a->left, ++levelcount);
    }
}

int countLevelsInt ( node*a , int levelcount ) {
    if (a == nullptr) {
        cout << "End of list reached. level count:" << levelcount << ". Returning..." << endl;
        return levelcount;
    }

    levelcount++;
    cout << "Node found at level " << levelcount << ". Value: " << (a->data) << endl;

    int count_left = countLevelsInt(a->left, levelcount);
    int count_right = countLevelsInt(a->right, levelcount);

    return max(count_left, count_right);
}

void preorder ( node* a ) {
    if (a == nullptr)
        return;

    cout << a->data << " ";
    preorder(a->left);
    preorder(a->right);
}
void inorder( node* a ) {
    if (a == nullptr)
        return;

    inorder(a->left);
    cout << a->data << " ";
    inorder(a->right);
}
void postorder ( node* a ) {
    if (a == nullptr)
        return;

    postorder(a->left);
    postorder(a->right);
    cout << a->data << " ";
}

int main()
{
    node* root1 = nullptr;
    insert(root1, 10);
    insert(root1, 11);
    insert(root1, 5);
    insert(root1, 16);
    insert(root1, 12;
    insert(root1, 8);

    //COUNTING LEVELS
    //int answer = countLevelsInt ( root1, 0 );
    //cout << "Answer: " << answer << endl;

    //SHOWING ALL LEVELS
    cout << "Showing preorder: "; preorder(root1); cout << endl;
    cout << "Showing inorder: "; inorder(root1); cout << endl;
    cout << "Showing postorder: "; postorder(root1); cout << endl;
    
    
    
    
    
    inorder(root1);
    postorder( root1 );

}