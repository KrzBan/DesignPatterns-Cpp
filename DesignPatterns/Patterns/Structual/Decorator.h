#pragma once

#include <iostream>
#include <array>
#include <type_traits>

namespace Decorator {

	struct Shape {
		std::array<size_t, 2> bounds;
	};

	struct Circle: public Shape {
		size_t radius;

		Circle(size_t rad) : radius{ rad } {}
	};

	struct Square :public Shape {
		size_t edge;

		Square(size_t size) : edge{ size } {}
	};

	//Dynamic decorator

	struct ColoredShape :public Shape {
		Shape& shape;
		std::array<char, 3> rgb;

		ColoredShape(Shape& shape, char r, char g, char b):
			shape{ shape }, rgb{ r, g, b } {}
	};

	struct TranslatedShape :public Shape {
		Shape& shape;
		int x, y;

		TranslatedShape(Shape& shape, int x, int y):
			shape{ shape }, x{ x }, y{ y }{}
	};

	//Static decorator
	template<typename Base>
	struct StaticColoredShape : public Base {
		static_assert(std::is_base_of<Shape, Base>::value, 
			"Template argument must be a Shape");

		std::array<char, 3> rgb;

		template<typename...Args>
		StaticColoredShape(char r, char g, char b, Args ...args)
			:Base{ std::forward<Args>(args)... }
			, rgb{ r,g,b }{}
	};

	template<typename Base>
	struct StaticTranslatedShape : public Base {
		static_assert(std::is_base_of<Shape, Base>::value,
			"Template argument must be a Shape");

		int x, y;

		template<typename...Args>
		StaticTranslatedShape(int x, int y, Args ...args)
			:Base{ std::forward<Args>(args)... }
			, x{ x }, y{ y }{}
	};
}