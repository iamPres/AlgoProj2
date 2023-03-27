//
// Created by Cole Cokins on 3/26/23.
//

#include "MyGraph.h"
#include <fstream>
#include "ostream"
#include <map>
#include "vector"
#include <limits>
#include <iostream>
#include <queue>

using namespace std;

void MyGraph::buildAdjMatrix(int n)
{
    this->nodeCount = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            this->adjMatrix[i][j] = pair<vector<int>, float>(vector<int>(), 0); // initialize all entries to 0
        }
    }
}

MyGraph::MyGraph() = default;

MyGraph::MyGraph(int n)
{
    this->adjMatrix = create2DArray<pair<vector<int>, float>>(n, n);
    this->nodeCount = n;
    this->buildAdjMatrix(n);
}

MyGraph::MyGraph(const MyGraph &g)
{
    for (int i = 0; i < this->nodeCount; i++) {
        for (int j = 0; j < this->nodeCount; j++) {
            this->adjMatrix[i][j] = g.adjMatrix[i][j];
        }
    }
}

MyGraph::~MyGraph() {
    delete2DArray(this->adjMatrix);
}

bool MyGraph::AddEdge(int i, int j, float p)
{
    float* matval = &adjMatrix[i][j].second;
    if (*matval == 0) {
        *(matval) = p;
        adjMatrix[j][i].second = p;
    }
}

void MyGraph::output(ostream &os)
{
    os << this->nodeCount << endl;
    for (int i = 0; i < this->nodeCount; i++) {
        for (int j = 0; j < this->nodeCount; j++) {
            float matval = this->adjMatrix[i][j].second;
            if (matval > 0) {
                int firstTerm = i;
                int secondTerm = j;
                if (i > j) {
                    firstTerm = j;
                    secondTerm = i;
                }
                os << firstTerm << " " << secondTerm << " " << matval << endl;
            }
         }
    }
    os << endl;
}

float MyGraph::prim(int start, int n) {
    float dist[n];
    bool visited[this->nodeCount];
    int parent[this->nodeCount];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] > dist[u])) {
                u = j;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            auto currentItem = this->adjMatrix[u][v];
            float currentVal = this->adjMatrix[u][v].second;
            if (currentVal > 0 && !visited[v] && currentVal > dist[v]) {
                parent[v] = u;

                cout << u << " " << v << " " << dist[v] << endl;
            }
        }
    }

    return sum;
}

pair<vector<int>, float> MyGraph::HW2Prog(int s, int t, bool printMST) {
    if (printMST) {
        this->output(cout);
    }

    float sum = this->prim(0, this->nodeCount); // start from node 0
    cout << "Sum: " << sum << endl;
    pair<vector<int>, float> pathWeights;
    return pathWeights;
}
