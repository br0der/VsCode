#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

ll n;
vector<ll> psum;
ll sum(int l, int r, int shift) {
    assert(l <= r);
    l+=shift, r+=shift;
    if (r>=n and l < n) {
        r%=n;
        return psum[r+1] + psum[n]-psum[l];
    }
    else if (r>=n == l>=n) {
        l%=n, r%=n;
        return psum[r+1]-psum[l];
    }
    else {
        assert(1==0);
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../data/input.txt","r", stdin);
        freopen("../../data/output.txt","w", stdout);
    #endif

    int tc; cin >> tc;
    while (tc--) {
        ll q; cin >> n >> q;
        vector<int> lis(n); rep(i, n) cin >> lis[i];
        
        psum = vector<ll> (n+1, 0); rep(i, n) psum[i+1] = psum[i]+lis[i];
        rep(i, q) {
            ll a, b; cin >> a >> b;
            ll out = 0;
            a--, b--;
            int aa = a/n, bb = b/n;
            a%=n;
            b%=n;
            if (aa==bb) {
                cout << sum(a, b, aa) << endl;
            }
            else {
                out+=(bb-aa-1)*psum[n];
                // cout << out << endl;
                out+=sum(a, n-1, aa);
                // cout << out << endl;
                out+=sum(0, b, bb);
                cout << out << endl;
            }
        }
    }

    return 0;
}