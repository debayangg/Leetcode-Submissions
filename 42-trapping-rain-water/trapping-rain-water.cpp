class Solution {
public:
    int trap(vector<int>& arr) {
    int n=arr.size(),max=INT_MIN,count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==max)
        count++;
    }
    int prev=arr[0],sum1=0,sum=0,i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==max)
        {
            count--;
            if(count>0)
            {
                sum+=sum1;
                sum1=0;
                prev=arr[i];
            }
            else
            {
                sum+=sum1;
                sum1=0;
                break;
            }
            continue;
        }
        if(arr[i]<=prev)
        {
            sum1+=prev-arr[i];
        }
        else
        {
            sum+=sum1;
            sum1=0;
            prev=arr[i];
        }
    }
    prev=arr[n-1];
    for(int j=n-2;j>=i;j--)
    {
        if(arr[j]<=prev)
        {
            sum1+=prev-arr[j];
        }
        else
        {
            sum+=sum1;
            sum1=0;
            prev=arr[j];
        }
    }

    return sum;
    }
};