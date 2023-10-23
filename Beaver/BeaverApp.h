#pragma once

#include"Utilities.h"

namespace bv {

	template<typename T>
	class BEAVER_API BeaverApp {
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		friend typename T;
	private:
		BeaverApp();

		inline static BeaverApp* sInstance{ nullptr };

		bool mShouldContinue{ true };
	};
}

#include"BeaverApp.cpp"