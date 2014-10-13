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

private:

  // Initialisation of ALMemory/DCM link
  void init();

  // Store sensor values.
  std::vector<float> sensorValues;
  boost::shared_ptr<AL::ALVideoDeviceProxy> visionProxy;
};

#endif // PUBLISHER_H
