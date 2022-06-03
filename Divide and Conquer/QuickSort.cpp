#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int s,int e){

    int pivot=arr[s];
    int count=0;
    
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }

    int pivotIdx = s+count;
    swap(arr[s],arr[pivotIdx]);

    int i = s, j = e;
    while (i<pivotIdx && j>pivotIdx)
    {
        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) 
        {
            j--;
        }

        if(i<pivotIdx && j>pivotIdx){
             swap(arr[i++], arr[j--]);
        }

    }

    return pivotIdx;
    
}

void QuickSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[10] = {2,4,1,6,9,10,0,9,3,5};
    int n = 10;

    QuickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;

return 0;
}