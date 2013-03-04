#pragma once

#include <boost/mpl/bool.hpp>
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

    typedef boost::mpl::bool_<false> TDRead;

    template <class TATraits>
    typename TATraits::TDType operator()(const TATraits& Traits)
    {
      typename TATraits::TDType Value;

      Traits.Read(Value, mStream);

      return Value;
    }

    std::istringstream mStringStream;

    std::istream& mStream;
};
