#ifndef __SHAREDPTR_H__
#define __SHAREDPTR_H__
#include <cstddef>
template <typename T> class shared_ptr
{
public:
	explicit shared_ptr(T* p = NULL);
	~shared_ptr();
	template <typename U>
	shared_ptr(shared_ptr<U> &other);
	template <typename U>
	shared_ptr& operator= (const shared_ptr<U>& other);	
	T* get() const ;
	T& operator*() const ;
	T* operator->() const ;
	size_t getCount() const;
private:
	T* m_p;
	size_t* m_counter;
	
};


template <typename T>
inline shared_ptr<T>::shared_ptr(T* p):m_p(p),m_counter(new size_t(1))
{}

template <typename T>
inline shared_ptr<T>::~shared_ptr()
{
	if(*m_counter > 1)
		m_counter--;
	else
	{
		delete m_p;
		delete m_counter;
	}
}

template <typename T>
template <typename U>
inline shared_ptr<T>::shared_ptr(shared_ptr<U> &other) : m_p(other.m_p), m_counter(other.m_counter)
{
	(*m_counter)++;
}

template <typename T>
template <typename U>
inline shared_ptr<T>& shared_ptr<T>:: operator= (const shared_ptr<U>& other)
{
	if(this == &other)
        return *this;
        
    m_p = other.m_p;
    m_counter = other.m_counter;
    *m_counter++;  
	return *this;
}


template <typename T>
inline  T& shared_ptr<T>:: operator*() const
{
      return *m_p;
}  

template <typename T>
inline  T* shared_ptr<T>:: operator->() const
{
      return m_p;
} 
 
template <typename T>
inline  T* shared_ptr<T>:: get() const
{ 
 	return m_p;
}


template <typename T>
inline  size_t shared_ptr<T>:: getCount()  const
{ 
 	return *m_counter;
}


#endif













