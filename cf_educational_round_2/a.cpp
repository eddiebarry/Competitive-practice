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
	string str;
	cin>>str;

	int is_first = 0;
	bool a_init=true, b_init=true;
	string a = "";
	string b = "";
	string temp = "";

	str += ";";

	// cout<<str<<"\n";

	for(auto c: str){
		if(c==44||c==59){
			// cout<<temp<<" "<<a_init<<" "<<b_init<<" "<<is_first<<"\n";
			if( is_first==0 && temp !="" || temp=="0"){
				a+= a_init? temp: ","+temp;
				a_init=false;
			}
			else{
				b+= b_init? temp: ","+temp;
				b_init=false;
			}
			temp="";
			is_first = 0;
		}
		
		else if(isalpha(c)||c=='.'){
			is_first=1;
			temp += c;
		}
		else if(c=='0'&&is_first==0){
			is_first=1;
			temp += c;
		}
		else{
			temp += c;
		}
	}
	a = a==""?"-":"\""+a+"\"";
	b = b==""?"-":"\""+b+"\"";

	cout<<a<<"\n";
	cout<<b<<"\n";
	return 0;
}
/********  Main() Ends Here *************/