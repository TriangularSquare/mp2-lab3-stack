#pragma once
#include <iostream>

template <class T>
struct TNode
{
	T value;
	TNode* pNext;
};

template <class T>
class TStackL {
private:
	TNode<T>* pFirst;
public:
	TStackL();
	TStackL(const TStackL<T>& tsl);
	~TStackL();

	TStackL<T>& operator=(const TStackL<T>& tsl);

	bool IsEmpty() const;

	bool operator==(const TStackL<T>& tsl) const;
	bool operator!=(const TStackL<T>& tsl) const;

	void Push(T elem);
	T Pop();
	T Top() const;

	void Clear();
};

template<class T>
inline TStackL<T>::TStackL()
{
	pFirst = NULL;
}

template<class T>
inline TStackL<T>::TStackL(const TStackL<T>& tsl)
{
	pFirst = NULL;
	if (!tsl.IsEmpty()) {
		TNode<T>* node;
		node = new TNode<T>;
		node->value = tsl.pFirst->value;
		node->next = NULL;
		pFirst = node;

		TNode<T>* prev = node;
		TNode<T>* other = tsl.pfirst->pNext;

		while (other != NULL) {
			node = new TNode<T>;
			node->value = other->value;
			node->pNext = NULL;
			prev->pNext = node;
			prev = node;
			other = other->pNext;
		}
	}
}

template<class T>
inline TStackL<T>::~TStackL()
{
	TNode<T>* node;
	while (pFirst != NULL) {
		node = pFirst;
		pFirst = pFirst->pNext;
		delete node;
	}
}

template<class T>
inline TStackL<T>& TStackL<T>::operator=(const TStackL<T>& tsl)
{
	if (this == &tsl) {
		return *this;
	}

	Clear();

	if (!tsl.IsEmpty()) {
		TNode<T>* node = new TNode<T>;
		node->value = tsl.pFirst->value;
		node->pNext = NULL;
		pFirst = node;

		TNode<T>* prev = node;
		TNode<T>* other = tsl.pFirst->pNext;

		while (other != NULL) {
			node = new TNode<T>;
			node->value = other->value;
			node->pNext = NULL;
			prev->pNext = node;
			prev = prev->pNext;
			other = other->pNext;
		}
	}
}

template<class T>
inline bool TStackL<T>::IsEmpty() const
{
	return pFirst == NULL;
}

template<class T>
inline bool TStackL<T>::operator==(const TStackL<T>& tsl) const
{
	TNode<T>* node = pFirst;
	TNode<T>* other = tsl.pFirst;

	while (node != NULL && other != NULL) {
		if (node->value != other->value) {
			return false;
		}
		node = node->pNext;
		other = other->pNext;
	}

	if (node != NULL || other != NULL) {
		return false;
	}

	return true;
}

template<class T>
inline bool TStackL<T>::operator!=(const TStackL<T>& tsl) const
{
	return !(this == &tsl);
}

template<class T>
inline void TStackL<T>::Push(T elem)
{
	TNode<T>* node = new TNode<T>;
	node->value = elem;
	node->pNext = pFirst;
	pFirst = node;
}

template<class T>
inline T TStackL<T>::Pop()
{
	if (pFirst == NULL) {
		throw "ERROR!";
	}
	T elem = pFirst->value;
	TNode<T>* prev = pFirst;
	pFirst = prev->pNext;
	delete prev;
	return elem;
}

template<class T>
inline T TStackL<T>::Top() const
{
	if (pFirst == NULL) {
		throw "ERROR";
	}
	return pFirst->value;
}

template<class T>
inline void TStackL<T>::Clear()
{
	TNode<T>* node;
	while (pFirst != NULL) {
		node = pFirst;
		pFirst = pFirst->pNext;
		delete node;
	}
}
