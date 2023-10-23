#include"Beaver.h"

#include <iostream>
class MyGame : public bv::BeaverApp<MyGame> {
public:

	virtual void OnUpdate() override {
		std::cout << "Beaver running" << std::endl;
	}

};

BEAVER_APPLICATION_START(MyGame);
