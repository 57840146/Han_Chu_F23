#include"Gehc.h"
#include <iostream>
class MyGame : public hc::GehcApp<MyGame> {
public:
	MyGame(){
		SetKeyPressedCallback([this](const hc::KeyPressed& e) {OnKeyPress(e); });

		//SetKeyReleasedCallback([this](const hc::KeyReleased& e) {OnKeyRelease(e); });
		

	}

	virtual void OnUpdate() override {
		Draw(mUnit);
		if (isJumping) {
			handleJump();
		}
		
	}

	void OnKeyPress(const hc::KeyPressed& e) {
		if (e.GetKeyCode() == GEHC_KEY_RIGHT) {
			mUnit.UpdateXCoord(50);
		}
		else if (e.GetKeyCode() == GEHC_KEY_LEFT) {
			mUnit.UpdateXCoord(-50);
		}
		else if (e.GetKeyCode() == GEHC_KEY_SPACE) {
			jump();
		}
	}


	void jump() {
		if (!isJumping || (isJumping && jumpsPerformed < maxJumps)) {
			if (jumpsPerformed == 0) {
				originalJumpStartY = mUnit.GetYCoord();
				jumpStartY = mUnit.GetYCoord();  // Starting position for the first jump
			}
			else if (jumpsPerformed == 1) {
				jumpStartY = mUnit.GetYCoord();  // Starting position for the second jump
				
			}
			isJumping = true;
			jumpPeakReached = false;
			jumpsPerformed++;
		}
	}

	void handleJump() {
		if (!jumpPeakReached) {
			mUnit.UpdateYCoord(jumpSpeed);  // Move up
			int currentJumpHeight = mUnit.GetYCoord() - jumpStartY;
			if (currentJumpHeight >= jumpHeight) {
				jumpPeakReached = true; 
			}
		}
		else {
			mUnit.UpdateYCoord(-jumpSpeed); // Move down
			if (mUnit.GetYCoord() <= originalJumpStartY) {
				isJumping = false;
				mUnit.UpdateYCoord(originalJumpStartY); // Reset to the original starting position
				jumpsPerformed = 0; // Reset the jump count after landing
			}
		}
	}
private:

	hc::Unit mUnit{ "../Assets/Pictures/persontest.png",500,0 };
	//std::vector<hc::Picture> mPerson;
	//hc::Picture mPerson{ "../Assets/Pictures/persontest.png" };
	//hc::Picture mbackground{ "../Assets/Pictures/background.png" };
	//hc::Picture Coin{ "../Assets/Pictures/Coin.png" };
	int jumpStartY = 0;
	int originalJumpStartY = 0; // The Initial y-coordinate (first jump)
	bool isJumping = false;
	bool jumpPeakReached = false; 
	int jumpsPerformed = 0; // current jump times
	const int maxJumps = 2; //max jump times
	const int jumpHeight = 150; // modify for max jump height
	const int jumpSpeed = 15; // modify for jump speed
};

GEHC_APPLICATION_START(MyGame);
