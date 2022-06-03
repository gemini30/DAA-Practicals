#include <bits/stdc++.h>
using namespace std;

void Loading(vector<int> arr, int n, int W)
{
    int ceil = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= W)
        {
            ceil++;
            W -= arr[i];
        }
    }
    cout << "The containers included in the ship are ";
    for (int i = 0; i <= ceil; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    int W;
    cout << "Enter the maximum capacity ";
    cin >> W;
    Loading(arr, n, W);
    return 0;
}