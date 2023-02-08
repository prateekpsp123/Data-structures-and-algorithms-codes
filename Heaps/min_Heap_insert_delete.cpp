#include<bits/stdc++.h>
using namespace std;   
//Class Heap 
class min_heap{
    public:
    int arr[100];
    int size;
    //Constructor
    min_heap()
    {
        size =0;
        arr[0] = -1;
    }
    //Insert Function
    void insert(int data)
    {
        size++;
        int index = size;
        while(index > 1)
        {
            int parent = index/2;
            if(arr[parent] > arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deltefromHeadp()
    {
        if(size == 0)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        //step 1: Put last element into the first index
        arr[1] = arr[size];
        //step 2: Remove the Last Element
        size--;
        //step 3: Take root Node to its correct Position
        int i=1;
        while(i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] > arr[leftIndex])
            {
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
           else if(rightIndex < size && arr[i] > arr[rightIndex])
            {
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};                        
int main(){            
                       
                       
    return 0;          
}                      