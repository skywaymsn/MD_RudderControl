
#include <Arduino.h>
#include <MD_RudderControl.h> // https://github.com/skywaymsn/MD_RudderControl
#include <MD_CompassBearing/src/MD_CompassBearing.h> // https://github.com/skywaymsn/MD_CompassBearing

namespace MD {

    Rudder::Rudder(Compass compass) {
        _rightRotation = _getRightRotation(compass.targetBearing, compass.currentBearing);
        _leftRotation = _getLeftRotation(_rightRotation);
    }

    unsigned long Compass::_getLeftRotation(_rightRotation) {
        _leftRotatation = (360 - _rightRotation);
        return _leftRotatation;
    }

    unsigned long Compass::_getRightRotation(targetBearing, currentBearing) {
        _rightRotation = (targetBearing - currentBearing);
        return _rightRotation;
    }
}
