#include <iostream>
using namespace std;

/*
    邻接矩阵
*/

#define inf -1

class Graph {
    public:
        int vertices;
        int** edges;

        Graph(int v);

        ~Graph();

        void addEdge(int u, int v, int w);
        void printGraph();
};

Graph::Graph(int v) {
    vertices = v;
    edges = new int*[vertices];
    for(int i = 0; i < vertices; i++) {
        edges[i] = new int[vertices];
        for(int j = 0; j < vertices; j++) {
            edges[i][j] = inf;
        }
    }
} 

Graph::~Graph() {
    for (int i = 0; i < vertices; i++) {
        delete edges[i];
    }
    delete edges;
}

void Graph::addEdge(int u, int v, int w) {
    edges[u][v] = w;
}

void Graph::printGraph() {
    for(int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << edges[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
} 

int main() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(4, 1, 11);
    g.addEdge(3, 2, 88);

    g.printGraph();
    return 0;
}