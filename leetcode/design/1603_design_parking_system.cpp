class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType) {
        if (carType == 1) {
            if (this->big == 0)
                return false;
            this->big--;
            return true;
        } else if (carType == 2) {
            if (this->medium == 0)
                return false;
            medium--;
            return true;
        } else {
            if (this->small == 0 )
                return false;
            small--;
            return true;
        }
    }

private:
    int big;
    int medium;
    int small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
