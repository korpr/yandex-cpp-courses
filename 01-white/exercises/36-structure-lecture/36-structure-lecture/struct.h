#include <string>
using namespace std;
struct Specialization {
    explicit Specialization ( string aValue ) : value ( aValue ) {};
    string value;
};

struct Course {
    explicit Course ( string aValue ) : value ( aValue ) {};
    string value;
};
struct Week {
    explicit Week ( string aValue ) : value ( aValue ) {};
    string value;
};

struct LectureTitle {

    explicit LectureTitle ( Specialization aS, Course aC, Week aW ) : specialization ( aS ), course ( aC ), week ( aW ) {}
    
    Specialization specialization;
    Course course;
    Week week;
};
