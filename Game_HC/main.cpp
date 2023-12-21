#include"Gehc.h"
#include <iostream>
#include<chrono>
#include<typeinfo>
class MyGame : public hc::GehcApp<MyGame> {
public:
	MyGame(){
		SetKeyPressedCallback([this](const hc::KeyPressed& e) {OnKeyPress(e); });
		lastCoinTime = std::chrono::steady_clock::now();
		lastshoesTime = std::chrono::steady_clock::now();
	}

	virtual void OnUpdate() override {
		Draw(0, 0, mbackground);
		Draw(Player);
		if (isJumping) {
			handleJump();
		}
		PlantingCoin();
		drawCoins();
		PlantingShoes();
		drawShoes();

		CollisionWithCoin();
		CheckForshoes();
	}

private:

	hc::Unit Player{ "../Assets/Pictures/player.png",mWindow.GetWidth()/2,0};
	hc::Picture mbackground{ "../Assets/Pictures/background.png" };

	std::vector<hc::Unit> coins;
	std::chrono::steady_clock::time_point lastCoinTime;
	const std::chrono::seconds coinInterval{ 1 }; // 1 coin per second

	std::vector<hc::Unit> Shoes;
	std::chrono::steady_clock::time_point lastshoesTime;
	const std::chrono::seconds shoesInterval{ 7 }; // 1 shoes per 5 seconds

	int jumpStartY = 0;
	int originalJumpStartY = 0; // the initial y-coordinate (first jump)
	bool isJumping = false;
	bool jumpPeakReached = false; 
	int jumpsPerformed = 0; // current jump times
	int maxJumps = 2; // max jump times
	const int jumpHeight = 150; // modify for max jump height
	const int jumpSpeed = 15; // modify for jump speed

	bool shoesPickedUp = false;
	std::chrono::steady_clock::time_point shoesPickupTime;
	const std::chrono::seconds shoesEffectDuration{ 10 }; // shoes effect duration 10seconds
	int originalMaxJumps = maxJumps;

	void OnKeyPress(const hc::KeyPressed& e) {
		if (e.GetKeyCode() == GEHC_KEY_RIGHT) {
			if (Player.GetXCoord() <= 850) {
				Player.UpdateXCoord(50);
			}
			
		}
		else if (e.GetKeyCode() == GEHC_KEY_LEFT) {
			if (Player.GetXCoord() <= 0) {
			}
			else {
				Player.UpdateXCoord(-50);
			}
		}
		else if (e.GetKeyCode() == GEHC_KEY_SPACE) {
			if (Player.GetYCoord() >= 600) {
			}
			else {
				jump();
			}
		}
	}


	void jump() {
		if (!isJumping || (isJumping && jumpsPerformed < maxJumps)) {
			isJumping = true;
			jumpPeakReached = false;
			jumpsPerformed++;

			if (jumpsPerformed == 1) {
				originalJumpStartY = Player.GetYCoord(); // Save the original Y position only on the first jump
			}
			jumpStartY = Player.GetYCoord(); // Starting position for the current jump
		}
	}

	void handleJump() {
		if (!jumpPeakReached) {
			Player.UpdateYCoord(jumpSpeed);  // Move up
			if (Player.GetYCoord() - jumpStartY >= jumpHeight) {
				jumpPeakReached = true; // The player has reached the peak of the jump
			}
		}
		else {
			Player.UpdateYCoord(-jumpSpeed); // Move down
			if (Player.GetYCoord() <= originalJumpStartY) {
				isJumping = false;
				jumpsPerformed = 0; // Reset the jump count after landing
			}
		}

	}

	int getRandomX() {
		return std::rand() % 1000;
	}

	int getRandomY() {
		return std::rand() % 800;
	}

	void PlantingCoin() {
		auto now = std::chrono::steady_clock::now();
		if (now - lastCoinTime >= coinInterval) {
			coins.emplace_back("../Assets/Pictures/coin.png", getRandomX(), getRandomY());// create new coin at a random position
			lastCoinTime = now;
		}	
	}
	
	void drawCoins() {
		for (auto& coin : coins) {
			Draw(coin);
		}
	}

	void CollisionWithCoin() {
		auto it = coins.begin();
		while (it != coins.end()) {
			if (hc::UnitsOverlap(Player, *it)) {
				it = coins.erase(it);
			}
			else {
				it++;
			}
		}
		
	}

	void PlantingShoes() {
		auto now = std::chrono::steady_clock::now();
		if (now - lastshoesTime >= shoesInterval) {
			Shoes.emplace_back("../Assets/Pictures/shoes.png", getRandomX(), 800);// create new coin at a random position
			lastshoesTime = now;
		}
		for (auto& shoes : Shoes) {
			shoes.UpdateYCoord(-5);  // shoes falling down speed

		}
		
	}

	void drawShoes() {
		for (auto& shoes : Shoes) {
			Draw(shoes);
		}
	}

	void CheckForshoes() {
		auto it = Shoes.begin();
		while (it != Shoes.end()) {
			if (hc::UnitsOverlap(Player, *it)) {
				it = Shoes.erase(it);
				shoesPickedUp = true;
				shoesPickupTime = std::chrono::steady_clock::now();
				maxJumps += 1;
			}
			else if (it->GetYCoord() <= 0) {//delete out screen shoes
				it = Shoes.erase(it);
			}
			else {
				it++;
			}
		}
		if (shoesPickedUp && (std::chrono::steady_clock::now() - shoesPickupTime >= shoesEffectDuration)) {
			maxJumps = originalMaxJumps; // revert max jumps to original
			shoesPickedUp = false;
		}

	}
};

GEHC_APPLICATION_START(MyGame);
