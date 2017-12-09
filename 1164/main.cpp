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
#define MAXN 100005

template<class T> bool is_prime(T n) { if((n%2==0 and n>2) or n<2 )	return false; for(T i=3;i*i<=n;i+=2){ if(n%i==0) return false;}return true;}
template<class T> T power(int a, T n) {  if(!n)  return 1; else if(n == 1) return a; else { T res = power(a,n/2); if(n & 1) return (res*a*res); else return (res*res);}}
lli n,q,tree[4*MAXN],lazy[4*MAXN];

void update(lli node,lli start,lli end,lli l,lli r,lli val)
{
    if(lazy[node])
    {
        tree[node] += (end - start + 1)*lazy[node];
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l)
        return ;
    if(start >= l and end <= r)
    {
        tree[node] += (end-start+1)*val;
        if(start != end)
        {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return ;
    }
    lli mid = (start+end) >> 1;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
    tree[node] = tree[2*node] + tree[2*node+1];
}
lli query(lli node,lli start,lli end,lli l,lli r)
{
    if(start > end or end < l or start > r)
        return 0;
    if(lazy[node])
    {
        tree[node] += (end - start + 1)*lazy[node];
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(start >= l and end <= r)
        return tree[node];
    lli mid = (start+end) >> 1;
    lli p1 = query(2*node,start,mid,l,r);
    lli p2 = query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{
	opt;
    lli z,t;
    scan(t);
    REP(z,1,t)
    {
        lli i,n,q;
        scan2(n,q);
        rep(i,4*MAXN)
        {
            tree[i] = 0;
            lazy[i] = 0;
        }
        printf("Case %lld:\n",z);
        while(q--)
        {
            lli c,x,y,val;
            scan3(c,x,y);
            if(!c)
            {
                scan(val);
                update(1,0,n-1,x,y,val);
            }
            else
            {
                print(query(1,0,n-1,x,y));
                printf("\n");
            }
        }
    }
	return 0;
}








