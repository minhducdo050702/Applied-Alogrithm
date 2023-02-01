#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

int main()
{
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    int maxsum = a[0];
    int ei = a[0];
    for (int i = 1; i < n; i++)
    {
        ei = max(ei + a[i], a[i]);
        maxsum = max(maxsum, ei);
    }
    cout << maxsum;
    return 0;
}
