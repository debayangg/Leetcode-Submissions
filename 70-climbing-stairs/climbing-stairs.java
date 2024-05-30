class Solution {
    public int climbStairs(int n) {
        int a1=1,a2=1,curr=1;
        for(int i=2;i<=n;i++)
        {
            curr=a1+a2;
            a2=a1;
            a1=curr;
        } 
        return curr;
    }
}