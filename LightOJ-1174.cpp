#include <bits/stdc++.h>
using namespace std;
#define mem(ara, value) memset(ara, value, sizeof(ara))

 bool visited[101];
 int tim[101];
 int tim2[101];
 int tim3[101];
 vector<int> v[101];
 int end;
 void bfs(int start)
 {
     queue<int> q;
     q.push(start);
     visited[start] = 1;
     while(!q.empty())
     {
         int u = q.front();
         q.pop();
         int len = v[u].size();
         for (int i = 0; i < len; i++)
         {
            if(!visited[v[u][i]])
            {
                tim[v[u][i]] = tim[u] + 1 ;
                q.push(v[u][i]);
                visited[v[u][i]] = 1;
            }
         }
     }
 }

 void bfs2(int start)
 {
     queue<int> q;
     q.push(start);
     visited[start] = 1;
     while(!q.empty())
     {
         int u = q.front();
         q.pop();
         int len = v[u].size();
         for (int i = 0; i < len; i++)
         {
            if(!visited[v[u][i]])
            {
                tim2[v[u][i]] = tim2[u] + 1 ;
                q.push(v[u][i]);
                visited[v[u][i]] = 1;
            }
         }
     }
 }

int main()
{
     int n;
     scanf("%d", &n);
     int j = 1;
     while(n--)
     {
         int a,b,c,d;
         scanf("%d %d", &a,&b);
         for (int i = 0; i < b; i++)
         {
             int x,y;
             cin >> x >> y;
             v[x].push_back(y);
             v[y].push_back(x);
         }
         scanf("%d %d", &c,&d);
         bfs(c);
         mem(visited,0);
         bfs2(d);
         for (int i = 0; i < a; i++)
         {
            tim3[i] = tim[i]+tim2[i];
         }
         printf("Case %d: %d\n",j++,*max_element(tim3,tim3+a));
         for (int k = 0; k <= 101; k++) {
             v[k].clear();
         }
         mem(visited,0);
         mem(tim,0);
         mem(tim2,0);
     }
}
