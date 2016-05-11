#pragma once

#include "IManager.h"

namespace Contracts {
	template<class T>
	class IGenericManager : 
		public IManager 
	{
	public:
		virtual void AddClient(T client) = 0;
		virtual void RemoveClient(T client) = 0;
	};
}
