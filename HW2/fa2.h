#ifndef FA_2_H
#define FA_2_H

#include<vector>
using std::vector;
#include<random>
using std::normal_distribution;
using std::mt19937;
#include<future>
using std::async;
#include<functional>
using std::function;

//Debug includes
#include<iostream>
using std::cout;

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
	
	function<size_t(size_t)> square = 
		[&](size_t num)
		{
			return num*num;
		};

	for(int i = 0; i < n; i++)
	{
		auto handle = async(std::launch::async,square,i);
		squares[i] = handle.get();
	}

	return squares;
}

template <typename fn >
function <int(int)> repeatFunction (fn f, int n)
{
	//int temp = f()
	//cout << "temp: "<<temp;
	return f;

}


#endif
