#pragma once

#include "TraitsDouble.h"
#include "TraitsUnsigned.h"

//-----------------------------------------------------------------------------
// This class defines a "position".  For each parameter, the "traits" are
// provided.
//-----------------------------------------------------------------------------
class TCPosition
{
  public:

    double mLatitude;

    static const TCTraitsDouble sLatitudeTraits;

    double mAltitude;

    static const TCTraitsDouble sAltitudeTraits;

    unsigned mSteps;

    static const TCTraitsUnsigned sStepsTraits;
};
