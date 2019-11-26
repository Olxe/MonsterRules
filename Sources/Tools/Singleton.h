#pragma once

template <typename T> 
class Singleton
{
protected:
	inline explicit Singleton();
	virtual ~Singleton();

public:
	static T* Instance();
	static void DeleteInstance();

protected:
	static T* m_instance;

};

template<typename T> 
T* Singleton<T>::m_instance = nullptr;

template<typename T>
inline T* Singleton<T>::Instance()
{
	if (!m_instance) m_instance = new T();
	return m_instance;
}

template<typename T>
inline void Singleton<T>::DeleteInstance()
{
	if (m_instance) {
		delete m_instance;
		m_instance = nullptr;
	}
}

template<typename T>
inline Singleton<T>::Singleton()
{
}

template<typename T>
inline Singleton<T>::~Singleton()
{
}
