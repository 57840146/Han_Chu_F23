#include"pch.h"
#include"GameWindow.h"
#include"GLFWCODE/GLFWImplementation.h"

namespace hc {
	GameWindow::GameWindow(){
#ifdef GEHC_MSCPP
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif GEHC_APPLE
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif GEHC_LINUX
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#endif
	}

	void GameWindow::Create(const std::string& name, int width, int height){
		mImplementation->Create(name, width, height);

	}

	int GameWindow::GetHeight() const{
		return mImplementation->GetHeight();
	}

	int GameWindow::GetWidth() const{
		return mImplementation->GetWidth();;
	}

	void GameWindow::SwapBuffers(){
		mImplementation->SwapBuffers();
	}

	void GameWindow::PollEvents(){
		mImplementation->PollEvents();
	}
}