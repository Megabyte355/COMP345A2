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
#include <vector>
#include <iostream>

class Observable
{
    public:
        Observable() {}
        virtual ~Observable() {}

        void attach(Observer*);
        void detach(Observer*);
        void notify();

    protected:
        // IObserver variables
        std::vector<Observer*> observers;
};

#endif /* IOBSERVABLE_H_ */
