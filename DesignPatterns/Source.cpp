#include <iostream>

#include "Patterns/Creational/Builder.h"
#include "Patterns/Creational/Factory.h"
#include "Patterns/Creational/Prototype.h"
#include "Patterns/Creational/Singleton.h"

#include "Patterns/Structual/Adapter.h"
#include "Patterns/Structual/Bridge.h"
#include "Patterns/Structual/Composite.h"
#include "Patterns/Structual/Decorator.h"
#include "Patterns/Structual/Facade.h"
#include "Patterns/Structual/Flyweight.h"
#include "Patterns/Structual/Proxy.h"

#include "Patterns/Behavioral/ChainOfResponsibility.h"
#include "Patterns/Behavioral/Command.h"
#include "Patterns/Behavioral/Iterator.h"
#include "Patterns/Behavioral/Mediator.h"
#include "Patterns/Behavioral/NullObject.h"
#include "Patterns/Behavioral/Observer.h"
#include "Patterns/Behavioral/State.h"


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

		//Composite let's us "compose" our data in a tree like structure
		//Example: Who's the tallest peron in the world?
		//World->FindTallest(), go through each continent,
		//Continent->FindTallest(), go through each country,
		//Country->FindTallest(), go through each city....
		//City->FindTallest(), finally, go through every person
		//we propagate work down the tree, using less and less generalized data structures

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

	if (0) {
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

	if (0) {
		using namespace ChainOfResponsibility;
		//simply a linkedList, where each node also stores the location 
		//of data they modify
		std::shared_ptr<Data> myData = std::make_shared<Data>( 1,2,3, 4.0 );

		Mod modList{ myData };
		TranslateMod trMod1{ myData, 1, 0, 0 };
		IncreaseMod incrMod{ myData, 10.0 };
		TranslateMod trMod2{ myData, 0, 2, 3 };

		modList.Add(&trMod1);
		modList.Add(&incrMod);
		modList.Add(&trMod2);

		std::cout << myData->x << " " << myData->y << " " << myData->z << " " << myData->d << '\n';
		modList.Handle();
		std::cout << myData->x << " " << myData->y << " " << myData->z << " " << myData->d << '\n';

		//other example from "Design Patterns in Modern C++" shows
		//a more automated system, automatically adding and removing
		//mods as we declare them, but it makes use of other design
		//patterns, not yet mentioned, and also boost::magic, I'll revisit it later
	}

	if (0) {
		using namespace Command;

		HardToLog htl{ 1,2 };
		htl.GetX();
		htl.SetY(10);

		EasyToLog etl{ 5,10 };
		etl.Command( ETLCommand{ Action::SET, ETLParam::x, 10} );
		etl.Command( ETLCommand{ Action::INCREASE, ETLParam::x, 10 });
		etl.Command( ETLCommand{ Action::DECREASE, ETLParam::y, 2 });
		auto x = etl.Command(ETLCommand{ Action::GET, ETLParam::x, 0 });
		auto queriedY = etl.Query(ETLQuery{ ETLParam::y });
	}

	if (0) {
		using namespace Iterator;

		//Used all over the place, Iterator is just some object, that points to something
		//but also, knows where the next (and or prev/other) object in a container is
		//pointers work just fine, easily adaptable with reverse iterator 
		//Node based iterators require a little more work

		Iterable it{};

		for (auto& elem : it) {
			std::cout << elem << '\n';
		}
	}

	if (0) {
		using namespace Mediator;

		//Mediator can connect several systems togheter,
		//allowing for smoother communication
		//Entity component system is also probably a sort of mediator

		Manager mgr;
		Object obj1(mgr, 1);
		Object obj2(mgr, -234);
		Object obj3(mgr, 1000);

		for (auto& pElem : mgr.objects) {
			std::cout << pElem->value << '\n';
		}

		if (0) {
			using namespace NullObject;

			DummyPrinter dmPrinter;
			//I really really need a printer
			//But I really really don't want to implement one
			//I just need Document to work
			Document doc("My String", dmPrinter);
			doc.Print();
		}
	}

	if (0) {
		using namespace Observer;

		Data data{};
		data.SetData(10);

		DataObserver dataObserver{};
		data.Subscribe(&dataObserver);

		data.SetData(20);
		data.SetData(30);

		data.Unsubscribe(&dataObserver);
		data.SetData(40);
	}

	if (1) {
		using namespace StateNS;

		StateMachine sm{};
		sm.AddRule(State::Start, Event::Any, State::Grounded);
		sm.AddRule(State::Grounded, Event::Jump, State::Airborne);
		sm.Options();
	}

	return 0;
}