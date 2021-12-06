#include "gtest/gtest.h"
#include "drone.h"
#include "composite_factory.h"

//4 unit tests

class DroneTest : public ::testing::Test {
public:
    void SetUp() {
    	const char* Dronejson ="{\"name\":\"drone\", \"entityId\":0, \"speed\":1,\"direction\":[0,0,0],\"position\":[0,0,0]}";

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
    picojson::value dValue;
	CompositeFactory factory = CompositeFactory();
};

TEST_F(DroneTest, SetSpeedTests) {
	if(!dValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Drone* drone = static_cast<Drone*>(factory.CreateEntity(dValue.get<picojson::object>())); 
	  if(drone == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }

    drone->SetSpeed(100);
    EXPECT_EQ(drone->GetSpeed(), 100);
    delete drone;
}

TEST_F(DroneTest, GetSpeedTests) {
	if(!dValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Drone* drone = static_cast<Drone*>(factory.CreateEntity(dValue.get<picojson::object>())); 
	  if(drone == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }
	  
    drone->SetSpeed(100);
    EXPECT_EQ(drone->GetSpeed(), 100);
    delete drone;
}

TEST_F(DroneTest, GetIdTests) {
	if(!dValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Drone* drone = static_cast<Drone*>(factory.CreateEntity(dValue.get<picojson::object>())); 
	  if(drone == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }
	  
    EXPECT_EQ(drone->GetId(), 0);
    delete drone;
}

TEST_F(DroneTest, UpdateTest) {
	if(!dValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Drone* drone = static_cast<Drone*>(factory.CreateEntity(dValue.get<picojson::object>())); 
	  if(drone == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }
	

	double arrows[4] = {1,0,0,0};
	bool moves[2] = {false,false};
	double dt = 0.5;

	EXPECT_EQ(drone->GetPosition(0), 0);
	drone->Update(dt,arrows,moves);

	EXPECT_EQ(drone->GetPosition(0), 0.5);
    
    delete drone;
}