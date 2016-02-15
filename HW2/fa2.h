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

template <typename fn>
auto repeatFunction (fn f, int n)
{
	return f;
}

/*int repeatFunction (std::function<int(int)> f , int n)
{
	return f(1);
}*/

//template<typename T>
/*inline int operator() (std::function<int(int num) f, int n) repeatFunction
{
	return f(num); //Dummy return 
}
*/
/*function<function<int(int)>f,int n >repeatFunction
{
	return f(n);
}*/

#endif
