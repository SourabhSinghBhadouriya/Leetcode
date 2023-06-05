//207 Course Schedule

bool canFinish(int N, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(N);
    vector<int> indegree(N, 0);

    for (vector<int> &ar : prerequisites)
    {
        graph[ar[0]].push_back(ar[1]);
        indegree[ar[1]]++;
    }

    queue<int> que;
    for (int i = 0; i < N; i++){
        if (indegree[i] == 0)
            que.push(i);
    }

    int vtxCount = 0;
    while (!que.empty())
    {
        int vtx = que.front();
        que.pop();
        vtxCount++;
        for (int v : graph[vtx])
        {
            if (--indegree[v] == 0)
                que.push(v);
        }
    }

    return vtxCount == N;
}
