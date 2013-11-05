/*
 * Observable.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Observable.h"

void Observable::attach(Observer * obs)
{
    observers.push_back(obs);
    std::cout << "Observer attached." << std::endl;
}

void Observable::detach(Observer * obs)
{
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if ((*it)->getSubscriberID() == obs->getSubscriberID())
        {
            observers.erase(it);
            std::cout << "Observer detached." << std::endl;
            break;
        }
    }
}

void Observable::notify()
{
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->update();
    }
}
