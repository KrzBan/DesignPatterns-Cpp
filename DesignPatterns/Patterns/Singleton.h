#pragma once

#include <iostream>

namespace Singleton {

	class TypicalSingleton {
	public:
		int dummyInt;
		double dummyDouble;

		static TypicalSingleton& get() {
			static TypicalSingleton singleton{};
			return singleton;
		}
	private:
		TypicalSingleton() = default;
		TypicalSingleton(const TypicalSingleton& other) = delete;
	};

	class NoInstanceSingleton {
	public:
		static void SetInt(int i);

		static double GetDouble();
	private:
		NoInstanceSingleton() = delete;
	};
}