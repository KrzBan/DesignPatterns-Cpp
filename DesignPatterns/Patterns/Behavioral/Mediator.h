#pragma once

#include <iostream>
#include <unordered_set>

namespace Mediator {

	class Object;

	struct Manager {

		std::unordered_set<Object*> objects;

		void AddObject(Object* obj) {
			objects.insert(obj);
		}
		void RemoveObject(Object* obj) {
			objects.erase(obj);
		}

	};
	
	class Object {
		Manager& m_Manager;

	public:
		int value;

		explicit Object(Manager& manager, int value)
			: m_Manager{ manager }, value{ value } {
			m_Manager.AddObject(this);
		}

		~Object() noexcept {
			m_Manager.RemoveObject(this);
		}
	};
}
