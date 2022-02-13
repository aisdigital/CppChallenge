/** \file utils.h
 *  \brief Some useful definitions.
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <algorithm>

#define STR_TO_LOWER(str_in, str_out) transform(str_in.begin(), str_in.end(), str_out.begin(), ::tolower)
#define STR_TO_UPPER(str_in, str_out) transform(str_in.begin(), str_in.end(), str_out.begin(), ::toupper)

#endif /* UTILS_H_ */