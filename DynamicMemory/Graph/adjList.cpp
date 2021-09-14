#include <iostream>
using namespace std;


//DOUBLY LINKED LIST STRUCT AND FUNCTIONS---------------------------------------
struct dllnode {
    int data;
    dllnode* prev;
    dllnode* next;
};

void insertdllnode(dllnode*& a, int val) {

    if (a == nullptr) {
        a = new dllnode;
        a->data = val;
        a->next = nullptr;
        a->prev = nullptr;
        cout << "Node with value" << val << " inserted into front of linked list." << endl;
        return;
    }

    //else if list has at least one node...
    dllnode* current = a;
    current = a->next;
    current->data = val;
    current->prev = a;
    current->next = nullptr;
}

bool findelementDLL(dllnode* a, int val) {
    if (a == nullptr) {
        cout << "list is empty. Terminating..." << endl;
        return false;
    }

    bool result = false;

    while (a != nullptr) {
        if (a->data == val) {
            cout << "Target element found! Stopping search..." << endl;
            result = true;
            break;
        }
    }

    return result;
}



//GRAPH STRUCT AND FUNCTIONS----------------------------------------------------

struct Graph {
    dllnode** arr;
    int nodecount;

    Graph(int n) {
        nodecount = n;
        cout << "Initializing new Graph instance..." << endl;
        arr = new dllnode * [nodecount];

        for (int i = 0; i < nodecount; i++)
        {
            arr[i] = nullptr;
            cout << "index " << i << " set to null pointer." << endl;
        }

        for (int i = 0; i < nodecount; i++)
        {
            insertdllnode(arr[i], i);
            cout << "Node number " << i << " initialized. Where the edges at?" << endl;
        }
    }
};


void insertEdge(Graph* g, int sourceindex, int destindex) {
    insertdllnode ( g->arr[sourceindex] , destindex );
}

bool isReachable(Graph* g, int n2, int n1) {
    return findelementDLL(g->arr[n2], n1);
}

int main()
{
    int nodecount = 10;
    Graph* g = new Graph(nodecount);

    insertEdge(g, 0, 1);


}