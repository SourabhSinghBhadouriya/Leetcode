// 785. Is Graph Bipartite?

    bool bipartite(vector<vector<int>>& graph, int src, vector<int> &vis) {
        queue<int> que;
        que.push(src);

        // No Color : -1 , Red : 0, Green : 1
        int color = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size-- ) {
                int rvtx = que.front();
                que.pop();
                if (vis[rvtx] != -1) {
                    if (color != vis[rvtx]) // conflict
                        return false;
                    continue;
                }

                vis[rvtx] = color;
                for (int v : graph[rvtx]) {
                    if (vis[v] == -1) {
                        que.push(v);
                    }
                }
            }

            color = (color + 1) % 2;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1 && !bipartite(graph, i, vis))
                return false;
        }

        return true;
    }
