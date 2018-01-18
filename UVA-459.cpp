#include <bits/stdc++.h>
using namespace std;

int d[27];
vector<int> li[27];
void dfs(int a)
{
    int n = li[a].size();
    for (int i = 0; i < n; ++i)
    {
        if(d[li[a][i]] == 0)
        {
            d[li[a][i]] = 1;
            dfs(li[a][i]);
        }
    }
}

int main(){
    int a;
    while(~scanf("%d" , &a))
    {
        char s;
        cin >> s;
        for (int i = 0; i < s-'A'; ++i)
        {
            char x,y;
            cin >> x >> y;
            li[x-'A'].push_back(y-'A');
            li[y-'A'].push_back(x-'A');
        }
        int ans = 0;
        for (int i = 0; i < s-'A'; ++i)
        {
            if( d[i] == 0)
            {
                d[i] == 1;
                dfs(i);
                ans++;
            }
        }
        cout << ans << endl;
    }
}
