#include"Gehc.h"

#include <iostream>
class MyGame : public hc::GehcApp<MyGame> {
public:

	virtual void OnUpdate() override {
		std::cout << "Gehc running" << std::endl;
	}

};

GEHC_APPLICATION_START(MyGame);
