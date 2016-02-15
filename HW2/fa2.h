#ifndef FA_2_H
#define FA_2_H

#include<vector>
using std::vector;
#include<random>
using std::normal_distribution;
using std::mt19937;
#include<functional>
using std::function;

inline vector<double> normRand (size_t n)
{
	vector<double> randNos;
	mt19937 gen (10); // Seed with constant -> we get same numbers at every run
	normal_distribution <double> dist(100.0,15.0);
	for(int i = 0; i < n; i++)
	{
		randNos.push_back(dist(gen));
	}

	return randNos;
}

inline vector<int> asyncSquares (size_t n)
{
	vector<int> squares(n);
	return squares; //Dummy return	
}

template <typename fn>
auto repeatFunction (fn f, int n)
{
	return f;
}

#endif
