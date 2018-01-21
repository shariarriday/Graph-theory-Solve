#include <bits/stdc++.h>
using namespace std;
#define mem(ara, value) memset(ara, value, sizeof(ara))

 bool visited[301];
 int col[301];
 vector<int> v[301];
 int bfs(int source)
 {
     mem(col, -1);
     mem(visited, 0);
     queue<int>Q;
     Q.push(source);
     visited[source] = true;
     col[source] = 1;
     while(!Q.empty())
     {
         int u = Q.front();
         Q.pop();
         int len = v[u].size();
         for(int j = 0 ; j < len ; j++)
         {
             if(col[u] == col[v[u][j]])
                 return 0;

             if(col[u] != col[v[u][j]] && !visited[v[u][j]])
             {
                if(col[u] == 1)
                    col[v[u][j]] = 2;
                else
                    col[v[u][j]] = 1;
                visited[v[u][j]] = true;
                Q.push(v[u][j]);
             }
         }
     }
     return 1;
 }

int main()
{

     int n;
     while(scanf("%d", &n) && n)
     {
         int a, b;
         while(scanf("%d %d", &a,&b) && a && b)
         {
             v[a].push_back(b);
             v[b].push_back(a);
         }
         int ans = bfs(1);
         if(ans == 0)
         printf("NO\n");
         else
         printf("YES\n");
         for (int k = 0; k <= n; k++) {
             v[k].clear();
         }
     }
}
