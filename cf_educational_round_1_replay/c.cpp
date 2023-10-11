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

#define print_cont(cont) std::copy(all(cont), std::ostream_iterator<decltype (cont)::value_type>(std::cout, " ")); cout<<"\n";

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
typedef long double ld;
typedef unsigned long long int ull;
typedef vector<long long> VLL;

/********** Main()  function **********/
int main()
{	
	ll tc;
	ld y, x;
	cin>>tc;

	vector< pair<ld, int> > angle;
	REP(i,tc){
		cin>>x>>y;
		ld angle_with_x_axis = atan2(y,x);
		angle.push_back(MP(angle_with_x_axis, i));
	}
	sort(all(angle));
	angle.push_back(angle[0]);

	ld angle_min = 2.0 * PI;
	ll ans_l, ans_r;

	REP(i, tc){
		ld angle_dif = angle[i+1].first - angle[i].first;		
		angle_dif = angle_dif < 0 ? -angle_dif: angle_dif;
		
		if(angle_dif > PI){
			angle_dif = 2.0*PI - angle_dif;
		}

		if (angle_dif < angle_min){
			ans_l = angle[i+1].second;
			ans_r = angle[i].second;
			angle_min = angle_dif;
		}
	}
	cout<<ans_l+1<<" "<<ans_r+1;

	return 0;
	
}
/********  Main() Ends Here *************/