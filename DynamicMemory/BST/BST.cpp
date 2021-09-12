#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data = 0;
    node* left = nullptr;
    node* right = nullptr;

    node(int n) {
        data = n;
    }
};

struct dllnode {
    int data = 0;
    dllnode* next = nullptr;
    dllnode* prev = nullptr;
    
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

void showNthLevel( node*a, int n, int i) {

    if (a == nullptr) {     //trivial base case reached
        cout << "Leaf node exceeded past level" << i << ". Returning..." << endl;
        return;
    }

    if ( i==n ) {           //intended base case reached
        cout << "Target level " << i << " reached. Printing: " << (a->data) << endl;
        return;
    }

    //else, keep recursin'.
    showNthLevel(a->left, n, i+1);
    showNthLevel(a->right, n, i+1);
}

int countleavesintref( node*a, int &count) {

    if (a == nullptr) {                                     //trivial base case
        cout << "nullpointer reached. Returning..." << endl << endl;
        return 0;
    }

    cout << "Currently at node " << a << " with value " << a->data << endl;

    if ( a->left==nullptr  &&  a->right == nullptr ) {      //target base case 
        count++;
        cout << "Found leaf with value " << a->data << ". Leafcount increased to " << count << endl;
        return count;
    }

    countleavesintref(a->left, count);
    countleavesintref(a->right, count);

    return count;

    /*
    return (
        countleavesintref(a->left, count)
        +
        countleavesintref(a->right, count)
    );            
    */
}

int countleavesintval( node*a, int count) {

    if (a == nullptr) {                                     //trivial base case
        cout << "nullpointer reached. Returning..." << endl << endl;
        return 0;
    }

    cout << "Currently at node " << a << " with value " << a->data << endl;

    if ( a->left==nullptr  &&  a->right == nullptr ) {      //target base case 
        count++;
        cout << "Found leaf with value " << a->data << ". Leafcount increased to " << count << endl;
        return count;
    }

    return (
        countleavesintval(a->left, count)
        +
        countleavesintval(a->right, count)
    );  
}

void countleavesvoid(node* a, int& count) {
    
    if (a == nullptr) {                                     //trivial base case
        cout << "nullpointer reached. Returning..." << endl;
        return;
    }

    if ( a->left == nullptr  &&  a->right == nullptr ) {    //intended base case
        count++;
        cout << "Leaf reached. Increased leafcount to " << count << endl;

        return;
    }

    countleavesvoid(a->left, count);
        
    countleavesvoid(a->right, count);
}


int findMinIterative( node*a) {
    while (a-> left != nullptr)
    {
        a = a->left;
    }
    return a->data;
}

int findMaxIterative( node*a) {
    while (a->right != nullptr)
    {
        a = a->right;
    }
    return a->data;
}

int countSiblingPairs( node* a, int level, int paircount, int i ) {
    return 0;
}

//prints two node values in each line ONLY if they are siblings.
void showSiblingPairs ( node* a, int level, int i, int &count, queue <int> &q) {     
    //base case 1: "nullptr found at the levelth level. can't go further down. Returning..."
    if (a == nullptr && i== level) {            
        count++;
        q.push(0);
        return;
    }
    //base case 2: one child found at the levelth level. won't go further down. Returning..."
    if (i == level) {                           
        count++;
        q.push(a->data);
        return;
    }
    //case 3: queue is doubly-filled. Does it contain a sibling pair?
    if ( count == 2 ) {     
        
        if ( q.front()!= 0  &&  q.back()!= 0 ) {
            //sibling pairs found! Printing: 

            cout << q.front() << " ";
            q.pop();

            cout << q.front() << " ";
            q.pop();

            cout << endl;
        }
        else {
            //this is not a sibling pair. Moving on...
            q.pop();
            q.pop();

        }
        //resetting queue member count for retasking...
        count -= 2;
    }

    //recursing left...
    showSiblingPairs(a->left, level, i + 1, count, q);
    
    //recursing right...
    showSiblingPairs(a->right, level, i + 1, count, q);
}


int main()
{
    node* root1 = nullptr;
    insert(root1, 10);
    insert(root1, 11);
    insert(root1, 5);
    insert(root1, 16);
    insert(root1, 12);
    insert(root1, 8);
    insert(root1, 4);
    
    //SHOWING ALL SIBLING PAIRS ON THE NTH LEVEL
    //helper queue
    queue <int> q;

    int level = 3;
    int i = 1;
    int count = 0;
    showSiblingPairs(root1, level, i, count, q);
    
    /*
    //SHOWING ALL NODES AT LEVEL n; starting iteration at i=1 
    int n = 2;
    int i = 1;
    showNthLevel(root1, n, i);
    */

    //COUNTING LEVELS
    //int answer = countLevelsInt ( root1, 0 );
    //cout << "Answer: " << answer << endl;

    /*
    //SHOWING ALL LEVELS
    cout << "Showing preorder: "; preorder(root1); cout << endl;
    cout << "Showing inorder: "; inorder(root1); cout << endl;
    cout << "Showing postorder: "; postorder(root1); cout << endl;
    */

    /*
    int count = 0;
    count = countleaves(root1, count);
    cout << count;
    */


    /*
    //COUNTING LEAVES
    int count = 0;
    cout << countleavesintref(root1, count);
    */

    /*
    //finding max and min value
    cout << findMinIterative(root1);
    cout << findMaxIterative(root1);
    */
    //int arr[8];




}