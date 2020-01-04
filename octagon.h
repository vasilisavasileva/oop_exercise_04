#pragma once
#include <iostream>
#include <cmath>
#include "vertex.h"


template<class T>
struct octagon {
	vertex<T> vertices[8];
	octagon(std::istream& is);
	double area() const;
	vertex<T> center() const;
	void print(std::ostream& os) const;
};

template<class T>
octagon<T>::octagon(std::istream& is) {
	for (int i = 0; i < 8; ++i) {
		is >> vertices[i];
	}
}

template<class T>
double octagon<T>::area() const {
	double area = 0;
	for (int i = 0; i < 8; i++) {
		area += (vertices[i].x) * (vertices[(i + 1) % 8].y) - (vertices[(i + 1) % 8].x) * (vertices[i].y);
	}
	area *= 0.5;
	return abs(area);
}


template<class T>
vertex<T> octagon<T>::center() const {
	vertex<T> res;
	res.x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x + vertices[4].x + vertices[5].x + vertices[6].x + vertices[7].x) / 8;
	res.y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y + vertices[4].y + vertices[5].y + vertices[6].x + vertices[7].y) / 8;
	return res;

}

template<class T>
void octagon<T>::print(std::ostream& os) const {
	for (int i = 0; i < 8; ++i) {
		os << vertices[i];
		if (i + 1 != 8) {
			os << ' ';
		}
	}
}
