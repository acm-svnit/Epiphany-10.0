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

class Matrix{
    public:
    ll n,m;
    vector<vector<ll>>A;
    Matrix(ll n1,ll m1)
    {
        n = n1;
        m = m1;
        A = vector<vector<ll>>(n,vector<ll>(m));
    }
    Matrix(ll n1){
        n = n1;
        m = n1;
        A = vector<vector<ll>>(n,vector<ll>(m));
    }
    Matrix operator * (const Matrix &other){
        ll p = other.n;
        ll q = other.m;
        if(m!=p) assert(0);
        Matrix product(n,q);
        for(ll i=0;i<n;i++)
            for(ll j=0;j<q;j++)
                for(ll k=0;k<m;k++)
                    product.A[i][j] = (product.A[i][j] + A[i][k] * other.A[k][j])%2;
        return product;
    }
};




bool isBobWin(ll n,ll k,ll type)
{
    vector<ll>aux(n);
    ll E,O;
        E = type==2 || type==3 ; 
        O = type==2 || type==4;
        for(ll i=0;i<n;i++){
            if(i&1) aux[i] = E;
            else aux[i] = O;
        }

    //matrix of size 2*n
    // 0 to n-1 represent AUX array
    // n to 2n-1 represent dp array
    Matrix Multiplier(2*n);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<2*n;j++){
            if(j<n) {
                if(j==i)
                    Multiplier.A[i][j] = 1;
                else
                    Multiplier.A[i][j] = 0; 
            }
            else{
                if(j==i+n)
                    Multiplier.A[i][j] = 1;
                else
                    Multiplier.A[i][j] = 0; 
            }
        }
    }
    for(ll i=n;i<2*n;i++){
        for(ll j=n;j<2*n;j++){
            ll x = i-n;
            ll y = j-n;
            ll dist;
            if(j>=i) dist = j-i;
            else dist = n - i + j ;
            if(dist>x) Multiplier.A[i][j]=0;
            else Multiplier.A[i][j]=1; 
        }
    }


    Matrix ans(2*n);
    for(ll i=0;i<2*n;i++)ans.A[i][i]=1;
    while(k)
    {
        if(k&1) ans = ans * Multiplier;
        Multiplier = Multiplier*Multiplier;
        k/=2;
    }

    Matrix in(1,2*n);
    for(ll i=0;i<n;i++) in.A[0][i] = aux[i];
    for(ll i=n;i<2*n;i++) in.A[0][i] = 1;

    Matrix out = in * ans;

    // for(ll i=0;i<2*n;i++) cout<<out.A[0][i]<<" ";

    ll H=0,T=0;
    for(ll i=n;i<2*n;i++) 
        if(out.A[0][i]) H++;
        else T++;

    if(H>T) return false;
    return true; 
        

}


int main()
{
    ll n,k,type;
    /*
    HEAD = 1
    TAIL = 0
    for based 1 index
    type-1 = all zero
    type-2 = all one
    type-3 = 1 at even possition, else 0
    type-4 = 0 at even possition, else 1
    */
    t()
    {
        cin>>n>>k;
        for(type=1;type<=4;type++)
        {
            if(isBobWin(n,k,type)){
                break;
            }
        }
        if(type>4) cout<<"ALICE\n";
        else cout<<"BOB "<<type<<"\n";
    }


       

}