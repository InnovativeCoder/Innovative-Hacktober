public class PartitionAlgo {
    public static String execute(int bytes,int parts) {
        StringBuilder stringBuilder=new StringBuilder();
        int v=bytes/(parts);
        int f=0;
        int x= (bytes)%(parts);
        int l=bytes-1;
        int t=f+(v-1);
        while(f<=l)
        {
            stringBuilder.append(f).append(":").append(t).append(";");
            f+=v;
            if(t==(l-x))
            {
                t=bytes-1;
                if(t!=0 && t<bytes) {
                    stringBuilder.append(f).append(":").append(t).append(";");
                }
                break;
            } else {
                t += v;
            }
        }
        return stringBuilder.toString();
    }
}
