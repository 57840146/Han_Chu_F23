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
		while (mShouldContinue) {
			OnUpdate();
		}
	}

	template<typename T>
	void BeaverApp<T>::OnUpdate() {
	}
}
