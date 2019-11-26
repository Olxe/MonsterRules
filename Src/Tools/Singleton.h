#pragma once

template <typename T> class Singleton
{
public:
	static T& Instance();

protected:
	static T m_instance;

private:
	T& operator=(const T& copy) {}
};

template<typename T> T Singleton<T>::m_instance = T();

template<typename T>
inline T& Singleton<T>::Instance()
{
	return m_instance;
}