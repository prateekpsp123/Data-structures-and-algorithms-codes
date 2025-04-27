#include<bits/stdc++.h>
using namespace  std;
//Question link: https://leetcode.com/problems/search-in-rotated-sorted-array/
int findPivot(vector<int>&nums){
  int start = 0;
  int end = nums.size() - 1;

  while(start <= end){
    int mid = start + (end - start)/2;

    // Case 1: and Case 2: as we know that both the array are sorted, even if it rotated so there is only one case where 
    // nums[mid] > nums[mid + 1] 
    // nums[mid - 1] > nums[mid] 
    if((mid < end) && nums[mid] > nums[mid + 1])
      return mid;
    else if(mid > start && nums[mid] < nums[mid - 1])
      return mid -1;
    // Case 3: This is the case as we know after the pivot element all the elements will be less than the start
    // so if it is the case where the nums[mid] < nums[start] then the elemets are smaller and the start is behind 
    // the pivot element so we will search backward because there will be our answer, so end = mid - 1;
    else if(nums[mid] < nums[start])
      end = mid - 1;
    else
    // else start = mid + 1, as now the mid is in the first line
      start = mid + 1;
  }
  return -1;
}

int binarySearch(vector<int>&nums, int target, int starts, int ends){
    int start = starts;
    int end = ends;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            end = mid - 1;
        else 
            start = mid + 1;
    }
    return -1;
}

int main(){
  vector<int>nums = {9, 12, 15, 16, 19, 2, 4 , 5, 6, 8};
  int pivot = findPivot(nums);
  int ans = -1;
  if(pivot == -1){
      ans = binarySearch(nums, target, 0, nums.size() -1);
  }
  else{
      if(target < nums[0])
          ans = binarySearch(nums, target, pivot + 1, nums.size()-1);
      if(ans != -1)
          return ans;
      else
          ans = binarySearch(nums, target, 0, pivot);
  }
  return 0;
}
