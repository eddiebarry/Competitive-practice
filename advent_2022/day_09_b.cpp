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
#define print_set(cont) std::copy(all(cont), std::ostream_iterator<char>(std::cout, " ")); cout<<"\n";

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

vector<PII> delta = { 
	{ -1, 0 },
	{  1, 0 },
	{  0, 1 },
	{  0, -1},
};

/********** Main()  function **********/
int main()
{		
	char c;
	string x;
	int idx_0 = 1, idx_1 = 1;
	vector<string> vec;
	vector< vector<int> > arr(102, vector<int>(102, 10));
	
	while(cin>>x){				
		for(auto y: x){
			arr[idx_0][idx_1++]=y-'0';
		}
		idx_0++;
		idx_1 = 1;
	}
	int ans = 0;

	FOR(i,1,101,1){
		FOR(j,1,101,1){
			bool temp = true;
			for(auto x: delta){
				temp = temp && arr[i+x.first][j+x.second] > arr[i][j];
			}
			if(temp){
				ans += arr[i][j]+1;
			}
		}
	}
	cout<<ans<<"\n";
}
/********  Main() Ends Here *************/
