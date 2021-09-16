#include <iostream>
#include <queue>
#include <stack>

using namespace std;

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
        a = newnode;
        a->next = nullptr;
        a->prev = nullptr;
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

        while (current->next != nullptr) {
            current = current->next;
        }
        //last node reached. Adding current node as next...
        current->next = newnode;
        newnode->prev = current;
        return;

    }
}



//GRAPH STRUCT AND FUNCTIONS----------------------------------------------------

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
        }

        for (int i = 0; i < nodecount; i++)
        {
            insertdllnode(arr[i], i);
        }

        //cout << "Initiatialized graph with " << nodecount << " nodes." << endl << endl;
    }
};

void insertEdge(Graph*& g, int sourceindex, int destindex) {
    insertdllnode(g->arr[sourceindex], destindex);
    //cout << "[.] Added an edge from " << sourceindex << " to " << destindex << endl << endl;
}

bool findelementDLL(dllnode* a, int val) {
    cout << "finding element..." << endl;

    if (a == nullptr) {
        cout << "list is empty. Terminating..." << endl;
        return false;
    }

    bool result = false;
    cout << "result set to " << result << endl;

    int i = 0;
    while (a != nullptr) {
        if (a->data == val) {
            result = true;
            break;
        }
        a = a->next;
    }

    return result;
}

//Q2 GLOBAL VARIABLES----------------------------------------------------------------------------
queue <int> currQ;
queue <int> nextQ;

int start = 0;
int vertexcount = 9;
int level = 0;

int* initPrintedArray() {

    int* printedArray = new int[vertexcount];
    for (int i = 0; i < vertexcount; i++)
    {
        printedArray[i] = 0;
        cout << "index number " << i << "initialized " << endl;
    }
    return printedArray;
}

int* printedArray = initPrintedArray();

bool nonePrinted(){
    bool result = true;

    for (int i = 0; i < vertexcount ; i++)
    {
        if (printedArray[i] == 1)
            result = false;
    }

    return result;
}

bool allPrinted( ) {
    bool result = true;

    for (int i = 0; i < vertexcount; i++)
    {
        if (printedArray[i] != 1)
            result = false;
    }

    return result;
}

void showCurrentLevel( queue <int> &q ) {  //given a queue of neighbors, prints all the values from it without changing the queue.
    while (!q.empty()) {
        if (printedArray[q.front()] == 0) {
            cout << q.front() << " ";
            printedArray[(q.front())] = 1;
        }
        else {
            cout << " X " << " ";
        }
        
        q.pop();
    }
}

queue <int> meetNeighbors( dllnode* a ) {
    queue <int> neighborsQ;

    while (a != nullptr) {
        neighborsQ.push(a->data);
        cout << "Met neighbor " << a->data << endl;
        a = a->next;
    }
    
    return neighborsQ;
}

queue <int> scanOutsidersDLL (Graph* g, dllnode* a) {
    queue <int> outsidersQ;
    cout << "Scanning for nodes outside node " << a->data << "'s level..." << endl;

    while (a != nullptr) {

        dllnode* current = g->arr[a->data]->next;

        while (current!=nullptr)
        {
            outsidersQ.push( current->data);
            cout << "Found outsider " << current->data << endl;
            current = current->next;
        }

        a = a->next;
    }

    return outsidersQ;
}

queue <int> scanOutsidersQ (Graph* g, queue <int> neighbors ) {
    queue <int> outsidersQ;
    //cout << "Scanning for nodes outside node " << neighbors.front() << "'s level..." << endl;

    while (!neighbors.empty()) {

        dllnode* current = g->arr[neighbors.front()]->next;

        while (current != nullptr)
        {
            outsidersQ.push(current->data);
            cout << "Found outsider " << current->data << endl;
            current = current->next;
        }

        neighbors.pop();

    }

    return outsidersQ;
}




queue <int> moveAhead( queue <int> &nextQ ) {
    queue <int> newneighbors;

    while (!nextQ.empty()) {
        if (printedArray[nextQ.front()] == 0) {
            newneighbors.push(nextQ.front());
        }
        nextQ.pop();
    }
    return newneighbors;
}

void printLevels(Graph* g, int startnode, int level) {
    
    cout << "\nstartnode: " << startnode << endl;

    if (nonePrinted()) {    //that means we just got here. Time to set up the base case
        cout << "Level " << level << ":" << startnode << endl;
        printedArray[startnode] = 1;
    }

    dllnode* neighbor = g->arr[startnode];
    queue <int> neighbors = meetNeighbors( neighbor->next);
    
    

    queue <int> nextQ = scanOutsidersDLL(g, neighbor->next);

    cout << "Level " << ++level << ": ";
    showCurrentLevel(neighbors); cout << endl << endl;


    while (!allPrinted()) {
        neighbors = moveAhead(nextQ); //-> 3 6 5
        nextQ = scanOutsidersQ(g, neighbors); // -> 2 5 8 3
        cout << "Level " << ++level << ": "; showCurrentLevel(neighbors); cout << endl << endl;
    }
    
}



int main() {

    
    Graph* g = new Graph(vertexcount);

    /*
    insertEdge(g, 0, 3);
    insertEdge(g, 0, 2);

    insertEdge(g, 1, 2);
    insertEdge(g, 1, 0);
    
    insertEdge(g, 2, 0);
    insertEdge(g, 2, 3);
    
    insertEdge(g, 3, 1);
    insertEdge(g, 3, 4);

    insertEdge(g, 4, 4);
    */



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
    
    //setting up graph according to hw6 example...

    //int level = 0;
    printLevels(g, 0, level);

    //queue <int> next = populateNext(g->arr[0]);
    
    //printLevel(g, 0);




}