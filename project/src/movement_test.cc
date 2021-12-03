#include "gtest/gtest.h"
//#include "beeline.h"
#include "composite_factory.h"

class MovementTest : public ::testing::Test {
public:
  void SetUp( ) { 
  }
protected:
};

TEST_F(MovementTest, beeline) {
  Drone* drone = CompositeFactory::CreateEntity("drone");
  drone.beeline();
  EXPECT_TRUE(false) << "Beeline is not implemented"; //need to check start and final pos
}

TEST_F(MovementTest, patrol) {
  Drone* drone = CompositeFactory::CreateEntity("drone");
  drone.patrol();
  EXPECT_TRUE(false) << "Beeline is not implemented"; //need to check start and final pos
}

/*
TEST_F(FactoryTest, CreateR) {
  Date day5(2016, 1, 01); 
  Date day6(2016, 3, 01);
  
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
  EXPECT_EQ(day5.DaysBetween(day6), 60) << "Leap year doesn't work";
}
*/