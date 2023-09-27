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


// long double get_angle_with_x(long double x, long double y){
// 	// long double x1 = x*1.0, y1 = y*1.0 ;
// 	long double angle = std::atan2l(y, x);

// 	return angle;
// }

/********** Main()  function **********/
int main()
{	
	// cout<<(get_angle_with_x(1,-1.732) * 180) / PI <<"\n";
	int tc;
	cin>>tc;

	// VII vectors;
	vector< pair<long double,int> > angle_with_x;

	REP(i,tc){
		long double x,y;
		cin>>x>>y;
		angle_with_x.PB(MP( std::atan2(y, x) ,i));
		// cout<<(angle_with_x[i].first * 180) / PI <<" "<<x<<" "<<y<<"\n";
	}
	sort(all(angle_with_x));

	int x,y;

	long double max_dist = 2.0*acos(-1);

	REP(i,tc){
		long double diff = angle_with_x[(i+1)%tc].first -  angle_with_x[i].first;
		// long double angle2 = ;
		if (diff < 0){
			diff += 2.0*acos(-1);
		}

		if(diff<max_dist){
			max_dist = diff;

			x = angle_with_x[i].second;
			y = angle_with_x[(i+1)%tc].second;
		}
	}
	cout<<x+1<<" "<<y+1<<"\n";



	return 0;
}
/********  Main() Ends Here *************/