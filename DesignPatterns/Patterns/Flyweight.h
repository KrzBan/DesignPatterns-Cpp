#pragma once

#include <iostream>
#include <boost/flyweight.hpp>

namespace Flyweight {

	//Tons of possible duplicates, huge memory usage
	struct User {
		std::string firstName;
		std::string lastName;

		User(const std::string& first_name, const std::string& last_name)
			: firstName{ first_name }, lastName{ last_name } {}
	};


	//One drawback, data is not mutable
	//But new value can be assigned
	//Can be implemented by hand, using something like a map
	struct MemoryEfficientUser {
		boost::flyweight<std::string> firstName;
		boost::flyweight<std::string> lastName;

		MemoryEfficientUser(const std::string& first_name, const std::string& last_name)
			: firstName{ first_name }, lastName{ last_name } {}
	};
}