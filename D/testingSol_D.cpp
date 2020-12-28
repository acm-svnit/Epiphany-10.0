#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define debug3(x, y,z) cout << #x << " = " << x << "   " << #y << " = " << y << " "<<#z<<" = "<<z<<"\n";
#define debugarray(arr,n) { cout << "[" ; for(ll i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"] , \n";}

const ll INF = 1e12;


// string is 0-index based
// compute D-valid in [1,R]
ll compute(string R,char D)
{
    ll n = R.length();
    vector<vector<ll>>dp(n,vector<ll>(4,0));
    dp[0][0] = 1; // start with zeros
    dp[0][1] = 0; //D-valid when start form even index
    dp[0][2] = R[0]-'0'-1; // D-valid when start from odd index
    dp[0][3] = 1; // D-valid when equal to R

    for(ll i=1;i<n;i++){
        dp[i][0] = 1;
        if(i%2==0){ // current index is odd when based 1
            dp[i][3] =  dp[i-1][3] * 1;
            dp[i][1] = (dp[i-1][1] * 9 )%MOD;
            dp[i][2] = (dp[i-1][2] * 10 + dp[i-1][0] * 9 + dp[i-1][3]*(R[i]-'0'))%MOD;
        }
        else{
            dp[i][3] = (dp[i-1][3] * (R[i]!=D))%MOD ;
            dp[i][2] = (dp[i-1][2]*9 + dp[i-1][3]*(R[i]-'0') - (D<R[i])*dp[i-1][3] + MOD )%MOD;
            dp[i][1] = (dp[i-1][1] * 10 + dp[i-1][0] * 9)%MOD ;
        }
    }
    ll ans = (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] - 1 + MOD)%MOD;
    return ans;
}


int main()
{
    fastio;
    ll i,j,n,m,x,y;
    t()
    {
        string L,R;
        char D;
        cin>>L>>R>>D;

        // doing L-1
        for(i=(ll)L.length()-1;i>=0;i--){
            if(L[i]=='0') L[i]='9';
            else{
                L[i]--;
                break;
            }
        }
        if(L.size()>1 && L[0]=='0') L.erase(0,1);

        ll ansR = compute(R,D);
        ll ansL = compute(L,D);
        // debug2(ansL,ansR);
        ll ans = (ansR-ansL + MOD)%MOD;
        cout<<ans<<"\n";
        
        



    }      
}