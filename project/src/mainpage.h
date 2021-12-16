/*! \mainpage Search And Rescue Drone System
 *
 * \section API
 *
 * This is the API for the Search and Rescue Drone system.
 *\n
 *  
 *
 * This is a colllaborative project between four students to create a drone search and rescue system.
 * The drone patrols the map constantly taking pictures. The drone utilizes an image processing system (iimageio library) to scan the pictures it takes for the robot. Once detected, the drone will beeline to the Robot's position.
 * Other entities can be created as well such as hospitals and recharge stations.
 * Simply use the arrow keys to move the drone. Click 'p' to patrol the map. Click 'b' to beeline to a position.
 * 
 * \n\n 
 * This project can be made by running "make" in the terminal with the given make file. This will successfully compile the code, which can then be run with the following: \n
 * "./build/web-app 8081 web/"\n
 * \n
 * 
 *
 * \section Overview
 * The project is split into two different subsystems: the simulation, and the camera. The simulation   consists of everything that is used when running the simulation, including: entities (such as robots, drones, recharge stations, and hospitals) that are created through the use of a composite factory pattern. A battery decorator is used to implement the ability to give any entity a battery object and have that battery interact with the simulation. Drones and robots are the main entities used as the goal of the entire simulation is for the drone to search out and rescue the robot. Drones have multiple different movement options that are implemented, which describe ways in which the drone moves about the simulation. These movement options include: patrolling, beelining, and manual movement via the arrow keys on a keyboard.
 *Drones are the only entity type that move about the simulation and most of the focus is on the drone during the simulation. This simulation is the main loop for the program to run and it will only stop upon a keyboard signal interrupt (CTRL + C).
 *
 *The camera subsystem is part of each drone, and it controls anything to do with taking pictures, analyzing them, and telling the drone what it has seen. The camera image processor uses a blob detection filter to gather information about where the drone is relative to other entities. This is the drone’s only way of interpreting the simulation.
 *
 *
 * <a href="uml.pdf" target="_blank"><b>Link to UML diagram</b></a>
 *
 * \section Getting-Started
 *
 *Navigate to a directory location to clone the repo to.
 *Execute the following command:
 * <b> git clone https://github.umn.edu/umn-csci-3081-f21/repo-team-75.git </b>
 *
 *
 *Navigate to the project directory inside the repo-team-75 directory.
 *To compile/build the code, use:
 * **make -j**
 *(make clean can be used at any time to delete all compiled objects, which can then be recompiled using make -j again.)
 *
 *Finally to run the simulation, use:
 *
 * <b>./build/test-app </b> to run tests for the compiled code
 *And
 * <b> ./build/web-app 8081 </b> web to run the actual simulation
 *8081 can be replaced with any desired port
 *
 *
 *To view the simulation while its running, open up a web browser and put in the following url:
 * **127.0.0.1:8081**
 *Where 8081 is the port specified in the previous instruction
 *
 *
 *To stop the simulation while its running, use:
 * **Ctrl + C** in the terminal window where it is running.
 *
 */
