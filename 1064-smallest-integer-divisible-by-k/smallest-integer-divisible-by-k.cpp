class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0)return -1;
        if(k%5==0)return -1;
        int n=1;
        int ans=1, rem=0;
        while(true)
        {
            rem+=n%k;
            rem%=k;
            if(rem==0)return ans;
            ans++;
            n=(n%k)*10;   
            //cout<<n<<" "<<rem<<endl;
        }
        return -1;
    }
};