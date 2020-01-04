#pragma once
#include <iostream>
#include <cmath>
#include "vertex.h"


template<class T>
struct pentagon {
	vertex<T> vertices[5];
	pentagon(std::istream& is);
	double area() const;
	vertex<T> center() const;
	void print(std::ostream& os) const;
};

template<class T>
pentagon<T>::pentagon(std::istream& is) {
	for (int i = 0; i < 5; ++i) {
		is >> vertices[i];
	}
}

template<class T>
double pentagon<T>::area() const {
	double area = 0;
	for (int i = 0; i < 5; i++) {
		area += (vertices[i].x) * (vertices[(i + 1) % 5].y) - (vertices[(i + 1) % 5].x) * (vertices[i].y);
	}
	area *= 0.5;
	return abs(area);
}
	

template<class T>
vertex<T> pentagon<T>::center() const {
	vertex<T> res;
	res.x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x + vertices[4].x) / 5;
	res.y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y + vertices[4].y) / 5;
	return res;

}

template<class T>
void pentagon<T>::print(std::ostream& os) const {
	for (int i = 0; i < 5; ++i) {
		os << vertices[i];
		if (i + 1 != 5) {
			os << ' ';
		}
	}
}