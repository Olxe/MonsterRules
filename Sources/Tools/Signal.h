#pragma once

#include <iostream>
#include <vector>
#include <functional>

template<typename T>
class Signal;

template<typename R, typename... Args>
class Signal<R(Args...)>
{
	typedef std::function<R(Args...)> F;
public:
	template<class T>
	void Connect(T&& Callback)
	{
		MyCallbacks.push_back(Callback);
	}
	std::vector<R> operator()(Args&&... args) const
	{
		std::vector<R> results;
		for (F const& f : MyCallbacks)
			results.push_back(f(std::forward<Args>(args)...));

		return results;
	}

private:
	std::vector<F> MyCallbacks;
};

template<typename... Args>
class Signal<void(Args...)>
{
	typedef std::function<void(Args...)> F;
public:
	template<class R>
	void Connect(R&& Callback)
	{
		MyCallbacks.push_back(Callback);
	}
	void operator()(Args&&... args) const
	{
		for (F const& f : MyCallbacks)
			f(std::forward<Args>(args)...);
	}
private:
	std::vector<F> MyCallbacks;
};