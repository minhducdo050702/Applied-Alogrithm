#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> toado;
int n;
int xmin = INT_MAX, ymin = INT_MAX;
int xmax = INT_MIN, ymax = INT_MIN;

int main()
{
    cin >> n;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        xmax = max(max(x1, x2), xmax);
        xmin = min(min(x1, x2), xmin);
        ymax = max(max(y1, y2), ymax);
        ymin = min(min(y1, y2), ymin);
    }
    cout << (xmax - xmin) * (ymax - ymin);
    return 0;
}