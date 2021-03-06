#include <iostream>

#include "Patterns/Builder.h"
#include "Patterns/Factory.h"
#include "Patterns/Prototype.h"

int main() {

	if(0){
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

	if(0){
		using namespace Factory;
		auto factory = CarFactory();
		auto fastCar = factory.makeCity("fast");
		auto comfortableCar = factory.makeCity("comfortable");

		auto functionalFactory = FunctionalCarFactory();
		auto functionalFast = functionalFactory.make("fast");
		auto functionalComfortable = functionalFactory.make("comfortable");
	}

	if (1) {
		using namespace Prototype;
		auto mainContact = EmployeeFactory::NewMainEmployee("Tak", "Jest");
		auto auxContact = EmployeeFactory::NewAuxEmployee("Nie", "Ma");

		std::cout << "Hired!\n";
	}

	return 0;
}