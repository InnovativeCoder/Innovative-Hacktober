 public void BubbleSort(int [] arr) 
    { 
        int l = arr.Length; 
        for (int i = 0; i < l - 1; i++) 
            for (int j = 0; j < l - i - 1; j++) 
                if (arr[j] > arr[j + 1]) 
                { 
                    int temp = arr[j]; 
                    arr[j] = arr[j + 1]; 
                    arr[j + 1] = temp; 
                } 
    } 
