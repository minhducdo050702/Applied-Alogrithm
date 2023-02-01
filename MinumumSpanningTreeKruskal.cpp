#include <bits/stdc++.h>
using namespace std;
typedef struct edge
{
    int u, v;
    int w;
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
} edge;
typedef struct union_find
{
    vector<int> iParent;
    union_find(int x)
    {
        iParent = vector<int>(x + 1);
        for (int i = 1; i <= x; i++)
            iParent[i] = i;
    }
    int FIND(int x)
    {
        if (iParent[x] == x)
            return x;
        else
        {
            iParent[x] = FIND(iParent[x]);
            return iParent[x];
        }
    }
    void UNION(int x, int y)
    {
        iParent[FIND(x)] = FIND(y);
    }
} union_find;

const int MAX = 1e5;
int N, M;
vector<edge> a;
void input()
{
    cin >> N >> M;
    int temp1, temp2, temp3;
    for (int i = 1; i <= M; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        a.push_back(edge(temp1, temp2, temp3));
    }
    sort(a.begin(), a.end(), [](edge a, edge b) -> bool
         { return a.w < b.w; });
}
int Kruskal()
{
    int res = 0;
    union_find d = union_find(N);
    for (auto i : a)
    {
        int x = i.u;
        int y = i.v;
        if (d.FIND(x) != d.FIND(y))
        {
            d.UNION(x, y);
            res += i.w;
        }
    }

    return res;
}
int main()
{
    input();
    cout << Kruskal();
    return 0;
}