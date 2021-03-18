#pragma once

#include <iostream>

namespace ChainOfResponsibility {

	struct Data {
		int x, y, z;
		double d;

		explicit Data(int x, int y, int z, double d)
			:x{ x }, y{ y }, z{ z }, d{ d } {}
	};

	class Mod {
		Mod* m_Next{ nullptr };

	protected:
		std::shared_ptr<Data> m_Data;
	public:
		Mod(const std::shared_ptr<Data>& data)
			:m_Data{ data } {}

	void Add(Mod* mod) {
		if (m_Next) m_Next->Add(mod);
		else m_Next = mod;
	}

	virtual void Handle() {
		if (m_Next) m_Next->Handle();
	}

	};
	
	class TranslateMod : public Mod {
		int m_X, m_Y, m_Z;
	public:
		explicit TranslateMod(std::shared_ptr<Data> data, int x, int y, int z)
			: Mod{ data }, m_X{ x }, m_Y{ y }, m_Z{ z } {}

		void Handle() override {
			m_Data->x += m_X;
			m_Data->y += m_Y;
			m_Data->z += m_Z;

			Mod::Handle();
		}
	};

	class IncreaseMod : public Mod {
		double m_D;
	public:
		explicit IncreaseMod(std::shared_ptr<Data> data, double d)
			: Mod{ data }, m_D{d} {}

		void Handle() override {
			m_Data->d += m_D;

			Mod::Handle();
		}
	};
}
