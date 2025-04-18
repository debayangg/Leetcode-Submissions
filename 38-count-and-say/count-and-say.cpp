class Solution {
public:
    string countAndSay(int n) 
    {
        string val="1";
        for(int i=2;i<=n;i++)
        {
            int cnt=0;
            string val1="";
            char prev=val[0];
            cnt++;
            for(int j=1;j<val.size();j++)
            {
                if(val[j]==prev)
                cnt++;
                else
                {
                    val1+=to_string(cnt);
                    val1+=prev;
                    prev=val[j];
                    cnt=1;
                }
            }
            val1+=to_string(cnt);
            val1+=prev;
            val=val1;
        }    
        return val;
    }
};