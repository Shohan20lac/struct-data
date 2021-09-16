#include <iostream>
#include <queue>

using namespace std;

const int maxsize = 9;
int nodecount = 0;



struct gnode {
    string name;

    gnode ( string s ) {
        name = s;
    }
};

struct Graph {
    int vertexcount;
    gnode** nodes;

    Graph( int n ) {
        vertexcount = n;
        nodes = new gnode * [n];
    }
};


void addVertex( Graph &g, string s )  {
    gnode* newnode = new gnode("A");
    
}





string* kthLevelFriends(Graph* g, int k) {
    
    
    return " ";
}

int main()
{
    //since there are nine nodes in the problem...
    Graph* g = new Graph(maxsize);
    cout << g->nodes[0];
    
}