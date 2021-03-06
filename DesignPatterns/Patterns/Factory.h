#pragma once

#include <iostream>
#include <map>
#include <functional>

namespace Factory {

	struct CityCar {
		virtual void build(int cost) = 0;
	};

	struct FastCar : CityCar {
		void build(int cost) override {
			std::cout << "Building a fast car with a cost of ";
			std::cout << cost << " money!\n";
		}
	};

	struct ComfortableCar : CityCar {
		void build(int cost) override {
			std::cout << "Building a comfortable car with a cost of ";
			std::cout << cost << " money!\n";
		}
	};

	struct CityCarFactory {
		virtual std::unique_ptr<CityCar> make() const = 0;
	};

	struct FastCarFactory : CityCarFactory {
		std::unique_ptr<CityCar> make() const override {
			return std::make_unique<FastCar>();
		}
	};

	struct ComfortableCarFactory : CityCarFactory {
		std::unique_ptr<CityCar> make() const override {
			return std::make_unique<ComfortableCar>();
		}
	};

	class CarFactory {
		std::map<std::string, std::unique_ptr<CityCarFactory>> cityFactories;

	public:
		CarFactory() {
			cityFactories["fast"] = std::make_unique<FastCarFactory>();
			cityFactories["comfortable"] = std::make_unique<ComfortableCarFactory>();
		}

		std::unique_ptr<CityCar> makeCity(const std::string& name) {
			auto car = cityFactories[name]->make();
			car->build(1000);
			return car;
		}
	};


	//Instead of defining multiple sub-factories, we can make one
	//and describe the making process as a function
	class FunctionalCarFactory {
		std::map<std::string, std::function<std::unique_ptr<CityCar>()>> factories;

	public:
		FunctionalCarFactory() {
			factories["fast"] = [] {
				auto fast = std::make_unique<FastCar>();
				fast->build(20000);
				return fast;
			};
			factories["comfortable"] = [] {
				auto comfortable = std::make_unique<ComfortableCar>();
				comfortable->build(20000);
				return comfortable;
			};
		}

		std::unique_ptr<CityCar> make(const std::string& name) {
			return factories[name]();
		}
	};

}