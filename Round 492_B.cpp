/*Writer : Md. Shafiur Rahman Dipu  */

#include <bits/stdc++.h>
using namespace std;

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define pi 2*acos(0.00)
#define INF 2e18

#define ull unsigned long long
#define ll long long
#define ld long double

#define vi vector<int>
#define qi queue<int>
#define si stack<int>
#define li list<int>
#define pb push_back
#define mx 100000007

#define rep(a,b) for(int i=a; i<b; i++)

void print2(vi v){for(int i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;}
void print1(int ar[],int n){for(int i=0; i<n; i++){cout<<ar[i]<<" ";}cout<<endl;}

vector<long> prime;
bool ar[1000008];

void sieveE(int n)
{
    memset(ar,true,sizeof ar);
    ar[0] = ar[1] = false;
    prime.push_back(2);
    for(int i=4; i<=n; i+=2) {
        ar[i] = false;
    }

    int sqrtn = sqrt(n);
    for(int i=3; i<=sqrtn; i+=2){
        if(ar[i]==true){
            for(int j = i*i; j<=n; j+=2*i){
                ar[j] = false;
            }
        }
    }

    for(int i=3; i<=n; i+=2){
        if(ar[i]==true) prime.push_back(i);
    }
}


ll NOD(ll n)
{
    ll sqrtn = sqrt(n);
    ll res = 1;
    int p;
    for(int i=0; i<prime.size() && prime[i]<=sqrtn ; i++){
        if(n%prime[i]==0){
            p = 0;
            while(n%prime[i]==0){
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt(n);
            p++;
            res *= p;
        }
    }
    if(n!=1){
        res *= 2;
    }

    return res;
}



int main()
{
    #ifdef dipu
    //freopen("inp.txt","r",stdin);
    #endif

    /// This code can find number of divisors of upto 10^12.
    /// That is the value of n can be maximum 10^12.
    /// With complexity of O(P(sqrt(n))) where P(sqrt(n)) defines the number of primes less than sqrt(n)
    /// There will be also additional complexity for Sieve.


    sieveE(1000005);
    ll n;
    cin >> n;
    ll x = NOD(n);
    cout << x << endl;

    return 0;
}
