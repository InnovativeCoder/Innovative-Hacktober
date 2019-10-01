#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;

    int len = s.size();

    char ch1;
    char ch2;
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '?')
        {
            ch1 = s[i];
            index = i;
            break;
        }
    }

    ch2 = ch1 == 'a' ? 'b' : 'a';

    if (index % 2 == 0)
    {
        for (int i = 0; i < len; i += 2)
        {
            s[i] = ch1;
        }
        for (int i = 1; i < len; i += 2)
            s[i] = ch2;
    }

    else
    {
        for (int i = 0; i < len; i += 2)
        {
            s[i] = ch2;
        }
        for (int i = 1; i < len; i += 2)
            s[i] = ch1;
    }

    cout << s;
}