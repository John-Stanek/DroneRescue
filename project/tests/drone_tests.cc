#include "gtest/gtest.h"
#include "drone.h"

class DroneTest : public ::testing::Test {
public:
    void SetUp() {

    }
protected:
    Drone* drone;
};

TEST_F(DroneTest, SetSpeedTests) {
    Drone* new_drone;
    new_drone->SetSpeed(100);
    EXPECT_EQ(new_drone->GetSpeed(), 100);
    
}
