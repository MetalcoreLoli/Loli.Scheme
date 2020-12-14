#include <vector>
namespace helper
{
    
    ///
    /// Funcition skip few elemnts of vector<T> from start of it
    /// source is source vector
    /// count is number of elements that will be skip
    /// return new vector without skiped elements
    ///
    template<typename T> std::vector<T> Skip(const std::vector<T>& source, int count)
    {
        std::vector<T> result;
        for(int i = count; i < source.size(); i++)
            result.push_back(source[i]);
        return result;
    }
}
