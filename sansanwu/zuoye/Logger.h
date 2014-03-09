/*******************************************************************************
  Title          : Logger.h
  Author         : n-critser 
  Created on     : 
  Description    : original basis from https://github.com/LaurentGomila/SFML/wiki/Source%3A-Simple-File-Logger-%28by-mateandmetal%29
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -g -Wall -Werror  
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <fstream>


/*Log file for collecting output:
 * ********************************
 * usage:  write_Log("string");
 * 		   write_Log(convertDigit(number));
 */
#ifndef LOGGER_H
#define LOGGER_H

namespace debug {
        class Logger {
                
        private:
                std::ofstream log_file; //("log.txt",std::ios::out | std::ios::app);
                unsigned int errors;
                unsigned int warnings;
                
                
        public:
                enum e_logType { DEBUG, WARNING, INFO };

                explicit Logger ( const char * project, const char *fname = "def_log.txt" )
                        : errors (0U), warnings (0U) {
                        log_file.open (fname);
                        if (log_file.is_open()) {
                                log_file << "Project name: "<< project << std::endl;
                                log_file << "Log_file_name:" << fname << std::endl;
                        }
                }

                ~Logger () {
                        if (log_file.is_open()) {
                                log_file << std::endl;
                                log_file << "Warnings: " <<warnings << std::endl;
                                log_file << "Errors:  "  <<errors  << std::endl;
                                log_file.close();
                        }
                }

                                
                friend Logger &operator<< (Logger &logger, const e_logType l_type) {
                        switch (l_type){
                        case DEBUG:
                                logger.log_file << "[DEBUG]: ";
                                ++logger.errors;
                                break;
                        case WARNING:
                                logger.log_file << "[WARNING]: ";
                                ++logger.warnings;
                                break;

                        case INFO:
                                logger.log_file << "[INFO]: ";
                                break;
                        }
                        return logger;
                }
                //friend Logger &operator << (Logger &logger, const char* text){
                friend Logger &operator << (Logger &logger, const char* text){
                        logger.log_file << text;
                        std::cout<<text;
                        return logger;
                }
                friend Logger &operator << (Logger &logger, const std::string str){
                        logger.log_file << str;
                        std::cout << str;
                        return logger;
                }

                friend Logger &operator << (Logger &logger, const int num){
                        logger.log_file << num;
                        std::cout << num;
                        return logger;
                }

                //Logger (const Logger &) = delete;
                //Logger &operator= (const Logger &) = delete;
                
        };

} /*namespace end  */
#endif

/*
void write_Log(const std::string & text){
	std::ofstream log_file("log_file.txt",std::ios::out |std::ios::app);// TODO: allow for clobber mode
	log_file << "\n";
	log_file << text ;
	std::cout<<  text << std::endl;
}
*/
