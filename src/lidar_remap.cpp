#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

class LidarRemapNode {
private:
    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::Publisher pub;

public:
    LidarRemapNode() {
        sub = nh.subscribe("/scan", 1, &LidarRemapNode::pointCloudCallback, this);
        pub = nh.advertise<sensor_msgs::LaserScan>("/scan_tf", 1);
    }

    void pointCloudCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
        sensor_msgs::LaserScan remapped_msg = *msg;
        remapped_msg.header.frame_id = "base_link";
        remapped_msg.header.stamp = ros::Time::now();
        pub.publish(remapped_msg);
    }
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "lidar_remap");
    LidarRemapNode lidar_remap_node;
    ros::spin();
    return 0;
}
