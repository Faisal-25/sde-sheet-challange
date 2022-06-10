class Solution {
    public static void setZeroes(int [][] matrix){
       int [] rowCheck = new int[matrix.length];
        int [] colCheck = new int[matrix[0].length];
        Arrays.fill(rowCheck,1);
        Arrays.fill(colCheck,1);
        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;j<matrix[0].length;j++){
                if(matrix[i][j] == 0){
                    rowCheck[i] = 0;
                    colCheck[j] = 0;
                }
            }
        }
        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;j<matrix[0].length;j++){
                if(rowCheck[i] == 0 || colCheck[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
       
    }

}