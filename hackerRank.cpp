#include <bits/stdc++.h>

using namespace std;
void dfs(int s,bool visited[],vector<int>adj[])
{
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
            dfs(adj[s][i],visited,adj);
    }
}
void intialize(bool visited[],int n)
{
    for(int i=0;i<n+1;i++)
        visited[i]=false;
}
int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        long x;
        long y;
        cin >> n >> m >> x >> y;

        vector<int>adj[n+1];
        bool visited[n+1];
        long connectedcomponents=0;

        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            adj[city_2].push_back(city_1);
            adj[city_1].push_back(city_2);
        }
     if(y>=x)
            cout<<n*x<<endl;
        else
        {
        intialize(visited,n);
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
             dfs(i,visited,adj);
             ++connectedcomponents;
             }
        }
        cout<<y*(n-connectedcomponents)+x*connectedcomponents<<endl;
      }
    }
    return 0;
}
