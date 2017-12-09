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
#define MAXN 100005

lli n,d,tree_min[4*MAXN],a[MAXN],tree_max[4*MAXN];

void build_min(lli node,lli start,lli end)
{
    if(start == end)
    {
        tree_min[node] = a[start];
        return ;
    }
    else
    {
        lli mid = (start + end) >> 1;
        build_min(2*node,start,mid);
        build_min(2*node+1,mid+1,end);
        tree_min[node] = min(tree_min[2*node],tree_min[2*node+1]);
    }
}

void build_max(lli node,lli start,lli end)
{
    if(start == end)
    {
        tree_max[node] = a[start];
        return ;
    }
    else
    {
        lli mid = (start + end) >> 1;
        build_max(2*node,start,mid);
        build_max(2*node+1,mid+1,end);
        tree_max[node] = max(tree_max[2*node],tree_max[2*node+1]);
    }
}

lli query_min(lli node,lli start,lli end,lli l,lli r)
{
    if(start > end or end < l or start > r)
        return inf;
    if(start >= l and end <= r)
        return tree_min[node];
    lli mid = (start+end) >> 1;
    lli p1 = query_min(2*node,start,mid,l,r);
    lli p2 = query_min(2*node+1,mid+1,end,l,r);
    return min(p1,p2);
}

lli query_max(lli node,lli start,lli end,lli l,lli r)
{
    if(start > end or end < l or start > r)
        return -inf;
    if(start >= l and end <= r)
        return tree_max[node];
    lli mid = (start+end) >> 1;
    lli p1 = query_max(2*node,start,mid,l,r);
    lli p2 = query_max(2*node+1,mid+1,end,l,r);
    return max(p1,p2);
}
int main()
{
	opt;
    lli t;
    scan(t);
    lli z;
    REP(z,1,t)
    {
        scan2(n,d);
        lli i,ans = -1;
        rep(i,4*MAXN) tree_min[i] = 0,tree_max[i] = 0;
        rep(i,n) scan(a[i]);
        build_min(1,0,n-1);
        build_max(1,0,n-1);
        rep(i,n-d+1)
        {
            ans = max(ans,query_max(1,0,n-1,i,i+d-1)-query_min(1,0,n-1,i,i+d-1));
        }
        printf("Case %lld: %lld\n",z,ans);
    }
	return 0;
}








