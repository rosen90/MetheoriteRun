#pragma once
#include "../Contracts/IGenericManager.h"
#include <vector>

namespace ContractImplementations {
	template<class T>
	class GenericManager :
		public Contracts::IGenericManager<T>
	{
	public:
		GenericManager();
		virtual ~GenericManager();
		virtual void AddClient(T client) override;

	protected:
		std::vector<T> clients;
	};

#include "GenericManager.hpp"
}


