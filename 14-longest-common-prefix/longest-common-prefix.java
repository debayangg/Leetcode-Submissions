class Solution {
    public String longestCommonPrefix(String[] strs) {
        String s=strs[0];
        for(int i=1;i<strs.length;i++)
        {
            String ans="";
            for(int j=0;j<Math.min(strs[i].length(),s.length());j++)
            {
                if(strs[i].charAt(j)==s.charAt(j))
                {
                    ans+=s.charAt(j);
                }
                else break;
            }
            s=ans;
            if(s.equals(""))break;
        }
        return s;
    }
}