
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<float,float>x,pair<float,float>y)
{
    float fr1 = x.first/x.second;
    float fr2 = y.first/y.second;
    return fr1>fr2;
}

int fractionalKnapsack(float w,vector<pair<float,float>>items){

    sort(items.begin(),items.end(),compare);
    float profit = 0.0;
    for(auto it: items){
        if(w>0){
            if(it.second<=w){
                w-=it.second;
                profit+=it.first;
            }
            else{
                profit+= float((it.first*w)/it.second);
                w = 0;
            }
        }
        else{
        break;
        }
    }
    return profit;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<float, float>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight of item number " << i + 1 << " : ";
        float p, w;
        cin >> p;
        cin >> w;
        arr[i].first = p;
        arr[i].second = w;
    }
    cout << "Enter the maximum weight bag can hold ";
    float W;
    cin >> W;
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr);
    
}