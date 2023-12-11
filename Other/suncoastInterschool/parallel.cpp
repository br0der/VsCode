#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<vector<ll>> vvlong;
ll MOD = 1e9+7;
#define pb push_back
string ln = "\n";

vvlong dp;
ll n, k, s;
ll func(int idx, int scoreLeft){
    if(idx==k){
        if(scoreLeft==0) return 1;
        return 0;
    }
    // Base case of finishing the last assignment
    
    if(scoreLeft<=0) return 0;
    // If you have already surpassed the score, this is not a valid way

    if(dp[idx][scoreLeft]==-1){
        ll out = 0;
        for(int i = 1; i <= 10; i++){
            // Score for the next task

            out+=func(idx+1, scoreLeft-i);
            // If we were on the next task with i less score to go, how many 
            // ways can we reach the desired score?

            out%=MOD;
        }

        dp[idx][scoreLeft] = out;
        // storing our answer so we don't have to compute it again.
    }
    return dp[idx][scoreLeft];
    // Because we use DP, previous computations get stored. The time complexity of this is
    // the maximum value of all of your states (k and k*10) multiplied by your transitions
    // (the [1:10] for loop). Time complexity of our DP works out to be O(k*k*10)
}

void solve()
{
    cin >> n >> k >> s;
    vector<vector<int>> startingVals(n);
    for(int i = 0; i < n; i++){
        startingVals[i] = {0, 0};
        // Every person starts off with 0 tasks
        // completed, and 0 score
    }
    for(int i = 0; i < s; i++){
        // setting up input, changing the starting vals vector
        int person; cin >> person;
        int score; cin >> score;
        startingVals[person-1][0] += 1;
        startingVals[person-1][1] += score;
    }
    dp = vector<vector<ll>>(k, vector<ll>(k*10+1, -1));
    ll maxScore = k*10;
    ll ans = 0;
    for(int i = 0; i <= maxScore; i++){
        // First, loop through all of the possible scores. 
        // Find how many ways each person can acheive this score and multiply them.
        ll curr = 1;
        for(int j = 0; j < n; j++){
            int completed = startingVals[j][0];
            int startingScore = startingVals[j][1];
            curr*=func(completed, i-startingScore);
            // See time complexity in func. Since we save previous answers
            // just count the time complexity in the DP. Imagine precomputing
            // the 2d (k x 10k) dp vector (array), then accessing the stored value at the
            // coordinates (completed, i-starting score)
            curr%=MOD;
        }
        ans+=curr;
        ans%=MOD;
    }
    // Final time complexity is the maximum of the dp and the double for loop, so
    // O(max(k*10*k, k*10*n))
    cout << ans << ln;
}
int main()
{
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}