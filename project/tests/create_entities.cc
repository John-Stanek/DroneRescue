#include "gtest/gtest.h"
#include "factory.h"
#include "composite_factory.h"
#include <fstream>
//#include "object.json"
//#include "EntityFactory.h"

class FactoryTest : public ::testing::Test {
public:
  void SetUp( ) { 


  	
  	//Create json objects
  	const char* Dronejson ="{\"name\":\"drone\", \"entityId\":0, \"speed\":1,\"direction\":[0,0,0],\"position\":[0,0,0]}";

  	const char* Robotjson ="{\"name\":\"robot\", \"entityId\":1,\"position\":[0,0,0]}";

  	const char* Chargerjson ="{\"name\":\"charger\", \"entityId\":2,\"position\":[0,0,0]}";

  	const char* Hospitaljson ="{\"name\":\"hospital\", \"entityId\":3,\"position\":[0,0,0]}";


  	//picojson::value dObj= picojson::value(dStr);
  	
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
}/*

void TearDown(){
    delete factory;

    }*/

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
  delete charger;
}
