#ifndef FA_2_H
#define FA_2_H

#include<vector>
using std::vector;
#include<functional>
using std::function;

inline vector<double> normRand (size_t n)
{
	vector<double> randNos(n);
	return randNos; //Dummy return
}

inline vector<int> asyncSquares (size_t n)
{
	vector<int> squares(n);
	return squares; //Dummy return	
}

function<function(function f,int n) repeatFunction
{
	return f;
} 

#endif
