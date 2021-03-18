#pragma once

#include <iostream>
#include <optional>

namespace Command {

	enum class Action {
		SET, GET, INCREASE, DECREASE
	};

	std::ostream& operator<<(std::ostream& os, const Action& a) {
		switch (a) {
		case Action::SET:
			os << "SET";
			break;
		case Action::GET:
			os << "GET";
			break;
		case Action::INCREASE:
			os << "INCREASE";
			break;
		case Action::DECREASE:
			os << "DECREASE";
			break;
		}
		return os;
	}

	void LogAction(const Action& a, int value) {
		std::cout << "Action: " << a << ", value: " << value << '\n';
	}


	class HardToLog {
		int x, y;
	public:
		HardToLog(int x, int y) : x{ x }, y{ y } {}

		void SetX(int value) {
			LogAction(Action::SET, value);
			x = value; 
		}
		int GetX() const {
			LogAction(Action::GET, x);
			return x; 
		}

		void SetY(int value) {
			LogAction(Action::SET, value); 
			y = value; 
		}
		int GetY() const { 
			LogAction(Action::GET, x); 
			return y; 
		}

		//..more functions to log, christ
	};

	enum class ETLParam{ x, y};


	struct ETLQuery {
		ETLParam param;
	};

	struct ETLCommand {
		Action action;
		ETLParam param;
		int value;
	};

	class EasyToLog {
		int x, y;
	public:
		EasyToLog(int x, int y) : x{ x }, y{ y } {}

		int Query(const ETLQuery& query) {
			int value{};
			switch (query.param) {
			case ETLParam::x: value =  x;
				break;
			case ETLParam::y: value =  y;
				break;
			}
			LogAction(Action::GET, value);
			return value;
		}

		std::optional<int> Command(const ETLCommand& cmd) {
			
			int* variable = nullptr;
			switch (cmd.param) {
			case ETLParam::x: variable = &x;
				break;
			case ETLParam::y: variable = &y;
				break;
			/*
			default:
				CrashAndBurn();
				break;
			*/
			}

			switch (cmd.action) {
			case Action::GET: return Query(ETLQuery{ cmd.param });
				break;
			case Action::SET: *variable = cmd.value;
				break;
			case Action::INCREASE: *variable += cmd.value;
				break;
			case Action::DECREASE: *variable -= cmd.value;
				break;
			}

			LogAction(cmd.action, cmd.value);
			return {};
		}
	};
}