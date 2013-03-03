#pragma once

#include <boost/variant.hpp>

template<
  template<class TAArgX> class TAOuter,
  class ...TAInner>
struct TSWrappingVariantMaker {};

template<
  template<class TAArgX> class TAOuter,
  class TAArg0>
struct TSWrappingVariantMaker<TAOuter, TAArg0>
{
  typedef TAOuter<TAArg0> TDItem0;

 typedef boost::variant<TDItem0> TDResult;
};

template<
  template<class TAArgX> class TAOuter,
  class TAArg0,
  class TAArg1>
struct TSWrappingVariantMaker<TAOuter, TAArg0, TAArg1>
{
  typedef TAOuter<TAArg0> TDItem0;

  typedef TAOuter<TAArg1> TDItem1;

  typedef boost::variant<TDItem0, TDItem1> TDResult;
};

template<
  template<class TAArgX> class TAOuter,
  class TAArg0,
  class TAArg1,
  class TAArg2>
struct TSWrappingVariantMaker<TAOuter, TAArg0, TAArg1, TAArg2>
{
  typedef TAOuter<TAArg0> TDItem0;

  typedef TAOuter<TAArg1> TDItem1;

  typedef TAOuter<TAArg2> TDItem2;

  typedef boost::variant<TDItem0, TDItem1, TDItem2> TDResult;
};
