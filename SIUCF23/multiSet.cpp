#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> vlong;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvlong;
ll MOD = 0;
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())



void solve()
{
    // empty multiset container
	multiset<int> gquiz1;

	// insert elements in random order
	gquiz1.insert(40);
	gquiz1.insert(30);
	gquiz1.insert(60);
	gquiz1.insert(20);
	gquiz1.insert(50);

	// 50 will be added again to
	// the multiset unlike set
	gquiz1.insert(50);
	gquiz1.insert(10);

	// printing multiset gquiz1
	cout << "\nThe multiset gquiz1 is : \n";
	for (auto itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;

	// assigning the elements from gquiz1 to gquiz2
	multiset<int> gquiz2(gquiz1.begin(), gquiz1.end());

	// print all elements of the multiset gquiz2
	cout << "\nThe multiset gquiz2 \n"
			"after assign from gquiz1 is : \n";
	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;

	// remove all elements up to element
	// with value 30 in gquiz2
	cout << "\ngquiz2 after removal \n"
			"of elements less than 30 : \n";
	gquiz2.erase(gquiz2.begin(), gquiz2.find(30));
	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}

	// remove all elements with value 50 in gquiz2
	int num;
	num = gquiz2.erase(50);
	cout << "\ngquiz2.erase(50) : \n";
	cout << num << " removed \n";
	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << endl;

	// lower bound and upper bound for multiset gquiz1
	cout << "\ngquiz1.lower_bound(35) : \n"
		<< *gquiz1.lower_bound(35) << endl;
	cout << "gquiz1.upper_bound(40) : \n"
		<< *gquiz1.upper_bound(40) << endl;

	// lower bound and upper bound for multiset gquiz2
	cout << "gquiz2.upper_bound(60) : \n"
		<< (gquiz2.upper_bound(60)==gquiz2.end()) << endl;
	cout << "gquiz2.upper_bound(40) : \n"
		<< *gquiz2.upper_bound(40) << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    solve();
    return 0;
}