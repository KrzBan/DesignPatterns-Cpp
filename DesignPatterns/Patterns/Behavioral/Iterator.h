#pragma once

#include <iostream>

namespace Iterator {

	class Iterable {
		static constexpr int size = 10;

		int someWeirdStuff[size];

	public:
		int* begin() { return someWeirdStuff; }
		int* end() { return someWeirdStuff + size; }
	};
}