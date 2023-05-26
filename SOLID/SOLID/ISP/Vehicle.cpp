#define interface struct

interface Engine {
	virtual void StartEngine() = 0;
	virtual void ShutDownEngine() = 0;
};
interface Radio {
	virtual void TurnRadioOn() = 0;
	virtual void TurnRadioOff() = 0;
};
interface Camera {
	virtual void TurnCameraOn() = 0;
	virtual void TurnCameraOff() = 0;
};

class Vehicle : public Engine {
public:
	bool IsEngineRunning() {
		return engine_running_;
	}

	void StartEngine() override {
		engine_running_ = true;
	}

	void ShutDownEngine() override {
		engine_running_ = false;
	}

private:
	bool engine_running_;
};


class Drone : public Vehicle, Camera {
public:
	bool IsCameraOn() {
		return camera_on_;
	}

	void TurnCameraOn() override {
		camera_on_ = true;
	}

	void TurnCameraOff() override {
		camera_on_ = false;
	}

private:
	bool camera_on_;
};

class Car : public Vehicle, Radio {
public:
	bool IsRadioOn() {
		return radio_on_;
	}

	void TurnRadioOn() override {
		radio_on_ = true;
	}

	void TurnRadioOff() override {
		radio_on_ = false;
	}

private:
	bool radio_on_;
};