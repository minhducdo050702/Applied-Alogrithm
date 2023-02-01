#include <bits/stdc++.h>
using namespace std;
bool isopen(char a)
{
    return a == '{' || a == '(' || a == '[';
}
bool check(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '{' && b == '}')
        return true;
    return false;
}
int check(string s)
{
    stack<char> a;
    for (int i = 0; i < s.length(); i++)
    {
        if (isopen(s[i]))
            a.push(s[i]);
        else
        {
            if (a.empty())
                return 0;
            if (check(a.top(), s[i]))
            {
                a.pop();
            }
            else
                return 0;
        }
    }
    if (a.empty())
        return 1;
    return 0;
}
int main()
{
    string str;
    getline(cin, str);
    cout << check(str) << endl;
    return 0;
}