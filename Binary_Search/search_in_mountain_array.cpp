#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int searchInMountainArray(vector<int>arr){
  int size = arr.size();
  int start = 0;
  int end = size -1;
  
  while(start < end){
    int mid = start + (end-start)/2;
    if(arr[mid] > arr[mid + 1])
      //You are at the decreasing part of the array and mid can be the possible answer that's why end = mid not mid -1
      end = mid;
    else
      // you are at the increasing part of the array, and we know already mid + 1 is greater and mid cannot be the
      // answer so we will do start = mid + 1 and not mid
      start = mid + 1;
  }
  return arr[start];
}

int main(){
  vector<int>arr = {2,7,12,16,18,15,13,5,1};
  int ans = searchInMountainArray(arr);
  cout<<"The Peak Element is: "<< ans <<endl;

  return 0;
};
