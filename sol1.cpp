#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define lld long long int

#define mp make_pair
#define fi first
#define se second
#define all(c) c.begin(),c.end()
#define PI 3.1415926
//a power n mod p
long long int modp(lld a,lld p,lld n)
{
    int d[100];
    int i,j,k,l;
    for(i=0;n>=1;i++)
    {
        d[i]=n%2;
        n/=2;
    }
    l=i;
    long long int e=1;
    if(d[0]==1) e*=(a%p);
    for(i=1;i<l;i++)
    {
        a*=a;
        a=a%p;
        if(d[i]==1) 
        {
            e*=a;
            e=e%p;
        }
    }
    return e%p;
}
lld modInverse(lld n, lld p) 
{ 
    return modp(n, p, p-2); 
}

long long int nCrModPFermat(lld n, lld r,lld p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
    
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    lld fac[n+1]; 
    fac[0] = 1; 
    for (lld i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
}


long long int mini(lld a,lld b)
{
    if(a>b) return b;
    return a;
}


int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //long long int p1=1000000007,p2=998244353;
    long long int z,p,x,y,min,R,max,n,m,i,j,k,ii,jj;
    long long int a[100][100],b[100][100],c[100][100];
    cin>>n>>k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            b[i][j]=c[i][j]=0;
        }
    b[n-1][n-1]=a[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
        b[n-1][i]=a[n-1][i]+b[n-1][i+1];
        c[n-1][i]=100*(n-1)+i+1;

        b[i][n-1]=a[i][n-1]+b[i+1][n-1];
        c[i][n-1]=100*(i+1)+n-1;
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=n-2;j>=0;j--)
        {
            if(b[i+1][j]>b[i][j+1])
            {
                b[i][j]=b[i][j+1]+a[i][j];
                c[i][j]=100*i+j+1;
            }
            else
            {
                b[i][j]=b[i+1][j]+a[i][j];
                c[i][j]=100*(i+1)+j;
            }
        }
    }
    
    min=b[0][0];
    i=0;
    j=0;
    while(i!=n-1 || j!=n-1)
    {
        x=c[i][j];
        i=x/100;
        j=x%100;
        if(i+j >= n) a[i][j]*=-1;
    }
    
    
    b[n-1][n-1]=a[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
        b[n-1][i]=a[n-1][i]+b[n-1][i+1];

        b[i][n-1]=a[i][n-1]+b[i+1][n-1];
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=n-2;j>=0;j--)
        {
            if(b[i+1][j]<b[i][j+1])
            {
                b[i][j]=b[i][j+1]+a[i][j];
            }
            else
            {
                b[i][j]=b[i+1][j]+a[i][j];
            }
        }
    }
    max=b[0][0];
    ans=max-min;
    if(ans>=k) cout<<"win";
    else cout<<"lose";
    return 0;
}
