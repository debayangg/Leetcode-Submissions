class Solution {
    public int minimumChairs(String s) {
        int n=0,mx=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='E')
            n++;
            else
            n--;
            if(n>mx)
            mx=n;
        }
        return mx;
    }
}