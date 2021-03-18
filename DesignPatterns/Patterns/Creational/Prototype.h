#pragma once

#include <iostream>

namespace Prototype {

	//So a prototype, in essence, it's just a deep-copyable
	//or serializable object that i can make a lot of copies of.
	//That way I can make a quick copy, for example, of a class with 10 fields, 
	//but only modify one ot them

	struct Address {
		std::string street;
		std::string city;
		int suite;
	};

	//Example class, which will be my prototype
	struct Contact {
		std::string firstName;
		std::string secondName;

		//A pointer, for some reason, to make it not trivially copyable
		Address* address = nullptr;
		Contact(const std::string& firstName, const std::string& secondName, Address* address) : firstName{ firstName }, secondName{ secondName }, address{ address } {}
		Contact(const Contact& other)
			:firstName{ other.firstName }, secondName{ other.secondName }, address{ new Address(*other.address) } {}
	};

	//Prototype factory

	class EmployeeFactory {
		static Contact main;
		static Contact aux;

	public:
		static std::unique_ptr<Contact> NewMainEmployee(std::string firstName, std::string secondName) {
			return NewEmployee(firstName, secondName, main);
		}
		static std::unique_ptr<Contact> NewAuxEmployee(std::string firstName, std::string secondName) {
			return NewEmployee(firstName, secondName, aux);
		}

	private:
		static std::unique_ptr<Contact> NewEmployee(std::string firstName, std::string secondName, const Contact& prototype) {
			auto employee = std::make_unique<Contact>(prototype);
			employee->firstName = firstName;
			employee->secondName = secondName;
			return employee;
		}
			
	};

	Contact EmployeeFactory::main{ std::string{"John"}, std::string{"Doe"}, new Address{"Street", "City", 9} };
	Contact EmployeeFactory::aux{ std::string{"Johnathan"}, std::string{"Doemat"}, new Address{"Streetskin", "Cityble", 91} };
}