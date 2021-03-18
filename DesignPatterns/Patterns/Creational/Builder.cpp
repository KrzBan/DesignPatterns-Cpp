#include "Builder.h"

namespace Builder {

	PersonBuilder Person::Create(std::string name) {
		return PersonBuilder{name};
	}

	PersonAddressBuilder PersonBuilderBase::lives() const {
		return PersonAddressBuilder(person);
	}

	PersonJobBuilder PersonBuilderBase::works() const {
		return PersonJobBuilder(person);
	}

}