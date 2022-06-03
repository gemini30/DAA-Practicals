#include <bits/stdc++.h>
using namespace std;

void findMinMax(vector<int> &nums, int low, int high, int &max, int &min)
{

    if (low == high)
    {
        if (nums[low] < min)
        {
            min = nums[low];
        }
        if (nums[low] > max)
        {
            max = nums[low];
        }
        return;
    }

    if (low == high - 1)
    {
        if (nums[low] < nums[high])
        {
            if (nums[low] < min)
            {
                min = nums[low];
            }
            if (nums[low] > max)
            {
                max = nums[low];
            }
        }
        else
        {
            if (nums[low] < min)
            {
                min = nums[low];
            }
            if (nums[low] > max)
            {
                max = nums[low];
            }
        }

      return;  
    }

    int mid = low+high/2;
    findMinMax(nums,low,mid,max,min);
    findMinMax(nums,mid+1,high,max,min);
}

int main(){
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    vector<int> nums(n);
     for (auto &it : nums)
    {
        cin >> it;
    }
    int min = INT_MAX, max = INT_MIN;
    findMinMax(nums,0,n-1,max,min);
    cout<<"Max element is: "<<max<<endl;
    cout<<"Min element is: "<<min;
    
    return 0;
}
