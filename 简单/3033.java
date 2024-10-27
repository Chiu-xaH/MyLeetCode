class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        for(int i = 0;i < n;i++) {
            int max = -1;
            for(int j = 0;j < m;j++) {
                if(matrix[j][i] > max) {
                    max = matrix[j][i];
                }
            }
            for(int j = 0;j < m;j++) {
                if(matrix[j][i] == -1) {
                    matrix[j][i] = max;
                }
            }
        }
        return matrix;
    }
}