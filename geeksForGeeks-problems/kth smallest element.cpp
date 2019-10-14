int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
	int T;
	cin>>T ;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int k ;
	    cin>>k;
	    sort(arr,arr+n);
	    cout<<arr[k-1]<<endl;
	}
	return 0;
}