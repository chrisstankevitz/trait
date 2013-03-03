#pragma once

#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsDecoder
{
  public:

    TCIoTraitsDecoder(std::istream& Stream)
    : mStringStream(),
      mStream(Stream)
    {
    }

    TCIoTraitsDecoder(const std::string& Bytes)
    : mStringStream(Bytes),
      mStream(mStringStream)
    {
    }

    template <typename TATraits>
    typename TATraits::TDType operator()(const TATraits& Traits)
    {
      typename TATraits::TDType Value;

      Traits.Read(Value, mStream);

      return Value;
    }

    std::istringstream mStringStream;

    std::istream& mStream;
};
