#include <iostream>
#include <tuple>
#include "vertex.h"
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "templates.h"

template<class T>
void processing(std::istream& is, std::ostream& os) {
	if constexpr (is_figurelike_tuple<T>::value) {
		int vert;
		std::cout << "Enter the number of vertices" << std::endl;
		std::cin >> vert;
		if (vert == 5) {
			vertex<double> A, B, C, D, E;
			is >> A >> B >> C >> D >> E;
			auto object = std::make_tuple(A, B, C, D, E);
			print(os, object);
			os << area(object) << std::endl;
			os << center(object) << std::endl;
			return;
		}
		if (vert == 6) {
			vertex<double> A, B, C, D, E, F;
			is >> A >> B >> C >> D >> E >> F;
			auto object = std::make_tuple(A, B, C, D, E, F);
			print(os, object);
			os << area(object) << std::endl;
			os << center(object) << std::endl;
			return;
		}
		if (vert == 8) {
			vertex<double> A, B, C, D, E, F, G, I;
			is >> A >> B >> C >> D >> E >> F >> G >> I;
			auto object = std::make_tuple(A, B, C, D, E, F, G, I);
			print(os, object);
			os << area(object) << std::endl;
			os << center(object) << std::endl;
			return;
		}
	}
	else {
		T object(is);
		print(os, object);
		os << '\n' << area(object) << std::endl;
		os << center(object) << std::endl;
		return;
	}
}

void PrintMenu() {
	std::cout << "Input figure type:" << std::endl;
	std::cout << "1 - pentagon" << std::endl;
	std::cout << "2 - octagon" << std::endl;
	std::cout << "3 - hexagon" << std::endl;
	std::cout << "4 - tuple" << std::endl;
	std::cout << "'q' to quit" << std::endl;
}

int main() {
	char obj_type;
	while (true) {
		PrintMenu();
		std::cin >> obj_type;
		switch (obj_type) {
		case'4':
			processing<std::tuple<vertex<double>>>(std::cin, std::cout);
			break;
		case'1':
			processing<pentagon<double>>(std::cin, std::cout);
			break;
		case'2':
			processing<octagon<double>>(std::cin, std::cout);
			break;

		case'3':
			processing<hexagon<double>>(std::cin, std::cout);
			break;

		case'q':
			return 0;

		default:
			std::cout << "Smth is wrong. Try another one." << std::endl;
			std::cout << "Input figure type:" << std::endl;
			std::cout << "1 - pentagon" << std::endl;
			std::cout << "2 - octagon" << std::endl;
			std::cout << "3 - hexagon" << std::endl;
			std::cout << "4 - tuple" << std::endl;
			std::cout << "'q' to quit" << std::endl;

		}
	}
	/*system("pause");
	return 0;*/
}