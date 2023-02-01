#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
vector<pair<int, int>> a;
void input()
{
    cin >> n;
    int temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        a.push_back(pair<int, int>(temp1, temp2));
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) -> bool
         {
             if (a.second < b.second)
                 return true;
             else if (a.second > b.second)
                 return false;
             else
                 return a.first < b.first; });
}
void process()
{
    int last = -1;
    for (auto i : a)
    {
        if (i.first > last)
        {
            last = i.second;
            cnt++;
        }
    }
}
int main()
{
    input();
    process();
    cout << cnt;
    return 0;
}