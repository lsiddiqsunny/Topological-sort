/*problem link: http://codeforces.com/contest/825/problem/E */
#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int now[mx];
vector<int>g[mx],rg[mx],comp;
long long cost[mx];
int visited[mx];
vector<int>s;
int t=0;
vector<int>ans;
int indegree[mx];

void dfs1(int u)
{
    visited[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(visited[v]==0) dfs1(v);
    }
    s.push_back(u);
}
void dfs2(int u)
{
    if(now[u]==0)
    {
        t++;

        now[u]=t;
    }
    // visited[u]=1;
    for(int i=0; i<rg[u].size(); i++)
    {
        int v=rg[u][i];
        dfs2(v);
    }

}
int main()
{
    int n;
    cin>>n;

    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        indegree[u]++;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    priority_queue<int, vector<int>, less<int> >q;
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    t=n;
    for(int j=1; j<=n; j++)
    {
        int u=q.top();

        q.pop();
        ans.push_back(u);
        now[u]=t;
        t--;
        for(int i=0; i<rg[u].size(); i++)
        {
            indegree[rg[u][i]]--;
            if(indegree[rg[u][i]]==0)
            {
                q.push(rg[u][i]);
            }
        }
    }




    for(int i=1; i<=n; i++)
    {
        cout<<now[i]<<" ";
    }
}
