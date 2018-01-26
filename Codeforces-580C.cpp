#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> g[n+1];
    bool visited[n+1];
    int con[n+1];
    memset(visited,0,sizeof(visited));
    memset(con,0,sizeof(con));
    bool cat[n+1];
    for (int i = 1; i <= n; i++) scanf("%d",&cat[i]);
    int x,y;
    for (int i = 0; i < n-1; i++)
    {
      int x,y;
      scanf("%d %d",&x,&y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int ans = 0;
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    con[1] = cat[1];
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      int len = g[u].size();
      for (int i = 0; i < len; i++)
      {
        if(!visited[g[u][i]])
        {
          if(cat[u] && cat[g[u][i]])
            con[g[u][i]] = con[u]+1;
          else if(cat[g[u][i]] && con[u] <= m)
            con[g[u][i]] = 1;
          else if(con[u] > m)
            con[g[u][i]] = m+1;
          else
            con[g[u][i]] = 0;

          q.push(g[u][i]);
          visited[g[u][i]] = 1;
        }
      }
      if(len == 1 && con[u] <= m && u != 1)
        ans++;
    }
    printf("%d\n",ans);
}
