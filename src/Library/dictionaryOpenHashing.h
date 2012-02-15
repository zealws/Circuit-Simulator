#ifndef _DICTIONARYOPENHASHING_H_
#define _DICTIONARYOPENHASHING_H_


#include <vector>


using namespace std;


#include "abstractDictionary.h"
#include "list.h"
#include "orderedPair.h"


template < typename keyType, typename itemType >
class dictionary : abstractDictionary< keyType, itemType > {

    private :

        static itemType ourErrorItem;

        virtual itemType & errorItemReference();
        virtual itemType const & errorItemConstReference() const;

        static keyType const ourErrorKey;

        virtual keyType const & errorKeyConstReference() const;

        static unsigned ourDefaultNumberOfBuckets;

        vector< list< orderedPair< keyType, itemType > > > myBuckets;

        virtual vector< list< orderedPair< keyType, itemType > > > & bucketsReference();
        virtual vector< list< orderedPair< keyType, itemType > > > const & bucketsConstReference() const;
        virtual void setBuckets(vector< list< orderedPair< keyType, itemType > > > const & v);

        unsigned (* myFold)(keyType const & key);

        virtual void setFold(unsigned (* p)(keyType const & key));

        mutable bool mySuccess;

        virtual void setSuccess(bool b) const;

        mutable itemType * mySuccessItemPointer;

        virtual itemType * successItemPointer() const;
        virtual void setSuccessItemPointer(itemType * p) const;

        mutable keyType const * mySuccessKeyPointer;

        virtual keyType const * successKeyPointer() const;
        virtual void setSuccessKeyPointer(keyType const * p) const;

        virtual unsigned hash(unsigned foldedKey) const;

    public :

        dictionary(unsigned initFold(keyType const & key));
        dictionary(unsigned initFold(keyType const & key), unsigned initNumberOfBuckets);
        dictionary(dictionary< keyType, itemType > const & original);

        virtual ~dictionary();

        dictionary< keyType, itemType > & operator =(
            dictionary< keyType, itemType > const & original
            );

        virtual unsigned numberOfBuckets() const;

        virtual unsigned (* fold() const)(keyType const & key);

        virtual bool success() const;

        virtual itemType & successItemReference();
        virtual itemType const & successItemConstReference() const;

        virtual keyType const & successKeyConstReference() const;

        virtual void insert(keyType const & key, itemType const & item);

        virtual void retrieve(keyType const & key) const;

        virtual void remove(keyType const & key);

        virtual void clear();

    };


//
// Private Members
//


template < typename keyType, typename itemType >
itemType dictionary< keyType, itemType>::ourErrorItem;


template < typename keyType, typename itemType >
itemType & dictionary< keyType, itemType>::errorItemReference() {

    return ourErrorItem;

    }


template < typename keyType, typename itemType >
itemType const & dictionary< keyType, itemType>::errorItemConstReference() const {

    return ourErrorItem;

    }


template < typename keyType, typename itemType >
keyType const dictionary< keyType, itemType>::ourErrorKey;


template < typename keyType, typename itemType >
keyType const & dictionary< keyType, itemType>::errorKeyConstReference() const {

    return ourErrorKey;

    }


template < typename keyType, typename itemType >
unsigned dictionary< keyType, itemType>::ourDefaultNumberOfBuckets = 521;


template < typename keyType, typename itemType >
vector< list< orderedPair< keyType, itemType > > > & dictionary< keyType, itemType>::bucketsReference() {

    return myBuckets;

    }


template < typename keyType, typename itemType >
vector< list< orderedPair< keyType, itemType > > > const & dictionary< keyType, itemType>::bucketsConstReference() const {

    return myBuckets;

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::setBuckets(vector< list< orderedPair< keyType, itemType > > > const & v) {

    myBuckets = v;

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::setFold(unsigned (* p)(keyType const & key)) {

    myFold = p;

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::setSuccess(bool b) const {

    mySuccess = b;

    }


template < typename keyType, typename itemType >
itemType * dictionary< keyType, itemType>::successItemPointer() const {

    return mySuccessItemPointer;

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::setSuccessItemPointer(itemType * p) const {

    mySuccessItemPointer = p;

    }


template < typename keyType, typename itemType >
keyType const * dictionary< keyType, itemType>::successKeyPointer() const {

    return mySuccessKeyPointer;

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::setSuccessKeyPointer(keyType const * p) const {

    mySuccessKeyPointer = p;

    }


template < typename keyType, typename itemType >
unsigned dictionary< keyType, itemType>::hash(unsigned foldedKey) const {

    return foldedKey % numberOfBuckets();

    }


//
// Public Members
//


template < typename keyType, typename itemType >
dictionary< keyType, itemType>::dictionary(unsigned initFold(keyType const & key))
        : myBuckets(ourDefaultNumberOfBuckets),
          myFold(initFold),
          mySuccess(true),
          mySuccessItemPointer(& errorItemReference()),
          mySuccessKeyPointer(& errorKeyConstReference())
        {

    }


template < typename keyType, typename itemType >
dictionary< keyType, itemType>::dictionary(
        unsigned initFold(keyType const & key),
        unsigned initNumberOfBuckets
        )
        : myBuckets(initNumberOfBuckets),
          myFold(initFold),
          mySuccess(true),
          mySuccessItemPointer(& errorItemReference()),
          mySuccessKeyPointer(& errorKeyConstReference())
        {

    }


template < typename keyType, typename itemType >
dictionary< keyType, itemType>::dictionary(dictionary< keyType, itemType> const & original)
        : myBuckets(original.bucketsConstReference()),
          myFold(original.fold()),
          mySuccess(original.success()),
          mySuccessItemPointer(& errorItemConstReference()),
          mySuccessKeyPointer(& errorKeyConstReference())
        {

    }


template < typename keyType, typename itemType >
dictionary< keyType, itemType>::~dictionary() {

    }


template < typename keyType, typename itemType >
dictionary< keyType, itemType> & dictionary< keyType, itemType>::operator =(
        dictionary< keyType, itemType> const & original
        ) {

    if (this != & original) {

        setBuckets(original.bucketsConstReference());
        setFold(original.fold());
        setSuccess(true);
        setSuccessItemPointer(& errorItemReference());
        setSuccessKeyPointer(& errorKeyConstReference());

        }

    return * this;

    }


template < typename keyType, typename itemType >
unsigned dictionary< keyType, itemType>::numberOfBuckets() const {

    return bucketsConstReference().size();

    }


template < typename keyType, typename itemType >
unsigned (* dictionary< keyType, itemType>::fold() const)(keyType const & key) {

    return myFold;

    }


template < typename keyType, typename itemType >
bool dictionary< keyType, itemType>::success() const {

    return mySuccess;

    }


template < typename keyType, typename itemType >
itemType & dictionary< keyType, itemType>::successItemReference() {

    return * successItemPointer();

    }


template < typename keyType, typename itemType >
itemType const & dictionary< keyType, itemType>::successItemConstReference() const {

    return * successItemPointer();

    }


template < typename keyType, typename itemType >
keyType const & dictionary< keyType, itemType>::successKeyConstReference() const {

    return * successKeyPointer();

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::insert(
        keyType const & key,
        itemType const & item) {

    constListPosition< orderedPair< keyType, itemType > > bucketPos(
        bucketsConstReference()[ hash(fold()(key)) ]
        );

    for ( ;
            ! bucketPos.isEnd() && bucketPos.constReference().firstConstReference() != key;
            bucketPos.advance())
        ; // do nothing

    setSuccess(bucketPos.isEnd());

    if (success()) {

        bucketsReference()[ hash(fold()(key)) ].first().insert(
            orderedPair< keyType, itemType >(key, item)
            );

        setSuccessItemPointer(
            & bucketsReference()[ hash(fold()(key)) ].first().reference().secondReference()
            );
        setSuccessKeyPointer(
            & bucketsConstReference()[ hash(fold()(key)) ].first().constReference().firstConstReference()
            );

        }

    else {

        setSuccessItemPointer(& errorItemReference());
        setSuccessKeyPointer(& errorKeyConstReference());

        }

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::retrieve(keyType const & key) const {

    constListPosition< orderedPair< keyType, itemType > > bucketPos(
        bucketsConstReference()[ hash(fold()(key)) ]
        );

    for ( ;
            ! bucketPos.isEnd() && bucketPos.constReference().firstConstReference() != key;
            bucketPos.advance())
        ; // do nothing

    setSuccess(! bucketPos.isEnd());

    if (success()) {

        setSuccessItemPointer(& const_cast< orderedPair< keyType, itemType > & >(
            bucketPos.constReference()).secondReference()
            );
        setSuccessKeyPointer(& bucketPos.constReference().firstConstReference());

        }

    else {

        setSuccessItemPointer(& const_cast< itemType & >(errorItemConstReference()));
        setSuccessKeyPointer(& errorKeyConstReference());

        }

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::remove(keyType const & key) {

    listPosition< orderedPair< keyType, itemType > > bucketPos(
        bucketsReference()[ hash(fold()(key)) ]
        );

    for ( ;
            ! bucketPos.isEnd() && bucketPos.reference().firstConstReference() != key;
            bucketPos.advance())
        ; // do nothing

    setSuccess(! bucketPos.isEnd());

    if (success())
        bucketPos.remove();

    setSuccessItemPointer(& errorItemReference());
    setSuccessKeyPointer(& errorKeyConstReference());

    }


template < typename keyType, typename itemType >
void dictionary< keyType, itemType>::clear() {

    for (int j = 0; j < numberOfBuckets(); ++ j)
        for ( ; ! bucketsConstReference()[ j ].isEmpty(); bucketsReference()[ j ].first().remove())
            ; // do nothing

    setSuccess(true);
    setSuccessItemPointer(& errorItemReference());
    setSuccessKeyPointer(& errorKeyConstReference());

    }


#endif
