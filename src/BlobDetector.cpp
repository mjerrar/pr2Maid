
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

/*
* @Author: Jerrar Bukhari
* @Date:   2018-12-16 20:03:16
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-16 20:59:37
*/

#include <PR2Maid/BlobDetector.h>


/**
 * @brief      Constructs the class BlobDetector
 */
Edge_Detector::Edge_Detector(): it_(nh_) {
    image_sub_ = it_.subscribe("/wide_stereo/left/image_raw", 1,
                               &Edge_Detector::imageCb, this);
    image_pub_ = it_.advertise("/edge_detector/raw_image", 1);
}

Edge_Detector::~Edge_Detector() {}

void Edge_Detector::imageCb(const sensor_msgs::ImageConstPtr& msg) {
    try {
        img_bridge = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings
                                        ::BGR8);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }
    img_src = img_bridge->image;
}


/**
 * @brief      Detect Edges of blobs
 *
 * @param[in]  img   The image
 *
 * @return     return the centroids of blobs
 */
cv::Mat Edge_Detector::detect_edges(cv::Mat img) {
    cv::Mat src, src_gray, centR, centG, centB, cent, holder;
    cv::Mat dst, detected_edges;
    cv::Mat thr, gray, points;
    cv::Mat color_planes[3];

    cv::Mat canny_output;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;

    img.copyTo(src);

    split(src, color_planes);

    cv::Mat red_plane = cv::max(color_planes[2]
     - color_planes[1] - color_planes[0], 0);
    cv::Mat green_plane = cv::max(color_planes[1]
     - color_planes[2] - color_planes[0], 0);
    cv::Mat blue_plane = cv::max(color_planes[0]
     - color_planes[1] - color_planes[2], 0);

    color_planes[2] = red_plane;
    color_planes[1] = green_plane;
    color_planes[0] = blue_plane;



    for (int iter = 0; iter <= 2; iter++) {
        cv::Scalar color;

        if (iter == 0) {
            color = cv::Scalar(180, 100, 0);
        } else if (iter == 1) {
            color = cv::Scalar(50, 180, 50);
        } else if (iter == 2) {
            color = cv::Scalar(0, 50, 180);
        }

        cv::threshold(color_planes[iter], thr, 20, 255, CV_THRESH_BINARY);
        cv::blur(thr, detected_edges, cv::Size(5, 5) );

        // detect edges using canny
        cv::Canny(detected_edges, canny_output, 50, 100, 5, false);
        // find contours
        cv::findContours(canny_output, contours, hierarchy, CV_RETR_TREE,
                        CV_CHAIN_APPROX_NONE, cv::Point(0, 0));
        // get the moments
        std::vector<cv::Moments> mu(contours.size());
        for (int i = 0; i < contours.size(); i++ )
        {mu[i] = cv::moments(contours[i], false);}
        // get the centroid of figures.
        std::vector<cv::Point2f> mc(contours.size());
        for (int i = 0; i < contours.size(); i++) {
            mc[i] = cv::Point2f(mu[i].m10 / mu[i].m00 , mu[i].m01 / mu[i].m00);
            points = cv::Mat(mc[i]);
            ROS_INFO_STREAM(points);
        }

        // draw contours
        cv::Mat drawing(canny_output.size(), CV_8UC3, cv::Scalar(0, 0, 0));
        for ( int i = 0; i < contours.size(); i++ ) {
            drawContours(drawing, contours, i, color, 2, 8,
                                hierarchy, 0, cv::Point());
            circle(drawing, mc[i], 25, color, -1, 8, 0);
        }

        if (iter == 0) {
            drawing.copyTo(centB);
        } else if (iter == 1) {
            drawing.copyTo(centG);
        } else if (iter == 2) {
            drawing.copyTo(centR);
        }
    }


    cv::max(centR, centG, cent);
    cv::max(cent, centB, cent);
    return cent;
}


/**
 * @brief      Publish the image at /edge_detector/raw topic
 */
void Edge_Detector::load_publish() {
    img_cent = detect_edges(img_src);
    img_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8",
                                img_cent).toImageMsg();
    image_pub_.publish(img_msg);
}


int main(int argc, char** argv) {
    ros::init(argc, argv, "Edge_Detector");
    Edge_Detector ic;
    ros::Rate loop(0.3);
    while (ros::ok()) {
        ic.load_publish();
        ros::spinOnce();
        loop.sleep();
    }
    return 0;
}
