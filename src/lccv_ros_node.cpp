#include "lccv_ros.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "lccv_ros");
    ros::NodeHandle nh("~");
    LccvRos lccv_ros(nh);
    ROS_INFO("Starting lccv_ros");
    lccv_ros.run();
    ROS_INFO("Exiting lccv_ros");
    return 0;
}