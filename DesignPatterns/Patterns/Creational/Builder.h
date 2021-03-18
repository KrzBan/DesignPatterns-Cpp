#pragma once

#include <iostream>

namespace Builder {

	class PersonBuilder;

	struct Person {
		std::string name;

		//Lives at
		std::string address;
		std::string postcode;
		std::string city;

		//Works at
		std::string company;
		std::string occupancy;
		double earnings = 0;

		static PersonBuilder Create(std::string name = "");
	};

	class PersonAddressBuilder;
	class PersonJobBuilder;

	//Fluent builder
	class PersonBuilderBase {
	protected:
		Person& person;
		explicit PersonBuilderBase(Person& person)
			:person(person) {}

	public:
		operator Person() {
			return std::move(person);
		}

		PersonAddressBuilder lives() const;
		PersonJobBuilder works() const;
	};

	//Only public
	class PersonBuilder : public PersonBuilderBase {
	private:
		Person p;
	public:
		PersonBuilder(std::string name) : PersonBuilderBase{ p } { p.name = name; }
	};

	class PersonAddressBuilder : public PersonBuilderBase {
	
	public:
		explicit PersonAddressBuilder(Person& person) 
			: PersonBuilderBase{ person } {}

		PersonAddressBuilder& at(std::string address) {
			person.address = address;
			return *this;
		}
		PersonAddressBuilder& with_postcode(std::string postcode) {
			person.postcode = postcode;
			return *this;
		}
		PersonAddressBuilder& in(std::string city) {
			person.city = city;
			return *this;
		}
	};

	class PersonJobBuilder : public PersonBuilderBase {

	public:
		explicit PersonJobBuilder(Person& person)
			: PersonBuilderBase{ person } {}

		PersonJobBuilder& at(std::string company) {
			person.company = company;
			return *this;
		}
		PersonJobBuilder& as_a(std::string occupancy) {
			person.occupancy = occupancy;
			return *this;
		}
		PersonJobBuilder& earning(double earnings) {
			person.earnings = earnings;
			return *this;
		}
	};
}