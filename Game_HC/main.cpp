#include"Gehc.h"

#include <iostream>
class MyGame : public hc::GehcApp<MyGame> {
public:
	MyGame() {
		SetKeyPressedCallback([this](const hc::KeyPressed& e) {OnKeyPress(e); });
	}

	virtual void OnUpdate() override {
		//std::cout << "Gehc running" << std::endl;
		//Draw(x,y,mPic);

		Draw(mUnit);
	}

	void OnKeyPress(const hc::KeyPressed& e) {
		if (e.GetKeyCode() == GEHC_KEY_RIGHT) {
			//x += 50;
			mUnit.UpdateXCoord(50);
		}
		else if (e.GetKeyCode() == GEHC_KEY_LEFT) {
			//x -= 50;
			mUnit.UpdateXCoord(-50);
		}
	}
private:
	hc::Picture mPic{ "../Assets/Pictures/test.png" };
	hc::Unit mUnit{ "../Assets/Pictures/test.png",100,500 };

	int x{ 100 };
	int y{ 100 };
};

GEHC_APPLICATION_START(MyGame);
