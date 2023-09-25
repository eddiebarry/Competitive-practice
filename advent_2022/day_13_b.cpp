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
	{1,1},
	{-1,-1},
	{1,-1},
	{-1,1},

	{0,1},
	{0,-1},
	{1,0},
	{-1,0},	
};

bool in(int A, int B, int C){
	return B <= A && A <= C;
}


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


int arr[40][10];

/********** Main()  function **********/
int main()
{		
	int x,y;
	char c;

	VII vec;
	REP(i,827){
		cin>>x>>c>>y;
		vec.push_back( MP(x,y) );
	}

	string temp;

	REP(i,12){
		VII new_vec;

		cin>>temp>>temp>>temp;
		// cout<<temp;
		vector<string> temp_split = split(temp);		

		int split_line = stoi(temp_split[1]);
		
		if(temp_split[0]=="x"){
			for(auto x: vec){
				if(x.first>split_line){
					x.first = split_line - (x.first - split_line);
				}

				if(x.first!=split_line){
					new_vec.push_back(x);
				}
			}
		}
		else{
			for(auto x: vec){
				if(x.second>split_line){
					x.second = split_line - (x.second - split_line);
				}

				if(x.second!=split_line){
					new_vec.push_back(x);
				}
			}
		}

		vec=new_vec;
	}
	set<PII> s;
	for(auto x: vec){
		s.insert(x);		
	}

	

	for(auto x: s){
		arr[x.first][x.second]=1;		
	}
	REP(j, 10){
		REP(i,40){
			if(arr[i][j]==1){
				cout<<"#";
			}
			else{
				cout<<" ";
			}
		}
		cout<<"\n";
	}
	
	// cout<<s.size();
}
/********  Main() Ends Here *************/