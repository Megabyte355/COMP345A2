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

class Observable
{
    public:
        Observable() {}
        virtual ~Observable() {}

        void attach(std::shared_ptr<Observer>);
        void detach(std::shared_ptr<Observer>);
        void notify();

    private:
        // IObserver variables
        std::vector<std::shared_ptr<Observer>> observers;
};

#endif /* IOBSERVABLE_H_ */
