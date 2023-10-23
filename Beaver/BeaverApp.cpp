#include"pch.h"
#include "BeaverApp.h"

namespace bv {

	template<typename T>
	BeaverApp<T>::BeaverApp(){
	}

	template<typename T>
	void BeaverApp<T>::Init() {
		if (sInstance == nullptr) {
			sInstance = new T;
		}
	}

	template<typename T>
	void BeaverApp<T>::RunInterface() {
		sInstance->Run();
	}

	template<typename T>
	void BeaverApp<T>::Run(){
		mWindow.Create("Game_HC", 1000, 800);

		while (mShouldContinue) {
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void BeaverApp<T>::OnUpdate() {
	}
}
