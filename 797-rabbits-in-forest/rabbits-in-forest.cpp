class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        map<int,int> mp;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            mp[answers[i]]++;
            if(mp[answers[i]]>answers[i]+1 && answers[i])
            {
                cnt+=answers[i]+1;
                mp[answers[i]]=1;
            }
        }
        cout<<cnt<<endl;
        for(auto id:mp)
        {
            if(id.second>0 && id.first)
            {
                cnt+=id.first+1;
            }
        }
        cnt+=mp[0];
        return cnt;
    }
};