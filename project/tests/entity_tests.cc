#include "gtest/gtest.h"
#include "entity.h"
#include "composite_factory.h"

//2 unit tests, 3 regression tests
class EntityTest : public ::testing::Test {
public:
    void SetUp() {
    	const char* Robotjson ="{\"name\":\"robot\", \"entityId\":1,\"position\":[0,0,0]}";

    	std::string err;
		const char* json_end = picojson::parse(rValue, Robotjson, Robotjson + strlen(Robotjson), &err);
		if (! err.empty()) {
		  std::cerr << err << std::endl;
		}
	 	else {
		    printf("robot json parsed\n");
		}
    }
protected:
    picojson::value rValue;
	CompositeFactory factory = CompositeFactory();
};

TEST_F(EntityTest, EntitySetPos) {
	if(!rValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Robot* robot = static_cast<Robot*>(factory.CreateEntity(rValue.get<picojson::object>())); 
	  if(robot == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }
	EXPECT_EQ(0,robot->GetPos()[0]);
	EXPECT_EQ(0,robot->GetPos()[1]);
	EXPECT_EQ(0,robot->GetPos()[2]);

	double pos[3] = {100, 200, 100};
    robot->SetPos(pos);

    EXPECT_EQ(100,robot->GetPos()[0]);
	EXPECT_EQ(200,robot->GetPos()[1]);
	EXPECT_EQ(100,robot->GetPos()[2]);

    delete robot;
}

TEST_F(EntityTest, EntityGetPos) {
	if(!rValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Robot* robot = static_cast<Robot*>(factory.CreateEntity(rValue.get<picojson::object>())); 
	  if(robot == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }
	EXPECT_EQ(0,robot->GetPos()[0]);
	EXPECT_EQ(0,robot->GetPos()[1]);
	EXPECT_EQ(0,robot->GetPos()[2]);

	double pos[3] = {100, 200, 100};
    robot->SetPos(pos);
    
    EXPECT_EQ(100,robot->GetPos()[0]);
	EXPECT_EQ(200,robot->GetPos()[1]);
	EXPECT_EQ(100,robot->GetPos()[2]);

    delete robot;
}

TEST_F(EntityTest, GetIdTests) {
	if(!rValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Robot* robot = static_cast<Robot*>(factory.CreateEntity(rValue.get<picojson::object>())); 
	  if(robot == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }
	  
    EXPECT_EQ(robot->GetID(), 1); 
    delete robot;
}

TEST_F(EntityTest, GetName) {
	if(!rValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Robot* robot = static_cast<Robot*>(factory.CreateEntity(rValue.get<picojson::object>())); 
	  if(robot == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }
	
	EXPECT_EQ(robot->GetName(), "robot");
	robot->SetName("not robot");
	EXPECT_EQ(robot->GetName(), "not robot");
    
    delete robot;
}

TEST_F(EntityTest, EntitySetDir) {
	if(!rValue.is<picojson::object>()){
		ASSERT_EQ(true,false); // force fail test
	}
	  Robot* robot = static_cast<Robot*>(factory.CreateEntity(rValue.get<picojson::object>())); 
	  if(robot == NULL){
	  	ASSERT_EQ(false,true); // force fail test
	  }
	
	EXPECT_EQ(0,robot->GetDir()[0]);
	EXPECT_EQ(0,robot->GetDir()[1]);
	EXPECT_EQ(0,robot->GetDir()[2]);

	double dir[3] = {10, 5, 1};
    robot->SetPos(dir);
    
    EXPECT_EQ(10,robot->GetPos()[0]);
	EXPECT_EQ(5,robot->GetPos()[1]);
	EXPECT_EQ(1,robot->GetPos()[2]);

    delete robot;
}