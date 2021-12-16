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
 * We designed a program that uses a drone to search a map, the camera on the drone uses image processing to detect the lost robot, and then rescue the robot. The drone initially starts searching the map looking for the robot. The drone has two different movement types patrol and beeline. The drone also has a battery to limit its movement time. If the drone’s battery life reaches twenty percent it will start to beeline to the closest recharge station. After the battery is recharged, it will start patrolling for the robot. The camera on the drone will keep taking pictures while using a canny edge detection filter to find the robot. Once the robot is found the drone will stop patrolling and beeline to the robot’s position. 
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
 *\How to Contribute:
 * How to add additional features to the program. First decide what feature you want to implement. Then look at the UML diagram that we have designed to show how to implement the new feature into the program. The UML diagram will show the relationship the new feature has with existing features. Based on how the relationships are shown the code written needs to be of the same design. If the new feature is not already in the UML design it will have to be implemented before a new feature can be started. The new feature can be inserted into the program as seen fit based on the model already given. After you create the model add the feature to the sprint.  Once completion of the code is achieved meet with your group to review your code. While reviewing make sure that the code will work together and not have any issues if you merge it together. Also check to make sure all of the classes are working together. After all the code works unanimously you can create pull requests to merge the code. We decided that the team should follow the Google C++ style guide. For example, we decided that following Google’s naming conventions would be highly beneficial to the project. Google specifies formatting rules for type names, variable names, and function names that help ensure consistency in naming and better identify the purpose of variables. Making sure that names are consistent and easily understood is important when different team members are working across multiple classes and multiple files. Although a majority of the style conventions were helpful, the team decided that some of the conventions should be modified. For example, the Google style guide proposes that lines of code should almost always remain under 80 characters long. While we agreed that the length of our lines of code should remain reasonable, 80 characters long was determined to be arbitrarily short. The Google style guide additionally restricts the use of tabs in all code. Although it is likely that spaces are better for ensuring legacy system compatibility, we believed it was better for the team to use tabs when indenting code to ensure consistency. The parting words section of the Google style guide outlines the importance of consistency. Working together as a team to keep the style of our code consistent has improved the communication between our team members and likely reduced the number of bugs in our code. 
 *
 * \section Image-Processing
 * An image processing subsystem is used to identify whether a Robot is present in images. To process an image, the Camera class within the Drone class calls the ProcessImages() function. The image to be processed is passed into this function. This function utilizes the ImageIO library to process the image with a series of filters. The ImageIO library contains algorithms for color thresholding and canny edge detection that are used to detect a Robot in an image. First, the BlobDetection filter from ImageIO is used to perform color thresholding on the image and find the color blobs. Next, the CannyEdgeDetect filter from ImageIO is used to detect the edges of the blobs. Lastly, a ratio of blob pixels to edge pixels is calculated and checked to see if the ratio is above a threshold. If the ratio is above the threshold, then the Robot is found and the function returns true. Adding new filters to the system could be done by creating a new function within the Camera class that processes images with new image filters. 
 * 
 * \section Simulation
 * The simulation is responsible for creating, moving, and updating all entities within the simulation. Entities include drones, robots, recharge stations, and hospitals. All interactions with the simulation are handled through the Simulation Facade class. The CreateEntity() function within the Simulation Facade is responsible for creating Entities. Entities are created using a CompositeFactory that contains a DroneFactory, RobotFactory, ChargerFactory, and a HospitalFactory. One of these factories is chosen to create a specific kind of Entity based on the picojson object passed into the call to CreateEntity(). This process uses a combination of the Abstract Factory and the Composite Factory design patterns as the CompositeFactory as well as all of the factories within the CompositeFactory inherit from an abstract Factory class.

The Update() function within the Simulation Facade is responsible for moving and updating Entities. The Simulation Facade contains a vector of all of the Entities within the simulation. The Update() function loops through each of the entities within this vector and calls the Update() function of each Entity. Polymorphism is used to change the behavior of the Update() function for each kind of Entity. The Update() function for a Drone Entity updates the movement of the Drone Entity. If a keyboard input is entered, the Drone will move according to the keyboard input. Otherwise, the Drone will move in either a Beeline or Patrol behavior depending on the movement option stored within the Drone. The Update() function for Drones also takes pictures via the Camera stored within each Drone. The Camera uses the Image Processor to find if a Robot is present in the picture.

Adding a new type of entity to the simulation is simple. First, ensure that the new entity type inherits from the Entity class. Next, add a new Factory to the CompositeFactory that will create this new type of Entity. Ensure that it checks the picojson object passed into CreateEntity() to see if an Entity of the new type should be created. Lastly, create a Update() function for the new type to define how it should be updated. A UML diagram of the end result would include a new class that inherits from Entity and a new Factory that is contained in the CompositeFactory.

 */
