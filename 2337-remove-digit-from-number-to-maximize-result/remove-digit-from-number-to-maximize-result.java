class Solution {
    public String removeDigit(String number, char digit) {
        String ans="";
        for(int i=0;i<number.length();i++)
        {
            if(number.charAt(i)==digit)
            {
                if(ans.length()==0)
                ans=number.substring(0,i)+number.substring(i+1);
                else
                {
                    String s=number.substring(0,i)+number.substring(i+1);
                    if(ans.compareTo(s)<0)
                    {
                        ans=s;
                    }
                }
            }
        }
        return ans;
    }
}