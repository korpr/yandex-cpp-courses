#include <string>
#include <vector>
using namespace std;

#define UNIQ_ID uId1(__LINE__)
#define uId1(ln) uId2(ln)
#define uId2(ln) var##ln

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}
