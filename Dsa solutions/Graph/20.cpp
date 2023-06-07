#include<bits/stdc++.h>
using namespace std;

// 210 Course Schedule II

vector<int> findOrder(int N, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(N);
    vector<int> indegree(N, 0);

    for (vector<int> &ar : prerequisites)
    {
        graph[ar[1]].push_back(ar[0]);
        indegree[ar[0]]++;
    }

    queue<int> que;
    for (int i = 0; i < N; i++)
        if (indegree[i] == 0)
            que.push(i);

    vector<int> ans;
    while (que.size() != 0)
    {
        int vtx = que.front();
        que.pop();
        ans.push_back(vtx);
        for (int v : graph[vtx])
        {
            if (--indegree[v] == 0)
                que.push(v);
        }
    }

    if (ans.size() != N)
        ans.clear();

    return ans;
}

// 210 Course Schedule II
vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(N);
        vector<int> indegree(N,0);
        for(vector<int> &ar : prerequisites){
            graph[ar[0]].push_back(ar[1]);
            indegree[ar[1]]++;
        }
        queue<int> que;
        vector<int> ans;
        for(int i=0;i<N;i++){
            if(indegree[i] == 0)
               que.push(i);
        }
        while(!que.empty()){
            int vtx = que.front();
            que.pop();
            ans.push_back(vtx);
            for(int v : graph[vtx]){
                if(--indegree[v] == 0){
                    que.push(v);
                }
            }
        }
        if(ans.size() != N)ans.clear();
        reverse(ans.begin(),ans.end());
        return ans;
    }