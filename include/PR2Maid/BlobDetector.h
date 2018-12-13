
/**
 * Copyright (C) 2018  Jerrar Bukhari
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INCLUDE_PR2MAID_BLOBDETECTOR_H_
#define INCLUDE_PR2MAID_BLOBDETECTOR_H_

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

static const std::string OPENCV_WINDOW = "Raw Image window";
static const std::string OPENCV_WINDOW_1 = "Edge Detection";

class Edge_Detector {
 private:
  ros::NodeHandle nh_;
  cv::Mat img_src;
  cv::Mat img_cent;
  cv_bridge::CvImagePtr img_bridge;
  sensor_msgs::ImagePtr img_msg;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher image_pub_;

 public:
  Edge_Detector();
  ~Edge_Detector();
  void imageCb(const sensor_msgs::ImageConstPtr& msg);
  cv::Mat detect_edges(cv::Mat img);
  void load_publish();
};

#endif  // INCLUDE_PR2MAID_BLOBDETECTOR_H_
