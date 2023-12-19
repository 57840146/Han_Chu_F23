#pragma once
//#include"pch.h"
#include"Utilities.h"
#include"PictureImplementation.h"
namespace hc {
	class GEHC_API Picture {
	public:
		Picture(const std::string& filePath);

		int GetWidth() const;
		int GetHeight() const;
		void Bind();
	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}