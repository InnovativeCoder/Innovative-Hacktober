public class QuickSort {  
    public static void main(String[] args) {  
            int i;  
            int[] A={66,53,78,21,63,78,10,97,45,85};  
            
            quickSort(A, 0, 9);  
            
            System.out.println("\n The sorted array is: \n");  
            
            for(i=0;i<10;i++)  
            System.out.println(A[i]);  
        }  
        public static int partition(int a[], int start, int end)  
        {  
              
            int left, right, temp, loc, flag;     
            loc = left = start;  
            right = end;  
            flag = 0;  
            while(flag != 1)  
            {  
                while((a[loc] <= a[right]) && (loc!=right))  
                right--;  
                if(loc==right)  
                flag =1;  
                else if(a[loc]>a[right])  
                {  
                    temp = a[loc];  
                    a[loc] = a[right];  
                    a[right] = temp;  
                    loc = right;  
                }  
                if(flag!=1)  
                {  
                    while((a[loc] >= a[left]) && (loc!=left))  
                    left++;  
                    if(loc==left)  
                    flag =1;  
                    else if(a[loc] <a[left])  
                    {  
                        temp = a[loc];  
                        a[loc] = a[left];  
                        a[left] = temp;  
                        loc = left;  
                    }  
                }  
            }  
            return loc;  
        }  
        static void quickSort(int a[], int start, int end)  
        {  
              
            int loc;  
            if(start<end)  
            {  
                loc = partition(a, start, end);  
                quickSort(a, start, loc-1);  
                quickSort(a, loc+1, end);  
            }  
        }  
    }
    
