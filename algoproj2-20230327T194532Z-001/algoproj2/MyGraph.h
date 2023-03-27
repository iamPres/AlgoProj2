//
// Created by Cole Cokins on 3/26/23.
//

#include <ostream>
#include <map>
#include <vector>

using namespace std;

#ifndef ALGOPROJ2_MYGRAPH_H
#define ALGOPROJ2_MYGRAPH_H

class MyGraph
{
private:
    int nodeCount = 0;
    pair<vector<int>, float>** adjMatrix;

public:
    MyGraph();
    explicit MyGraph(int n);
    MyGraph(const MyGraph &g);
    ~MyGraph();

    template<typename T>
    static T** create2DArray(unsigned nrows, unsigned ncols)
    {
        T **ptr = nullptr;
        T *pool = nullptr;
        ptr = new T *[nrows];             // allocate pointers (can throw here)
        pool = new T[nrows * ncols]{T()}; // allocate pool (can throw here)
         for (unsigned i = 0; i < nrows; ++i, pool += ncols) {
             ptr[i] = pool;
         }
         return ptr;
    }

    template<typename T>
    static void delete2DArray(T** array) {
        delete[] array[0]; // remove the pool
        delete[] array;    // remove the pointers
    }

    void buildAdjMatrix(int n);
    float prim(int, int);
    bool AddEdge(int i, int j, float p);
    void output(ostream &os);
    pair<vector<int>, float> HW2Prog(int s, int t, bool printMST);
};

#endif // ALGOPROJ2_MYGRAPH_H
