#pragma once

#include <iostream>
#include <vector>
#include <map>

//conflicting names, thus NS
namespace StateNS {

	enum class State {
		Start, Grounded, Airborne, End
	};

	enum class Event {
		Any, Jump
	};

	std::ostream& operator<<(std::ostream& os, const State& st) {
		switch (st) {
		case State::Start: os << "Start";
			break;
		case State::Grounded: os << "Grounded";
			break;
		case State::Airborne: os << "Airborne";
			break;
		case State::End: os << "End";
			break;
		}
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Event& e) {
		switch (e) {
		case Event::Any : os << "Any";
			break;
		case Event::Jump : os << "Jump";
			break;
		}
		return os;
	}

	class StateMachine {
		State m_CurrentState = State::Start;

		std::map<State, std::vector<std::pair<Event, State>>> m_Rules;

	public:
		explicit StateMachine() {
			m_Rules[State::Start].push_back({ Event::Any, State::End });
		}

		//Doesn't check for duplicates, but I want to keep it simple
		void AddRule(State from, Event event, State to) {
			m_Rules[from].push_back({ event, to });
		}

		void Options() {
			size_t i = 1;
			std::cout << "Current state: " << m_CurrentState << '\n';
			for (auto& pair : m_Rules[m_CurrentState]) {
				std::cout << i++ << ". Event: " << pair.first << ", State: " << pair.second << '\n';
			}
		}
	};

}