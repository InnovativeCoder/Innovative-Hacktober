#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k, count=0, totProbLeft=0;

    cin>>n>>k;

    int probChLeft[n];

    for(int i=0; i<n; i++)
    {
        cin>>probChLeft[i];
        totProbLeft += probChLeft[i];
    }

    int ch=1, page = 1, probNo, probPerPage[100*n];

    for(int i=0; i<100*n; i++)
    {
        probPerPage[i] = 0;
    }

    while(totProbLeft > 0)
    {
        probNo = 0;
        while(probChLeft[ch-1]>0)
        {
            while(probPerPage[page-1]<k && probChLeft[ch-1]>0)
            {
                probNo++;
                probPerPage[page-1]++;

                if(probNo==page)
                    count++;

                totProbLeft--;
                probChLeft[ch-1]--;
            }
            page++;
        }
        ch++;    
    }

    cout<<count;

    return 0;
}