#include <bits/stdc++.h>
using namespace std;


void coinChange(int amt,int deno[],int n){
    vector<int> coins;
    int reqCoins = 0;
    for(int i=n-1;i>=0;i--){
        while(amt>=deno[i]){
            amt-=deno[i];
            reqCoins++;
            coins.push_back(deno[i]);
        }
    }

    cout<<"Minimum coins required are: "<<reqCoins<<endl;
    cout<<"Coins used are:"<<endl;
    for(auto it: coins){
        cout<<it<<" ";
}
    
}

int main(){

    int n;
    cout<<"Enter number of denominations: "<<endl;
    cin>>n;
    int deno[n];
    cout<<"Enter all the denominations: "<<endl;
    for(int i = 0; i<n;i++){
        cin>>deno[i];
    }
    cout<<"Enter amount: "<<endl;
    int amt;
    cin>>amt;
    coinChange(amt,deno,n);
   
    return 0;
}