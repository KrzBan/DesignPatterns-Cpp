#pragma once

#include <iostream>

namespace Monad {

	struct Layered {
		int**** value;

		Layered(int val) {
			value = new int***{};
			*value = new int**{};
			**value = new int*{};
			***value = new int{val};
		}
		~Layered() noexcept {
			delete*** value;
			delete** value;
			delete* value;
			delete value;
		}
	};

	template<typename T>
	struct Maybe;

	template <typename T>
	static Maybe<T> maybe(T* context) {
		return Maybe<T>(context);
	}

	template <typename T>
	struct Maybe {
		T* context;
		Maybe(T* context) : context{ context } {}

		template<typename Func>
		auto With(Func evaluator) {
			return context != nullptr ? maybe(evaluator(context)) :
				nullptr;
		}

		template<typename Func>
		auto Do(Func action) {
			if (context != nullptr) action(context);
			return *this;
		}
	};
}