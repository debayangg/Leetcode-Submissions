class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int> vec;
        if(n%2)
        {
            vec.push_back(0);
            int x=1;
            for(int i=0;i<n-1;i++)
            {
                if(i%2)
                vec.push_back(x++);
                else
                vec.push_back(-x);
            }
        }
        else
        {
            int x=1;
            for(int i=0;i<n;i++)
            {
                if(i%2)
                vec.push_back(x++);
                else
                vec.push_back(-x);
            }
        }
        return vec;
    }
};