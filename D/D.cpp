#include<bits/stdc++.h>
using namespace std;

const long long int M = 1e9 + 7;

string s;
int d;
vector<vector<vector<vector<vector<long long int>>>>> dp;

long long int dControllableNumbers(int n , bool tight , bool leading , bool check , bool pos) {
    if(n == 0) {
        return check == 1;
    }
    if(dp[n][tight][leading][check][pos] != -1) {
        return dp[n][tight][leading][check][pos];
    }
    int ub = tight ? (s[s.size()-n]-'0') : 9;
    long long int ans = 0;
    for(int i = 0 ; i <= ub ; ++i) {
        ans = (ans%M + dControllableNumbers(n-1 , tight&(i == ub) , leading & (i == 0) , check & (((leading & (i == 0)) == 0 && pos == 0 && i == d) ? 0 : 1) , ((leading & (i == 0)) == 0) ? (pos^1) : pos)%M)%M;
    }
    return dp[n][tight][leading][check][pos] = ans%M;
}

bool checkForL(int n) {
    for(int i = 1 ; i <= n ; ++i) {
        if(i%2 == 0) {
            if((s[i-1]-'0') == d) {
                return false;
            }
        }
        else {
            // Not needed anything
        }
    }
    return true;
}

void solve() {
    string l , r;
    cin >> l >> r >> d;
    s = r;
    dp = vector<vector<vector<vector<vector<long long int>>>>> (s.size()+5 , vector<vector<vector<vector<long long int>>>> (2 , vector<vector<vector<long long int>>> (2 , vector<vector<long long int>> (2 , vector<long long int> (2 , -1)))));
    long long int ansr = dControllableNumbers(s.size() , 1 , 1 , 1 , 1);
    s = l;
    dp = vector<vector<vector<vector<vector<long long int>>>>> (s.size()+5 , vector<vector<vector<vector<long long int>>>> (2 , vector<vector<vector<long long int>>> (2 , vector<vector<long long int>> (2 , vector<long long int> (2 , -1)))));
    long long int ansl = dControllableNumbers(s.size() , 1 , 1 , 1 , 1);
    int c = checkForL(s.size());
    cout << (ansr%M - ansl%M + c + M)%M << "\n";
    cout << ansr << " " << ansl << "\n";
}

int main() {
    int tc = 1;
    cin >> tc;
    for(int i = 0 ; i < tc ; ++i) {
        solve();
    }    
}
