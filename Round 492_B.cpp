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


int primeList[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43 };
ull resNum, resDiv,n;

void HCN(int pos, int limit, ull num, ull div)
{
    if(div > resDiv){
        resNum =  num;
        resDiv = div;
    }
    else if(div == resDiv && num < resNum){
        resNum = num;
    }

    if(pos==14) return;

    ull p = primeList[pos];

    for(int i=1; i<=limit; i++){
        if( p*num > n) break;
        HCN(pos+1,i, p*num, div*(i+1));
        p *= primeList[pos];
    }

}

int main()
{
    #ifdef dipu
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif

    cin >> n;
    int p = ceil(log2(n));
    HCN(0,p,1,1);

    cout << resNum << endl;


    return 0;
}
