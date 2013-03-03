#pragma once

#include <boost/optional.hpp>
#include <iosfwd>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsDouble
{
  public:

    typedef double TDType;

    enum TEEncoding
    {
      eFloat64BigEndian,
      eUint32BigEndian
    };

    typedef boost::optional<unsigned> TDOptional;

    TCIoTraitsDouble(
      TEEncoding Encoding,
      TDOptional ScaleToEncode = TDOptional(),
      TDOptional TranslateToEncode = TDOptional());

    TEEncoding mEncoding;

    TDOptional mScaleToEncode;

    TDOptional mTranslateToEncode;

    void Write(double Value, std::ostream& Stream) const;

    void Read(double& Value, std::istream& Stream) const;
};
