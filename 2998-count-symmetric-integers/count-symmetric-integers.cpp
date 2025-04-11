class Solution {
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int cnt=0;
        for(int n=low;n<=high;n++)
        {
            if(n==10000)continue;
            if(n<1000 && n>=100)continue;
            if(n>=1 && n<10)continue;
            vector<int> digs(4);
            
            int cp=n;

            for(int i=1;i<=4;i++)
            {
                digs[i-1]=cp%10;
                cp/=10;
            }

            // for(int i=0;i<4;i++)
            // cout<<digs[i]<<" ";
            // cout<<endl;

            if(digs[3]==0 && digs[2]==0)
            {
                if(digs[1]==digs[0])cnt++;
            }
            else
            {
                if(digs[3]+digs[2]==digs[1]+digs[0])cnt++;
            }
        }
        return cnt;
    }
};