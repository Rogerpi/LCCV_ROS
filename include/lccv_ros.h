#pragma once

#include <ros/ros.h>
#include "lccv.hpp"

#include <image_transport/image_transport.h>

class LccvRos
{
public:
    LccvRos(ros::NodeHandle &nh, int framerate = 20);
    ~LccvRos();

    void run();

private:

    // image publisher
    image_transport::Publisher lccv_pub_;
    image_transport::ImageTransport it_;

    Lccv lccv_;
    ros::NodeHandle nh_;

    std::unique_ptr<lccv::PiCamera> cam_;

    int framerate_;
};
