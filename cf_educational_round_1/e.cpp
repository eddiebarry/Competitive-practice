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

int DP_ans[30][30][51];


int DP(int n, int m, int k){
	if(n>m){
		n = n ^ m;
		m = n ^ m;
		n = n ^ m;
	}

	if(DP_ans[n-1][m-1][k]!=-1){
		return DP_ans[n-1][m-1][k];
	}	
	if(k==0){
		DP_ans[n-1][m-1][k] = 0;
		return 0;
	}
	else if (n*m==k){
		DP_ans[n-1][m-1][k] = 0;
		return 0;
	}
	else if (n*m<k){
		DP_ans[n-1][m-1][k] = INF;
		return INF;
	}
	else{
		int ans = INF;
		// int temp_ans;
		// cout<<"vertical\n";
		// vertical cut
		REP(i,m-1){
			// Now we have 2 rectangles of size
			// i+1 * n, m-(i+1) * n
			// We can take 0,1,2,3...k from rec1 and k, k-1, k-2...0 from rect 2
			REP(j,k+1){
				// cout<<i+1<<" "<<n<<" "<<j<<endl;
				// cout<<m-(i+1)<<" "<<n<<" "<<k-j<<endl;
				ans = min(n*n + DP(i+1,n,j) + DP(m-(i+1),n,k-j), ans);
			}
		}
		// cout<<"Horizontal\n";
		// horizontal cut
		REP(i,n-1){
			// Now we have 2 rectangles of size
			// m*(i+1), n-(i+1) * m
			// We can take 0,1,2,3...k from rec1 and k, k-1, k-2...0 from rect 2
			REP(j,k+1){
				// cout<<i+1<<" "<<m<<" "<<j<<endl;
				// cout<<n-(i+1)<<" "<<m<<" "<<k-j<<endl;

				ans = min(m*m + DP(i+1,m,j) + DP(n-(i+1),m,k-j), ans);
			}
		}
		DP_ans[n-1][m-1][k] = ans;
		return ans;
	}
	
}

/********** Main()  function **********/
int main()
{
	int tc, n, m, k;
	cin>>tc;
	memset(DP_ans,-1,sizeof(DP_ans));

	while(tc--){
		cin>>n>>m>>k;
		// cout<<n<<" "<<m<<" "<<k<<endl;		
		cout<<DP(n,m,k)<<"\n";
	}
	return 0;
}
/********  Main() Ends Here *************/