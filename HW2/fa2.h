/*
	Arsh Chauhan
	fa2.h
	Header for fa2_test.cpp
	02/15/2016
*/


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



/*
	normRand: Geberates n pseudorandom numbers using C++11 random number generators 
	Pre: None
	Post: Returns a vector of size n. Each element is a pseudorandom number
		  Uses constant seed to generate same numbers every run
*/
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


/*
	asyncSquares: Calculates squares from 0 - n asynchronously
	Pre: None
	Post: Returns vector of size n, where:
			squares[0] = 0, squares [1] = 1,...,squares [n] = n*n
*/
inline vector<int> asyncSquares (size_t n)
{
	vector<int> squares(n);
	vector<std::future<size_t>> handles;
	
	function<size_t(size_t)> square = 
		[&](size_t num)
		{
			return num*num;
		};

	for(size_t i = 0; i < n; i++)
	{
		handles.push_back(async(std::launch::async,square,i));
	}

	for(size_t i = 0; i < n; i++)
	{
		squares[i] = handles[i].get();
	}

	return squares;
}


/*
	repeatFunction: closure that calls a passed function n times
	Pre: f must be prototyped as int foo(int)
	Post: Returns a std:function which performs the passed function n times 
*/
inline function <int(int)> repeatFunction (function <int(int num)> f, int n)
{
	function <int(int)> retFn = [=] (int arg)
	{
		
		for (int i = 0; i < n; i++)
		{
			arg = f(arg);
		}
		return arg;
	};

	return retFn;

}


#endif
