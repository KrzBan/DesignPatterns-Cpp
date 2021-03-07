#include <iostream>

#include "Patterns/Builder.h"
#include "Patterns/Factory.h"
#include "Patterns/Prototype.h"
#include "Patterns/Singleton.h"

int main() {

	if(0){
		using namespace Builder;

		Person p = Person::Create("Krzysztof")
			.lives().at("Kombi")
					.with_postcode("12-345")
					.in("Arachowice")
			.works().at("Lice")
					.as_a("Student")
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

	if (0) {
		using namespace Prototype;
		auto mainContact = EmployeeFactory::NewMainEmployee("Tak", "Jest");
		auto auxContact = EmployeeFactory::NewAuxEmployee("Nie", "Ma");

		std::cout << "Hired!\n";
	}

	if (1) {
		using namespace Singleton;

		//Works through get, there a static instance exists
		auto someInt = TypicalSingleton::get().dummyInt;
		TypicalSingleton::get().dummyDouble = 5.0;

		//Purely static interface, static data defined in cpp file
		NoInstanceSingleton::SetInt(5);
		auto someDouble = NoInstanceSingleton::GetDouble();
		auto anotherDouble = NoInstanceSingleton::GetDouble();

		std::cout << "Done!\n";

	}
	return 0;
}