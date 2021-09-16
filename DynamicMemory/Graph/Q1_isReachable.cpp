#include <iostream>
using namespace std;



//DOUBLY LINKED LIST STRUCT AND FUNCTIONS---------------------------------------
struct dllnode {
    int data;
    dllnode* prev;
    dllnode* next;
};

void insertdllnode(dllnode*& a, int val) {

    dllnode* newnode = new dllnode;
    newnode->data = val;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    dllnode* current = a;

    if (a == nullptr) {
        //cout << "List is empty. Adding new head..." << endl;
        a = newnode;
        a->next = nullptr;
        a->prev = nullptr;
        //cout << "Node with value" << val << " inserted into front of linked list." << endl;
        return;
    }

    if (a->next == nullptr) {
        //last element reached. Adding node as next...
        a->next = newnode;
        newnode->prev = a;
        return;
    }

    else {
        // this node is neither null nor the last node. So...iterate all the way to the end.
        //cout << "List has more than one elements. Traversing to end..." << endl;

        while (current->next != nullptr) {
            current = current->next;
        }
        //last node reached. Adding current node as next...
        current->next = newnode;
        newnode->prev = current;
        return;
        
    }
}

bool findelementDLL(dllnode* a, int val) {
    //cout << "finding element..." << endl;
    
    if (a == nullptr) {
        //cout << "list is empty. Terminating..." << endl;
        return false;
    }

    bool result = false;
    cout << "result set to " << result << endl;

    int i = 0;
    while (a != nullptr) {
        if (a->data == val) {
            //cout << "Target element found! Stopping search..." << endl;
            result = true;
            break;
        }
        a = a->next;
    }

    return result;
}



//GRAPH STRUCT AND FUNCTIONS----------------------------------------------------

int vertexcount = 9;
int* visitedArray = new int[vertexcount];
void resetVisitedArray() {
    for (int i = 0; i < vertexcount; i++)
    {
        visitedArray[i] = 0;
    }
}

struct Graph {
    dllnode** arr;
    int nodecount;

    Graph(int n) {
        nodecount = n;
        //cout << "Initializing new Graph instance..." << endl;
        arr = new dllnode * [nodecount];

        for (int i = 0; i < nodecount; i++)
        {
            arr[i] = nullptr;
            //cout << "index " << i << " set to null pointer." << endl;
        }

        for (int i = 0; i < nodecount; i++)
        {
            insertdllnode(arr[i], i);
            //cout << "Node number " << i << " initialized. Where the edges at?" << endl << endl;
        }
    }
};


void insertEdge(Graph* &g, int sourceindex, int destindex) {
    insertdllnode ( g->arr[sourceindex] , destindex );
    //cout << "[.] Added an edge from " << sourceindex << " to " << destindex << endl << endl;
}


void dfs(Graph* g, int startnode) {
    
    if (visitedArray[startnode] == 1)
        return;
    
    else {
        cout << startnode << " ";
        visitedArray[startnode] = 1;
    }
    
     dllnode* neighbor = g->arr[startnode]->next;
     
     while (neighbor!=nullptr)
     {
         dfs(g, neighbor->data);
         neighbor = neighbor->next;
     }

}

void isReachableHelper (Graph* g, int startnode, int targetval, bool &isReachable) {

    cout << "\nstartnode: " << startnode << endl;
    cout << "Visited startnode? :" << visitedArray[startnode] << endl;
    
    if ( visitedArray[startnode] == 1 ) {
        cout << "already visited this node. returning..." << endl;
        return;
    }

    else {
        //cout << startnode << " ";
        visitedArray[startnode] = 1;
    }

    if (startnode == targetval) {
        cout << "destination reached! Returning..." << endl;
        isReachable = true;
        return;
    }

    dllnode* neighbor = g->arr[startnode]->next;
    cout << "neighbor: " << neighbor->data << endl;
    if (neighbor->data == targetval) {
        isReachable = 1;
        return;
    }
        

    while (neighbor != nullptr)
    {

        isReachableHelper(g, neighbor->data, targetval, isReachable);
        neighbor = neighbor->next;
    }
}

bool isReachable (Graph* g, int startnode , int targetval ) {

    bool result = false;
    //cout << "result: " << result << endl;
    isReachableHelper(g, startnode, targetval, result);
    return result;
}

int main()
{
    //vertext count is globally = 6
    Graph* g = new Graph(vertexcount);
    resetVisitedArray();
    
    /*
    //setting up aeccording to simple example:
    insertEdge(g, 0, 1);
    insertEdge(g, 0, 2);
    insertEdge(g, 1, 2);
    insertEdge(g, 2, 3);
    insertEdge(g, 3, 1);
    insertEdge(g, 3, 5);
    insertEdge(g, 5, 0);
    insertEdge(g, 5, 4);
    insertEdge(g, 5, 2);

    //cout << visitedArray[0] << endl;
    cout << "dfs print: ";  dfs(g, 0); cout << endl;
    resetVisitedArray();
    
    cout << isReachable(g, 0, 5) << endl; //-> 1
    //cout << isReachable(g, 0, 4) << endl; //-> 0 

    */

    
    //setting up graph according to hw6 example...
    
    
    insertEdge(g, 0, 1);
    insertEdge(g, 0, 8);
    insertEdge(g, 0, 7);
    
    insertEdge(g, 1, 8);

    insertEdge(g, 2, 4);
    insertEdge(g, 2, 8);

    insertEdge(g, 3, 2);

    insertEdge(g, 5, 8);
    insertEdge(g, 5, 3);

    insertEdge(g, 6, 5);

    insertEdge(g, 7, 6);
    insertEdge(g, 7, 5);

    insertEdge(g, 8, 3);
    

    cout << "dfs print: ";  dfs(g, 0); cout << endl;
    resetVisitedArray();

    cout << isReachable(g, 1, 8) << endl;
    

}