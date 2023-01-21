/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return min(nums[0],nums[1]);
        if(nums[low] <= nums[high]) return nums[low];
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] < nums[high]) high=mid;
            else low = mid+1;
        }
        return nums[low];
    }
};
