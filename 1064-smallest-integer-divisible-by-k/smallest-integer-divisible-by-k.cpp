class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0)return -1;
        if(k%5==0)return -1;
        int n=1;
        int ans=0, rem=-1;
        while(rem)
        {
            if(rem==-1)rem=0;
            rem+=n%k;
            rem%=k;
            ans++;
            n=(n%k)*10;   
        }
        return ans;
    }
};