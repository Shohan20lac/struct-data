#include <iostream>
using namespace std;

struct Graph {
    
    int adjmat[4][4];

    Graph() {

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                adjmat[i][j] = 0;
    }    
};


void addEdgeAdjMat( Graph * &g, int source, int dest) {
    g->adjmat[source][dest] = 1;
}

int main()
{
    Graph* g = new Graph;
   
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

    cout << g->adjmat [8][3];

    cout << "hi";

    return 0;
}