class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> anagramDict = new HashMap<>();
        for (String str : strs) {
            char[] strArr = str.toCharArray();
            Arrays.sort(strArr);
            String sortedString = new String(strArr);
            List<String> currStrs = anagramDict.getOrDefault(sortedString, new ArrayList<>());
            currStrs.add(str);
            anagramDict.put(sortedString, currStrs);
        }

        List<List<String>> output = new ArrayList<>();
        for (String str : anagramDict.keySet()) {
            output.add(anagramDict.get(str));
        }

        return output;
    }
}
