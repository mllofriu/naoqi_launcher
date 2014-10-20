/// <summary>
/// Module to save current values to a file in each DCM iteration (each 10 ms)
/// </summary>

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <boost/shared_ptr.hpp>
#include <iostream>
#include <fstream>

// ROS includes
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <camera_info_manager/camera_info_manager.h>
#include <image_transport/image_transport.h>

#include <alcommon/almodule.h>
#include <alproxies/alvideodeviceproxy.h>

using namespace std;

namespace AL
{
  class ALBroker;
}

/// <summary>
/// Class to publish images as a ros topic
/// </summary>
class Publisher : public AL::ALModule
{
public:
    Publisher(boost::shared_ptr<AL::ALBroker> pBroker,
                        const std::string &pName);

    virtual ~Publisher();
    void init();

private:
    void publishImage();
    void publishImages();
    void publishInfo();
    void nodeletManager();
    boost::shared_ptr<AL::ALVideoDeviceProxy> visionProxy;
    image_transport::CameraPublisher camera_pub;
    boost::shared_ptr<camera_info_manager::CameraInfoManager> cinfo_;
    std::string name;

};

#endif // PUBLISHER_H
