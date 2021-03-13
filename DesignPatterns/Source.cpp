#include <iostream>

#include "Patterns/Builder.h"
#include "Patterns/Factory.h"
#include "Patterns/Prototype.h"
#include "Patterns/Singleton.h"
#include "Patterns/Adapter.h"
#include "Patterns/Bridge.h"
#include "Patterns/Composite.h"
#include "Patterns/Decorator.h"
#include "Patterns/Facade.h"
#include "Patterns/Flyweight.h"
#include "Patterns/Proxy.h"

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

	if (0) {
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

	if (0) {
		using namespace Adapter;

		Service service;

		Vec3<int> myVec{ 1,2,3 };//treating Vec3 data as packed and tribvially iterable can be justified, but nonetheless, it's UB.

		//Vec3 is incompatible with Service, we can't modify Service, so we create an adapter
		VecAdapter<int> adapter(myVec);

		service.PrintIterable(adapter.data.begin(), adapter.data.end());
	}

	if (0) {
		using namespace Bridge;

		//ConsolePrinter knows how to print all kinds of documents all by itself,
		//but we use we call those different methods b using distinguishable classes.
		//Printer class, in this scenarion, acts as a bridge between DocumentX and ConsolePrinter.
		ConsolePrinter consolePrinter;
		DocumentB db{ consolePrinter };
		db.Print();
	}

	if (0) {
		using namespace Composite;

		BadClass badClass{};
		auto badSum = badClass.Sum();

		CompositeClass compositeClass{};
		auto compositeSum = compositeClass.Sum();

		//Well, it's more of a structural pattern, so nothing to see here
		//CompositeClass is just much more scalable than BadClass, that's all
	}

	if (0) {
		using namespace Decorator;

		//dynamic decorator
		//has no accessto circles' methods and/or variables
		Circle circle{ 5 };
		ColoredShape coloredCircle{ circle, 125,0,0 };

		//static decorator
		//has access to all members
		//no runtime decoration
		StaticTranslatedShape<StaticColoredShape<Square>> square{ 5,10, 0,255,0,10 };

		std::cout << "Square has a size of: " << square.edge;
		std::cout << " and a translation of: " << square.x << ", " << square.y << '\n';
	}

	if (0) {
		using namespace Facade;

		//Even though, VulkanWindow is a fairly complicated class,
		//Window provides a simple and intuitive api forthe user

		//To properly show how the Facade pattern works, you need a 
		//complicated system, which clashes with an idea of a simple example.
		//I hope this and .h file suffices.

		Window window{ 640,480 };
	}

	if (0) {
		using namespace Flyweight;

		//The same idea that's behind database normalization
		//Separate data from eachother, reduce redundancy
		//Less memory usage
		//std::string_view follow the same pattern

		//both last names are separate objects
		User user1{ "Mike", "Smith" };
		User user2{ "Jane", "Smith" };
		assert(&user1.lastName != &user2.lastName);

		//Here, last names occupy the same memory
		MemoryEfficientUser user3{ "John", "Doe" };
		MemoryEfficientUser user4{ "Anne", "Doe" };
		assert(&user3.lastName.get() == &user4.lastName.get());
	}

	if (1) {
		using namespace Proxy;

		//smart_pointers are examples of Proxies
		//something that takes a class and makes it lazy is also a proxy
		//Proxy<t> would behave like T, but add some additional funcionality to it

		Property<std::string> stringProperty{};
		assert(stringProperty.IsSet() == false);

		stringProperty = "Hello World!";
		assert(stringProperty.IsSet() == true);
		
		std::cout << (std::string)stringProperty << '\n';
	}
	return 0;
}