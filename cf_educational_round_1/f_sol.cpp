/*
*   Copyright (C) 2015 All rights reserved.
*   
*   filename: 598F.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2015-11-14 00:19:39
*   last modified: 2015-11-14 00:19:39
*/
#include<bits/stdc++.h>
using namespace std;

typedef long double LD;
LD get()
{
	double x;
	scanf("%lf", &x);
	return x;
}

struct P
{
	LD x, y;
	P() {}
	P(LD x, LD y): x(x), y(y) {}
	void read() { x = get(), y = get(); }
};

typedef P V;
V operator + (const V &A, const V &B) { return V(A.x + B.x, A.y + B.y); }
V operator - (const V &A, const V &B) { return V(A.x - B.x, A.y - B.y); }
LD Cross(const V &A, const V &B) { return A.x * B.y - A.y * B.x; }
LD Dot(const V &A, const V &B) { return A.x * B.x + A.y * B.y; }
LD Length(const V &A) { return sqrt(Dot(A, A)); }

const LD eps = 1e-10;
inline int dcmp(LD x) { return (x > eps) - (x < -eps); }

const int maxn = 1001;
int n, m;
P p[maxn];

vector< pair<LD, LD> > vec;
inline void add(LD x, LD flag) { vec.push_back(make_pair(x, -flag)); }

LD get(const P &p, const V &v, const P &q, const V &w)
{
	V u = p - q;
	return Cross(w, u) / Cross(v, w);
}

void getSegmentInter(const P &p, const V &v, const P &q, const V &w)
{
	if (!dcmp(Cross(v, w)))
	{
		if (!dcmp(Cross(v, q - p)))
		{
			LD l = Dot(v, q - p) / Dot(v, v);
			LD r = Dot(v, q + w - p) / Dot(v, v);
			if (l > r) swap(l, r);
			add(l, +1);
			add(r, -1);
		}
	}
	else
	{
		static int num = 0;
		LD tmp = get(q, w, p, v);
		if (dcmp(tmp) >= 0 && dcmp(tmp - 1) <= 0)
		{
			LD rate = 1;
			if (dcmp(tmp) == 0 || dcmp(tmp - 1) == 0) rate = .5;
			tmp = get(p, v, q, w);
			add(tmp, dcmp(Cross(w, v)) > 0? +rate: -rate);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		p[i].read();
	p[n] = p[0];

	while (m--)
	{
		P a, b;
		a.read();
		b.read();
		vec.clear();
		for (int i = 0; i < n; i++)
			getSegmentInter(a, b - a, p[i], p[i + 1] - p[i]);
		sort(vec.begin(), vec.end());
		LD ans = 0, k = 0;
		for (size_t i = 0; i < vec.size(); i++)
		{
			k += vec[i].second;
			if (dcmp(k))
				ans += vec[i + 1].first - vec[i].first;
		}
		ans *= Length(b - a);
		printf("%.20f\n", double(ans));
	}
}