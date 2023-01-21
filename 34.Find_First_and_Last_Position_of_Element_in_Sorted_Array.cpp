/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
    int first(vector<int> &nums,int start,int end,int target){
        int ans= -1;
        int low = start,high = end;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int last(vector<int> &nums,int start,int end,int target){
        int ans= -1;
        int low = start,high = end;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> v(2,-1);
        int n = nums.size();
        int firstInd = first(nums,0,n-1,target);
        int lastInd = last(nums,0,n-1,target);
        return {firstInd,lastInd};
        }
};
