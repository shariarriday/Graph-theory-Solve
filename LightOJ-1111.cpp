#include <bits/stdc++.h>
using namespace std;
#define mem(ara, value) memset(ara, value, sizeof(ara))

 bool visited[1001];
 int tim[1001];
 vector<int> v[1001];

 void dfs(int start)
 {
     visited[start] = 1;
     int len = v[start].size();
     for (int i = 0; i < len; i++)
     {
        if(!visited[v[start][i]])
        {
            tim[v[start][i]]++;
            dfs(v[start][i]);
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
         int a, b,c;
         scanf("%d %d %d", &a,&b,&c);
         int n[a];
         for (int i = 0; i < a; i++)
         {
             cin >> n[i];
         }
         for (int i = 0; i < c; i++)
         {
             int x,y;
             cin >> x >> y;
             v[x].push_back(y);
         }
         int ans = 0;
         for (int i = 0; i < a; i++)
         {
             mem(visited,0);
             tim[n[i]]++;
             dfs(n[i]);
         }
         for (int i = 1; i <= b; i++)
         {
             if(tim[i] == a)
                ans++;
         }
         printf("Case %d: %d\n",j++,ans);
         for (int k = 0; k <= 1001; k++) {
             v[k].clear();
         }
         mem(tim,0);
     }
}
