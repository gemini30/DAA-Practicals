#include <bits/stdc++.h>
using namespace std;

 bool isSafe(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int r = row;
        int c = col; 
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        
        // Check row
        col = c; 
        row = r;
        while(col>=0) {
            if(board[row][col] == 'Q'){
                 return false;
            }
            col--; 
        }
    
        // Check lower diagonal
        row = r;
        col = c; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--; 
        }
        
        return true; 
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '_'; 
            }
        }
    }
     vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '_'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n); 
        return ans; 
    }
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

vector<vector<string>> res = solveNQueens(4);

    for(auto it: res){
        for(auto it2:it){
        cout<<it2<<"\n";
        }
        cout<<endl;
}

int sols = res.size();
cout<<"Number of unique ways = "<<sols<<endl;
return 0;
}