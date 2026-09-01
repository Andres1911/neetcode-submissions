class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            sb.append(s + '\n');
        }
        return sb.toString();
    }

    public List<String> decode(String str) {
        ArrayList<String> strs = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c != '\n') {
                sb.append(c);
            }
            else {
                strs.add(sb.toString());
                sb.setLength(0);
            }
        }
        return strs;
    }
}
