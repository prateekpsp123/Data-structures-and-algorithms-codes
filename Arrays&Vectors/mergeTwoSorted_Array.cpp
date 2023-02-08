#include<bits/stdc++.h>
using namespace std;   

vector<int> mergeSortedArray(vector<int>arr1, vector<int>arr2){
  
    int n = arr1.size();
    int m = arr2.size();
    vector<int>mergeArray(n+m);
    int i=0;
    int j=0;
    int mainIndex=0;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            mergeArray[mainIndex++] = arr1[i++];
        }
        else if(arr1[i] > arr2[j]){
            mergeArray[mainIndex++] = arr2[j++];
        }
        else{
            mergeArray[mainIndex++] = arr1[i++];
        }
    }

    while(i<n){
        mergeArray[mainIndex++] = arr1[i++];
    }
    while(j<m){
        mergeArray[mainIndex++] = arr2[j++];
    }
    return mergeArray;
}                       
int main(){
      
    vector<int>arr1{2,6,8,11,18,21};
    vector<int>arr2{1,12,23,34,36,41};
    vector<int>mergeArray = mergeSortedArray(arr1,arr2);
    cout<<"Your Merged Array is: "<<endl;
    for(auto i:mergeArray){
        cout<<i<<" ";
    }          
    return 0;          
}                      