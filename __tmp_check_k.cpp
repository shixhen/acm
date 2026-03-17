#include <bits/stdc++.h>
using namespace std;

long long solve_dp(int n, int m, vector<int> A, vector<int> B){
    vector<pair<int,int>> missions(n);
    int sumA=0,sumB=0;
    for(int i=0;i<n;i++){missions[i]={A[i],B[i]}; sumA+=A[i]; sumB+=B[i];}
    sort(missions.begin(), missions.end(), [&](auto &x, auto &y){return x.second>y.second;});
    int maxTime=min(m,sumA);
    int maxPick=min(n,maxTime);
    int sumBLimit=min(sumB,maxPick*10);
    const long long NEG=-(1LL<<60);
    static long long dp[305][305];
    for(int t=0;t<=maxTime;t++) for(int s=0;s<=sumBLimit;s++) dp[t][s]=NEG;
    dp[0][0]=0;
    for(auto [a,b]:missions){
        for(int t=maxTime-a;t>=0;t--){
            for(int s=sumBLimit-b;s>=0;s--){
                if(dp[t][s]==NEG) continue;
                dp[t+a][s+b]=max(dp[t+a][s+b], dp[t][s]+s);
            }
        }
    }
    long long ans=0;
    for(int t=0;t<=maxTime;t++) for(int s=0;s<=sumBLimit;s++) ans=max(ans,dp[t][s]);
    return ans;
}

long long brute(int n,int m, vector<int>A, vector<int>B){
    long long ans=0;
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    for(int mask=0; mask<(1<<n); mask++){
        vector<int> v;
        int tm=0;
        for(int i=0;i<n;i++) if(mask>>i&1){ v.push_back(i); tm+=A[i]; }
        if(tm>m) continue;
        sort(v.begin(), v.end(), [&](int i,int j){ if(B[i]!=B[j]) return B[i]>B[j]; return i<j;});
        long long cur=0, pre=0;
        for(int i: v){ cur += pre; pre += B[i]; }
        ans=max(ans,cur);
    }
    return ans;
}

int main(){
    mt19937 rng(123456);
    for(int n=1;n<=12;n++){
        for(int it=0; it<20000; it++){
            int m=rng()%21; // allow >10 too
            vector<int>A(n),B(n);
            for(int i=0;i<n;i++){A[i]=rng()%10+1; B[i]=rng()%10+1;}
            auto x=solve_dp(n,m,A,B);
            auto y=brute(n,m,A,B);
            if(x!=y){
                cout<<"Mismatch!\n";
                cout<<n<<" "<<m<<"\n";
                for(int i=0;i<n;i++) cout<<A[i]<<(i+1==n?'\n':' ');
                for(int i=0;i<n;i++) cout<<B[i]<<(i+1==n?'\n':' ');
                cout<<x<<" "<<y<<"\n";
                return 0;
            }
        }
    }
    cout<<"OK\n";
}
