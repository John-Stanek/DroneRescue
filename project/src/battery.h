#ifndef BATTERY_H_
#define BATTERY_H_

class Battery {

    public:
        Battery();
        Battery(float batLife);
        void SetBatteryLife(float batLife);
        float GetMax();
        float GetBatteryLife();
        void ReduceBatteryLife(float dt);
        void RechargeBatteryLife(float dt);
        bool IsEmpty();
        void SetEmpty(bool emp);
        void CheckEmpty();

    private:
        float batteryLife; float maxCharge; bool empty;
};
#endif