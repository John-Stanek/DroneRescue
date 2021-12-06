// #include "battery.h"
// #include "gtest/gtest.h"


// class BatteryTest : public::testing::Test {
//     public:
//     void SetUp(){
//         battery_test = Battery(5000);
//     }
//     protected:
//         Battery battery_test;

// };
// TEST_F(BatteryTest, SetBatteryLifeTests){
//     Battery new_battery(500);
//     new_battery.SetBatteryLife(1000);
//     EXPECT_EQ(new_battery.GetBatteryLife(), 1000);
// }
// TEST_F(BatteryTest, GetBatteryLifeTests){
//     Battery new_battery(500);
//     EXPECT_EQ(new_battery.GetBatteryLife(), 500);
// }
// TEST_F(BatteryTest, ReduceBatteryLifeTests){
//     Battery new_battery(1000);
//     new_battery.ReduceBatteryLife(100);
//     EXPECT_EQ(new_battery.GetBatteryLife(), 900);
// }
// TEST_F(BatteryTest, RechargeBatteryLifeTests){
//     Battery new_battery(1000);
//     new_battery.RechargeBatteryLife(100);
//     EXPECT_EQ(new_battery.GetBatteryLife(), 1100);s
// }