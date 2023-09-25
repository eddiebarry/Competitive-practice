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
	ll tc, n, x;
	cin>>tc;

	while(tc--){
		int m, s;
		cin>>m>>s;

		VI vec(m);
		REP(i,m){
			cin>>vec[i];
		}
		

		ll sum = accumulate(all(vec),0LL);
		ll ac_4 = ((sum+s)*8) +1;
		

		ll n = -1;
		for(ll i = 1; i*i <= ac_4; i++){
			if(i*i==ac_4){
				n = i;
			}
		}

		// ll n = sqrt(1+8*sum);
		if(n!=-1){
			if(n%2==1){
				n = (n - 1)/2;
				if(*max_element(all(vec))<= n){
					cout<<"YES\n";
				}
				else{
					cout<<"NO\n";;
				}
				
			}
			else{
				cout<<"NO\n";;
			}
		}
		else{
			cout<<"NO\n";;
		}
	}
	return 0;
}
/********  Main() Ends Here *************/