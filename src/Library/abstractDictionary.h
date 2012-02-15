#ifndef _ABSTRACTDICTIONARY_H_
#define _ABSTRACTDICTIONARY_H_


template < typename keyType, typename itemType >
class abstractDictionary {

    public :

        virtual ~abstractDictionary();

        virtual bool success() const = 0;

        virtual itemType & successItemReference() = 0;
        virtual itemType const & successItemConstReference() const = 0;

        virtual void insert(keyType const & key, itemType const & item) = 0;

        virtual void retrieve(keyType const & key) const = 0;

        virtual void remove(keyType const & key) = 0;

    };


template < typename keyType, typename itemType >
abstractDictionary< keyType, itemType >::~abstractDictionary()
{

    }


#endif
