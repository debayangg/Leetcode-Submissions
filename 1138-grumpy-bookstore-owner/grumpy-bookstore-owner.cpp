class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        if(n<=minutes)
        {
            int sum=0;
            for(int i:customers)
            {
                sum+=i;
            }
            return sum;
        }
        else
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if(!grumpy[i])
                sum+=customers[i];
            }

            int i=0,j=minutes-1;
            int val=0;
            for(int k=i;k<=j;k++)
            {
                val+=grumpy[k]*customers[k];
            }
            int mx=val;
            j++;
            i++;
            while(i<n && j<n)
            {
                val=val+(grumpy[j]*customers[j])-(grumpy[i-1]*customers[i-1]);
                mx=max(mx,val);
                i++;
                j++;
            }

            return sum+mx;
        }
    }
};