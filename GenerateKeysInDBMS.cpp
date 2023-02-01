#include <bits/stdc++.h>
using namespace std;

int n, L, m, a[10010];
string s[10010];

bool cmp(string x, string y)
{
    return x < y;
}

int main()
{
    cin >> n >> L >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        a[i] = j;
        string k = "";
        for (int l = 0; l < L - to_string(j).length(); l++)
        {
            k += '0';
        }
        k += to_string(j);
        while (k <= s[n - 1])
        {
            j++;
            k = "";
            for (int l = 0; l < L - to_string(j).length(); l++)
            {
                k += '0';
            }
            k += to_string(j);
        }
        s[n + i] = k;
    }
    sort(s, s + n + m, cmp);
    for (int i = 0; i < n + m; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}