#pragma once

#include"Utilities.h"
#include"GameWindow.h"

namespace bv {

	template<typename T>
	class BeaverApp {
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		friend typename T;
	private:
		BeaverApp();

		inline static BeaverApp* sInstance{ nullptr };

		GameWindow mWindow;

		bool mShouldContinue{ true };
	};
}

#include"BeaverApp.cpp"