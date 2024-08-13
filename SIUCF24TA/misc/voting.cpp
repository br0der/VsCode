#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,q,c;
        cin>>n>>q>>c;
        vector<vector<int>> voting(n);
        for (int i=0;i<n;i++){
            int num;
            cin>>num;
            num--;
            voting[num].push_back(i);
        }

        for (int i=0;i<q;i++){
            int l,r,n;
            cin>>l>>r>>n;
            l--;
            r--;
            n--;
            if (voting[n].size()==0){
                cout<<"0\n";
            }else{
                cout<<upper_bound(voting[n].begin(),voting[n].end(),r) - lower_bound(voting[n].begin(),voting[n].end(),l)<<"\n";
            }
        }
    }
    return 0;
}
/*
1
5 1 2
1 1 1 1 1
1 5 2
*/
