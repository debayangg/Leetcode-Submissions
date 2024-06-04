class Solution {
    public int longestPalindrome(String s) {
        int n=s.length();
        HashMap<Character,Integer> m = new HashMap<>();
        for(int i=0;i<n;i++)
        {
            char ch=s.charAt(i);
            if(m.containsKey(ch))
            {
                m.put(ch,m.get(ch)+1);
            }
            else
            {
                m.put(ch,1);
            }
        }
        int count=0;
        for(char ch : m.keySet())
        {
            count+=2*(m.get(ch)/2);
        }
        if(n>count)
        {
            count++;
        }

        return count;
    }
}