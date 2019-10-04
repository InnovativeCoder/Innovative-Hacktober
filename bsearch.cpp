#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int bs(int arr[], int lo, int hi, int s, int &noc)
{
    if (lo > hi)
    {
        return -1;
    }
    else
    {
        int mid = (lo + hi) / 2;

        if (arr[mid] == s)
            return mid;
        else if (arr[mid] > s)
        {
            noc++;
            return bs(arr, lo, mid - 1, s, noc);
        }
        else
        {
            noc++;
            return bs(arr, mid + 1, hi, s, noc);
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    string s1;
    ifstream infile;
    ofstream outfile;
    infile.open(argv[1]);
    outfile.open(argv[2]);
    int n = 0;
    string num;
    int sign=1;
    if (infile.is_open())
    {
        getline(infile, s1);
        int arr[s1.length()] = {0};
        for (int i = 0; s1[i] != '\0'; i++)
        {
            if (s1[i] == ',')
            {
                arr[n]=sign*arr[n];
                n++;
                sign=1;
            }
            else if(s1[i]=='-')
            {
                sign=-1;
            }
            else
            {
                arr[n] = arr[n] * 10 + (s1[i] - 48);
            }
        }   

        for(int i=0;i<n+1;i++)
        {
            cout<<arr[i]<<" ";
        }     
        cout<<"\n";
        sort(arr,arr+(n+1));
          for(int i=0;i<n+1;i++)
        {
            cout<<arr[i]<<" ";
        }
        
        
        while (!infile.eof())
        {
            int noc = 1;
            getline(infile, num);
            int number = 0;
            for (int i = 0; num[i] != '\0'; i++)
            {
                number = number * 10 + (num[i] - 48);
            }
            int lo = 0;
            int hi = n;
            int f = bs(arr, lo, hi, number, noc);
            if (f == -1)
                outfile << number << " not found\n";
            else
            {
                outfile << number << " found at position " << f+1<< " after " << noc << " comparisons\n";
            }
        }
    }
    infile.close();
    outfile.close();
}