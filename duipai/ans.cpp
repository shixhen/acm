#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=1e9;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll tc;cin>>tc;
    while(tc--)
    {
        ll n;cin>>n;
        vector<ll>vec(n);
        for(ll&i:vec)cin>>i;
        vector<ll>stk;
        for(ll&i:vec)
        {
            while(!stk.empty()&&stk.back()>=i)stk.pop_back();
            stk.push_back(i);
        }
        vec=stk;
        n=size(vec);
        vector<ll>dp(n+1,inf);dp[0]=0;
 
        vector<ll>ptr(129);
        for(ll i=0;i<n;i++)
        {
            for(ll cost=1;cost<=128;cost++)
            {
                while(ptr[cost]<n&&(vec[ptr[cost]]+vec[i]-1)/vec[i]<=cost)
                {
                    ptr[cost]++;
                    dp[ptr[cost]]=min(dp[ptr[cost]],dp[i]+cost);
                }
            }
        }
        cout<<dp[n]<<"\n";
    }
}