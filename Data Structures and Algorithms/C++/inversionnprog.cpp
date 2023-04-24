#include <iostream>
#include<string>
#include<fstream>
using namespace std;
int main(int argc, char **argv)
{

    string s;
    ifstream infile;
    ofstream outfile;
    infile.open(argv[1]);
    outfile.open(argv[2]);
    int n = 0;
    if (infile.is_open())
    {
        getline(infile, s);
        int arr[s.length() ]= {0} ;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == ' ')
            {
                n++;
            }
            else
            {
                arr[n] = arr[n] * 10 + (s[i] - 48);
            }
        }
       
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    outfile<<arr[i]<<","<<arr[j]<<"\n";
                }
            }
        }
    }
    infile.close();
    outfile.close();
}
