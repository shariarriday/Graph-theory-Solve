#include<bits/stdc++.h>
using namespace std;
vector<int> vec[200001];

int col[200001];
int ans[200001];
int pre[200001];

void bfs(int start)
{
    col[start] = 1; //coloring starting point black
    ans[start] = 1;
    pre[start] = 0;
    queue<int> q;
    q.push(start);
    int b = 1;
    while(!q.empty())
    {
        int v = q.front(); //the current ancestor
        q.pop(); //dequeuing the current ancestor before loop
        int s = 1;
        for(int i = 0 ; i < vec[v].size() ; i++)
        {
            if(col[vec[v][i]] == 0) // checks if the vertex is white
            {
                q.push(vec[v][i]); //pushes the unchecked vertex
                col[vec[v][i]] = 1;
                pre[vec[v][i]] = v;
                if(s == ans[v] || s == ans[pre[v]])
                {
                    s+= (s == ans[pre[v]])+(s == ans[v]);
                    s+= (s == ans[v])+(s == ans[pre[v]]);
                }
                ans[vec[v][i]] = s++;
            }
        }
    }
}

int main()
{
    int x;
    cin >> x;
    int a = x-1;
    int y,z;
    while(a--)
    {
        cin >> y >> z;
        vec[y].push_back(z);
        vec[z].push_back(y);
    }
    bfs(1);
    int maxs = 0;
    for(int i = 1 ; i <=x ; i++)
    {
        maxs = max(maxs,ans[i]);
    }
    cout << maxs << endl;
    for(int i = 1 ; i <=x ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
