class Solution {
    public int appendCharacters(String s, String t) {
        int i=0,j=0,n=s.length(),m=t.length();
        for(i=0;i<n && j<m;i++)
        {
            if(s.charAt(i)==t.charAt(j))
            {
                j++;
            }
        }
        //System.out.println(j);
        return (m-j);
    }
}