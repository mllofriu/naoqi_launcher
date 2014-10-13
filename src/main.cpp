#include <signal.h>
#include <boost/shared_ptr.hpp>
#include <alcommon/albroker.h>
#include <alcommon/almodule.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>
#include "publisher.h"

#ifdef _WIN32
# define ALCALL __declspec(dllexport)
#else
# define ALCALL
#endif

#define BOILERPLATE(x) \
extern "C" \
{ \
  ALCALL int _createModule(boost::shared_ptr<AL::ALBroker> pBroker)\
  {\
    AL::ALBrokerManager::setInstance(pBroker->fBrokerManager.lock()); \
    AL::ALBrokerManager::getInstance()->addBroker(pBroker); \
    AL::ALModule::createModule<x>(pBroker, #x ); \
    return 0; \
  } \
  ALCALL int _closeModule() \
  { \
    return 0; \
  } \
}

BOILERPLATE(Publisher)
