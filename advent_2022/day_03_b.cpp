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

/********** Main()  function **********/
int main()
{
	std::string line;
	vector<string> nums_temp_a, nums_temp_b;
	while (cin>>line)
	{	
		nums_temp_a.push_back(line);
		nums_temp_b.push_back(line);
	}

	// find oxygen rating
	REP(i,12){		
		multiset<string> a_temp,b_temp;		
		for(auto x: nums_temp_a){
			if(x[i]=='0'){
				a_temp.insert(x);
			}
			else{
				b_temp.insert(x);
			}
		}
		if(a_temp.size()>b_temp.size()){
			nums_temp_a = vector<string> (a_temp.begin(), a_temp.end());
		}
		else{
			nums_temp_a = vector<string> (b_temp.begin(), b_temp.end());			
		}
		if(nums_temp_a.size()==1){
			break;
		}	
	}
	// find CO2 rating
	REP(i,12){		
		multiset<string> a_temp,b_temp;		
		for(auto x: nums_temp_b){
			if(x[i]=='0'){
				a_temp.insert(x);
			}
			else{
				b_temp.insert(x);
			}
		}
		if(a_temp.size()<=b_temp.size()){
			nums_temp_b = vector<string> (a_temp.begin(), a_temp.end());
		}
		else{
			nums_temp_b = vector<string> (b_temp.begin(), b_temp.end());			
		}		
		if(nums_temp_b.size()==1){
			break;
		}
	}

	bitset <12> first(nums_temp_a[0]);
	bitset <12> secnd(nums_temp_b[0]);

	cout<<secnd.to_ulong()*first.to_ulong();
	return 0;
}
/********  Main() Ends Here *************/