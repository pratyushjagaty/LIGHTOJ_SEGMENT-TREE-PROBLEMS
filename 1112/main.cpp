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

#define scan(N)/*----------------------*/scanf("%d",&N)
#define print(N)/*---------------------*/printf("%d",N)
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

template<class T> bool is_prime(T n) { if((n%2==0 and n>2) or n<2 )	return false; for(T i=3;i*i<=n;i+=2){ if(n%i==0) return false;}return true;}
template<class T> T power(int a, T n) {  if(!n)  return 1; else if(n == 1) return a; else { T res = power(a,n/2); if(n & 1) return (res*a*res); else return (res*res);}}

#define MAXN 100005

int a[MAXN],tree[4*MAXN],lazy[4*MAXN];
int n,q;
void build(int node,int start,int end)
{
    if(start == end)
    {
        tree[node] = a[start];
        return;
    }
    int mid = (start+end)>>1;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node] = tree[2*node] + tree[2*node+1];
}
void update(int node,int start,int end,int l,int r,int val)
{
    if(lazy[node])
    {
        tree[node] += (end-start+1)*lazy[node];
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or end < l or start > r)
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
    int mid = (start+end) >> 1;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node,int start,int end,int l,int r)
{
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node])
    {
        tree[node] += (end-start+1)*lazy[node];
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    int mid = (start+end) >> 1;
    int p1 = query(2*node,start,mid,l,r);
    int p2 = query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{
	opt;
    int z,t;
    scan(t);
    for(z = 1 ; z <= t ; z++)
    {
        scan2(n,q);
        int i;
        rep(i,n) scan(a[i]);
        printf("Case %d:\n",z);
        build(1,0,n-1);
        while(q--)
        {
            int tp,l,r,val;
            scan2(tp,l);
            if(tp == 1)
            {
                print(a[l]);
                printf("\n");
                update(1,0,n-1,l,l,-a[l]);
                a[l] = 0;
            }
            else if(tp == 2)
            {
                scan(val);
                a[l] += val;
                update(1,0,n-1,l,l,val);
            }
            else if(tp == 3)
            {
                scan(r);
                printf("%d\n",query(1,0,n-1,l,r));
            }
        }
    }
	return 0;
}








