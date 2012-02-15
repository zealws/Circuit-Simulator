#ifndef _LIST_H_
#define _LIST_H_


#include "abstractList.h"
#include "bareBonesDoublyLinkedList.h"


template < typename itemType > class listPosition;
template < typename itemType > class constListPosition;
template < typename itemType > class list;


template < typename itemType >
class listPosition : public abstractListPosition< itemType > {

    friend class constListPosition< itemType >;

    private:

        static itemType ourErrorItem;

        virtual itemType & errorItemReference();

        doublyLinkedList< itemType > myInternalRepresentation;

        virtual doublyLinkedList< itemType > & internalRepresentationReference();
        virtual doublyLinkedList< itemType > const & internalRepresentationConstReference() const;
        virtual void setInternalRepresentation(doublyLinkedList< itemType > const & other);

        list< itemType > * mySubjectList;

        virtual list< itemType > * const & subjectListConstReference() const;
        virtual void setSubjectList(list< itemType > * const & other);

        virtual bool isValid() const;
        virtual bool isValidable() const;

        bool myLastOperationCausedAnError;

        virtual void setError(bool b);

        bool myLastOperationWasSuccessful;

        virtual void setSuccess(bool b);

        listPosition(list< itemType > * otherSubjectList);
        listPosition(
            doublyLinkedList< itemType > const & otherInternalRep,
            list< itemType > * otherSubjectList
            );

    public:

        listPosition();
        listPosition(list< itemType > & subject);
        listPosition(listPosition< itemType > const & otherPosition);

        virtual ~listPosition();

        virtual bool error() const;
        virtual bool success() const;

        virtual listPosition< itemType > end();
        virtual listPosition< itemType > first();

        virtual listPosition< itemType > next();
        virtual listPosition< itemType > previous();

        virtual void advance();
        virtual void advanceToEnd();

        virtual void retreat();
        virtual void retreatToFirst();

        virtual itemType & reference();
        virtual void retrieve(itemType & i);

        virtual void insert(itemType const & i);
        virtual void remove();

        virtual bool isFirst() const;
        virtual bool isEnd() const;

        virtual bool operator ==(constListPosition< itemType > const & otherPosition) const;
        virtual bool operator !=(constListPosition< itemType > const & otherPosition) const;

        listPosition< itemType > & operator =(
            listPosition< itemType > const & otherPosition
            );

    };


template < typename itemType >
class constListPosition : public abstractConstListPosition< itemType> {

    private:

        static itemType ourErrorItem;

        virtual itemType const & errorItemConstReference() const;

        doublyLinkedList< itemType > myInternalRepresentation;

        virtual doublyLinkedList< itemType > const & internalRepresentationConstReference() const;
        virtual void setInternalRepresentation(doublyLinkedList< itemType > const & other);

        list< itemType > const * mySubjectList;

        virtual list< itemType > const * const & subjectListConstReference() const;
        virtual void setSubjectList(list< itemType > const * const & other);

        virtual bool isValid() const;
        virtual bool isValidable() const;

        bool myLastOperationCausedAnError;

        virtual void setError(bool b);

        bool myLastOperationWasSuccessful;

        virtual void setSuccess(bool b);

        constListPosition(list< itemType > const * otherSubjectList);
        constListPosition(
            doublyLinkedList< itemType > const & otherInternalRep,
            list< itemType > const * otherSubjectList
            );

    public:

        constListPosition();
        constListPosition(list< itemType > const & subject);
        constListPosition(constListPosition< itemType > const & otherPosition);
        constListPosition(listPosition< itemType > const & otherPosition);

        virtual ~constListPosition();

        virtual bool error() const;
        virtual bool success() const;

        virtual constListPosition< itemType > end();
        virtual constListPosition< itemType > first();

        virtual constListPosition< itemType > next();
        virtual constListPosition< itemType > previous();

        virtual void advance();
        virtual void advanceToEnd();

        virtual void retreat();
        virtual void retreatToFirst();

        virtual itemType const & constReference();
        virtual void retrieve(itemType & i);

        virtual bool isFirst() const;
        virtual bool isEnd() const;

        virtual bool operator ==(constListPosition< itemType > const & otherPosition) const;
        virtual bool operator !=(constListPosition< itemType > const & otherPosition) const;

        constListPosition< itemType > & operator =(
            constListPosition< itemType > const & otherPosition
            );
        constListPosition< itemType > & operator =(
            listPosition< itemType > const & otherPosition
            );

    };


template < typename itemType >
class list : public abstractList< itemType > {

    friend class listPosition< itemType >;
    friend class constListPosition< itemType >;

    private:

        doublyLinkedList< itemType > myHeaderOfItemsInList;

        virtual doublyLinkedList< itemType > & headerOfItemsInListReference();
        virtual doublyLinkedList< itemType > const & headerOfItemsInListConstReference() const;

        doublyLinkedList< itemType > myTrailerOfItemsInList;

        virtual doublyLinkedList< itemType > & trailerOfItemsInListReference();
        virtual doublyLinkedList< itemType > const & trailerOfItemsInListConstReference() const;
        virtual void setTrailerOfItemsInList(doublyLinkedList< itemType > const & other);

    public:

        list();
        list(list< itemType > const & originaList);
        virtual ~list();

        virtual bool isEmpty() const;

        virtual listPosition< itemType > first();
        virtual listPosition< itemType > end();

        virtual constListPosition< itemType > first() const;
        virtual constListPosition< itemType > end() const;

        list< itemType > & operator =(list< itemType > const & originalList);

    };


#include <cstddef>


using namespace std;


//
// Class listPosition
//


//
// Private members
//


template < typename itemType >
itemType listPosition< itemType >::ourErrorItem;


template < typename itemType >
itemType & listPosition< itemType >::errorItemReference() {

    return ourErrorItem;

    }


template < typename itemType >
doublyLinkedList< itemType > & listPosition< itemType >::internalRepresentationReference() {

    return myInternalRepresentation;

    }


template < typename itemType >
doublyLinkedList< itemType > const & listPosition< itemType >::internalRepresentationConstReference() const {

    return myInternalRepresentation;

    }


template < typename itemType >
void listPosition< itemType >::setInternalRepresentation(doublyLinkedList< itemType > const & other) {

    myInternalRepresentation = other;

    }


template < typename itemType >
list< itemType > * const & listPosition< itemType >::subjectListConstReference() const {

    return mySubjectList;

    }


template < typename itemType >
void listPosition< itemType >::setSubjectList(list< itemType > * const & other) {

    mySubjectList = other;

    }


template < typename itemType >
bool listPosition< itemType >::isValid() const {

    return ! internalRepresentationConstReference().isNull() && subjectListConstReference() != NULL;

    }


template < typename itemType >
bool listPosition< itemType >::isValidable() const {

    return subjectListConstReference() != NULL;

    }


template < typename itemType >
void listPosition< itemType >::setError(bool b) {

    myLastOperationCausedAnError = b;

    }


template < typename itemType >
void listPosition< itemType >::setSuccess(bool b) {

    myLastOperationWasSuccessful = b;

    }


//
// NOTE:  This constructor is used only to construct invalid positions that
//     can be made valid (by moving the position to the first or end position).
//

template < typename itemType >
listPosition< itemType >::listPosition(list< itemType > * otherSubjectList)
        : myInternalRepresentation(),
          mySubjectList(otherSubjectList),
          myLastOperationCausedAnError(true),
          myLastOperationWasSuccessful(false)
        {

    }


template < typename itemType >
listPosition< itemType >::listPosition(
        doublyLinkedList< itemType > const & otherInternalRep,
        list< itemType > * otherSubjectList
        )
        : myInternalRepresentation(otherInternalRep),
          mySubjectList(otherSubjectList),
          myLastOperationCausedAnError(false),
          myLastOperationWasSuccessful(true)
        {

    }


//
// Public members
//


template < typename itemType >
listPosition< itemType >::listPosition(list< itemType > & subject)
        : myInternalRepresentation(subject.headerOfItemsInListConstReference()),
          mySubjectList(& subject),
          myLastOperationCausedAnError(false),
          myLastOperationWasSuccessful(true)
        {

    }


template < typename itemType >
listPosition< itemType >::listPosition()
        : myInternalRepresentation(),
          mySubjectList(NULL),
          myLastOperationCausedAnError(false),
          myLastOperationWasSuccessful(false)
        {

    }


template < typename itemType >
listPosition< itemType >::listPosition(listPosition< itemType > const & otherPosition)
        : myInternalRepresentation(otherPosition.internalRepresentationConstReference()),
          mySubjectList(otherPosition.subjectListConstReference()),
          myLastOperationCausedAnError(otherPosition.myLastOperationCausedAnError),
          myLastOperationWasSuccessful(otherPosition.myLastOperationWasSuccessful)
        {

    }


template < typename itemType >
listPosition< itemType >::~listPosition() {

    }


template < typename itemType >
bool listPosition< itemType >::error() const {

    return myLastOperationCausedAnError;

    }


template < typename itemType >
bool listPosition< itemType >::success() const {

    return myLastOperationWasSuccessful;

    }


template < typename itemType >
listPosition< itemType > listPosition< itemType >::end() {

    setError(! isValidable());
    setSuccess(! error());

    if (! error())
        return
            listPosition< itemType >(
                subjectListConstReference()
                    -> trailerOfItemsInListConstReference().prefixConstReference(),
                subjectListConstReference()
                );
    else
        return listPosition< itemType >(subjectListConstReference());

    }


template < typename itemType >
listPosition< itemType > listPosition< itemType >::first() {

    setError(! isValidable());
    setSuccess(! error());

    if (! error())
        return
            listPosition< itemType >(
                subjectListConstReference() -> headerOfItemsInListConstReference(),
                subjectListConstReference()
                );
    else
        return listPosition< itemType >(subjectListConstReference());

    }


template < typename itemType >
listPosition< itemType > listPosition< itemType >::next() {

    setError(! isValid() || isEnd());
    setSuccess(! error());

    if (! error())
        return
            listPosition< itemType >(
                internalRepresentationConstReference().suffixConstReference(),
                subjectListConstReference()
                );
    else
        return listPosition< itemType >(subjectListConstReference());

    }


template < typename itemType >
listPosition< itemType > listPosition< itemType >::previous() {

    setError(! isValid() || isFirst());
    setSuccess(! error());

    if (! error())
        return
            listPosition< itemType >(
                internalRepresentationConstReference().prefixConstReference(),
                subjectListConstReference()
                );
    else
        return listPosition< itemType >(subjectListConstReference());

    }


template < typename itemType >
void listPosition< itemType >::advance() {

    operator =(next());

    }


template < typename itemType >
void listPosition< itemType >::advanceToEnd() {

    operator =(end());

    }


template < typename itemType >
void listPosition< itemType >::retreat() {

    operator =(previous());

    }


template < typename itemType >
void listPosition< itemType >::retreatToFirst() {

    operator =(first());

    }


template < typename itemType >
itemType & listPosition< itemType >::reference() {

    setError(! isValid() || isEnd());
    setSuccess(! error());

    if (! error())
        return internalRepresentationReference().suffixReference().headReference();
    else
        return errorItemReference();

    }


template < typename itemType >
void listPosition< itemType >::retrieve(itemType & i) {

    setError(! isValid() || isEnd());
    setSuccess(! error());

    if (! error())
        i = internalRepresentationReference().suffixReference().headReference();

    }


template < typename itemType >
void listPosition< itemType >::insert(itemType const & i) {

    setError(! isValid());
    setSuccess(! error());

    if (! error())
        internalRepresentationReference().insertAfterFirst(i);

    }


template < typename itemType >
void listPosition< itemType >::remove() {

    setError(! isValid() || isEnd());
    setSuccess(! error());

    if (! error())
        internalRepresentationReference().removeAfterFirst();

    }


template < typename itemType >
bool listPosition< itemType >::isFirst() const {

    return isValid() && internalRepresentationConstReference().prefixConstReference().isNull();

    }


template < typename itemType >
bool listPosition< itemType >::isEnd() const {

    return
        isValid()
            && internalRepresentationConstReference().suffixConstReference().suffixConstReference().isNull();

    }


template < typename itemType >
bool listPosition< itemType >::operator ==(
        constListPosition< itemType > const & otherPosition
        ) const {

    return otherPosition == * this;

    }


template < typename itemType >
bool listPosition< itemType >::operator !=(
        constListPosition< itemType > const & otherPosition
        ) const {

    return ! operator ==(otherPosition);

    }


template < typename itemType >
listPosition< itemType > & listPosition< itemType >::operator =(
        listPosition< itemType > const & otherPosition
        ) {

    if (this != & otherPosition) {

        setInternalRepresentation(otherPosition.internalRepresentationConstReference());
        setSubjectList(otherPosition.subjectListConstReference());
        myLastOperationCausedAnError = otherPosition.myLastOperationCausedAnError;
        myLastOperationWasSuccessful = otherPosition.myLastOperationWasSuccessful;

        }

    return * this;

    }


//
// Class constListPosition
//


//
// Private members
//


template < typename itemType >
itemType constListPosition< itemType >::ourErrorItem;


template < typename itemType >
itemType const & constListPosition< itemType >::errorItemConstReference() const {

    return ourErrorItem;

    }


template < typename itemType >
doublyLinkedList< itemType > const & constListPosition< itemType >::internalRepresentationConstReference() const {

    return myInternalRepresentation;

    }


template < typename itemType >
void constListPosition< itemType >::setInternalRepresentation(
        doublyLinkedList< itemType > const & other
        ) {

    myInternalRepresentation = other;

    }


template < typename itemType >
list< itemType > const * const & constListPosition< itemType >::subjectListConstReference() const {

    return mySubjectList;

    }


template < typename itemType >
void constListPosition< itemType >::setSubjectList(list< itemType > const * const & other) {

    mySubjectList = other;

    }


template < typename itemType >
bool constListPosition< itemType >::isValid() const {

    return ! internalRepresentationConstReference().isNull() && subjectListConstReference() != NULL;

    }


template < typename itemType >
bool constListPosition< itemType >::isValidable() const {

    return subjectListConstReference() != NULL;

    }


template < typename itemType >
void constListPosition< itemType >::setError(bool b) {

    myLastOperationCausedAnError = b;

    }


template < typename itemType >
void constListPosition< itemType >::setSuccess(bool b) {

    myLastOperationWasSuccessful = b;

    }


//
// NOTE:  This constructor is used only to construct invalid positions that
//     can be made valid (by moving the position to the first or end position).
//

template < typename itemType >
constListPosition< itemType >::constListPosition(
        list< itemType > const * otherSubjectList
        )
        : myInternalRepresentation(),
          mySubjectList(otherSubjectList),
          myLastOperationCausedAnError(true),
          myLastOperationWasSuccessful(false)
        {

    }


template < typename itemType >
constListPosition< itemType >::constListPosition(
        doublyLinkedList< itemType > const & otherInternalRep,
        list< itemType > const * otherSubjectList
        )
        : myInternalRepresentation(otherInternalRep),
          mySubjectList(otherSubjectList),
          myLastOperationCausedAnError(false),
          myLastOperationWasSuccessful(true)

        {

    }


//
// Public members
//


template < typename itemType >
constListPosition< itemType >::constListPosition()
        : myInternalRepresentation(),
          mySubjectList(NULL),
          myLastOperationCausedAnError(false),
          myLastOperationWasSuccessful(false)

        {

    }


template < typename itemType >
constListPosition< itemType >::constListPosition(list< itemType > const & subject)
        : myInternalRepresentation(subject.headerOfItemsInListConstReference()),
          mySubjectList(& subject),
          myLastOperationCausedAnError(false),
          myLastOperationWasSuccessful(true)

        {

    }


template < typename itemType >
constListPosition< itemType >::constListPosition(
        constListPosition< itemType > const & otherPosition
        )
        : myInternalRepresentation(otherPosition.internalRepresentationConstReference()),
          mySubjectList(otherPosition.subjectListConstReference()),
          myLastOperationCausedAnError(otherPosition.myLastOperationCausedAnError),
          myLastOperationWasSuccessful(otherPosition.myLastOperationWasSuccessful)

        {

    }


template < typename itemType >
constListPosition< itemType >::constListPosition(
        listPosition< itemType > const & otherPosition
        )
        : myInternalRepresentation(otherPosition.internalRepresentationConstReference()),
          mySubjectList(otherPosition.subjectListConstReference())
        {

    }


template < typename itemType >
constListPosition< itemType >::~constListPosition() {

    }


template < typename itemType >
bool constListPosition< itemType >::error() const {

    return myLastOperationCausedAnError;

    }


template < typename itemType >
bool constListPosition< itemType >::success() const {

    return myLastOperationWasSuccessful;

    }


template < typename itemType >
constListPosition< itemType > constListPosition< itemType >::end() {

    setError(! isValidable());
    setSuccess(! error());

    if (! error())
        return
            constListPosition< itemType >(
                subjectListConstReference()
                    -> trailerOfItemsInListConstReference().prefixConstReference(),
                subjectListConstReference()
                );
    else
        return constListPosition< itemType >(subjectListConstReference());

    }


template < typename itemType >
constListPosition< itemType > constListPosition< itemType >::first() {

    setError(! isValidable());
    setSuccess(! error());

    if (! error())
        return
            constListPosition< itemType >(
                subjectListConstReference() -> headerOfItemsInListConstReference(),
                subjectListConstReference()
                );
    else
        return constListPosition< itemType >(subjectListConstReference());

    }


template < typename itemType >
constListPosition< itemType > constListPosition< itemType >::next() {

    setError(! isValid() || isEnd());
    setSuccess(! error());

    if (! error())
        return
            constListPosition< itemType >(
                internalRepresentationConstReference().suffixConstReference(),
                subjectListConstReference()
                );
    else
        return constListPosition< itemType >(subjectListConstReference());

    }


template < typename itemType >
constListPosition< itemType > constListPosition< itemType >::previous() {

    setError(! isValid() || isFirst());
    setSuccess(! error());

    if (! error())
        return
            constListPosition< itemType >(
                internalRepresentationConstReference().prefixConstReference(),
                subjectListConstReference()
                );
    else
        return constListPosition< itemType >(subjectListConstReference());

    }


template < typename itemType >
void constListPosition< itemType >::advance() {

    operator =(next());

    }


template < typename itemType >
void constListPosition< itemType >::advanceToEnd() {

    operator =(end());

    }


template < typename itemType >
void constListPosition< itemType >::retreat() {

    operator =(previous());

    }


template < typename itemType >
void constListPosition< itemType >::retreatToFirst() {

    operator =(first());

    }


template < typename itemType >
itemType const & constListPosition< itemType >::constReference() {

    setError(! isValid() || isEnd());
    setSuccess(! error());

    if (! error())
        return internalRepresentationConstReference().suffixConstReference().headConstReference();
    else
        return errorItemConstReference();

    }


template < typename itemType >
void constListPosition< itemType >::retrieve(itemType & i) {

    setError(! isValid() || isEnd());
    setSuccess(! error());

    if (! error())
        i = internalRepresentationConstReference().suffixConstReference().headConstReference();

    }


template < typename itemType >
bool constListPosition< itemType >::isFirst() const {

    return isValid() && internalRepresentationConstReference().prefixConstReference().isNull();

    }


template < typename itemType >
bool constListPosition< itemType >::isEnd() const {

    return
        isValid()
            && internalRepresentationConstReference().suffixConstReference().suffixConstReference().isNull();

    }


template < typename itemType >
bool constListPosition< itemType >::operator ==(
        constListPosition< itemType > const & otherPosition
        ) const {

    return
        internalRepresentationConstReference().isIdentical(
            otherPosition.internalRepresentationConstReference()
            );

    }


template < typename itemType >
bool constListPosition< itemType >::operator !=(
        constListPosition< itemType > const & otherPosition
        ) const {

    return ! operator ==(otherPosition);

    }


template < typename itemType >
constListPosition< itemType > & constListPosition< itemType >::operator =(
        constListPosition< itemType > const & otherPosition
        ) {

    if (this != & otherPosition) {

        setInternalRepresentation(otherPosition.internalRepresentationConstReference());
        setSubjectList(otherPosition.subjectListConstReference());
        myLastOperationCausedAnError = otherPosition.myLastOperationCausedAnError;
        myLastOperationWasSuccessful = otherPosition.myLastOperationWasSuccessful;

        }

    return * this;

    }


template < typename itemType >
constListPosition< itemType > & constListPosition< itemType >::operator =(
        listPosition< itemType > const & otherPosition
        ) {

    setInternalRepresentation(otherPosition.internalRepresentationConstReference());
    setSubjectList(otherPosition.subjectListConstReference());
    myLastOperationCausedAnError = otherPosition.myLastOperationCausedAnError;
    myLastOperationWasSuccessful = otherPosition.myLastOperationWasSuccessful;

    return * this;

    }


//
// Class list
//


//
// Private members
//


template < typename itemType >
doublyLinkedList< itemType > & list< itemType >::headerOfItemsInListReference() {

    return myHeaderOfItemsInList;

    }


template < typename itemType >
doublyLinkedList< itemType > const & list< itemType >::headerOfItemsInListConstReference() const {

    return myHeaderOfItemsInList;

    }


template < typename itemType >
doublyLinkedList< itemType > & list< itemType >::trailerOfItemsInListReference() {

    return myTrailerOfItemsInList;

    }


template < typename itemType >
doublyLinkedList< itemType > const & list< itemType >::trailerOfItemsInListConstReference() const {

    return myTrailerOfItemsInList;

    }


template < typename itemType >
void list< itemType >::setTrailerOfItemsInList(doublyLinkedList< itemType > const & other) {

    myTrailerOfItemsInList = other;

    }


//
// Public members
//


template < typename itemType >
list< itemType >::list()
        : myHeaderOfItemsInList(),
          myTrailerOfItemsInList()
        {

    headerOfItemsInListReference().insertFirst(itemType());
    setTrailerOfItemsInList(headerOfItemsInListConstReference());
    headerOfItemsInListReference().insertFirst(itemType());

    }


template < typename itemType >
list< itemType >::list(list< itemType > const & originalList)
        : myHeaderOfItemsInList(),
          myTrailerOfItemsInList()
        {

    originalList.headerOfItemsInListConstReference().duplicate(
        headerOfItemsInListReference(),
        trailerOfItemsInListReference()
        );

    }


template < typename itemType >
list< itemType >::~list() {

    headerOfItemsInListReference().destroy();

    }


template < typename itemType >
bool list< itemType >::isEmpty() const {

    return first() == end();

    }


template < typename itemType >
listPosition< itemType > list< itemType >::first() {

    return listPosition< itemType >(* this);

    }


template < typename itemType >
listPosition< itemType > list< itemType >::end() {

    return listPosition< itemType >(* this).end();

    }


template < typename itemType >
constListPosition< itemType > list< itemType >::first() const {

    return constListPosition< itemType >(* this);

    }


template < typename itemType >
constListPosition< itemType > list< itemType >::end() const {

    return constListPosition< itemType >(* this).end();

    }


template < typename itemType >
list< itemType > & list< itemType >::operator =(list< itemType > const & originalList) {

    if (this != & originalList) {

        headerOfItemsInListReference().destroy();
        originalList.headerOfItemsInListConstReference().duplicate(
            headerOfItemsInListReference(),
            trailerOfItemsInListReference()
            );

        }

    return * this;

    }


#endif
