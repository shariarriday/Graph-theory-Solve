#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d" , &n))
    {
        int ar[n];
        for (int i = 0; i < n; ++i)
            cin >> ar[i];
        int m;
        cin >> m;
        int q;
        for (int i = 0; i < m; ++i)
        {
            cin >> q;
            int* l = upper_bound(ar,ar+n,q);
            int* k = lower_bound(ar,ar+n,q);
            if(k-ar-1 >= 0 && l-ar < n)
                cout << ar[k-ar-1] << " " <<ar[l-ar] << endl;
            else if(l-ar >= n)
                cout << ar[k-ar-1] << " X"<< endl;
            else
                cout << "X " <<ar[l-ar] << endl;
        }
    }
}
