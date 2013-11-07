/*
 * Observable.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Observable.h"

long Observable::attachments = 0;

void Observable::attach(Observer * obs)
{
    observers.push_back(obs);
    attachmentID = attachments++;
    std::cout << "Observable #" << attachmentID << " attached." << std::endl;

}

void Observable::detach(Observer * obs)
{
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if ((*it)->getSubscriberID() == obs->getSubscriberID())
        {
            observers.erase(it);
            std::cout << "Observable #" << attachmentID << " detached." << std::endl;
            break;
        }
    }
}

void Observable::notify()
{
    std::cout << "Observable #" << attachmentID << " calling notify()." << std::endl;
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->update();
    }
}
