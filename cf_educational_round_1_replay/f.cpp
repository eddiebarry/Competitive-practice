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
#include <iomanip>
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

class Point{
	public:
		ld x,y;

	Point(ld a, ld b){
		x = a;
		y = b;
	}

	Point(){
		x = 0;
		y = 0;
	}

	void get(){
		cin>>x>>y;
	}

	Point operator+(Point b ){
		return Point(x +  b.x, y + b.y);
	}

	Point operator-(Point b ){
		return Point(x -  b.x, y - b.y);
	}
};

typedef Point Vector;

ld DOT(Point a, Point b ){
	return a.x*b.x +  a.y * b.y;
}

ld CROSS(Point a, Point b ){
	return a.x*b.y -  a.y * b.x;
}

bool is_zero(ld a){
	return a<EPS && a>-EPS;
}

bool is_collinear(Vector a, Vector b){
	return is_zero(CROSS(a,b));
}

ld get_inter_param(Point x, Vector v, Point a, Vector b){
	ld k =  ( CROSS(a,b) - CROSS(x,b) ) / CROSS(v,b);
	return k;
}

/********** Main()  function **********/
int main()
{	
	ll n, m;
	cin>>n>>m;

	ld x,y;

	vector<Point> vec;
	REP(i,n){
		Point x;
		x.get();
		vec.PB(x);
	}
	vec.PB(vec[0]);

	REP(i,m){
		Point a,b;
		a.get();
		b.get();
		
		vector< pair<ld, ld> > intersections;
		// find all intersections
		Point x = a;
		Vector v = b-a;

		REP(i,n){
			Point a = vec[i];
			Vector b = vec[i+1]-vec[i];

			

			// find intersection
			if(is_zero(CROSS(v,b))){
				// parallel could be collinear
				
				// check if collinear
				if(is_zero(CROSS(a-x,v))){
					ld l = DOT( v, a - x ) / (DOT(v,v));
					ld r = DOT( v, a + b - x) / (DOT(v,v));;
					
					if(l>r){
						swap(l,r);
					}

					// cout<<l<<" is l"<<r<<" is r\n";
					// ld rate = 1;
					intersections.PB(MP(l, 2));
					intersections.PB(MP(r, -2));
				}
			}
			else{
				ld m = get_inter_param(a,b, x, v);
				ld rate = 1;

				// m is on the vector
				if(m>-EPS && m < 1+EPS){
					if(is_zero(m) || is_zero(m-1)){
						rate = 0.5;
					}

					ld k = get_inter_param(x, v, a, b);
					intersections.PB(MP(k, CROSS(v,b) > 0 ? rate : -rate));
				}
			}
		}
		sort(all(intersections));

		ld max_size = 0;
		ld is_in = 0;
		REP(i, intersections.size()){
			
			is_in += intersections[i].second;
			// cout<<intersections[i].first<<" "<<intersections[i].second<<"\n";
			// cout<<is_in<<"\n";

			if(!is_zero(is_in)){
				max_size += intersections[i+1].first - intersections[i].first;
			}
		}

		cout<<std::setprecision(20)<<max_size*sqrt(DOT(v,v))<<"\n";
	}

	return 0;
	
}
/********  Main() Ends Here *************/