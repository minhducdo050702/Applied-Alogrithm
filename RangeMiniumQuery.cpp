#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int n, m;
vector<int> a;
int lookup[MAX][30]; // lookuop i j la chi so be nhat phan tu tu i den i+2^j-1
int res = 0;
void process()
{
    for (int i = 0; i < n; i++)
        lookup[i][0] = i;
    int i = 0;
    for (int j = 1; (i + (1 << j) - 1) < n; j++)
        for (int i = 0; i < n; i++)
        {
            if (a[lookup[i][j - 1]] <= a[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
}
int query(int c, int d)
{
    int e = log2(d - c + 1);
    return min(a[lookup[c][e]], a[lookup[d + 1 - (1 << e)][e]]);
}

int main()
{
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    process();
    cin >> m;
    int temp1, temp2;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2;
        res += query(temp1, temp2);
    }
    cout << res;
    return 0;
}