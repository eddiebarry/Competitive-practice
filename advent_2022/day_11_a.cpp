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

/********** Main()  function **********/
int main()
{		
	string x;
	int arr[10][10];
	// int diff[10][10];
	int idx_x = 0, idx_y = 0;
	int flashes = 0;
	while(cin>>x){						
		for(auto y: x){
			arr[idx_x][idx_y++] = y -'0';
		}
		idx_x++;
		idx_y=0;
	}
	REP(x,100){
		queue<PII> q;

		set<PII> flash;

		REP(i,10){
			REP(j,10){				
				arr[i][j]++;								
				if(arr[i][j]>9){
					// add all neighbors
					flash.insert(MP(i,j));

					for(auto x: delta){
						if( 
							in(i+x.first , 0, 9) && 
							in(j+x.second, 0, 9) 
						){
							q.push(MP(i+x.first,j+x.second));					
						}
					}					
				}
			}
		}

		while(!q.empty()){
			PII temp = q.front();
			q.pop();

			// hasnt flashed
			if(flash.find(temp)==flash.end() ){
				int i = temp.first, j = temp.second;
				arr[i][j]++;
				

				// If it flashes
				if(arr[i][j]>9){					
					flash.insert(MP(i,j));

					// add all neighbors
					for(auto x: delta){
						if( 
							in(i+x.first , 0, 9) && 
							in(j+x.second, 0, 9) 
						){
							temp = MP(i+x.first, j+x.second);

							// if the neighbor hasnt flashed
							if(flash.find(temp)==flash.end() )
								q.push(temp);					
						}
					}					
				}
			}
		}

		REP(i,10){
			REP(j,10){
				if(arr[i][j]==10){
					flashes++;
					arr[i][j]=0;
				}
			}
		}

		cout<<"################################\n";
		REP(i,10){
			REP(j,10){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	

	cout<<flashes<<"\n";
}
/********  Main() Ends Here *************/