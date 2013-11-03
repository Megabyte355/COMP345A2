/*
 * IObservable.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef IOBSERVABLE_H_
#define IOBSERVABLE_H_

#include "Observer.h"
#include <memory>

class Observable
{
    public:
        Observable() {}
        virtual ~Observable() {}

        virtual void attach(std::shared_ptr<Observer>) = 0;
        virtual void detach(std::shared_ptr<Observer>) = 0;
        virtual void notify() = 0;
};

#endif /* IOBSERVABLE_H_ */
