#include <iostream>
#include "sum_reverse_sort.h"
#include "test_runner.h"

void sumTest()
{
    AssertEq ( Sum ( 1, 3 ), Sum ( 3, 1 ), "1+3 == 3+1" );
    AssertEq ( 3, Sum ( 0, 3 ), "0,3 = 0" );
}

void reverseTest()
{
    AssertEq ( "1234", Reverse ( "4321" ), "4321->1234" );
}

void sortTest()
{
    std::vector<int> ex = {1, 2, 3, 4, 5};
    std::vector<int> test = {2, 1, 3, 5, 4};
    Sort ( test );
    AssertEq ( ex, test, "4321 = 1234" );
}
int main ( int argc, char **argv )
{
    TestRunner r;
    r.RunTest ( sumTest, "sum test" );
    r.RunTest ( reverseTest, "reverse test" );
    r.RunTest ( sortTest, "sort test" );
    return 0;
}
