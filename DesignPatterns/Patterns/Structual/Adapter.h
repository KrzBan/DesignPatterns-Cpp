#pragma once

#include <iostream>
#include <vector>

namespace Adapter {

	//Some example class
	template<typename T>
	struct Vec3 {
		T x, y, z;

		Vec3() = default;
	};

	//Unchangeable service, incompatible with Vec3
	class Service {
	public:
		Service() = default;

		template<typename T>
		void PrintIterable(T begin, T end) {
			for (; begin != end; ++begin) {
				std::cout << *begin << '\n';
			}
		}
	};

	template<typename T>
	struct VecAdapter {
		std::vector<T> data;

		explicit VecAdapter(const Vec3<T>& vec) {
			data.push_back(vec.x);
			data.push_back(vec.y);
			data.push_back(vec.z);
		}
	};
}