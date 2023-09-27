/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*
*/
 
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)

#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)

#define MP make_pair
#define PB push_back

#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long long int ll;
typedef unsigned long long int ull;

/********** Main()  function **********/
int main()
{
	string x;
	cin>>x;

	vector<char> str(x.size());
	int idx=0;
	for(auto ch : x){
		str[idx++]=ch;
	}
	// for(auto x: str){
		// cout<<x;
	// }
	// cout<<"\n";


	int tc, l, r, k;
	cin>>tc;

	while(tc--){
		VII new_pos;
		cin>>l>>r>>k;

		// cout<<l<<r<<k<<"\n";
		FOR(i,l-1,r,1){
			char x = str[i];
			int rel_idx = i - (l-1);
			int new_idx = (l-1) + (rel_idx + k) % (r-l+1);

			// cout<<i<<" "<<new_idx<<" "<<x<<"\n";

			new_pos.PB(MP(new_idx, (int)x));
		}
		// cout<<"\n\n\n";
		for(auto x: new_pos){
			str[x.first] = (char) x.second;
		}
	}
	for(auto x: str){
		cout<<x;
	}
	return 0;
}
/********  Main() Ends Here *************/