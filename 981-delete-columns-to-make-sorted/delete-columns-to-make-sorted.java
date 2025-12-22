class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs[0].length();
        Set<Integer> st = new HashSet<>();
        for(int i=0;i<n;i++)
        {
            boolean flag = false;
            for(int j=1;j<strs.length;j++)
            {
                if(strs[j].charAt(i)<strs[j-1].charAt(i)) {
                    flag = true;
                    break;
                }
            }

            if(flag)st.add(i);
        }

        return st.size();
    }
}