class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
         int left=0,right=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                right++;}
            else{
                swap(nums[i],nums[left]);
                left++;right++; }} 
        return nums;}};
 