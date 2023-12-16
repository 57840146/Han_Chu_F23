#pragma once

#include"Utilities.h"

namespace hc {
	class GEHC_API KeyPressed {
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;

	private:
		int mKeyCode;

	};

	class GEHC_API KeyReleased {
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;

	private:
		int mKeyCode;

	};
	
	class GEHC_API WindowClosed {

	};
}