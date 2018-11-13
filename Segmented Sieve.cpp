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
vector<ll> prime2;
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

void segmentedSieve(ll a, ll b)
{
    if(a==1) a++;
    ll sqrtn = sqrt(b);
    sieveE(sqrtn);
    memset(ar,true, sizeof ar);

    for(int i=0; i<prime.size() && prime[i]<=sqrtn; i++){
        ll p = prime[i];
        ll j = p*p;
        if(j<a) j = ((a+p-1)/p)*p;

        for( ; j<=b; j+=p){
            ar[j-a] = false;
        }
    }

    for(ll i=a; i<=b; i++){
        if(ar[i-a]==true) prime2.push_back(i);
    }

}


int main()
{
    #ifdef dipu
    //freopen("inp.txt","r",stdin);
    #endif

    /// difference between a and b must be less than or equal 10^5. That is (b-a)<=10^5.
    /// Maximum value of a and b must be less than or equal 10^12. That is a,b <=10^12.
    /// Otherwise segmented sieve will not work.


    ll a,b;
    cin >> a >> b;

    segmentedSieve(a,b);
    for(int i=0; i<prime2.size(); i++){
        cout << prime2[i] << " ";
    }
    cout << endl;

    return 0;
}
