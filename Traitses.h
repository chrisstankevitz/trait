#pragma once

#include "TraitsDouble.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/variant.hpp>
#include <vector>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <class TAObject>
class TCTraitses
{
  public:

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template<class TAVisitor>
    void Visit(const TAVisitor& Visitor, TAObject* pObject)
    {
      for (const auto& Item : mItems)
      {
        boost::apply_visitor(TCVisitor<TAVisitor>(Visitor, pObject), Item);
      }
    }

  protected:

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <class TATraits>
    struct TSItem
    {
      TSItem(
        const TATraits* pTraits,
        boost::function<const typename TATraits::TDType&(const TAObject*)> Get)
        : mpTraits(pTraits),
          mGet(Get)
      {
      }

      const TATraits* mpTraits;

      boost::function<const typename TATraits::TDType&(const TAObject*)> mGet;
    };

    typedef boost::variant<TSItem<TCTraitsDouble>> TDItem;

    typedef std::vector<TDItem> TDItems;

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template<class TAVisitor>
    class TCVisitor : public boost::static_visitor<void>
    {
      public:

        TCVisitor(const TAVisitor& Visitor, TAObject* pObject)
          : mVisitor(Visitor),
            mpObject(pObject)
        {
        }

        template <class TATraits>
        void operator()(const TSItem<TATraits>& Item) const
        {
          mVisitor(*Item.mpTraits, Item.mGet(mpObject));
        }

      private:

        const TAVisitor& mVisitor;

        TAObject* mpObject;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    TCTraitses(const std::vector<TDItem>& Items)
      : mItems(Items)
    {
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <class TATraits, class TAMember>
    static TDItem Make(const TATraits& Traits, TAMember Member)
    {
      typedef typename TATraits::TDType TDType;

      return TSItem<TATraits>(&Traits, boost::bind<const TDType&>(Member, _1));
    }

  private:

    const TDItems mItems;

};
