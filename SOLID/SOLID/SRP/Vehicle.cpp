class Vehicle {
public:
	Vehicle(int maxFuel) {
		max_fuel_ = maxFuel;
		remaining_fuel_ = maxFuel;
	}

	int GetMaxFuel() {
		return max_fuel_;
	}

	int GetRemainingFuel() {
		return remaining_fuel_;
	}

	void SetRemainingFuel(int remaining_fuel) {
		remaining_fuel_ = remaining_fuel;
	}

	void Accelerate() {
		remaining_fuel_--;
	}

private:
	int max_fuel_;
	int remaining_fuel_;
};

class GasStation
{
public:
	void ReFuel(Vehicle *customer) {
		int maxFuelAmount = customer->GetMaxFuel();
		customer->SetRemainingFuel(maxFuelAmount);
	}
};