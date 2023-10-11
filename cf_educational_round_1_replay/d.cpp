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

int arr[1001][1001];
int visited[1001][1001];

int curr_component;

int get_flattened_idx(int x, int y){
	return x * 1000 + y;
}

/********** Main()  function **********/
int main()
{	
	ll  n, m, tc;
	cin>>n>>m>>tc;
	REP(i,n){
		string x;
		cin>>x;
		REP(j,m){
			arr[i][j] = x[j] == '*' ? 0 : 1;
		}
	}
	
	

	int x,y;
	MPII ans;	
	REP(i,tc){
		curr_component = i+1;
		cin>>x>>y;
		x--;
		y--;
		
		if(visited[x][y]==0){
			// not visited
			stack<int> to_visit;
			int curr_ans = 0;

			// SETI to_visit;
			to_visit.push(get_flattened_idx(x,y));
			while(!to_visit.empty()){
				int flat_idx = to_visit.top();
				to_visit.pop();
				int i = flat_idx / 1000, j = flat_idx % 1000;
				if(visited[i][j]!=0){
					continue;
				}

				visited[i][j] = curr_component;
				if(arr[i+1][j]==0){
					curr_ans++;
				}else{
					to_visit.push(get_flattened_idx(i+1,j));
				}
				if(arr[i-1][j]==0){
					curr_ans++;
				}else{
					to_visit.push(get_flattened_idx(i-1,j));
				}
				if(arr[i][j+1]==0){
					curr_ans++;
				}else{
					to_visit.push(get_flattened_idx(i,j+1));
				}
				if(arr[i][j-1]==0){
					curr_ans++;
				}
				else{
					to_visit.push(get_flattened_idx(i,j-1));
				}
			}

			ans[curr_component]=curr_ans;
			cout<<curr_ans<<"\n";
		}
		else{
			cout<<ans[visited[x][y]]<<"\n";
		}
	}
	return 0;
	
}
/********  Main() Ends Here *************/