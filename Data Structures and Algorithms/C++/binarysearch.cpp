#include <iostream>
#include <stdio.h>
#include <fstream> 
#include <string.h>
#include <stdlib.h>
using namespace std;
int comp;
int binSearch(int arr[], int l, int r, int x) 
{ 
if (r >= l) { 
        int mid = (l+r) / 2; 
        if (arr[mid] == x) 
       {comp++;
            return mid; 
  	} 
       else if (arr[mid] > x) 
       {
       	comp++;
       	return binSearch(arr, l, mid - 1, x); 
	   }
            
  		else
  		{comp++;
		  return binSearch(arr, mid + 1, r, x); 
		  }
        
    }   
return -1;
}
int main(int argc,char** argv)
 { 
    ifstream fin;
    ofstream fout;
    string str,str2;
    int arr[100],arr2[100];
    int i=0,j=0; 
    fin.open(argv[1]); 
    fout.open(argv[2]); 
    if(!fin)
	{
		exit(1);
	}
	 if(!fout)
	{
		exit(1);
	}
  	
	while(fin>>arr[i]) {
  		getline(fin, str ,',');
			i++;
		}
	 
	 
	fin.clear();
	fin.seekg(0, ios::beg);
	while(fin>>arr2[j])
	  {
	  getline(fin, str2, '\n');
	  j++;
}

	 
	int m, n, temp=0;
    for(m = 0; m <i; m++)
    {
        for(n = 0; n < i-m-1; n++)
        {
            if( arr[n] > arr[n+1])
            {
                temp = arr[n];
                arr[n] = arr[n+1];
                arr[n+1] = temp;
            } 
        }
    }
  

	for(int op=1;op<j;op++)
	  { int x=arr2[op];
	    comp=0;
	  	int result = binSearch(arr, 0, i-1 , x); 
        (result == -1) ? fout<<x<<"  not found  "<<endl 
		:fout<<x<<" found at position "<< result+1<< " after "<<comp<<" comparisons"<<endl  ; 
     }
      fin.close();
      fout.close();
 	return 0;
} 

