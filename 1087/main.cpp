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

lli a[MAXN],BIT[MAXN],vis[MAXN],n,q;

void update(lli x,lli del)
{
    for(;x <= n ; x += x&-x)
        BIT[x] += del;
}
lli query(lli x)
{
    lli sum = 0;
    for(;x > 0 ; x -= x&-x)
        sum += BIT[x];
    return sum;
}
int main()
{
	opt;
    lli t,z;
    scan(t);
    REP(z,1,t)
    {
        lli nn,i,cnt = 0;
        scan2(nn,q);
        n = nn+q+1;
        rep(i,MAXN)
        {
            BIT[i] = 0;
            a[i] = 0;
            vis[i] = 0;
        }
        printf("Case %lld:\n",z);
        REP(i,1,nn)
        {
            scan(a[i]);
            update(i,1);
            vis[i] = 1;
            cnt++;
        }

        char ch;
        lli k;
        while(q--)
        {
            getchar();
            scanf("%c %lld",&ch,&k);
            if(ch == 'a')
            {
                nn++;
                a[nn] = k;
                vis[nn] = 1;
                cnt++;
                update(nn,1);
            }
            else
            {
                if(k > cnt)
                    printf("none\n");
                else
                {
                    lli lo = 1,hi = nn;
                    while(lo <= hi)
                    {
                        lli mid = (lo+hi) >> 1;
                        lli val = query(mid);
                        if(val < k)
                            lo = mid+1;
                        else if(val > k)
                            hi = mid-1;
                        else if(val == k)
                        {
                            if(vis[mid])
                            {
                                printf("%lld\n",a[mid]);
                                vis[mid] = 0;
                                update(mid,-1);
                                cnt--;
                                break;
                            }
                            else
                                hi = mid-1;
                        }

                    }

                }
            }
        }
    }
	return 0;
}








