#pragma once

#include <boost/mpl/bool.hpp>
#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsEncoder
{
  public:

    TCIoTraitsEncoder(std::ostream& Stream)
    : mStringStream(),
      mStream(Stream)
    {
    }

    TCIoTraitsEncoder()
    : mStringStream(),
      mStream(mStringStream)
    {
    }

    std::string GetBytes() const
    {
      return mStringStream.str();
    }

    typedef boost::mpl::bool_<true> TDRead;

    template <class TATraits>
    void operator()(
      const TATraits& Traits,
      const typename TATraits::TDType& Value)
    {
      Traits.Write(Value, mStream);
    }

    std::ostringstream mStringStream;

    std::ostream& mStream;
};
