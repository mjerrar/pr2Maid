# PR2Maid
[![Build Status](https://travis-ci.org/mjerrar/mygit.svg?branch=master)](https://travis-ci.org/mjerrar/mygit) [![Coverage Status](https://coveralls.io/repos/github/mjerrar/TurtleMaid/badge.svg?branch=master)](https://coveralls.io/github/mjerrar/TurtleMaid?branch=master)

PR2 based robot to detect and pick lego bricks from the floor.

Obsolete -- Update in Progress
## Dependencies
This ROS package is relies on the follwoing dependencies
- [ROS Kinetic](http://wiki.ros.org/kinetic) to be installed on Ubuntu 16.04. Installation instructions are outlined [here](http://wiki.ros.org/kinetic/Installation/Ubuntu).
- [Gazebo](http://gazebosim.org/) version 7.0.0 or above. Installation instructions can be found [here](http://gazebosim.org/tutorials?cat=guided_b&tut=guided_b1).
- [Turtlebot3](https://www.turtlebot.com/) packages are required. Run the following command to install all turtlebot3 related packages.
```
sudo apt-get install ros-kinetic-joy ros-kinetic-teleop-twist-joy ros-kinetic-teleop-twist-keyboard ros-kinetic-laser-proc ros-kinetic-rgbd-launch ros-kinetic-depthimage-to-laserscan ros-kinetic-rosserial-arduino ros-kinetic-rosserial-python ros-kinetic-rosserial-server ros-kinetic-rosserial-client ros-kinetic-rosserial-msgs ros-kinetic-amcl ros-kinetic-map-server ros-kinetic-move-base ros-kinetic-urdf ros-kinetic-xacro ros-kinetic-compressed-image-transport ros-kinetic-rqt-image-view ros-kinetic-gmapping ros-kinetic-navigation ros-kinetic-interactive-markers

sudo apt-get install ros-kinetic-turtlebot3*
```
- [Open Manipulator](http://emanual.robotis.com/docs/en/platform/turtlebot3/pc_setup/#install-ubuntu-on-remote-pc) packages are required. Run the following command to install all related packages.
```
sudo apt-get install ros-kinetic-ros-controllers ros-kinetic-gazebo* ros-kinetic-moveit* ros-kinetic-dynamixel-sdk ros-kinetic-dynamixel-workbench-toolbox ros-kinetic-industrial-core

sudo apt-get install qtbase5-dev qt5-qmake libqt5core5a libqt5gui5

sudo apt-get install ros-kinetic-open-manipulator*
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
*package dependencies to be updated*

## Solo Iterative Process (SIP)
Solo Iterative Process (SIP) is used in the development of the project. The planning and development of the project is done in three sprints. 

[Product backlog, Iteration worklogs and Sprint Schedule](https://docs.google.com/spreadsheets/d/1BXONT9rXvMvA1cxp4xclEKAFVJLtd7bnc62gGaKURDw/edit?usp=sharing).

[Sprint Planning Notes](https://docs.google.com/document/d/1e8vr-PIZ81hwqdo8a6nIUMVqKOvmAPhXKA3kNQ5tHN8/edit?usp=sharing).


## Operation
*To do*

## Run
*To do*

## Test
*To do*

## Demo
*To be updated*

## Known Issues/ Bugs
*To do*

## API and other developer documentation
*To do*
