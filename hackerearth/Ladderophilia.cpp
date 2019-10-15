#include <iostream>


using namespace std;


int main()
 
{

    int n,x=0,i=1;

    cin>>n;

    while(i>0)

    {

        if(i%3!=0)

        {

            cout<<"*   *"<<endl;

        }

        if(x==n)

        break;

        if(i%3==0)

        {

            cout<<"*****"<<endl;

            x++;

        }


        i++;

    }

        cout<<"*   *"<<endl;

}
