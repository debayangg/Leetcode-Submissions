class Solution {
    public int minOperations(int n) {
        int val=n;
        int max=2*(n-1)+1-n;
        if(n%2==0)
        {
            return (1+max)*n/4;
        }
        else
        {
            return (2+max)*(n-1)/4;
        }
    }
}