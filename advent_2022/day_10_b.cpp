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

/********** Main()  function **********/
int main()
{		
	string x;
	map<char, int> mp;
	mp[')']=3;
	mp[']']=57;
	mp['}']=1197;
	mp['>']=25137;

	mp['(']=1;
	mp['[']=2;
	mp['{']=3;
	mp['<']=4;

	map<char, char> opp;
	opp[')']='(';
	opp[']']='[';
	opp['}']='{';
	opp['>']='<';

	set<char> open_chars{'(','[','{','<'};
	set<char> clos_chars{')',']','}','>'};

	vector<ll> ans;
	while(cin>>x){				
		stack <char> stk;
		bool incomplete=true;
		for(auto c: x){
			// cout<<c<<" ";
			if( open_chars.find(c)!= open_chars.end() ){
				stk.push(c);
			}
			else{
				if(stk.top()==opp[c]){
					stk.pop();
				}
				else{
					incomplete = false;					
					break;
				}
			}
		}
		if(incomplete){
			ll total_score = 0;
			while(!stk.empty()){
				// cout<<stk.top()<<" ";
				total_score *= 5;
				total_score += mp[stk.top()];
				stk.pop();
			}
			ans.push_back(total_score);
		}
	}
	sort(all(ans));

	cout<<ans[ans.size()/2]<<"\n";
}
/********  Main() Ends Here *************/