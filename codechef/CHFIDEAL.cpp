#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
    int y;
    srand(time(NULL));
    int x=(rand()%3)+1;
    int z=(rand()%3)+1;
    cout<<x<<endl<<flush;
    cin>>y;
    while(y==z)
    {
        z=(rand()%3)+1;
    }
    if(y>0&&y<4)
    {
    if(x!=y)
        cout<<z<<endl<<flush;
    }
    return 0;
}
