#pragma once

#include <iostream>

namespace Proxy {

	template<typename T>
	class Property {
		T m_Value{};
		bool m_Set = false;

	public:
		Property() = default;
		Property(const T& value) : m_Value{ value }, m_Set{ true }{};

		operator T&() { return m_Value; }
		operator const T& () const { return m_Value; }
		T& operator =(const T& newValue) { m_Value = newValue; m_Set = true; return m_Value; }

		void Set(const T& value) { m_Value = value; m_Set = true; }

		bool IsSet() const { return m_Set; }
	};

}