#pragma once

#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsEncoder
{
  public:

    template <typename TATraits>
    void operator()(
      const TATraits& Traits,
      const typename TATraits::TDType& Value)
    {
      Traits.Write(Value, mStream);
    }

    std::ostringstream mStream;
};
