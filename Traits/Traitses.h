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

    //-------------------------------------------------------------------------
    // Visitor: mutable
    // Object: mutable
    //-------------------------------------------------------------------------
    template<class TAVisitor>
    void Visit(TAVisitor& Visitor, TAObject& Object)
    {
      TCVisitorMM<TAVisitor> VisitorMM(Visitor, Object);

      for (const auto& Item : mItems)
      {
        boost::apply_visitor(VisitorMM, Item);
      }
    }

  protected:

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <class TATraits>
    struct TSItem
    {
      typedef boost::function<
        const typename TATraits::TDType&(const TAObject&)> TDGet;

      typedef boost::function<
        void (TAObject&, const typename TATraits::TDType&)> TDSet;

      TSItem(
        const TATraits* pTraits,
        const TDGet& Get,
        const TDSet& Set)
        : mpTraits(pTraits),
          mGet(Get),
          mSet(Set)
      {
      }

      const TATraits* mpTraits;

      TDGet mGet;

      TDSet mSet;
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
    template<class TAVisitor>
    class TCVisitorMM : public boost::static_visitor<void>
    {
      public:

        TCVisitorMM(TAVisitor& Visitor, TAObject& Object)
          : mVisitor(Visitor),
            mObject(Object)
        {
        }

        template <class TATraits>
        void operator()(const TSItem<TATraits>& Item)
        {
          Item.mSet(mObject, mVisitor(*Item.mpTraits));
        }

      private:

        TAVisitor& mVisitor;

        TAObject& mObject;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    TCTraitses(const std::vector<TDItem>& Items)
      : mItems(Items)
    {
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <class TAMember, class TAType>
    static void DoSet(TAMember Member, TAObject& Object, const TAType& Type)
    {
      boost::bind<TAType&>(Member, &Object)() = Type;
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <class TATraits, class TAMember>
    static TDItem Make(const TATraits& Traits, const TAMember& Member)
    {
      typedef typename TATraits::TDType TDType;

      return TSItem<TATraits>(
        &Traits,
        boost::bind<const TDType&>(Member, _1),
        boost::bind(DoSet<TAMember, TDType>, Member, _1, _2));
    }

  private:

    const TDItems mItems;

};
