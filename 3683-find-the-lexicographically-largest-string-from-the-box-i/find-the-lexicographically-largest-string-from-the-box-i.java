class Solution {
    public String answerString(String word, int numFriends) {
        StringBuilder s = new StringBuilder(), ans = new StringBuilder();
        
        if (numFriends == 1) return word;
        
        for (int i = 0; i < word.length() - numFriends + 1; i++) {
            s.append(word.charAt(i));
            if (ans.toString().compareTo(s.toString()) < 0) {
                ans = new StringBuilder(s);
            }
        }

        for (int i = word.length() - numFriends + 1; i < word.length(); i++) {
            s.deleteCharAt(0);
            s.append(word.charAt(i));
            if (ans.toString().compareTo(s.toString()) < 0) {
                ans = new StringBuilder(s);
            }
        }

        while (s.length() > 0) {
            s.deleteCharAt(0);
            if (ans.toString().compareTo(s.toString()) < 0) {
                ans = new StringBuilder(s);
            }
        }
        
        return ans.toString();
    }
}
