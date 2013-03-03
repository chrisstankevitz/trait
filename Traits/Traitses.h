#pragma once

#include "Utility/WrappingVariantMaker.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/variant.hpp>
#include <vector>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <class TAObject, class ... TAAllowableTraits>
class TCTraitses
{
  public:

    //-------------------------------------------------------------------------
    // Visitor: const
    // Object: const
    //-------------------------------------------------------------------------
    template<class TAVisitor>
    void Visit(const TAVisitor& Visitor, const TAObject& Object)
    {
      TCVisitorCC<TAVisitor> VisitorCC(Visitor, Object);

      for (const auto& Item : mItems)
      {
        boost::apply_visitor(VisitorCC, Item);
      }
    }

    //-------------------------------------------------------------------------
    // Visitor: mutable
    // Object: const
    //-------------------------------------------------------------------------
    template<class TAVisitor>
    void Visit(TAVisitor& Visitor, const TAObject& Object)
    {
      TCVisitorMC<TAVisitor> VisitorMC(Visitor, Object);

      for (const auto& Item : mItems)
      {
        boost::apply_visitor(VisitorMC, Item);
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
        boost::function<const typename TATraits::TDType&(const TAObject&)> Get)
        : mpTraits(pTraits),
          mGet(Get)
      {
      }

      const TATraits* mpTraits;

      boost::function<const typename TATraits::TDType&(const TAObject&)> mGet;
    };

    typedef typename
      TSWrappingVariantMaker<TSItem, TAAllowableTraits ...>::TDResult TDItem;

    typedef std::vector<TDItem> TDItems;

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template<class TAVisitor>
    class TCVisitorCC : public boost::static_visitor<void>
    {
      public:

      TCVisitorCC(const TAVisitor& Visitor, const TAObject& Object)
          : mVisitor(Visitor),
            mObject(Object)
        {
        }

        template <class TATraits>
        void operator()(const TSItem<TATraits>& Item) const
        {
          mVisitor(*Item.mpTraits, Item.mGet(mObject));
        }

      private:

        const TAVisitor& mVisitor;

        const TAObject& mObject;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template<class TAVisitor>
    class TCVisitorMC : public boost::static_visitor<void>
    {
      public:

      TCVisitorMC(TAVisitor& Visitor, const TAObject& Object)
          : mVisitor(Visitor),
            mObject(Object)
        {
        }

        template <class TATraits>
        void operator()(const TSItem<TATraits>& Item)
        {
          mVisitor(*Item.mpTraits, Item.mGet(mObject));
        }

      private:

        TAVisitor& mVisitor;

        const TAObject& mObject;
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
