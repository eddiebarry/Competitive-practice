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


class Board {
	public: 
		int arr[5][5];

		int sum_marked;

		int mark(int score){
			sum_marked = 0;
			REP(i,5){
				REP(j,5){
					if(score==arr[i][j]){
						arr[i][j] = -1;						
					}
					
					if(arr[i][j] != -1){
						sum_marked += arr[i][j];
					}
				}
			}
			bool bingo = true; 
			REP(i,5){
				bingo = true;
				REP(j,5){
					bingo = arr[i][j]==-1 && bingo;
				}

				if(bingo){
					return sum_marked*score;
				}
			}

			REP(j,5){
				bingo = true;
				REP(i,5){
					bingo = arr[i][j]==-1 && bingo;
				}

				if(bingo){
					return sum_marked*score;
				}
			}

			return -1;
		}

		void print(){
			REP(i,5){
				REP(j,5){
					cout<<arr[i][j]<<" ";
				}
				cout<<"\n";
			}
			cout<<"\n\n\n\n";
		}

		Board(VI x){
			REP(i,25){
				arr[i/5][i%5]=x[i];
			}
			sum_marked = 0;
		}
};

/********** Main()  function **********/
int main()
{
	int x;
	char c;
	VI bingo_nums;
	while(cin>>x>>c){
		bingo_nums.push_back(x);		
		if(c=='*'){
			break;
		}		
	}

	vector<Board> boards;
	while(cin>>x){
		VI vec(25);
		vec[0]=x;
		REP(i,24){
			cin>>vec[i+1];
		}
		boards.push_back(Board(vec));
	}
	
	int max_score = -1, score;
	for(auto x: bingo_nums){
		REP(i,boards.size()){
			score = boards[i].mark(x);
			max_score = score > max_score ? score : max_score;
			

			if(score != -1){				
				cout<<score<<" "<<x<<"\n";
				boards[i].print();				
			}
		}
		if(max_score!=-1){
			break;
		}
	}
	cout<<max_score<<"\n";

	
}
/********  Main() Ends Here *************/