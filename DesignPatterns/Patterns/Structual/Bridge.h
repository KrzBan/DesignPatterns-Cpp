#pragma once

#include <iostream>

namespace Bridge {

	struct Printer {
		virtual void PrintA() = 0;
		virtual void PrintB() = 0;
		virtual void PrintC() = 0;
	};

	struct ConsolePrinter: public Printer {

		void PrintA() override {
			std::cout << "Printing A!\n";
		}
		void PrintB() override {
			std::cout << "Printing B!\n";
		}
		void PrintC() override {
			std::cout << "Printing C!\n";
		}
	};

	class DocumentA {
		Printer& m_Printer;
	public:
		explicit DocumentA(Printer& printer): m_Printer { printer } {}

		void Print() { m_Printer.PrintA(); }
	};

	class DocumentB {
		Printer& m_Printer;
	public:
		explicit DocumentB(Printer& printer) : m_Printer{ printer } {}

		void Print() { m_Printer.PrintB(); }
	};

	class DocumentC {
		Printer& m_Printer;
	public:
		explicit DocumentC(Printer& printer) : m_Printer{ printer } {}

		void Print() { m_Printer.PrintC(); }
	};
}