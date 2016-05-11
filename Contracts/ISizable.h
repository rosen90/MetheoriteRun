#pragma once

namespace Contracts
{
	class ISizable
	{
	public:
		virtual int GetX() = 0;
		virtual int GetY() = 0;
		virtual void SetX(int) = 0;
		virtual void SetY(int) = 0;

		virtual int GetW() = 0;
		virtual int GetH() = 0;
		virtual void SetW(int) = 0;
		virtual void SetH(int) = 0;
	};
}