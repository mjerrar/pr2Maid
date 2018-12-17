# PR2Maid
[![Build Status](https://travis-ci.org/mjerrar/pr2Maid.svg?branch=master)](https://travis-ci.org/mjerrar/mygit)   [![Coverage Status](https://coveralls.io/repos/github/mjerrar/TurtleMaid/badge.svg?branch=master)](https://coveralls.io/github/mjerrar/TurtleMaid?branch=master)   [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)   

PR2 based Path Planar and Lego Brick Picker Robot.

This project aims to develop the software stack using agile software development process to demonstrate the simulation of a PR2 robot that localizes in a given map and explores the environment to look for lego bricks lying around.

The PR2Maid is aimed at offloading some of the menial workload from the household domestic
worker by traversing the house floor searching for scattered Lego Bricks which it identifies, picks and
places at designated areas in order to declutter the house floor. The PR2’s off the shelf hardware consistes of two 7 DOF robotic arm mounted on a mobile base while the sensor suite comprises of a plethora of sensors including stereao cameras IMUs, two Lidars, etc. Together these components make the PR2Maid adept of many other household chores.

The repository is a ROS package implementing a Simulated PR2 Robot in a Gazebo simulator. It uses in-built ROS global path planar, a color blob detector and an opensource laser line extractor to search localize, pick and plac elego bricks in know envirenment. It utilizes th amcl Monte Carlo Localization library to estimate its pose.

## Dependencies
This ROS package is relies on the follwoing dependencies
- [ROS Kinetic](http://wiki.ros.org/kinetic) to be installed on Ubuntu 16.04. Installation instructions are outlined [here](http://wiki.ros.org/kinetic/Installation/Ubuntu).
- [Gazebo](http://gazebosim.org/) version 7.0.0 or above. Installation instructions can be found [here](http://gazebosim.org/tutorials?cat=guided_b&tut=guided_b1).
- [PR2](http://www.willowgarage.com/pages/software/overview) packages are required. Run the following command to install all pr2 related packages.
```
sudo apt-get install ros-kinetic-pr2-*
```
- [MoveIt](http://moveit.ros.org/install/) packages are required. Run the following command to install all related packages.
```
sudo apt-get install ros-kinetic-moveit
```
- [OpenCV v3](https://github.com/jayrambhia/Install-OpenCV) packages are required. Run the following command to install all related packages.
```
sudo apt-get install -y build-essential
sudo apt-get install -y cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install -y python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

# Download v3.0.0 .zip file and extract.
curl -sL https://github.com/Itseez/opencv/archive/3.0.0-beta.zip > opencv.zip
unzip opencv.zip
cd opencv-3.0.0-beta
  
 # Create a new 'build' folder.
mkdir build
cd build
  
 # Set build instructions for Ubuntu distro.
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_OPENGL=ON ..
  
 # Run 'make' with four threads.
make -j4
  
 # Install to OS.
sudo make install
  
 # Add configuration to OpenCV to tell it where the library files are located on the file system (/usr/local/lib)
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
  
sudo ldconfig
```
- [rostest](http://wiki.ros.org/rostest) framework is used for integration tests and [googletest](https://github.com/google/googletest) framework is used for unit tests. 


### Package dependences
The following are the package dependies:
- geometry_msgs
- nav_msgs
- roscpp
- rospy
- sensor_msgs
- std_msgs
- visualization_msgs
- tf
- move_base
- move_base_msgs
- actionlib
- eigen
- cv_bridge


## Solo Iterative Process (SIP)
Solo Iterative Process (SIP) is used in the development of the project. The planning and development of the project is done in three sprints. 

[Product backlog, Iteration worklogs and Sprint Schedule](https://docs.google.com/spreadsheets/d/1BXONT9rXvMvA1cxp4xclEKAFVJLtd7bnc62gGaKURDw/edit?usp=sharing).


[Sprint Planning Notes](https://docs.google.com/document/d/1e8vr-PIZ81hwqdo8a6nIUMVqKOvmAPhXKA3kNQ5tHN8/edit?usp=sharing).


[Video Presentation](https://youtu.be/Wo3xityZZCc)


## Build
In your desired directory, run the following commands.
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone https://github.com/mjerrar/pr2Maid.git
cd ..
catkin_make
```


## Run
The package consists of several different nodes and launch files
First, launch the PR2 robot model in the the lego_room.world
```
cd <path to catkin_ws>
source devel/setup.bash
roslaunch pr2maid pr2_gazebo.launch
```
Then run the navigation and localization stack using the follwoing command
```
roslaunch pr2maid pr2_nav.launch
```
Now, to visualize the planning of the planning markers and to command to there robot to nay position simply run
```
roslaunch pr2_navigation_global rviz_move_base.launch
```
To visualize the Output of the Line Extractor
```
rosrun pr2maid pr2maid_Line_extraction_node
```
and then enable visual markers in Rviz to see an overlay, you can also turn on other markers to visualize.


## Demo
![AMCL Localization](https://github.com/mjerrar/pr2Maid/blob/master/images/amcl.png)
![Line Segment Extraction](https://github.com/mjerrar/pr2Maid/blob/master/images/line_extraction.gif)
![Navigation](https://github.com/mjerrar/pr2Maid/blob/master/images/navigation.png)
![Obstacle](https://github.com/mjerrar/pr2Maid/blob/master/images/obstacle.png)

## API and other developer documentation
[kam3k/laser_line_extractor](https://github.com/kam3k/laser_line_extraction) This packages helps in isolating line segments from laser scans. It is released under BSD-3 License which can be found in the [src/Laser_Line_Extractor](https://github.com/mjerrar/pr2Maid/tree/master/src/LaserLineExtractor) folder. 


## Known Issues/ Bugs
- On restart of Rviz GUI, IMU simualted IMU sensor fails and takes time to recover effecting the EKF odometry estimation.

## Doxygen Documentation
Doxygen Documentation generation steps:
```
cd <path to package root>
mkdir Doxygen
cd Doxygen
doxygen -g <config_file_name>
```
Open configuration file and update the following:
```
PROJECT_NAME = 'pr2maid'
INPUT = ../src ../include/pr2maid/ ../test
ENABLE_PREPROCESSING = NO
```
Run and generate the documents by executing the following:
```
doxygen <config_file_name>
```

## Coverage
Install lcov
```
sudo apt-get install lcov
```
To check for coverage, execute the following commands.
```
cd <path to catkin_ws>/build
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info '/opt/*' '/usr/*' '*/devel/*' '*test_*' '*_test*' --output-file coverage.info
lcov --list coverage.info
```
The results are shown below:
![Coverage](https://github.com/mjerrar/pr2Maid/blob/master/results/coverage.png)
