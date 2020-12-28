#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long int a , b , c;
    cin >> a >> b >> c;
    if((a+b+c)%4 == 0 && 3*a >= (b+c) && 3*b >= (a+c) && 3*c >= (a+b)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    long long int tc = 1;
    cin >> tc;
    while(tc-- > 0) {
        solve();
    }
}
