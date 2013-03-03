#pragma once

#include "Position.h"
#include "Traitses.h"
#include "UiTraitsDouble.h"
#include "UiTraitsUnsigned.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCPositionUiTraits
: public TCTraitses<TCPosition, TCUiTraitsDouble, TCUiTraitsUnsigned>
{
  public:

    static const TCUiTraitsDouble sLatitudeTraits;

    static const TCUiTraitsDouble sAltitudeTraits;

    static const TCUiTraitsUnsigned sStepsTraits;

    TCPositionUiTraits();
};
