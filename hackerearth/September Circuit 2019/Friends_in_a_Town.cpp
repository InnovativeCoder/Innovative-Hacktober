    /*
    // Sample code to perform I/O:
     
    cin >> name;                            // Reading input from STDIN
    cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
     
    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
    */
     
    // Write your code here
    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int n,m;
        long int k;
        cin>>n>>m>>k;
        long int arr1[n+1]={0};//rewards
        int arr2[n+1]={0};//day person becomes happy.
        typedef vector<int>v;
        unordered_map<int,v>m1;
        int x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            m1[x].emplace_back(y);
            m1[y].emplace_back(x);
        }
        long int q;
        cin>>q;
        int j=0;
        for(int i=1;i<q+1;i++)
        {
            cin>>x>>y;
            int counter=0;
            for(auto it:m1[x])
                {      
                          arr1[it]+=y;
                           if(arr1[it]>=k &&arr2[it]==0)
                           {
                              arr2[it]=i;
                              counter+=1;
                           }
                        }
                j+=counter;
                if(j==n)
                {
                  break;
                }
        }
        for(int i=1;i<n+1;i++)
        {
            if(arr2[i])
            cout<<arr2[i]<<" ";
            else
            cout<<"-1"<<" ";
        }
    }