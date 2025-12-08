class Solution {
    public int countTriples(int n) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int a = i*i;
            for(int j=i+1;j<=n;j++)
            {
                int b = j*j;
                int c = (int)Math.sqrt(a+b);
                if(c*c == (a+b) && c<=n)
                {
                    cnt+=2;
                    //System.out.println(i+" "+j);
                }
            }
        }
        return cnt;
    }
}