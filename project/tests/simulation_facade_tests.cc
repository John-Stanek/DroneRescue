#include "gtest/gtest.h"

#include "simulation.h"

//5 component tests

class SimulationTest : public ::testing::Test {
	public:
		picojson::value dValue,rValue,cValue, hValue;
		Simulation* simulation;
		
		void SetUp() {
			simulation = new Simulation();
			//Create json objects
			const char* drone_json ="{\"name\":\"drone\", \"entityId\":0, \"speed\":1,\"direction\":[0,0,0],\"position\":[0,0,0]}";

			const char* robot_json ="{\"name\":\"robot\", \"entityId\":1,\"position\":[0,0,0]}";

			const char* charger_json ="{\"name\":\"recharge station\", \"entityId\":2,\"position\":[0,0,0]}";

			const char* hospital_json ="{\"name\":\"hospital\", \"entityId\":3,\"position\":[0,0,0]}";
			
			//parse drone json
			std::string err;
			const char* json_end = picojson::parse(dValue, drone_json, drone_json + strlen(drone_json), &err);
			if (! err.empty()) {
			  std::cerr << err << std::endl;
			}

			//parse robot json
			json_end = picojson::parse(rValue, robot_json, robot_json + strlen(robot_json), &err);
			if (! err.empty()) {
			  std::cerr << err << std::endl;
			}

			//parse charger json
			json_end = picojson::parse(cValue, charger_json, charger_json + strlen(charger_json), &err);
			if (! err.empty()) {
			  std::cerr << err << std::endl;
			}

			//parse hospital json
			json_end = picojson::parse(hValue, hospital_json, hospital_json + strlen(hospital_json), &err);
			if (! err.empty()) {
			  std::cerr << err << std::endl;
			}
		}
};

TEST_F(SimulationTest, TestCreateDronePos) {
	simulation->CreateEntity(dValue.get<picojson::object>());
	EXPECT_EQ(simulation->GetEntity(0)->GetPos()[0], 0);
	EXPECT_EQ(simulation->GetEntity(0)->GetPos()[1], 0);
	EXPECT_EQ(simulation->GetEntity(0)->GetPos()[2], 0);
	delete simulation;
}

TEST_F(SimulationTest, TestCreateDroneDir) {
	simulation->CreateEntity(dValue.get<picojson::object>());
	EXPECT_EQ(simulation->GetEntity(0)->GetDir()[0], 0);
	EXPECT_EQ(simulation->GetEntity(0)->GetDir()[1], 0);
	EXPECT_EQ(simulation->GetEntity(0)->GetDir()[2], 0);
	delete simulation;
}


TEST_F(SimulationTest, TestCreateEntitiesID) {
	simulation->CreateEntity(dValue.get<picojson::object>());
	EXPECT_EQ(simulation->GetEntity(0)->GetID(), 0);
	
	simulation->CreateEntity(rValue.get<picojson::object>());
	EXPECT_EQ(simulation->GetEntity(1)->GetID(), 1);
	
	simulation->CreateEntity(cValue.get<picojson::object>());
	EXPECT_EQ(simulation->GetEntity(2)->GetID(), 2);
	
	delete simulation;
}

TEST_F(SimulationTest, TestUpdate) {
	simulation->CreateEntity(dValue.get<picojson::object>());
	simulation->CreateEntity(rValue.get<picojson::object>());
	simulation->CreateEntity(cValue.get<picojson::object>());
	double arrows[4] = {0.0, 0.0, 0.0, 0.0};
	bool moves[2] = {false, false};
	simulation->Update(0.1, arrows, moves);

	delete simulation;
}

TEST_F(SimulationTest, TestFinishUpdate) {
	simulation->CreateEntity(dValue.get<picojson::object>());
	simulation->CreateEntity(rValue.get<picojson::object>());
	simulation->CreateEntity(cValue.get<picojson::object>());
	simulation->FinishUpdate(hValue.get<picojson::object>());

	delete simulation;
}

