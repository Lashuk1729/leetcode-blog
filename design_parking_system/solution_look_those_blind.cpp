class ParkingSystem {
private:
    int big, medium, small;

public:
    ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small) {}
    
    bool addCar(int carType) {
        cout << big <<" "<< medium <<" "<< small << endl;
        if(carType == 1) {
            if(big >= 1) {
                big -= 1;
                return true;
            }
            else
                return false;
        }
        else if(carType == 2) {
            if(medium >= 1) {
                medium -= 1;
                return true;
            }
            else
                return false;
        }
        else {
            if(small >= 1) {
                small -= 1;
                return true;
            }
            else
                return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */