#include <vector>

void Reverse ( std::vector<int>& v )
{
    size_t  size = v.size ();
    
    for ( int idx = 0 ; idx < size / 2; ++idx ) {
        int temp = v[idx];
        v[idx] = v[size - idx - 1];
        v[size - idx - 1] = temp;
    }
}
