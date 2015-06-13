/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
}

LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
LL a[maxn], n, t, m, p, ans;


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(~scanf("%lld%lld", &n, &p))
    {
        for(int i=0;i<n;i++) scanf("%lld", &a[i]), a[i]=a[i]%p;
        sort(a, a+n);
        LL ans=(a[n-2]+a[n-1])%p;
        int i=0, j=n-1;
        //while(a[i]+a[j]>=p) j--;
        while(i<j)
        {
            while(i<j && a[i]+a[j]>=p) j--;
            if(i<j) ans=max(ans, (a[i]+a[j])%p);
            i++;
            while(i<j && a[i]+a[j]<p) i++;
            if(i-1<j) ans=max(ans, (a[i-1]+a[j])%p);
            j--;
        }
        printf("%lld\n", ans);//<<endl;
    }
}
