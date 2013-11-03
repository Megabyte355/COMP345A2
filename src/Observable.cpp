/*
 * Observable.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Observable.h"

void Observable::attach(std::shared_ptr<Observer> obs)
{
    observers.push_back(obs);
}

void Observable::detach(std::shared_ptr<Observer> obs)
{
    for (std::vector<std::shared_ptr<Observer>>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if ((*it)->getSubscriberID() == obs->getSubscriberID())
        {
            observers.erase(it);
            break;
        }
    }
}

void Observable::notify()
{
    for (std::vector<std::shared_ptr<Observer>>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->update();
    }
}
