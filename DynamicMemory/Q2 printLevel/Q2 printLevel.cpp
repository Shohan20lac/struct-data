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
    dllnode** adjlist;
    int nodecount;

    Graph(int n) {
        nodecount = n;
        //cout << "Initializing new Graph instance..." << endl;
        adjlist = new dllnode * [nodecount];

        for (int i = 0; i < nodecount; i++)
        {
            adjlist[i] = nullptr;
        }

        for (int i = 0; i < nodecount; i++)
        {
            insertdllnode(adjlist[i], i);
        }

        //cout << "Initiatialized graph with " << nodecount << " nodes." << endl << endl;
    }
};

void insertEdge(Graph*& g, int sourceindex, int destindex) {
    insertdllnode(g->adjlist[sourceindex], destindex);
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

bool isReachable(Graph* g, int n1, int n2) {

    dllnode* targethead = g->adjlist[n2];
    int targetval = n1;

    
    return findelementDLL(targethead, targetval);
}

//Q2 GLOBAL VARIABLES----------------------------------------------------------------------------
queue <int> currQ;
queue <int> nextQ;

int start = 0;
int vertexcount = 9;
int level = 0;


//Q2 HELPER FUNCTIONS============================================================================
void populateCurrent( Graph* g, dllnode* a ) {
    
    dllnode* current = a->next; // because next level's population starts with head->next nodes.
    while (current != nullptr) {
        currQ.push( current -> data );
        //cout << current->data << " pushed to the top of currQ" << endl;
        current = current->next; 
    }
}
void populateNext( Graph* g, dllnode* a ) {
    
    dllnode* current = a->next; // because next level's population starts with head->next nodes.
    while (current != nullptr) {
        nextQ.push( current -> data );
        //cout << current->data << " pushed to the top of nextQ" << endl;
        current = current->next; 
    }
}
//yes, I could have just written one function and made a queue a parameter. I chose not to.


int* initPrintedArray( ) {
    
    int* printedArray = new int[vertexcount];
    for (int i = 0; i < vertexcount; i++)
    {
        printedArray[i] = 0;
        cout << "index number " << i << "initialized " << endl;
    }
    return printedArray;
}

int* printedArray = initPrintedArray();

bool allPrinted() {
    bool allprinted = false;

    for (int i = 0; i < vertexcount; i++)
    {
        if (printedArray[i] == 1)
            allprinted = true;
        else {
            allprinted = false;
            break;
        }
    }

    return allprinted;
}

int printedcount() {
    int result=0;

    for (int i = 0; i < vertexcount; i++)
    {
        if (printedArray[i] == 1)
            result++;
    }

    return result;
}


void showCurrent(  ) {
    while (!currQ.empty()) {
        int prindex = currQ.front();
        if (printedArray[prindex] == 0) {
            cout << prindex << " " ;
            printedArray[prindex] = 1;
        }
        currQ.pop();

    }
    
}

void clearCurrent() {
    while (!currQ.empty()) {
        cout << "clearing..." << endl;
        currQ.pop();
    }
}

void lookAhead( Graph* g, queue <int> q) {



    while (!q.empty()) {
        int i = q.front();
        populateNext(g, g->adjlist[i]); //populate nextQ with all the nodes connected with g->adjlist[i]
        q.pop();
    }
}

void proceed() {
    
}

void printLevel( Graph* g) {


    dllnode* current = g->adjlist[start];
    populateCurrent(g, current);
    lookAhead(g, currQ);

    cout << "Level 0: " << current->data << endl;
    printedArray[start] = 1;

    while (!allPrinted()) {
        //cout << printedcount() << " nodes have been printed. More to go..." << endl;
        level++;

        cout << "Level " << level << ": "; showCurrent(); cout << endl;

        while (!nextQ.empty()) {
            currQ.push(nextQ.front());
            nextQ.pop();
        }

        lookAhead(g, currQ);
        //cout << nextQ.front();


    }
}



int main() {

    Graph* g = new Graph(vertexcount);

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

    
    printLevel(g);

    


}