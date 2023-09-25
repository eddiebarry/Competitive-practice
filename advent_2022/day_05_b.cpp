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
	char c;
	int x,y, a,b;
	while(cin>>x>>c>>y>>temp>>a>>c>>b){
		// FOR(i,x,y+1,1)
		if(x==a){
			FOR(i, min(y,b), max(y,b)+1, 1){
				arr[x][i]++;
			}
		}

		if(y==b){
			FOR(i, min(a,x), max(a,x)+1, 1){
				arr[i][y]++;
			}
		}		

		if(max(a,x)-min(a,x)==max(b,y)-min(b,y)){

			if(x>a){
				swap(x,a);
				swap(y,b);
			}

			FOR(i, x, a+1, 1){
				if(b>y){
					arr[i][y+i-x]++;
				}
				else{
					arr[i][y-i+x]++;
				}
				
			}
		}
	}
	int cnt = 0;
	REP(i, 1000){
		REP(j, 1000){
			if(arr[i][j]>1){
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";

	
}
/********  Main() Ends Here *************/