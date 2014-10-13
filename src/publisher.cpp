/// <summary>
/// Module to save current values to a file in each DCM iteration (each 10 ms)
/// </summary>

#include "publisher.h"
#include <boost/shared_ptr.hpp>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <alcommon/almodule.h>

#include <alerror/alerror.h>

// Used to read values of ALMemory directly in RAM
#include <alvision/alvisiondefinitions.h>

#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

using namespace AL;

/// <summary>
/// Module to save current values to a file in each DCM iteration (each 10 ms)
/// </summary>
/// <param name="broker"> A smart pointer to the broker.</param>
/// <param name="name">   The name of the module. </param>
Publisher::Publisher(boost::shared_ptr<AL::ALBroker> broker,
                                         const std::string &name)
    : AL::ALModule(broker, name)
{
    setModuleDescription( "Publish images as a ros topic" );

    // Init nao node
    int argc = 0;
    char** argv = NULL;
    ros::init(argc, argv, "nao_publisher");

    // Subscribe to the camera
    try {
        visionProxy = boost::shared_ptr<ALVideoDeviceProxy>
           (new ALVideoDeviceProxy());
        int cam_index = 0;
        visionProxy->subscribeCamera("ros_local_cam", cam_index, kVGA, kYUVColorSpace, 30);
    } catch (const ALError& e) {
        std::cerr << "Could not create proxy: " << e.what() << std::endl;
    }


}

Publisher::~Publisher()
{
}


// Initialisation of ALmemory fast access, DCM commands, Alias, stiffness, ...
void Publisher::init()
{
}
