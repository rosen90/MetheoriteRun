#pragma once
#include "../ContractImplementation/GenericManager.h"

namespace Contracts {
	class IControlable;
}

namespace Managers {
	class EventManager :
		public ContractImplementations::GenericManager<Contracts::IControlable*>
	{
	public:
		EventManager();
		virtual ~EventManager();

		virtual bool Process() override;
	};
}

