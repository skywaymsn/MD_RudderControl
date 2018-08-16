#ifndef MD_RUDDER
#define MD_RUDDER

#include <Arduino.h>

namespace MD {
  class Rudder {
    public:
      Rudder::Rudder(Compass compass); // 
      void currentBearing(unsigned long value); 
      void targetBearing(unsigned long value);  
      void rotationLeftDistance(unsigned long value);              // Distance to turn left for the target bearing
      void rotationRightDistance(unsigned long value);             // Distance to turn right for the target bearing
      int _rudder_attitude_custom;          // Degrees to turn the rudder if not using the angle divider.
    private:
      unsigned long _getCurrentBearing(); // Read the current bearing from the device
      unsigned long _leftRotation;
      unsigned long _rightRotation;
      unsigned long currentBearing;
      int _rudder_direction;                // 0 for Starboard (right), 1 for port (left)
      int _rudder_attitude_tiny = 10;       // Degrees to turn the rudder
      int _rudder_attitude_small = 20;      // Degrees to turn the rudder
      int _rudder_attitude_medium = 45;     // Degrees to turn the rudder
      int _rudder_attitude_hard = 60;       // Degrees to turn the rudder

  };
}
#endif
