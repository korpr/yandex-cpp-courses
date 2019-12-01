#include <exception>
#include <system_error>
#include <string>

using namespace std;
extern string AskTimeServer();

class TimeServer
{
public:
    string GetCurrentTime ()
    {
        try {
            last_fetched_time = AskTimeServer();
        } catch ( const system_error& ex ) {
        
        }
        return last_fetched_time;
    }
    
private:
    string last_fetched_time = "00:00:00";
};
