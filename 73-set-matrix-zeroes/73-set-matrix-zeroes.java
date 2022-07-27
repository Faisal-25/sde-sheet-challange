class Solution {
    public static void setZeroes(int [][] matrix){
       int [] rowCheck = new int[matrix.length];
        int [] colCheck = new int[matrix[0].length];
       
        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;j<matrix[0].length;j++){
                if(matrix[i][j] == 0){
                    rowCheck[i] = 1;
                    colCheck[j] = 1;
                }
            }
        }
        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;j<matrix[0].length;j++){
                if(rowCheck[i] == 1 || colCheck[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
       
    }

}