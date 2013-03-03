#pragma once

#include "Position.h"
#include "TraitsDouble.h"
#include "TraitsUnsigned.h"
#include "Traitses.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCPositionUiTraits
: public TCTraitses<TCPosition, TCTraitsDouble, TCTraitsUnsigned>
{
  public:

    static const TCTraitsDouble sLatitudeTraits;

    static const TCTraitsDouble sAltitudeTraits;

    static const TCTraitsUnsigned sStepsTraits;

    TCPositionUiTraits();
};
