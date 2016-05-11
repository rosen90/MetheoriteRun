#pragma once
#include "../ContractImplementation/GenericManager.h"


namespace Managers {
	class BossManager :
		public ContractImplementations::GenericManager<Contracts::IManager*>
	{
	public:
		BossManager();
		virtual ~BossManager();

		virtual bool Process() override;

		template<class T>
		static Contracts::IGenericManager<T>* GetManager();
		
		static BossManager* GetInstance();

	private:
		static BossManager* Instance;
		static const int FPS = 60;
		unsigned currentFrame;
	};

	#include "BossManager.hpp"
}
