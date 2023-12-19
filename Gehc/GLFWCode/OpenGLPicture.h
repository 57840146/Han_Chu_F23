#pragma once
#include"pch.h"
#include"../Gehc/PictureImplementation.h"

namespace hc {
	class OpenGLPicture : public PictureImplementation {
	public:
		OpenGLPicture(const std::string& fileP);
		~OpenGLPicture();

		int GetWidth() const override;
		int GetHeight() const override;
		void Bind() override;
	private:
		unsigned int mTexture;
		int width;
		int height; 
		int nrChannels;
	};
}