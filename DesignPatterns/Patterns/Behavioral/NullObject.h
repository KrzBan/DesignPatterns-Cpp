#pragma once

#include <iostream>

namespace NullObject {

	class Printer {
	public:
		virtual void Print(const std::string& str) = 0;
	};

	class Document {
		std::string m_Data;
		Printer& m_Printer;
	public:
		Document(const std::string& data, Printer& printer) 
			:m_Data{ data }, m_Printer{ printer } {}

		void Print() {
			m_Printer.Print(m_Data);
		}
	};

	class DummyPrinter: public Printer {
	public:
		void Print(const std::string& str) override {};
	};

}