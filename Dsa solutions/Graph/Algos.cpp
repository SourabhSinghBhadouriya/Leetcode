#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int v, w;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addEdge(vector<vector<Edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

//  O(2E) == O(E)
void display(vector<vector<Edge>> &graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << (i + " -> ");
        for (Edge e : graph[i])
        {
            cout  << " ("<< e.v <<","<< e.w << ")";
        }
        cout << endl;
    }
}
    vector<int> par, size;

    int findPar(int u) {
        return par[u] == u ? u : (par[u] = findPar(par[u]));
    }

    void merge(int p1, int p2) {
        if (size[p1] < size[p2]) {
            par[p1] = p2;
            size[p2] += size[p1];
        } else {
            par[p2] = p1;
            size[p1] += size[p2];
        }
    }

    // {{u,v,w}}
    void unionFind(vector<vector<int>> Edges, int N) {
        vector<vector<Edge>> graph(N, vector<Edge>());
        for (int i = 0; i < N; i++) {
            par[i] = i;
            size[i] = 1;
        }

        for (vector<int> &e : Edges) {
            int u = e[0], v = e[1], w = e[2];
            int p1 = findPar(u);
            int p2 = findPar(v);
            if (p1 != p2) {
                merge(p1, p2);
                addEdge(graph, u, v, w);
            }
        }
    }

    // kruskalAlgo
    void kruskalAlgo(vector<vector<int>> &edges, int N) {
        // {{u,v,w}}
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
        unionFind(edges, N);
    }
