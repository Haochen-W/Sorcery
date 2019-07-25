#include "exception.h"

InvalidPosition::InvalidPosition(std::string s): s{s} {}
std::string InvalidPosition::getErrorMessage(){return s;}


ExceedMaximum::ExceedMaximum(std::string s): s{s} {}
std::string ExceedMaximum::getErrorMessage(){return s;}
