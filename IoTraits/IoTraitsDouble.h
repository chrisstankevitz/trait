#pragma once
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

    TCIoTraitsDouble(
      TEEncoding Encoding,
      double ScaleToEncode = 1,
      double TranslateToEncode = 0);

    TEEncoding mEncoding;

    double mScaleToEncode;

    double mTranslateToEncode;

    void Write(double Value, std::ostream& Stream) const;
};
