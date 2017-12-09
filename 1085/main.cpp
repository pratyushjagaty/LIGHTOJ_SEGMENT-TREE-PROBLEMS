/*
	##############################
	## Author: Pratyush Gaurav ###
	## College: NIT ROURKELA #####
	##############################
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long/*--------------------*/lli;
typedef long double/*------------------*/ld;
typedef unsigned long long/*-----------*/ulli;
typedef pair<lli, lli >/*----------------*/plli;
typedef vector<plli >/*-----------------*/vplli;

#define rep(i,a)/*---------------------*/for(i = 0 ; i < a ; i++)
#define repr(i,a)/*--------------------*/for(i = a ; i >= 0 ; i--)
#define REP(i,a,b)/*-------------------*/for(i = a ; i <= b ; i++)
#define REPR(i,a,b)/*------------------*/for(i = a ; i >= b ; i--)

#define scan(N)/*----------------------*/scanf("%lld",&N)
#define print(N)/*---------------------*/printf("%lld",N)
#define scan2(N1,N2)/*-----------------*/scanf("%lld %lld",&N1,&N2)
#define print2(N1,N2)/*----------------*/printf("%lld %lld",N1,N2)
#define scan3(N1,N2,N3)/*--------------*/scanf("%lld %lld %lld",&N1,&N2,&N3)
#define print3(N1,N2,N3)/*-------------*/printf("%lld %lld %lld",N1,N2,N3)

#define lb/*---------------------------*/lower_bound
#define ub/*---------------------------*/upper_bound
#define pb/*---------------------------*/push_back
#define popb/*-------------------------*/pop_back

#define mem(a,b)/*---------------------*/memset(a,b,sizeof(a))
#define opt/*--------------------------*/ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz/*---------------------------*/size()

#define MP/*---------------------------*/make_pair
#define bs/*---------------------------*/binary_search
#define gcd(a, b)/*--------------------*/__gcd(a, b)
#define lcm(a, b)/*--------------------*/((a)*((b)/gcd(a,b)))
#define sqr(x)/*-----------------------*/(x)*(x)
#define all(a)/*-----------------------*/a.begin(),a.end()

#define ff/*---------------------------*/first
#define ss/*---------------------------*/second

#define endl/*-------------------------*/'\n'
#define inf/*--------------------------*/(lli)2000000000000
#define MOD/*--------------------------*/(lli)1000000007

template<class T> bool is_prime(T n) { if((n%2==0 and n>2) or n<2 )	return false; for(T i=3;i*i<=n;i+=2){ if(n%i==0) return false;}return true;}
template<class T> T power(int a, T n) {  if(!n)  return 1; else if(n == 1) return a; else { T res = power(a,n/2); if(n & 1) return (res*a*res); else return (res*res);}}

#define MAXN 2000005

lli n,BIT[MAXN],a[MAXN];

void update(lli x,lli delta)
{
    for(;x <= n ;x += x&-x)
        BIT[x] += delta;
}
lli query(lli x)
{
    lli res = 0;
    for(;x > 0 ;x -= x&-x)
        res += BIT[x];
    return res;
}
int main()
{
	opt;
    lli z,t;
    scan(t);
    REP(z,1,t)
    {
        scan(n);
        map<lli,lli> m;
        lli i,cnt = 0,ans = 0;
        vector<lli> b;
        BIT[0] = 0;
        REP(i,1,n)
        {
            scan(a[i]);
            BIT[i] = 0;
            b.push_back(a[i]);
        }
        sort(all(b));
        rep(i,n)
        {
            if(!m[b[i]])
            {
                m[b[i]] = ++cnt;
            }
        }
        REP(i,1,n)
        {
            lli res = (query(m[a[i]]-1) + 1)%MOD;
            ans = (ans + res)% MOD;
            update(m[a[i]],res);
        }
        printf("Case %lld: %lld\n",z,ans);
    }
	return 0;
}








