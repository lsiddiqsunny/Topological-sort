
#include<bits/stdc++.h>
using namespace std;
#define mx 200005

vector<int>g[mx];
int visited[mx];
vector<int>s;
void dfs(int u)
{
    visited[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(visited[v]==0) dfs(v);
    }
    s.push_back(u);
}
int main()
{
    int n;
    cin>>n; //number of vertex

    int m;
    cin>>m; //number of edges
    while(m--)
    {
        int u,v;
        cin>>u>>v;

        g[u].push_back(v); //making one directional graph

    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0) dfs(i);
    }

    for(int i=0; i<n; i++)
    {

        cout<<s[i]<<" ";

    }
    cout<<endl;

}
