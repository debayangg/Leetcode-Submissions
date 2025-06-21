class Solution {
    public int minimumDeletions(String word, int k) {
        HashMap<Character, Integer> freqMap = new HashMap<>();
        for (char c : word.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        List<Integer> freqs = new ArrayList<>(freqMap.values());
        Collections.sort(freqs);  // Sorted frequencies

        int n = freqs.size();
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + freqs.get(i);
        }

        int minDeletions = Integer.MAX_VALUE;

        for (int left = 0; left < n; left++) {
            int startFreq = freqs.get(left);
            int endFreq = startFreq + k;

            int right = left;
            while (right < n && freqs.get(right) <= endFreq) {
                right++;
            }

            int deleteLeft = prefixSum[left];

            int deleteRight = 0;
            for (int i = right; i < n; i++) {
                deleteRight += freqs.get(i) - endFreq;
            }

            minDeletions = Math.min(minDeletions, deleteLeft + deleteRight);
        }

        return minDeletions;
    }
}
