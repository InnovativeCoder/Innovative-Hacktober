#include <iostream>

#include <cstring>

using namespace std;


int main()
 
{

    int t,no,i,c,l;

    char x[100];

    cin>>t;

    while(t--)

    {

        cin>>x;

        l=strlen(x);

        no=0;

        for(i=0;i<l;i++)

        {

                switch(x[i]-'0')

                {

                    case 0:
			 no=no+6;

                   	 break;

                    case 1:
			 no=no+2;

                   	 break;

                    case 2:
			 no=no+5;

                   	 break;

                    case 3:
			 no=no+5;

                   	 break;

                    case 4:
			 no=no+4;

                   	 break;

                    case 5:
			 no=no+5;

                   	 break;

                    case 6:
			 no=no+6;

                   	 break;

                    case 7:
			 no=no+3;

                   	 break;

                    case 8:
			 no=no+7;

                   	 break;

                    case 9:
			 no=no+6;
			 break;

                }

        
}

    
     if(no%2==0)

        {

            c=(no/2);

            while(c--)

            {

                cout<<"1";

            }

            cout<<endl;

        }

        else

        {

            c=(no/2)-1;

            cout<<"7";

            while(c--)

            {

                cout<<"1";

            }

            cout<<endl;

        }

    }

}
