#include"pch.h"
#include"Picture.h"
#include"GLFWCode/OpenGLPicture.h"
namespace hc {
	Picture::Picture(const std::string& filePath) {
#ifdef GEHC_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(filePath) };
#elif GEHC_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(filePath) };
#elif GEHC_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(filePath) };
#endif
	}

	int Picture::GetWidth()const{
		return mImplementation->GetWidth();
	}

	int Picture::GetHeight()const{
		return mImplementation->GetHeight();
	}

	void Picture::Bind(){
		mImplementation->Bind();
	}

}