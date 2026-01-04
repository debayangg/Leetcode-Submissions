class Solution {
public:
    vector<int> sieve(int n)
    {
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i * i <= n; i++)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    vector<int> ans;
    for(int i=2;i<=n;i++)
    if(isPrime[i]==1)ans.push_back(i);
    return ans;
    }

    int sumFourDivisors(vector<int>& nums) 
    {
        int n=1e5;
        vector<int> vec = sieve(n);
        int m = vec.size();
        cout<<m<<endl;
        set<int> ans;
        map<int,int> mp;
        //for(int x:vec)cout<<x<<"\n";
        int mx = *( max_element(nums.begin(),nums.end()) );
        for(int i=0;i<m && vec[i]<=mx && vec[i]<46337;i++)
        {

            for(int j=i+1;j<m && vec[i]*vec[j]<=mx;j++)
            {
                ans.insert(vec[i]*vec[i]*vec[i]);
                mp[vec[i]*vec[i]*vec[i]] = vec[i]; 
                ans.insert(vec[i]*vec[j]);
                mp[vec[i]*vec[j]] = vec[i];
            }
        }
        int sum=0;
        
        for(int x:nums)if(ans.count(x))sum+=( 1+x+mp[x]+(x/mp[x]) );
        
        return sum;
    }
};