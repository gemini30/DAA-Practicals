#include <bits/stdc++.h>
using namespace std;

void optimalStorageTapes(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    float Mrt = 0;
    int i = n;
    for (auto it : arr)
    {
        Mrt += it * i;
        i--;
    }
    cout << "The optimal way to store the tapes are in the order :";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    Mrt/=n;
    cout << "The mean time they take will be " << Mrt  << endl;
}

int main()
{
    int n;
    cout<<"Enter number of tapes: "<<endl;
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter tape lengths: "<<endl;
    for (auto &it : arr)
    {
        cin >> it;
    }
    optimalStorageTapes(arr, n);
    return 0;
}