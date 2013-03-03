#pragma once

#include <boost/optional.hpp>
#include <iosfwd>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsUnsigned
{
  public:

    typedef unsigned TDType;

    enum TEEncoding
    {
      eUint32BigEndian
    };

    typedef boost::optional<unsigned> TDOptional;

    TCIoTraitsUnsigned(
      TEEncoding Encoding,
      TDOptional ScaleToEncode = TDOptional(),
      TDOptional TranslateToEncode = TDOptional());

    TEEncoding mEncoding;

    TDOptional mScaleToEncode;

    TDOptional mTranslateToEncode;

    void Write(unsigned Value, std::ostream& Stream) const;

    void Read(unsigned& Value, std::istream& Stream) const;
};
