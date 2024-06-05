class Solution {
    public List<String> commonChars(String[] words) {
        int[][] arr = new int[26][words.length];
        for(int i=0;i<words.length;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                arr[words[i].charAt(j)-'a'][i]++;
            }
        }
        List<String> ans = new ArrayList<>();
        for(int i=0;i<26;i++)
        {
            int f=Integer.MAX_VALUE;
            for(int j=0;j<words.length;j++)
            {
                f=Math.min(f,arr[i][j]);
            }
            while(f-->0)
            {
                ans.add(Character.toString('a'+i));
            }
        }
        return ans;
    }
}