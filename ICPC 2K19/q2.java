import java.io.*;
import java.util.*;


class GFG {
    public static void main (String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int testcase=Integer.parseInt(br.readLine());
        StringTokenizer st;
        int i,j;
        String h;
        while(--testcase>=0){
            h=br.readLine().trim();
            st=new StringTokenizer(h);
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());            
            String s=br.readLine();
            st=new StringTokenizer(s);

            int a[]=new int[n];
            for(i=0;i<n;i++){
                a[i]=Integer.parseInt(st.nextToken());
            }
            
            ArrayList <Integer> ar=new ArrayList <Integer> ();

            int sum=0,count=0,tp=0;
            int max=n/k;
            int free=0;
            int max1=max+free;
            boolean flag=true;
            if(n==k){
               for(i=0;i<n;i++)
                {
                    if(a[i]<0){
                        flag=false;
                        break;
                    }
                } 
            }
            else
            {
                for(i=0;i<n;i++)
                {
                    if(count+1==k){
                        sum=sum+a[i];
                    }
                    else if(tp+1==max1){
                        if(sum+a[i]<0){
                            flag=false;
                            break;
                        }
                        else{
                            ar.add(a[i]);
                            tp=0;
                            count++;
                            sum=0;
                        }
                    }

                    if(tp==0 && a[i]<0){
                        sum+=a[i];
                        tp++;
                    }
                    else if(a[i]>0 && i!=n-1){
                        sum+=a[i];
                        tp++;

                        if(a[i+1]>0)
                        {
                            ar.add(a[i]);
                            free=max-tp;
                            max1=max1-max+max+free;
                            count++;
                            sum=0;
                        }
                        else{
                            
                        }
                    }
                    //max1=max+free;
                }
            }

            if(!flag){
                System.out.println("NO");
            }
            else{
                System.out.println("YES");
                for(i=0;i<ar.size();i++){
                    System.out.print(ar.get(i)+" ");
                }
                System.out.println();
            }
            
        }
    }
}