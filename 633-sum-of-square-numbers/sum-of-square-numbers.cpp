class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrtl(c);i++)
        {
            int val=sqrtl(c-(i*i));
            if((val*val)+(i*i)==c)
            return true;
        }
        return false;
    }
};