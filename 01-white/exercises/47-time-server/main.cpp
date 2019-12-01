#include <iostream>
#include <string>
#include "time-server.cpp"

using namespace std;

string AskTimeServer ()
{
    return "0000000000";
};

int main ()
{
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime () << endl;
    } catch ( exception & e ) {
        cout << "Exception got:" << e.what () << endl;
    }
    return 0;
}
