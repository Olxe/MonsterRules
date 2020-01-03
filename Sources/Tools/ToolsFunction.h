#ifndef __UTILITY__
#define __UTILITY__

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

template<class T>
inline void clearVector(std::vector< T* >& v)
{
	while(!v.empty()){
		if (v.back()) {
			delete v.back();
			v.back() = NULL;
		}
		
		v.pop_back();
	}
}

template<class T>
inline void clearPtr(T*& v)
{
	if(v){
		delete v;
		v = nullptr;
	}

}
inline void Out() {
	std::cout << std::endl;
}

template<typename First, typename ... Strings>
inline void Out(First arg, const Strings&... rest) {
	std::cout << arg << " ";
	Out(rest...);
}

template<typename T>
inline void OutV(const sf::Vector2<T>& v) {
	std::cout << v.x << " <> " << v.y << std::endl;
}

template<class T>
inline void display(T v)
{
	std::cout << v << std::endl;//almost deleted
}

template<class T>
inline void display2DVector(const std::vector< std::vector<T> >& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j];
		}
		std::cout << std::endl;
	}
}

inline bool isStrOnlyDigit(const std::string& str)
{
	for(auto it = str.begin(); it != str.end(); ++it){
		if(!isdigit(*it)) return false;
	}

	return true;
}

#endif