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

int arr[1000][1000];

/********** Main()  function **********/
int main()
{	
	string temp;
	int idx, x,y;

	vector<string> vec(9,"a");
	vec[0]="dlvtmhf";
	vec[1]="hqgjctnp";
	vec[2]="rsdmph";
	vec[3]="lbvf";
	vec[4]="nhglq";
	vec[5]="wbdgrmp";
	vec[6]="gmnrchlq";
	vec[7]="clw";
	vec[8]="rdlqjzmt";

	stack<char>stk[9];

	REP(i,9){
		for(auto x: vec[i]){
			stk[i].push(x);
		}
	}
	while(cin>>temp>>idx>>temp>>x>>temp>>y){
		x--;
		y--;
		REP(i, idx){			
			char c = stk[x].top();

			stk[x].pop();
			stk[y].push(c);
		}
	}
	string ans = "";
	REP(i,9){
		ans += toupper(stk[i].top());
	}
	cout<<ans<<"\n";
	
}
/********  Main() Ends Here *************/