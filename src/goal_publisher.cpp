#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/PoseStamped.h>
#include <fstream>
#include <string>
#include <vector>
#include <tf/tf.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class GoalPublisher {
public:
    GoalPublisher(const std::string& goal_file) : ac("move_base", true), goal_index(0) {
        // Wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))) {
            ROS_INFO("Waiting for the move_base action server to come up");
        }

        // Load goals from the CSV file
        loadGoals(goal_file);

        // Send the first goal
        sendNextGoal();
    }

private:
    ros::NodeHandle nh;
    MoveBaseClient ac;
    std::vector<geometry_msgs::PoseStamped> goals;
    size_t goal_index;

    void loadGoals(const std::string& goal_file) {
        std::ifstream infile(goal_file);
        std::string line;
        std::getline(infile, line); // Skip the header

        while (std::getline(infile, line)) {
            std::istringstream iss(line);
            std::string token;
            geometry_msgs::PoseStamped goal;
            goal.header.frame_id = "map";

            std::getline(iss, token, ',');
            goal.pose.position.x = std::stod(token);
            std::getline(iss, token, ',');
            goal.pose.position.y = std::stod(token);
            std::getline(iss, token, ',');
            double theta = std::stod(token);
            tf::Quaternion q;
            q.setRPY(0, 0, theta);
            goal.pose.orientation.x = q.x();
            goal.pose.orientation.y = q.y();
            goal.pose.orientation.z = q.z();
            goal.pose.orientation.w = q.w();

            goals.push_back(goal);
        }
    }

    void sendNextGoal() {
        if (goal_index < goals.size()) {
            move_base_msgs::MoveBaseGoal goal;
            goal.target_pose = goals[goal_index];
            ac.sendGoal(goal);
            goal_index++;
        } else {
            ROS_INFO("All goals have been processed");
        }
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "goal_publisher");

    ros::NodeHandle private_nh("~");
    std::string goal_file;
    private_nh.param<std::string>("goal_file", goal_file, "waypoints.csv");

    // creating the GoalPublisher object, passing the goal file as a parameter, received from the parameter server
    GoalPublisher goal_publisher("waypoints.csv");

    ros::spin();
    return 0;
}