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
typedef unsigned long long int ull;
typedef vector<long long> VLL;

int DP[31][31][51];

int min(int a, int b){
	return a<b?a:b;
}

int solve_dp(int n, int m, int k){
	if(n > m)
		std:swap(n,m);

	if(DP[n][m][k]!=-1){
		return DP[n][m][k];
	}

	if(n*m==k || k == 0){
		DP[n][m][k] = 0;
		return DP[n][m][k];
	}	

	ll temp_ans = INF;
	
	REP(i,k+1){
		// take i from one section and k-i from other section
		
		// cut horizontally
		FOR(j,1,n,1){
			temp_ans = min(  solve_dp(j, m, i) + solve_dp(n-j, m, k-i) + m * m , temp_ans);
		}

		// cut vertically
		FOR(j,1,m,1){
			temp_ans = min( solve_dp(n, j, i) + solve_dp(n, m-j, k-i) + n * n , temp_ans);
		}
	}

	DP[n][m][k] = temp_ans;

	return DP[n][m][k];
}

/********** Main()  function **********/
int main()
{	
	ll tc, n, m, k;
	cin>>tc;
	memset(DP,-1,sizeof(DP));

	solve_dp(30,30,50);

	while(tc--){
		cin>>n>>m>>k;
		if(DP[n][m][k]==-1){
			cout<<solve_dp(n,m,k)<<"\n";
		}
		else{
			cout<<solve_dp(n,m,k)<<"\n";
		}
	}
	return 0;
	
}
/********  Main() Ends Here *************/