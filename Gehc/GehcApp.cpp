#include"pch.h"
#include "GehcApp.h"

namespace hc {

	template<typename T>
	GehcApp<T>::GehcApp(){
	}

	template<typename T>
	void GehcApp<T>::Init() {
		if (sInstance == nullptr) {
			sInstance = new T;
		}
	}

	template<typename T>
	void GehcApp<T>::RunInterface() {
		sInstance->Run();
	}

	template<typename T>
	void GehcApp<T>::Run(){
		mWindow.Create("Game_HC", 1000, 800);

		while (mShouldContinue) {
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void GehcApp<T>::OnUpdate() {
	}
}
