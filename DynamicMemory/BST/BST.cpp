#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct BinaryTreeNode {
    int data = 0;
    BinaryTreeNode* left = nullptr;
    BinaryTreeNode* right = nullptr;

    BinaryTreeNode(int n) {
        data = n;
    }
};

struct dllBinaryTreeBinaryTreeNode {
    int data = 0;
    dllBinaryTreeBinaryTreeNode* next = nullptr;
    dllBinaryTreeBinaryTreeNode* prev = nullptr;
    
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

void insert (BinaryTreeNode*& a, int x) {
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

void remove(BinaryTreeNode*& a, int x) {
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

void countLevelsVoid (BinaryTreeNode* a, int levelcount) {
    if (a == nullptr) {
        cout << "End of list reached. level count:" << levelcount << ". Returning..." << endl;
        return;
    }

    if (a != nullptr) {
        levelcount++;
        cout << "BinaryTreeNode found at level "<< levelcount <<". Value: "<< (a->data) << endl;

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

int countLevelsInt ( BinaryTreeNode*a , int levelcount ) {
    if (a == nullptr) {
        cout << "End of list reached. level count:" << levelcount << ". Returning..." << endl;
        return levelcount;
    }

    levelcount++;
    cout << "BinaryTreeNode found at level " << levelcount << ". Value: " << (a->data) << endl;

    int count_left = countLevelsInt(a->left, levelcount);
    int count_right = countLevelsInt(a->right, levelcount);

    return max(count_left, count_right);
}

void preorder ( BinaryTreeNode* a ) {
    if (a == nullptr)
        return;

    cout << a->data << " ";
    preorder(a->left);
    preorder(a->right);
}
void inorder( BinaryTreeNode* a ) {
    if (a == nullptr)
        return;

    inorder(a->left);
    cout << a->data << " ";
    inorder(a->right);
}
void postorder ( BinaryTreeNode* a ) {
    if (a == nullptr)
        return;

    postorder(a->left);
    postorder(a->right);
    cout << a->data << " ";
}

void showNthLevel( BinaryTreeNode*a, int n, int i) {

    if (a == nullptr) {     //trivial base case reached
        cout << "Leaf BinaryTreeNode exceeded past level" << i << ". Returning..." << endl;
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



int countleavesintref( BinaryTreeNode*a, int &count) {

    if (a == nullptr) {                                     //trivial base case
        cout << "nullpointer reached. Returning..." << endl << endl;
        return 0;
    }

    cout << "Currently at BinaryTreeNode " << a << " with value " << a->data << endl;

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

int countleavesintval( BinaryTreeNode*a, int count) {

    if (a == nullptr) {                                     //trivial base case
        cout << "nullpointer reached. Returning..." << endl << endl;
        return 0;
    }

    cout << "Currently at BinaryTreeNode " << a << " with value " << a->data << endl;

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

void countleavesvoid(BinaryTreeNode* a, int& count) {
    
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


int findMinIterative( BinaryTreeNode*a) {
    while (a-> left != nullptr)
    {
        a = a->left;
    }
    return a->data;
}

int findMaxIterative( BinaryTreeNode*a) {
    while (a->right != nullptr)
    {
        a = a->right;
    }

    return a->data;
}

int countSiblingPairs( BinaryTreeNode* a, int level, int paircount, int i ) {
    return 0;
}

//prints two BinaryTreeNode values in each line ONLY if they are siblings.
void showSiblingPairs ( BinaryTreeNode* a, int level, int i, int &count, queue <int> &q) {     
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

void sumcousins(BinaryTreeNode* a, int val, int level, int i, int& count, queue <int>& q) {
    //base case 1: "nullptr found at the levelth level. can't go further down. Returning..."
    if (a == nullptr && i == level) {
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
    if (count == 2) {

        if (q.front() != 0 && q.back() != 0) {
            //sibling pairs found! Printing: 

            int front = q.front();
            cout << q.front() << " ";
            q.pop();

            int back = q.front();
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
    sumcousins(a->left, val, level, i + 1, count, q);

    //recursing right...
    sumcousins(a->right, val, level, i + 1, count, q);

    
}

void sumsiblings (BinaryTreeNode* a, int val, int &level, int i, int& count, queue <int>& q) {
    //base case 1: "nullptr found at the levelth level. can't go further down. Returning..."
    if (a == nullptr && i == level) {
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
    if (count == 2) {
        cout << "query is doubly filled! sibling pair?" << endl;
        if (q.front() != 0 && q.back() != 0) {
            //sibling pairs found! Printing: 

            int result = q.front();
            q.pop();

            result += q.front();
            q.pop();

            cout << "printing results" << endl;
            cout << result;
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
    sumsiblings(a->left, val, level, i + 1, count, q);

    //recursing right...
    sumsiblings(a->right, val, level, i + 1, count, q);


}

int sumgen ( BinaryTreeNode* a, int val, int&level, int i, int &gensum ) {
    cout << "\n\n i =" << i << ", level =" << level << endl << endl;
    
    if (level == 0) {   //initial target BinaryTreeNode not found yet
        if (a->data = val)  //initial target found!
        {
            cout << "initial target BinaryTreeNode of value " << a->data << " found at level " << i << endl;
            gensum = gensum + (a->data); cout << "Generation sum set to " << gensum << endl;
            level = i;
            cout << "level set to " << level << endl;
        }



    }
    else {//if initial target BinaryTreeNode has already been found
        if (a == nullptr || i > level ) return 0;
        if (i == level) {
            gensum = gensum + (a->data);
            cout << "Generation sum extended to " << gensum << endl;
        }
    }
    
    cout << sumgen(a->left, val, level, i + 1, gensum);
    cout << sumgen(a->right, val, level, i + 1, gensum);

    return gensum;
}

int returnLevel(BinaryTreeNode* a, int val, int level ) {
    if ( a == nullptr) return 0;

    if (a->data == val) return level;
    else
        return 0;

    int leftreturn = returnLevel(a->left, val , level+1);
    int rightreturn = returnLevel(a->right, val, level+1);

    return (leftreturn + rightreturn);
}

/*
* int sumcousins(BinaryTreeNode* a, int val, int level, int cousinsum, bool levelLock) {
    if (a == nullptr) return 0;

    if (a->data == val) return level;
    else
        return 0;

    int leftreturn = sumcousins(a->left, val, level + 1, cousinsum, levelLock);
    int rightreturn = sumcousins(a->right, val, level + 1, cousinsum, levelLock);

    return (cousinsum);
}
*/

bool foundelement (BinaryTreeNode* a, int val) {
    if (a == nullptr) return false;

    if (a->data == val)
        return true;
    
    if (a->data > val) 
        return foundelement(a->left, val);    // if val < thisBinaryTreeNodeval, that's our cue to go left;
    else
        return foundelement(a->right, val);
}



int distanceTo( BinaryTreeNode*a , int val, int length) {  //returns the distance from root BinaryTreeNode to destination BinaryTreeNodeS
    if (a == nullptr)
        return 0;

    if (a->data == val)
        return length;

    int leftdist = distanceTo(a->left, val, length + 1);
    int rightdist = distanceTo(a->right, val, length + 1);

    return (leftdist + rightdist);
}

int getDistance( BinaryTreeNode* a, int val1, int val2 , int length) {

    if ( !foundelement(a, val1) && !foundelement(a, val2)) {
        cout << "one of the elements is missing! aborting operation..." << endl;
    }

    //base case: target value reached.
    if ( (a->data == val1) ||  (a->data == val2) ) {
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

        int leftdist = distanceTo (a, val1, length);
        int rightdist = distanceTo(a, val2, length);

        return leftdist + rightdist;
    }
}

int countBinaryTreeNodes( BinaryTreeNode* a, int &count ) {

    if (a == nullptr)
        return 0;
    else
        count++;

    int templeft = countBinaryTreeNodes(a->left, count);
    int tempright = countBinaryTreeNodes(a->right, count);
        
    return count;
        
}

void storeNthLevelArray(BinaryTreeNode* a, int*& arr, int n, int i) {

    if (a == nullptr) {     //trivial base case reached
        cout << "null pointer" << i << ". Returning..." << endl;
        return;
    }

    if (i == n) {           //intended base case reached
        cout << "Target level " << i << " reached. Printing: " << (a->data) << endl;
        return;
    }

    //else, keep recursin'.
    storeNthLevelArray(a->left, arr, n, i + 1);
    storeNthLevelArray(a->right, arr, n, i + 1);


}


void populateStackCousins(BinaryTreeNode* a, stack <int>& s, int val, int n, int i, int& stackindex) {


    //if we are at the target level
    if (i == n) {           //intended base case reached
        
        if (a->data == val || a == nullptr) {

        }
        else {
            cout << "Adding level" << i << "node of value <<" << a->data << " to stack..." << endl;
            s.push(a->data);
        }
        return;
    }

    //else, if we are outside the target nth level
    if (a == nullptr) {     //trivial base case reached
        return;
    }

    //else, keep recursin'.
    populateStackCousins(a->left, s, val, n, i + 1, stackindex);
    populateStackCousins(a->right, s, val, n, i + 1, stackindex);
}


int targetindex = 0;
int siblingindex = 0;
bool targetFound = 0;

int getLevel(BinaryTreeNode* a, int val, int i) {
    if (a == nullptr)
        return 0;
    if (a->data == val)
        return i;

    int leftval = getLevel(a->left, val, i + 1);
    int rightval = getLevel(a->right, val, i + 1);

    return (max(leftval, rightval));
}

int sumcousins ( BinaryTreeNode* a, int val, int * &arr, int i, int &count ) {
    
    int level = getLevel(a, i, 1);

    stack <int> s;
    int stackindex = 0;

    populateStackCousins(a, s, level, val, i, stackindex);
    

    
    return 0;
}





int main()
{
    BinaryTreeNode* root1 = nullptr;
    insert(root1, 10);
    insert(root1, 11);
    insert(root1, 5);
    insert(root1, 16);
    insert(root1, 12);
    insert(root1, 8);
    insert(root1, 4);

    int count = 0;
    int val = 10;
    int* arr = new int[7];
    
    cout << sumcousins(root1, val, arr, 1, count);

    cout << arr[0] << endl;
}


    /*
    int level = 0;
    int gensum = 0;
    int i = 1;
    int result = sumgen(root1, 5, level, i, gensum);
    cout << "Result: " << result;
    */

    /*
    //distance between BinaryTreeNodes
    int length = 0;
    cout << getDistance(root1, 8, 11, 0);*/

    /*
    //SHOWING ALL SIBLING PAIRS ON THE NTH LEVEL
    //helper queue
    queue <int> q;

    int level = 3;
    int i = 1;
    int count = 0;
    showSiblingPairs(root1, level, i, count, q);
    
    /*
    //SHOWING ALL BinaryTreeNodeS AT LEVEL n; starting iteration at i=1 
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




