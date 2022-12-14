#include "gtest/gtest.h"
#include "factory.h"
#include "composite_factory.h"
#include <fstream>


//4 integration tests, 1 regression test
class FactoryTest : public ::testing::Test {
public:
  void SetUp( ) { 
  	//Create json objects
  	const char* Dronejson ="{\"name\":\"drone\", \"entityId\":0, \"speed\":1,\"direction\":[0,0,0],\"position\":[0,0,0]}";

  	const char* Robotjson ="{\"name\":\"robot\", \"entityId\":1,\"position\":[0,0,0]}";

  	const char* Chargerjson ="{\"name\":\"recharge station\", \"entityId\":2,\"position\":[0,0,0]}";

  	const char* Hospitaljson ="{\"name\":\"hospital\", \"entityId\":3,\"position\":[0,0,0]}";
  	
	//parse drone json
	std::string err;
	const char* json_end = picojson::parse(dValue, Dronejson, Dronejson + strlen(Dronejson), &err);
	if (! err.empty()) {
	  std::cerr << err << std::endl;
	}
 	else {
	    printf("drone json parsed\n");
	}

	//parse robot json
	json_end = picojson::parse(rValue, Robotjson, Robotjson + strlen(Robotjson), &err);
	if (! err.empty()) {
	  std::cerr << err << std::endl;
	}
 	else {
	    printf("robot json parsed\n");
	}

	//parse charger json
	json_end = picojson::parse(cValue, Chargerjson, Chargerjson + strlen(Chargerjson), &err);
	if (! err.empty()) {
	  std::cerr << err << std::endl;
	}
 	else {
	    printf("charger json parsed\n");
	}

	//parse hospital json
	json_end = picojson::parse(hValue, Hospitaljson, Hospitaljson + strlen(Hospitaljson), &err);
	if (! err.empty()) {
	  std::cerr << err << std::endl;
	}
 	else {
	    printf("hospital json parsed\n");
	}
}
protected:
	picojson::value dValue,rValue,cValue, hValue;
	CompositeFactory factory = CompositeFactory();

};

TEST_F(FactoryTest, CreateDrone) { 
	if(!dValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
  Drone* drone = static_cast<Drone*>(factory.CreateEntity(dValue.get<picojson::object>())); 
  if(drone == NULL){
  	ASSERT_EQ(false,true); // force fail test
  }

  EXPECT_EQ(drone->GetX(),0);
  EXPECT_EQ(drone->GetY(),0);
  EXPECT_EQ(drone->GetZ(),0);

  EXPECT_EQ(drone->GetID(), 0);

  EXPECT_EQ(drone->GetName(), "drone");
  delete drone;
}


TEST_F(FactoryTest, CreateRobot) {  
  if(!rValue.is<picojson::object>()){
		ASSERT_EQ(false,true); // force fail test
	}
  Robot* robot = static_cast<Robot*>(factory.CreateEntity(rValue.get<picojson::object>())); 
  if(robot == NULL){
  	ASSERT_EQ(true,false); // force fail test
  }
  EXPECT_EQ(robot->GetX(),0);
  EXPECT_EQ(robot->GetY(),0);
  EXPECT_EQ(robot->GetZ(),0);

  EXPECT_EQ(robot->GetID(), 1);

  EXPECT_EQ(robot->GetName(), "robot");
  delete robot;
}


TEST_F(FactoryTest, CreateHospital) {  
  if(!hValue.is<picojson::object>()){
		ASSERT_EQ(false,true); // force fail test
	}
  Hospital* hospital = static_cast<Hospital*>(factory.CreateEntity(hValue.get<picojson::object>())); 
  if(hospital == NULL){
  	ASSERT_EQ(true,false); // force fail test
  }
  EXPECT_EQ(hospital->GetX(),0);
  EXPECT_EQ(hospital->GetY(),0);
  EXPECT_EQ(hospital->GetZ(),0);

  EXPECT_EQ(hospital->GetID(), 3);

  EXPECT_EQ(hospital->GetName(), "hospital");
  delete hospital;
}

TEST_F(FactoryTest, CreateCharger) {  
  if(!cValue.is<picojson::object>()){
		ASSERT_EQ(false,true); // force fail test
	}
  Charger* charger = static_cast<Charger*>(factory.CreateEntity(cValue.get<picojson::object>())); 
  if(charger == NULL){
  	ASSERT_EQ(true,false); // force fail test
  }
  EXPECT_EQ(charger->GetX(),0);
  EXPECT_EQ(charger->GetY(),0);
  EXPECT_EQ(charger->GetZ(),0);

  EXPECT_EQ(charger->GetID(), 2);

  EXPECT_EQ(charger->GetName(), "recharge station");
  delete charger;

}


TEST_F(FactoryTest, CreateEachEntity) {  

  if(!hValue.is<picojson::object>()){
    ASSERT_EQ(false,true); // force fail test
  }
  if(!cValue.is<picojson::object>()){
    ASSERT_EQ(false,true); // force fail test
  }
  if(!rValue.is<picojson::object>()){
    ASSERT_EQ(false,true); // force fail test
  }
  if(!dValue.is<picojson::object>()){
    ASSERT_EQ(true,false); // force fail test
  }
  Robot* robot = static_cast<Robot*>(factory.CreateEntity(rValue.get<picojson::object>())); 
  Hospital* hospital = static_cast<Hospital*>(factory.CreateEntity(hValue.get<picojson::object>())); 
  Charger* charger = static_cast<Charger*>(factory.CreateEntity(cValue.get<picojson::object>())); 
  Drone* drone = static_cast<Drone*>(factory.CreateEntity(dValue.get<picojson::object>())); 
  if(drone == NULL){
    ASSERT_EQ(false,true); // force fail test
  }

  if(charger == NULL){
    ASSERT_EQ(true,false); // force fail test
  }
  if(hospital == NULL){
    ASSERT_EQ(true,false); // force fail test
  }
  if(robot == NULL){
    ASSERT_EQ(true,false); // force fail test
  }
  EXPECT_EQ(hospital->GetX(),0);
  EXPECT_EQ(hospital->GetY(),0);
  EXPECT_EQ(hospital->GetZ(),0);
  EXPECT_EQ(hospital->GetID(), 3);
  EXPECT_EQ(hospital->GetName(), "hospital");

  EXPECT_EQ(charger->GetX(),0);
  EXPECT_EQ(charger->GetY(),0);
  EXPECT_EQ(charger->GetZ(),0);
  EXPECT_EQ(charger->GetID(), 2);
  EXPECT_EQ(charger->GetName(), "recharge station");

  EXPECT_EQ(robot->GetX(),0);
  EXPECT_EQ(robot->GetY(),0);
  EXPECT_EQ(robot->GetZ(),0);
  EXPECT_EQ(robot->GetID(), 1);
  EXPECT_EQ(robot->GetName(), "robot");
  
  EXPECT_EQ(drone->GetX(),robot->GetX());
  EXPECT_EQ(drone->GetY(),robot->GetY());
  EXPECT_EQ(drone->GetZ(),robot->GetZ());
  EXPECT_EQ(drone->GetID(), 0);
  EXPECT_EQ(drone->GetName(), "drone");
  delete drone;
  delete robot;
  delete charger;
  delete hospital;
}

