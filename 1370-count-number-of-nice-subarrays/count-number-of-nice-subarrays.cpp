class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> vec(n);
        map<int,int> m;
        m[0]=1;
        vec[0]=(nums[0]%2==1);
        m[vec[0]]++;
        int sum=0;
        sum+=m[vec[0]-k];
        for(int i=1;i<n;i++)
        {
            vec[i]=vec[i-1]+((nums[i]%2==1));
            m[vec[i]]++;
            sum+=m[vec[i]-k];
        }
        return sum;
    }
};