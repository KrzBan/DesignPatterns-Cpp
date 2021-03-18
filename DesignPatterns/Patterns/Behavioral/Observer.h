#pragma once

#include <iostream>
#include <unordered_set>

namespace Observer {

	template<typename T>
	struct Observer {
		virtual void Notified(const T& source, std::string field) = 0;
	};

	template<typename T>
	class Observable {
		std::unordered_set<Observer<T>*> observers;
	public:
		void Notify(T& source, const std::string& name) {
			for (auto& elem : observers) {
				elem->Notified(source, name);
			}
		}
		void Subscribe(Observer<T>* o) { observers.insert(o); }
		void Unsubscribe(Observer<T>* o) { observers.erase(o); }
	};


	struct Data : Observable<Data> {
		int m_Data;
	
		void SetData(int newVal) {
			m_Data = newVal;
			Notify(*this, "data");
		}
	};

	class DataObserver :public Observer<Data> {
		void Notified(const Data& source, std::string field) override {
			std::cout << field << " field modified!\n";
		}

	};
}