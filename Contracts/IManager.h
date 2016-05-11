#pragma once

namespace Contracts {
	class IManager 
	{
	public:
		virtual bool Process() = 0;
	};
}