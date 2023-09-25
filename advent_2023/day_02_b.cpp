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

#define P1_RCK 'A'
#define P1_PAP 'B'
#define P1_XIR 'C'
#define P2_RCK 'X'
#define P2_PAP 'Y'
#define P2_XIR 'Z'

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
	char first, second;

	map<char,char> second_win;
	second_win[P1_RCK]=P2_PAP;
	second_win[P1_PAP]=P2_XIR;
	second_win[P1_XIR]=P2_RCK;

	map<char,char> second_draw;
	second_draw[P1_RCK]=P2_RCK;
	second_draw[P1_PAP]=P2_PAP;
	second_draw[P1_XIR]=P2_XIR;	

	map<char,char> second_lose;
	second_lose[P1_RCK]=P2_XIR;
	second_lose[P1_PAP]=P2_RCK;
	second_lose[P1_XIR]=P2_PAP;


	map<char,int> result_scores;
	result_scores['X']=0;
	result_scores['Y']=3;
	result_scores['Z']=6;


	map<char,int> char_scores;
	char_scores[P2_RCK]=1;
	char_scores[P2_PAP]=2;
	char_scores[P2_XIR]=3;

	int score = 0;
	char picked_char;


	while (cin>>first>>second)
	{	
		score += result_scores[second];

		// MUST WIN
		if(second=='Z'){
			picked_char = second_win[first];
		}
		// MUST DRAW
		else if(second=='Y'){
			picked_char = second_draw[first];
		}
		// MUST LOSE
		else if(second=='X'){
			picked_char = second_lose[first];
		}
		score += char_scores[picked_char];

		// cout<<first<<" "<<second<<" "<<picked_char<<"\n";	
		// break;	
	}
	cout<<score;
	return 0;
}
/********  Main() Ends Here *************/