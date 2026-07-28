class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9<s)return -1;
        else
        {
            int val=0;
            while(n--)
            {
                if(s>=9)
                {
                    val=val*10+9;
                    s-=9;
                }
                else if(s!=0)
                {
                    val=val*10+s;
                    s=0;
                }
                else
                {
                    val*=10;
                }
            }
            return val;
        }
    }
};