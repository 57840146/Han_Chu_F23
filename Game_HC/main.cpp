#include"Gehc.h"

#include <iostream>
class MyGame : public hc::GehcApp<MyGame> {
public:
	MyGame() {
		SetKeyPressedCallback([this](const hc::KeyPressed& e) {OnKeyPress(e); });
	}

	virtual void OnUpdate() override {
		//std::cout << "running" << std::endl;
		Draw(x, y, mPic);
		//Draw(0, 0, mbackground);
		//Draw(mUnit);
	}

	void OnKeyPress(const hc::KeyPressed& e) {
		if (e.GetKeyCode() == GEHC_KEY_RIGHT) {
			std::cout << "testr" << std::endl;
			//x += 50;
			mUnit.UpdateXCoord(50);
		}
		else if (e.GetKeyCode() == GEHC_KEY_LEFT) {
			//x -= 50;
			std::cout << "testl" << std::endl;
			mUnit.UpdateXCoord(-50);
		}
	}
private:
	hc::Picture mPic{ "../Assets/Pictures/test.png"};
	hc::Unit mUnit{ "../Assets/Pictures/images.png",0,0 };
	hc::Picture mbackground{ "../Assets/Pictures/test4.png" };
	int x{ 0 };
	int y{ 0 };
};

GEHC_APPLICATION_START(MyGame);
