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
#include <iomanip>
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
#define EPS 1e-10
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
typedef long double ld;


struct POINT {
	ld x,y;

	POINT(){
		x=0;
		y=0;
	}

	POINT(ld a, ld b){
		x = a;
		y = b;
	}
};

POINT point_get(){
	POINT p_temp;
	cin>>p_temp.x>>p_temp.y;
	return p_temp;
}

typedef POINT VECTOR;

POINT operator+(POINT a, POINT b){
	return POINT(a.x+b.x, a.y+b.y);
}

POINT operator-(POINT a, POINT b){
	return POINT(a.x-b.x, a.y-b.y);
}

ld CROSS(const VECTOR &a,const VECTOR &b){
	return a.x * b.y - a.y * b.x;
}

ld DOT(const VECTOR &a,const VECTOR &b){
	return a.x * b.x + a.y *b.y;
}

ld MAG(const VECTOR &a){
	return sqrt(a.x * a.x + a.y *a.y);
}

bool is_zero(ld a){
	return a< EPS && a> -EPS;
}

ld get_seg_inter(const POINT &p,const VECTOR &v,const POINT &q,const VECTOR &w){
	VECTOR u = p-q;
	return CROSS(u,w) / CROSS(w,v);
}

vector< pair<ld, double> > intersections;

void get_intersections(const POINT &p,const VECTOR &v,const POINT &q,const VECTOR &w){
	// check if parallel
	if(is_zero(CROSS(v,w))){
		// if collinear
		if(is_zero(CROSS(q-p, v))){
			// find intersection
			ld l = DOT(q   - p, v) / DOT(v,v);
			ld r = DOT(q+w - p, v) / DOT(v,v);

			if (l>r){
				std::swap(l,r);
			}
			intersections.PB(make_pair(l,-1));
			intersections.PB(make_pair(r,+1));
		}
	}
	else{
		ld temp = get_seg_inter(q,w, p,v);
		if( - EPS < temp  && temp < 1+EPS){
			// seg is on q
			ld rate = 1;			
			if(is_zero(temp) || is_zero(temp-1)){
				rate=0.5;
			}

			ld temp = get_seg_inter(p,v,q,w);
			intersections.push_back( MP( temp, CROSS(w,v) > 0 ? -rate:rate) );
		}
	}
}

/********** Main()  function **********/
int main()
{
	int n,m;
	cin>>n>>m;


	vector<POINT> p_vec;
	REP(i,n){
		POINT p = point_get();
		p_vec.PB(p);
	}


	while(m--){
		POINT a,b;
		a = point_get();
		b = point_get();
		// cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<"\n";
		intersections.clear();

		REP(i,n){
			// iterate over all segment and add parameter intersection
			get_intersections(a, b-a, p_vec[i], p_vec[(i+1)%n] - p_vec[i]);
		}
		sort(all(intersections));

		ld ans = 0;
		ld rate = 0;
		for(int i = 0; i < intersections.size(); i++){
			// cout<<intersections[i].first<<" "<<intersections[i].second<<"\n";

			rate +=intersections[i].second;
			if(!is_zero(rate)){
				ans += intersections[i+1].first - intersections[i].first;
			}
		}
		cout<<std::setprecision(20)<<ans*MAG(b-a)<<"\n";
	}
	return 0;
}
/********  Main() Ends Here *************/