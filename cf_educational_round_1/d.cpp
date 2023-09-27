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
// #include <unordered_set>
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

int n,m,tc,ans;
int arr[1001][1001];
int num_paint = 0;
int connected_component_num=1e7+1;

MPII ans_map;

// int ans[1000][1000];

void dfs(int x, int y){
	// cout<<x<<" "<<y<<"\n";

	if(arr[x][y]==connected_component_num){
		return;
	}

	arr[x][y]=connected_component_num;
	

	if(arr[x+1][y]==0){
		num_paint++;
	}
	else if(arr[x+1][y]==1){
		dfs(x+1, y);
	}

	if(arr[x-1][y]==0){
		num_paint++;
	}
	else if(arr[x-1][y]==1){
		dfs(x-1, y);
	}

	if(arr[x][y+1]==0){
		num_paint++;
	}
	else if(arr[x][y+1]==1){
		dfs(x, y+1);
	}

	if(arr[x][y-1]==0){
		num_paint++;
	}
	else if(arr[x][y-1]==1){
		dfs(x, y-1);
	}
}

/********** Main()  function **********/
int main()
{	

	int a, b;

	cin>>a>>b>>tc;
	
	string x;
	REP(i,a){
		cin>>x;
		REP(j,b){
			arr[i][j] = x[j]=='.'? 1: 0;
		}
	}

	// REP(i,a){
	// 	REP(j,b){
	// 		cout<<arr[i][j];
	// 	}
	// 	cout<<"\n";
	// }

	

	
	while(tc){
		cin>>n>>m;	
		n--;
		m--;
		if(arr[n][m]>=1e7+1){
			cout<<ans_map[arr[n][m]]<<"\n";
		}
		else{
			num_paint = 0;
			dfs(n,m);	
			
			// REP(i,a){
			// 	REP(j,b){
			// 		cout<<arr[i][j]<<" ";
			// 	}
			// 	cout<<"\n";
			// }

			ans_map[connected_component_num]=num_paint;
			cout<<ans_map[connected_component_num++]<<"\n";
		}
		tc--;
	}
	return 0;
}
/********  Main() Ends Here *************/