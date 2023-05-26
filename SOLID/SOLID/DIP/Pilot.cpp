class Car
{
public:
    virtual void Accelerate() = 0;
};

class RacingCar : public Car
{
public:
    RacingCar(int max_fuel) {
        max_fuel_ = max_fuel;
        remaining_fuel_ = max_fuel;
    }

    void Accelerate() {
        power_++;
        remaining_fuel_--;
    }

private:
    int max_fuel_;
    int remaining_fuel_;
    int power_;
};

class Pilot {
public:
    Pilot(Car* car) {
        vehicle_ = car;
    }

    void IncreaseSpeed() {
        vehicle_->Accelerate();
    }

private:
    Car* vehicle_;
};