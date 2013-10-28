/*
 * IObserver.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef IOBSERVER_H_
#define IOBSERVER_H_

class IObserver
{
    public:
        IObserver() {}
        virtual ~IObserver() {};

        virtual void update() = 0;
};

#endif /* IOBSERVER_H_ */
