class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n=s.length(), len=(int)Math.ceil((double)n/k);
        String[] wd = new String[len];
        int l=0;
        for(int i=0;i<n;)
        {
            String w="";
            for(int j=0;j<k && i<n;j++,i++)
            {
                w+=s.charAt(i);
            }
            //System.out.println(w+" "+i+" "+l);
            wd[l]=w;
            l++;
        }
        while(wd[l-1].length()!=k)
        wd[l-1]+=fill;

        return wd;
    }
}