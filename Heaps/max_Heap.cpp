#include<bits/stdc++.h>
using namespace std;  
//Class Heap 
class max_heap{
    public:
    int arr[100];
    int size;
    //Constructor
    max_heap()
    {
        size =0;
        arr[0] = -1;
    }
    //Insert Function
    void insertIntoHeap(int data)
    {
        size++;
        arr[size] = data;
        int index = size;
        while(index > 1)
        {
            int parent = index/2;
            if(arr[parent] < arr[index])
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
    void deltefromHeap()
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
            int larger;
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex > size && rightIndex <= size)
            {
                larger = rightIndex;
                if(arr[i] < arr[larger])
                {
                    swap(arr[i],arr[larger]);
                    i = larger;
                }
                else
                {
                    return;
                }
            }
            else if(rightIndex > size && leftIndex <= size)
            {
                larger = leftIndex;
                if(arr[i] < arr[larger])
                {
                    swap(arr[i],arr[larger]);
                    i = larger;
                }
                else
                {
                    return;
                }
            }
            else if(leftIndex <= size && rightIndex <= size)
            {
                larger = arr[leftIndex] > arr[rightIndex] ? leftIndex : rightIndex;
                if(arr[i] < arr[larger])
                {
                    swap(arr[i],arr[larger]);
                    i = larger;
                }
                else
                {
                    return;
                }
            }
            else
            {
                return;
            }
        }
    }
    void printHeap()
    {
        for(int i=1; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};                       
int main(){ 

    max_heap h1;
    h1.insertIntoHeap(23);
    h1.insertIntoHeap(42);
    h1.insertIntoHeap(83);
    h1.insertIntoHeap(12);
    h1.insertIntoHeap(17);
    h1.deltefromHeap();
    h1.deltefromHeap();
    h1.insertIntoHeap(35);
    h1.printHeap();
    return 0;          
}                      