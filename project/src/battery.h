#ifndef BATTERY_H_
#define BATTERY_H_

class Battery {

    public:
        /**
        * @brief Construct a new Battery object
        * 
        */
        Battery();
        /**
         * @brief Construct a new Battery object
         * 
         * @param batLife 
         */
        Battery(float batLife);
        /**
         * @brief Set the Battery Life object
         * 
         * @param batLife 
         */
        void SetBatteryLife(float batLife);
        /**
         * @brief Get the Battery Life object
         * 
         * @return float 
         */
        float GetBatteryLife();
        /**
         * @brief Reduces the battery life of an entity
         * 
         * @param dt 
         */
        void ReduceBatteryLife(float dt);
        /**
         * @brief Recharges the battery life of an entity
         * 
         * @param dt 
         */
        void RechargeBatteryLife(float dt);

    private:

        float batteryLife; 
};
#endif