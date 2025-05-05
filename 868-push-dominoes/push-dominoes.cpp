class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        int start=-1,end=-1;
        vector<pair<int,int>> right;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='R' && start==-1)
            start=i;
            else if(dominoes[i]=='R' && start!=-1)
            {
                right.push_back({start,i});
                start=i;
            }
            else if(dominoes[i]=='L' && start!=-1)
            {
                right.push_back({start,start+(i-start-1)/2});
                if((i-start+1)%2!=0)s.insert(start+(i-start)/2);
                start=end=-1;
            }
        }
        if(start!=-1)
        right.push_back({start,n-1});

        for(pair<int,int> x:right)
        {
            int a=x.first, b=x.second;
            for(int i=a;i<=b;i++)
            dominoes[i]='R';
        }
        bool flag=false;

        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='.' && flag && s.find(i)==s.end())
            dominoes[i]='L';
            else if(dominoes[i]=='R' || s.find(i)!=s.end())
            flag=false;
            else if(dominoes[i]=='L')
            flag=true;
        }
        return dominoes;
    }
};