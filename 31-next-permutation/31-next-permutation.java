class Solution {
    public static void reverse(int [] nums,int lo,int hi){
        while(lo<hi){
            int temp = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = temp;
            lo++;
            hi--;
        }
    }
    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while(i>=0&&nums[i]>=nums[i+1]){
            i--;
        }
        int j = nums.length -1;
       if(i<0){
           reverse(nums,i+1,nums.length-1);
           return;
       }
        while(j>=0){
            if(nums[j]>nums[i]){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                break;
            }
            j--;
        }
        reverse(nums,i+1,nums.length-1);
    }
}