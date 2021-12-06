#include "gtest/gtest.h"
#include "drone.h"

class DroneMovementTest : public ::testing:Test {
public:
    void SetUp() {

    }
protected:
    Drone drone;
}

TEST_F(DroneMovementTest, TestMovementConstructor) {
    Drone drone;
    drone.movement = new Patrol();    
    ASSERT_EQ(drone.movement, Patrol());
    delete drone.movement;
    drone.movement = new Beeline();
    ASSERT_EQ(drone.movement, Beeline());
}
