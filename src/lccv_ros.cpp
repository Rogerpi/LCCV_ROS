#include "lccv_ros.h"
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>


LccvRos::LccvRos(ros::NodeHandle &nh, int framerate) : nh_(nh), it_(nh), framerate_(framerate)
{
    lccv_pub_ = it_.advertise("image", 5);

    cam_ = std::make_unique<lccv::PiCamera>();
    cam_->options->photo_width = 4056;
    cam_->options->photo_height = 3040;
    cam_->options->verbose=true;
}

LccvRos::~LccvRos()
{
}

void LccvRos::run()
{
    sensor_msgs::ImagePtr msg;
    cv_bridge::CvImage cv_image;

    // ros rate
    ros::Rate loop_rate(framerate_);

    while (ros::ok())
    {
        if (!cam_->capturePhoto(cv_image.image))
        {
            ROS_ERROR("Camera error");
        }
        cv_image.encoding = "bgr8";
        msg = cv_image.toImageMsg();
        lccv_pub_.publish(msg);
        loop_rate.sleep();
    }
}

