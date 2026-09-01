class Solution {
    public boolean isValidSudoku(char[][] board) {
        return isValidRows(board) && isValidCol(board) && isValidBox(board);
    }

    boolean isValidRows(char[][] board) {
        for (char[] row : board) {
            Set<Character> current = new HashSet<Character>();
            for (char c : row) {
                System.out.println("Char: " + c);
                if (c != '.' && current.contains(c)) {
                    return false;
                }
                current.add(c);
            }
        }
        return true;
    }

    boolean isValidCol(char[][] board) {
        for (int i = 0; i < board[0].length; i++) {
            Set<Character> current = new HashSet<Character>();
            for (int j = 0; j < board.length; j++) {
                char c = board[j][i];
                System.out.println("Char: " + c + " Col: " + i);
                if (c != '.' && current.contains(c)) {
                    return false;
                }
                current.add(c);
            }
        }
        return true;
    }

    boolean isValidBox(char[][] board) {
        int totBoxes = 9;
        int boxSize = 3;
        for (int k = 0; k < totBoxes; k++) {
            Set<Character> current = new HashSet<Character>();
            for (int i = 0; i < boxSize; i++) {
                for (int j = 0; j < boxSize; j++) {
                    int boxRow = (k / boxSize) * boxSize;
                    int boxCol = (k % boxSize) * boxSize;
                    char c = board[boxRow + i][boxCol + j];
                    System.out.println("Char: " + c + " Box: " + k + " Row: " + boxRow + " Col: " + boxCol);
                    if (c != '.' && current.contains(c)) {
                        return false;
                    }
                    current.add(c);
                }
            }
        }
        return true;
    }
}
 