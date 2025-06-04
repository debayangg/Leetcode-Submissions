class Solution {
    public String answerString(String word, int numFriends) {
        String s="", ans="";
        if(numFriends==1)return word;
        for(int i=0;i<word.length()-numFriends+1;i++)
        {
            s+=word.charAt(i);
            if(ans.compareTo(s)<0)
            ans=s;
        }

        for(int i=word.length()-numFriends+1;i<word.length();i++)
        {
            s=s.substring(1);
            s+=word.charAt(i);
            if(ans.compareTo(s)<0)
            ans=s;
        }

        while(!s.equals(""))
        {
            s=s.substring(1);
            if(ans.compareTo(s)<0)
            ans=s;
        }
        return ans;
    }
}