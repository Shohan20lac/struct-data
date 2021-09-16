
#include <iostream>
#include <queue>
using namespace std;

//graph has 9 nodes 0 to 8
const int maxsize = 9;

int* initPrintedArray() {

    int* printedArray = new int[maxsize];
    for (int i = 0; i < maxsize; i++)
    {
        printedArray[i] = 0;
        cout << "index number " << i << "initialized " << endl;
    }
    return printedArray;
}

int* printedArray = initPrintedArray();


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

void showQueue(queue <int> q) {
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

void dfs(Graph* g, int startnode) {

    if (printedArray[startnode] == 1)
        return;

    else {
        cout << startnode << " ";
        printedArray[startnode] = 1;
    }

    dllnode* neighbor = g->arr[startnode]->next;

    while (neighbor != nullptr)
    {
        dfs(g, neighbor->data);
        neighbor = neighbor->next;
    }

}

void printPath( Graph* g, int current, int final, queue <int> path ) {

    if (printedArray[(current)] == 1)
        return;

    if (current == final) {
        showQueue(path); cout << final << endl;
        return;
    }
    
    printedArray[(current)] = 1;
    path.push(current);
    
    dllnode* neighbor = g->arr[current]->next;  
    // selects the first neighbor of the current-th adjacency list of the graph

    while ( neighbor!=nullptr )
    {
        printPath(g, neighbor->data, final, path);
        neighbor = neighbor->next;
        
        printedArray[current] = false;
    }

}

int main()
{
    Graph* g = new Graph(maxsize);

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

    queue <int> path;
    printPath(g, 0, 4, path );
}