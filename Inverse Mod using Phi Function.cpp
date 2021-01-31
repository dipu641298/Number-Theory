
#include<bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mx = 100005;
const int INF = 999999999;


ll bmod(ll a, ll b, ll m)
{
    if(b == 0){return 1;}
    else if(b%2==1){
        return ((a%m) * bmod(a, b -1, m))%m;
    }
    else{
        b /= 2;
        return (bmod(a,b,m) * bmod(a,b,m))%m;
    }
}

bool pr[100007];
vector<int> prime;

void sieve(int n)
{
    memset(pr, true, sizeof pr);
    pr[0] = pr[1] = false;
    prime.push_back(2);
    int sqt = sqrt(n);
    for(int i=4; i<=n; i+=2){
        pr[i] = false;
    }

    for(int i=3; i<sqt; i+=2){
        if(pr[i] == true){
            for(int j = i*i; j<=n; j+= 2*i){
                pr[j] = false;
            }
        }
    }

    for(int i = 3; i<=n; i++){
        if(pr[i] == true){
            prime.push_back(i);
        }
    }

}

ll phi(ll x)
{
    ll p = x;
    ll sqrtn = sqrt(x);
    for(int i=0; i<prime.size() && prime[i]<=sqrtn; i++){
        if(x%prime[i] == 0){
            p /= prime[i];
            p *= prime[i] -1;

            while(x%prime[i]==0){
                x /= prime[i];
            }
            sqrtn = sqrt(x);
        }

    }

    if(x!=1){
        p /= x;
        p *= x -1 ;
    }

    return p;
}

int main()
{
    sieve(100005);
    #ifdef dipu
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif
    ll n,m;
    cin >> n >> m;
    ll p = phi(m);
    ll mod_inv = bmod(n,p-1,m);

    cout << mod_inv << endl;


   return 0;
}
