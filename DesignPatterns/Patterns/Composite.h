#pragma once

#include <iostream>
#include <array>
#include <numeric>

namespace Composite {

	struct BadClass {
		int a, b, c;
		BadClass() : a{ 0 }, b{ 0 }, c{ 0 } {}

		void SetA(int value) { a = value; }
		void SetB(int value) { b = value; }
		void SetC(int value) { c = value; }

		int GetA() const { return a; }

		int Sum() const { return a + b + c; }
	};

	//This class is bad,because it's easy to forget to update sum() as we add more properties to this class
	//We should strive to make this as generic as it can

	struct CompositeClass {
		enum Properties { a, b, c, count};
		std::array<int, count> properties;
		CompositeClass() : properties{} {}

		void SetA(int value) { properties[a] = value; }
		void SetB(int value) { properties[b] = value; }
		void SetC(int value) { properties[c] = value; }

		int GetA() const { return properties[a]; }

		int Sum() const { return std::accumulate(properties.begin(), properties.end(), 0); }
	};

	//Now, the class methods are generic and more expandable, we can add max(), min() and any other method we want
	//and later, when we add a new property, we won't have to update these methods
}