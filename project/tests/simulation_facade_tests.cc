#include "gtest/gtest.h"

#include "simulation.h"

class SimulationTest : public ::testing::Test {
	public:
		picojson::value val;
		std::string drone_json, robot_json, charger_json, hospital_json;
		Simulation simulation;
		int* ptr = NULL;
		
		void SetUp() {
			simulation = Simulation();
			//Create test json inputs
			drone_json ="{\"name\":\"drone\", \"entityId\":0, \"speed\":1,\"direction\":[0,0,0],\"position\":[0,0,0]}";
			robot_json ="{\"name\":\"robot\", \"entityId\":1,\"position\":[0,0,0]}";
			charger_json ="{\"name\":\"recharge station\", \"entityId\":2,\"position\":[0,0,0]}";
			hospital_json ="{\"name\":\"hospital\", \"entityId\":3,\"position\":[0,0,0]}";
		}
};

TEST_F(SimulationTest, TestCreateEntity) {
	val = picojson::value(drone_json);
	simulation.CreateEntity(val.get<picojson::object>(), ptr);
	EXPECT_EQ(simulation.GetEntity(0).GetID(), 0);

}
