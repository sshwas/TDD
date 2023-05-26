enum class DrivingMode {
	kSport = 0,
	kComfort
};

class Vehicle {
public:
	int GetPower() {
		return power_;
	}

	void SetPower(int power) {
		power_ = power;
	}

	int GetSuspensionHeight() {
		return suspension_height_;
	}

	void SetSuspensionHeight(int suspension_height) {
		suspension_height_ = suspension_height;
	}

private:
	int power_;
	int suspension_height_;
};