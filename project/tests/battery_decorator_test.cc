#include "gtest/gtest.h"
#include "factory.h"
#include "composite_factory.h"
#include <fstream>
#include "battery_decorator.h"

//1 integration test
class BatteryDecoratorTest : public ::testing::Test {
  public:
    void SetUp( ) { 
      //Create json objects
      const char* Dronejson ="{\"name\":\"drone\", \"entityId\":0, \"speed\":1,\"direction\":[0,0,0],\"position\":[0,0,0]}";

        //parse drone json
      std::string err;
      const char* json_end = picojson::parse(dValue, Dronejson, Dronejson + strlen(Dronejson), &err);
      if (! err.empty()) {
        std::cerr << err << std::endl;
      }
      else {
          printf("drone json parsed\n");
      }
    }

    protected:
      picojson::value dValue,rValue,cValue, hValue;
      CompositeFactory factory = CompositeFactory();
};

TEST_F(BatteryDecoratorTest, AddBattery) {
  if(!dValue.is<picojson::object>()){
    ASSERT_EQ(true,false); // force fail test
  }
  Drone* drone = static_cast<Drone*>(factory.CreateEntity(dValue.get<picojson::object>())); 
  if(drone == NULL){
    ASSERT_EQ(false,true); // force fail test
  }
  EXPECT_EQ(drone->hasBattery,false);

  BatteryEntity* electricEntity= new BatteryEntity(drone); //call decorator

  EXPECT_EQ(electricEntity->battery->GetBatteryLife() > 0,true);

  EXPECT_EQ(drone->GetPosition(0),electricEntity->GetPosition(0)); //inital positions should be equal

  double arrows[4] = {1.0, 0.0, 0.0, 0.0};
  bool moves[2] = {false, false};
  electricEntity->Update(0.01, arrows, moves); //check update function

  EXPECT_EQ(drone->GetPosition(0),electricEntity->GetPosition(0)); //updated positions should be equal

  delete electricEntity;
  delete drone;
}