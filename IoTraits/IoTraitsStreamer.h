#pragma once

#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsStreamer
{
  public:

    template <typename TATraits>
    void operator()(
      const TATraits& Traits,
      const typename TATraits::TDType& Value) const
    {
      //Traits.Write(Value, mStream);
    }

    std::ostringstream mStream;
};
