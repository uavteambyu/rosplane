#include <ros/ros.h>
#include <rosplane_msgs/Waypoint.h>

#define num_waypoints 3

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rosplane_simple_path_planner");

  ros::NodeHandle nh_;
  ros::Publisher waypointPublisher = nh_.advertise<rosplane_msgs::Waypoint>("waypoint_path", 10);

  float Va = 14;
  float wps[5*num_waypoints] =
  {
    200, 0, -50, 90*M_PI/180, Va,
    150, 100, -50, 180*M_PI/180, Va,
    100,0 , -50, 270*M_PI/180, Va,
  };

  for (int i(0); i <= num_waypoints; i++)
  {
    ros::Duration(2).sleep();
    rosplane_msgs::Waypoint new_waypoint;
    if (i == num_waypoints){
      ros::Duration(30);
      new_waypoint.clear_wp_list = true;
    }else{
        new_waypoint.w[0] = wps[i*5 + 0];
        new_waypoint.w[1] = wps[i*5 + 1];
        new_waypoint.w[2] = wps[i*5 + 2];
        new_waypoint.chi_d = wps[i*5 + 3];

        new_waypoint.chi_valid =false;
        new_waypoint.Va_d = wps[i*5 + 4];
        if (i == 0)
          new_waypoint.set_current = true;
        else
          new_waypoint.set_current = false;
        new_waypoint.clear_wp_list = false;
    }
    waypointPublisher.publish(new_waypoint);
    ros::Duration(10).sleep();

  }

  return 0;
}
