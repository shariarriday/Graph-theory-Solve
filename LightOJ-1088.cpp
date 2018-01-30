#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,m;
    scanf("%d" , &t);
    int i =1;
    while(t--)
    {
        scanf("%d %d" , &n,&m);
        int ar[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &ar[i]);
        int q,w;
        printf("Case %d:\n", i++);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d" ,&q,&w);
            int* l = upper_bound(ar,ar+n,w);
            int* k = lower_bound(ar,ar+n,q);
            printf("%ld\n",l-k);
        }
    }
}
