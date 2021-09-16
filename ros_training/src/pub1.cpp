#include "ros/ros.h" // header for ROS system
#include "std_msgs/String.h" // string message type from std_msgs package

#include <sstream>

// Node to publish a topic

int main(int argc, char **argv)
{



  ros::init(argc, argv, "talker"); // Initialize ROS, with name of node

  ros::NodeHandle n; // Create a handle to node; initialize node

  // Message type: std_msgs::String
  // Topic name: my_topic
  // Size of queue: 1000 
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("my_topic", 1000);

  ros::Rate loop_rate(10); // looping rate

  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg; // Declare variabe msg

    std::stringstream ss; // Declare variable ss
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

