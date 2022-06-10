class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new LinkedList<>();
    
        for(int i = 1;i<=numRows;i++){
            List<Integer> l = new LinkedList<>();
            for(int j = 0;j<i;j++){
                if(j == 0 || j == i-1){
                    l.add(1);
                }
                else{
                    l.add(ans.get(i-2).get(j)+ans.get(i-2).get(j-1));
                }
            }
            ans.add(l);
        }
        return ans;
    }
}