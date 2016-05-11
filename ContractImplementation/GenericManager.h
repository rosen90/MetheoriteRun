#pragma once
#include "../Contracts/IGenericManager.h"
#include <vector>
#include <algorithm>

using std::vector;

namespace ContractImplementations {
	template<class T>
	class GenericManager :
		public Contracts::IGenericManager<T>
	{
	public:
		GenericManager();
		virtual ~GenericManager();
		virtual void AddClient(T client) override;
		virtual void RemoveClient(T client) override;

	protected:
		vector<T> clients;
	};

#include "GenericManager.hpp"
}
