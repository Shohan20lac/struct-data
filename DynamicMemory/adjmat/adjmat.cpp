#include <iostream>
using namespace std;

int vertexcount = 9;
int* visitedArray = new int[vertexcount];


struct Graph {
    
    int adjmat[9][9];

    Graph() {

        for (int i = 0; i < vertexcount; i++)
            for (int j = 0; j < vertexcount; j++)
                adjmat[i][j] = 0;
    }    
};

void initVisited() {
    for (int k = 0; k < vertexcount; k++)
    {
        for (int l = 0; l < vertexcount; l++)
        {
            visitedArray[k]= 0;
        }
    }
}

void resetVisited () {
    for (int k = 0; k < vertexcount; k++)
    {
        for (int l = 0; l < vertexcount; l++)
        {
            visitedArray[k] = 0;
        }
    }
}

void addEdgeAdjMat( Graph * &g, int source, int dest) {
    g->adjmat[source][dest] = 1;
}

void showAdjMat( Graph *g ) {
    for (int i = 0; i < vertexcount; i++)
    {
        for (int j = 0; j < vertexcount; j++)
        {
            cout << g->adjmat[i][j] << " ";
        }
        cout << endl;
    }
}

bool isReachable( Graph* g, int n1, int n2 ) {      //tests whether n1 is reachable from n2.
    return false;
}


void showPaths() {

    

}

int main()
{
    Graph* g = new Graph;

    initVisited();
   
    addEdgeAdjMat(g, 0, 1);
    addEdgeAdjMat(g, 0, 8);
    addEdgeAdjMat(g, 0, 7);

    addEdgeAdjMat(g, 1, 8);

    addEdgeAdjMat(g, 2, 4);
    addEdgeAdjMat(g, 2, 8);

    addEdgeAdjMat(g, 3, 2);

    addEdgeAdjMat(g, 5, 8); 
    addEdgeAdjMat(g, 5, 3);

    addEdgeAdjMat(g, 6, 5);

    addEdgeAdjMat(g, 7, 6);
    addEdgeAdjMat(g, 7, 5);

    addEdgeAdjMat(g, 8, 3);

    showAdjMat(g);

    return 0;
}