/*
 * StackException.h
 *
 *  Created on: Oct 25, 2013
 *      Author: chaos
 */

#ifndef STACKEXCEPTION_H_
#define STACKEXCEPTION_H_

#include<stdexcept>
#include<string>
class int : public std::logic_error {
public:
	int(const std::string & message = ""): logic_error(message.c_str()) {};
	~int()throw();
};

#endif /* STACKEXCEPTION_H_ */
