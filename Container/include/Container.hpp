#ifndef                     __CONTAINER__
    #define                 __CONTAINER__
#include <list>
#include <vector>
#include <iostream>
template<typename T, template<typename, typename...> class Container>
class                       Contain
{
    public:
        Contain(void) {};

        void                push(T const &data)
        {
            _container.push_back(data);
        };

        void                aff(void)
        {
            for(auto &value : _container)
            {
                if (value == 7)
                    std::cout << "Value: 7" << std::endl;
                else
                    std::cout << "Value: " << value << std::endl;
            }
        };
        
        void                add(void)
        {
            for(auto &value : _container)
            {
                value++;
            }     
        };
    private:
        Container<T>        _container;
};

#endif //                   __CONTAINER__