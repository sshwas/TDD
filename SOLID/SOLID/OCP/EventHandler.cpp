#include "Vehicle.cpp"

class Mode {
public:
	virtual int getPower() = 0;
	virtual int getSuspensionHeight() = 0;
};

class SportMode : public Mode {
public:
	int getPower() override { return 500; }
	int getSuspensionHeight() override { return 10; }
};

class ComportMode : public Mode {
public:
	int getPower() override { return 400; }
	int getSuspensionHeight() override { return 20; }
};

class NormalMode : public Mode {
public:
	int getPower() override { return 400; }
	int getSuspensionHeight() override { return 10; }
};

class EventHandler {
public:
	EventHandler(Vehicle* vehicle) {
		vehicle_ = vehicle;
	}

	void changeDrivingMode(Mode* driving_mode) {
		vehicle_->SetPower(driving_mode->getPower());
		vehicle_->SetSuspensionHeight(driving_mode->getSuspensionHeight());
	}

private:
	Vehicle* vehicle_;
};

#if false
class EventHandler {
public:
	EventHandler(Vehicle vehicle) {
		vehicle_ = vehicle;
	}

	void changeDrivingMode(DrivingMode driving_mode) {
		switch (driving_mode) {
		case DrivingMode::kSport: {
			vehicle_.SetPower(500);
			vehicle_.SetSuspensionHeight(10);
			break;
		}
		case DrivingMode::kComfort: {
			vehicle_.SetPower(400);
			vehicle_.SetSuspensionHeight(20);
			break;
		}
		default: {
			vehicle_.SetPower(400);
			vehicle_.SetSuspensionHeight(20);
			break;
		}
			   // when we need to add another mode (e.g. ECONOMY) 2 classes will change DrivingMode and EventHandler.
		}
	}

private:
	Vehicle vehicle_;
};
#endif
