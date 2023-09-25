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
#include <unordered_map>
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
#define IN(A, MIN, MAX) ( MIN <= A && A <= MAX)

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
	{0,1},
	{0,-1},
	{1,0},
	{-1,0},
};

vector<string> split(string x){
	
	std::string s = x;
	std::string delimiter = "=";
	s += delimiter;

	vector<string> vec;
	
	size_t pos = 0;
	std::string token;
	
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		vec.push_back(token);
		s.erase(0, pos + delimiter.length());
	}

	return vec;
}

/********** Main()  function **********/
int main()
{		
	string x, a, b;
	vector<VI> vec;
	while(cin>>a){
		VI temp;
		for(auto x: a){
			temp.push_back(x-'0');
		}
		vec.push_back(temp);
	}
	int x_size = vec[0].size();
	int y_size = vec.size();

	int dist[y_size][x_size];
	REP(i, x_size){
		REP(j, y_size){
			dist[j][i]=INF;
		}
	}

	// cout<<x_size<<" "<<y_size<<"\n";

	set< PII > pq;
	pq.insert(MP(0,0));

	while(!pq.empty()){
		int score = (*pq.begin()).first;
		int y = (*pq.begin()).second / 1000;
		int x = (*pq.begin()).second % 1000;

		pq.erase(*pq.begin());

		int new_x, new_y;
		for(auto diff: delta){			
			new_y = y + diff.first;
			new_x = x + diff.second;

			if(IN(new_x,0,x_size-1) && IN(new_y, 0, y_size-1)){
				if(dist[new_y][new_x] > score+ vec[new_y][new_x]){
					dist[new_y][new_x] = score+ vec[new_y][new_x];
					pq.insert(MP(dist[new_y][new_x], new_y* 1000 +  new_x ));
				}
			}
		}
	}
	cout<<dist[y_size-1][x_size-1];
}
/********  Main() Ends Here *************/