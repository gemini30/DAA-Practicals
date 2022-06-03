#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int len1 = mid - s +1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIdx = s;
    for(int i = 0;i<len1;i++){
        first[i]= arr[mainArrayIdx++];
    }

    mainArrayIdx = mid +1;
    for(int i = 0;i<len2;i++){
        second[i]= arr[mainArrayIdx++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIdx = s;

    while (index1 < len1 && index2<len2)
    {
        if(first[index1]<second[index2]){
            arr[mainArrayIdx++]=first[index1++];
        }
        else{
            arr[mainArrayIdx++]=second[index2++];
        }
    }

    while (index1<len1)
    {
        arr[mainArrayIdx++]=first[index1++];
    }
    while (index2<len2)
    {
        arr[mainArrayIdx++]=second[index2++];
    }
    
    delete []first;
    delete []second;

}

void mergeSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

return 0;
}