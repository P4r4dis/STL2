#ifndef                 __FIND__
    #define             __FIND__

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator  do_find(T &type, int var)
{
    return std::find(type.begin(), type.end(), var);
}


#endif //               __FIND__