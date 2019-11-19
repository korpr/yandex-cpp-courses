#include <string>
using namespace std;
struct Specialization {
    explicit Specialization ( const string& aValue ) : value ( aValue ) {};
    string value;
};

struct Course {
    explicit Course ( const string& aValue ) : value ( aValue ) {};
    string value;
};
struct Week {
    explicit Week ( const string& aValue ) : value ( aValue ) {};
    string value;
};

struct LectureTitle {

    explicit LectureTitle ( const Specialization& aS, cont Course& aC, const Week& aW ) : specialization ( aS ), course ( aC ), week ( aW ) {}
    
    Specialization specialization;
    Course course;
    Week week;
};
