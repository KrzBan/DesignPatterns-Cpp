#include "Singleton.h"

namespace Singleton {

	struct NoInstanceSingletonData {
		int dummyInt = 0;
		double dummyDouble = 0;
	};

	static NoInstanceSingletonData data{};

	void NoInstanceSingleton::SetInt(int i) {
		data.dummyInt = i;
	}

	double NoInstanceSingleton::GetDouble() {
		auto temp = data.dummyDouble;
		data.dummyDouble = (data.dummyDouble + data.dummyInt) * 5.0;
		return temp;
	}

}