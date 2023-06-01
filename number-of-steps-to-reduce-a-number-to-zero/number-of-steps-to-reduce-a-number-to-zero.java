class Solution {
    public int numberOfSteps(int num) {
        int steps[]= new int[num+1];
        steps[0]=0;
        for(int i=1;i<=num;i++)
        {
            int min=steps[i-1];
            
            if(i%2==0 && min>steps[i/2])
            min=steps[i/2];

            steps[i]=1+min;
        }

        return steps[num];
    }
}