#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

    int t, a[10], c[10], flag = 0;

    cin >> t;
    while (t--)
    {
        flag = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < 3; i++)
        {
            cin >> c[i];
        }

        // sorting according to age
        // will also shift the cost
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3 - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                    swap(c[j], c[j + 1]);
                }
            }
        }

        int prevAge = a[0];
        int prevCost = c[0];

        // for (int i = 1; i < 3; i++)
        // {
        //     if (a[i] == prevAge)
        //     {
        //         if (prevCost != c[i])
        //         {
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     else if (c[i] < prevCost)
        //     {
        //         flag = 1;
        //         break;
        //     }
        //     prevAge = a[i];
        //     prevCost = c[i];
        // }

        int cost[2], age[2];

        cost[0] = c[1] - c[0];
        cost[1] = c[2] - c[1];

        age[0] = a[1] - a[0];
        age[1] = a[2] - a[1];

        if ((age[0] == 0 && cost[0] == 0) || (age[0] > 0 && cost[0] > 0) || (age[0] < 0 && cost[0] < 0))
        {
            if ((age[1] == 0 && cost[1] == 0) || (age[1] > 0 && cost[1] > 0) || (age[1] < 0 && cost[1] < 0))
            {
                flag = 1;
            }
        }

        if (flag)
            cout << "FAIR" << endl;
        else
            cout << "NOT FAIR" << endl;
    }

    return 0;
}