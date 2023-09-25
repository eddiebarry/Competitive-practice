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
	vector< vector<string> > vec;
	char c;
	string x;
	int sum = 0;
	while(cin>>x){		
		vector<string> temp;
		temp.push_back(x);
		REP(i,9){
			cin>>x;
			sort(all(x));
			temp.push_back(x);
		}
		cin>>c;

		REP(i,4){
			cin>>x;
			temp.push_back(x);
		}		
		vec.push_back(temp);

		set<char> alphabet[10];

		REP(i,'g'-'a'+1){
			alphabet[5].insert('a'+i);
			alphabet[6].insert('a'+i);
		}

		FOR(i, 0, 10, 1){
			if(temp[i].size()==2){
				for(auto x: temp[i]){
					alphabet[1].insert(x);
				}
			}
			if(temp[i].size()==3){
				for(auto x: temp[i]){
					alphabet[7].insert(x);
				}
			}
			if(temp[i].size()==4){
				for(auto x: temp[i]){
					alphabet[4].insert(x);
				}
			}
			if(temp[i].size()==5){
				set<char> temp_5;

				for(auto x: temp[i]){
					if(alphabet[5].find(x)!=alphabet[5].end()){
						temp_5.insert(x);
					}
				}
				alphabet[5] = temp_5;

			}
			if(temp[i].size()==6){
				set<char> temp_6;

				for(auto x: temp[i]){
					if(alphabet[6].find(x)!=alphabet[6].end()){
						temp_6.insert(x);
					}
				}
				alphabet[6] = temp_6;

			}
			if(temp[i].size()==7){
				for(auto x: temp[i]){
					alphabet[8].insert(x);
				}
			}
		}

		// a = [7] - [1]
		set<char> temp_7 = alphabet[7];
		for(auto x : alphabet[1]){
			temp_7.erase(x);
		}
		char a = *temp_7.begin();
		// cout<<a<<" is a\n";

		// g = INT[2,3,5] - [4] - a;
		set<char> temp_5 = alphabet[5];
		for(auto x : alphabet[4]){
			temp_5.erase(x);
		}
		temp_5.erase(a);

		char g = *temp_5.begin();
		// cout<<g<<" is g\n";

		// d = INT[2,3,5] - g - a;
		temp_5 = alphabet[5];
		temp_5.erase(a);
		temp_5.erase(g);

		char d = *temp_5.begin();
		// cout<<d<<" is d\n";

		// b = [4] - [7] - d;
		set<char> temp_4 = alphabet[4];
		for(auto x : alphabet[7]){
			temp_4.erase(x);
		}
		temp_4.erase(d);
		char b = *temp_4.begin();
		// cout<<b<<" is b\n";

		// f = INT[6,9,0] - a - d - g;
		set<char> temp_6 = alphabet[6];
		temp_6.erase(a);
		temp_6.erase(g);
		temp_6.erase(b);
		char f = *temp_4.begin();
		// cout<<f<<" is f\n";

		// c = [1] - f;
		set<char> temp_1 = alphabet[1];
		temp_1.erase(f);
		char c = *temp_1.begin();
		// cout<<c<<" is c\n";

		// c = [1] - f;
		set<char> temp_8 = alphabet[8];
		temp_8.erase(a);
		temp_8.erase(b);
		temp_8.erase(c);
		temp_8.erase(d);
		temp_8.erase(f);
		temp_8.erase(g);
		char e = *temp_8.begin();
		// cout<<e<<" is e\n";

		string one = string(1,c) + string(1,f);
		cout<<one<<" is one\n";


		break;
	}
	cout<<sum;
	
}
/********  Main() Ends Here *************/