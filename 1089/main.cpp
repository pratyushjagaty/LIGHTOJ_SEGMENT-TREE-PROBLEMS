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
typedef pair<lli, lli >/*--------------*/plli;
typedef vector<plli >/*-----------------*/vplli;

#define rep(i,a)/*---------------------*/for(i = 0 ; i < a ; i++)
#define repr(i,a)/*--------------------*/for(i = a ; i >= 0 ; i--)
#define REP(i,a,b)/*-------------------*/for(i = a ; i <= b ; i++)
#define REPR(i,a,b)/*------------------*/for(i = a ; i >= b ; i--)

#define scan(N)/*----------------------*/scanf("%d",&N)
#define print(N)/*---------------------*/printf("%d\n",N)
#define scan2(N1,N2)/*-----------------*/scanf("%d %d",&N1,&N2)
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
#define MAXN/*-------------------------*/1000005

template<class T> bool is_prime(T n) { if((n%2==0 and n>2) or n<2 )	return false; for(T i=3;i*i<=n;i+=2){ if(n%i==0) return false;}return true;}
template<class T> T power(int a, T n) {  if(!n)  return 1; else if(n == 1) return a; else { T res = power(a,n/2); if(n & 1) return (res*a*res); else return (res*res);}}

int n,q,tree[MAXN];

void update(int x,int delta)
{
    for(; x < MAXN ; x += x&-x)
        tree[x] += delta;
}
int query(int x)
{
    int res = 0;
    for(; x > 0 ; x -= x&-x)
        res += tree[x];
    return res;
}
int main()
{
	opt;
    int t,z;
    scan(t);
    REP(z,1,t)
    {
        scan2(n,q);
        int i,l,r,p,cnt = 0;
        printf("Case %d:\n",z);
        vector<pair<int,int> > ranges;
        map<int,int> m;
        vector<int> v,queries;
        rep(i,MAXN) tree[i] = 0;
        rep(i,n)
        {
            scan2(l,r);
            ranges.push_back(make_pair(l,r));
            v.pb(l);
            v.pb(r);
        }
        while(q--)
        {
            scan(p);
            v.pb(p);
            queries.pb(p);
        }
        sort(all(v));
        rep(i,v.size())
        {
            if(!m[v[i]])
            {
                m[v[i]] = ++cnt;
            }
        }
        rep(i,ranges.size())
        {
            update(m[ranges[i].ff],1);
            update(m[ranges[i].ss]+1,-1);
        }
        rep(i,queries.size())
        {
            print(query(m[queries[i]]));
        }
    }
	return 0;
}








