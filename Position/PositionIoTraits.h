#pragma once

#include "Position.h"
#include "Traits/Traitses.h"
#include "IoTraits/IoTraitsDouble.h"
#include "IoTraits/IoTraitsUnsigned.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCPositionIoTraits
: public TCTraitses<TCPosition, TCIoTraitsDouble, TCIoTraitsUnsigned>
{
  public:

    static const TCIoTraitsDouble sLatitudeTraits;

    static const TCIoTraitsDouble sAltitudeTraits;

    static const TCIoTraitsUnsigned sStepsTraits;

    TCPositionIoTraits();
};
