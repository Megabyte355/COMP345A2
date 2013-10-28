/*
 * IObservable.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef IOBSERVABLE_H_
#define IOBSERVABLE_H_

#include "IObserver.h"

class IObservable
{
    public:
        IObservable();
        virtual ~IObservable();

        virtual void attach(IObserver &) = 0;
        virtual void detach(IObserver &) = 0;
        virtual void notify() = 0;
};

#endif /* IOBSERVABLE_H_ */
