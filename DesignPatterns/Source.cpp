#include <iostream>

#include "Patterns/Builder.h"

int main() {

	{
		using namespace Builder;
		Person p = Person::Create("Krzysiusiak")
			.lives().at("Kombatantow 9")
					.with_postcode("27-200")
					.in("Starachowice")
			.works().at("Litceum II")
					.as_a("Uczen")
					.earning(0.0);

		std::cout << "Built!\n";
	}

	return 0;
}