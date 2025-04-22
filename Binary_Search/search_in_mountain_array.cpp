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
      end = mid;
    else
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
