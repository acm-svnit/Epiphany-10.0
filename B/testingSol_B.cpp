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

const ll INF = 1e16;

int main()
{
    fastio;
    t()
    {
        ll n;
        cin>>n;
        vector<ll>a(n),x(n),b(n);
        for(ll i=0;i<n;i++)cin>>a[i];
        if(n>3)
        {
            for(ll i=1;i<n;i++) b[i] = a[i-1]-a[i];

            for(ll i=1;i<=n-2;i++){
                x[i] = b[i-1];
                if(i>=3) x[i] += x[i-3]; 
            }
            ll offset;
            if(n%3==0) offset = INF;
            else if(n%3==1){
                ll i = n-3;
                offset = a[i+2]-a[i+1]-x[i];
            }
            else {
                ll i = n-4;
                offset = a[i+2]-a[i+1]-x[i];
            } 
            for(ll i=1;i<=n-2;i+=3) x[i]+=offset;
        }
        vector<ll>out(n);
        for(ll i=0;i<n;i++)
            out[i] = (i>0 ? x[i-1] : 0)  + x[i] + a[i] + (i<n-1 ? x[i+1] : 0);
        bool ans= true;
        for(ll i=1;i<n;i++) {
            if(x[i]<0 || out[i]!=out[i-1]) ans=false;
        }
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";



    }


}