#pragma once

#include"Utilities.h"
#include"GameWindow.h"

namespace hc {

	template<typename T>
	class GehcApp {
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		friend typename T;
	private:
		GehcApp();

		inline static GehcApp* sInstance{ nullptr };

		GameWindow mWindow;

		bool mShouldContinue{ true };
	};
}

#include"GehcApp.cpp"