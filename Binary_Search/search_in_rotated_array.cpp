#include<stdc++.h>
unsing namespace  std;
// Some Modification is Needed is this code 
int binarySearch(vector<int>&nums, int target, int start, int end){
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

int findPivot(vector<int>&nums){
  int start = 0;
  int end = nums.size() - 1;

  while(start <= end){
    int mid = start + (end - start)/2;
    if((mid < end) && nums[mid] > nums[mid + 1])
      return mid;
    else if(mid > start && nums[mid] < nums[mid - 1])
      return mid;
    else if(nums[mid] < nums[start])
      start = mid + 1;
    else
      end = mid -1;
  }
  return -1;
}

int main(){
  return 0;
}
