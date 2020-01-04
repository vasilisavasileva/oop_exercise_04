#pragma once
#include <iostream>

template<class T>
struct vertex {
	T x;
	T y;
};

template<class T>
vertex<T> operator+(const vertex<T>& A, const vertex<T>& B) {
	vertex<T> res;
	res.x = A.x + B.x;
	res.y = A.y + B.y;
	return res;
}

template<class T>
vertex<T> operator/=(vertex<T>& A, const double B) {
	A.x /= B;
	A.y /= B;
	return A;
}

template<class T>
std::istream& operator>> (std::istream& is, vertex<T>& p) {
	is >> p.x >> p.y;
	return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const vertex<T>& p) {
	os << '[' << p.x << ' ' << p.y << ']';
	return os;
}