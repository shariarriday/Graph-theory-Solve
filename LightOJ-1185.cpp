#include <bits/stdc++.h>
using namespace std;
#define mem(ara, value) memset(ara, value, sizeof(ara))

bool visited[101][2];
vector<int> v[101];
void dfs(int start,int col)
{
    int nextcol = 0;
    if(col!=-1)
        visited[start][col] = 1;
    if(col == 0)
        nextcol = 1;
    else
        nextcol = 0;
    for(int i = 0 ; i < v[start].size(); i++)
    {
        if(!visited[v[start][i]][nextcol])
        {
            dfs(v[start][i],nextcol);
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
         int a,b;
         scanf("%d %d", &a,&b);
         for (int i = 0; i < b; i++)
         {
             int x,y;
             cin >> x >> y;
             v[x].push_back(y);
             v[y].push_back(x);
         }
         dfs(1,-1);
         int ans = 0;
         for (int k = 1; k <= a; k++)
         {
             if(visited[k][1])  ans++;
             //cout << visited[k][1] << endl;
         }
         printf("Case %d: %d\n",j++,ans);
         for (int k = 0; k <= 101; k++) {
             v[k].clear();
         }
         mem(visited,0);
     }
}
