// comment 1
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define STR "// comment 1&#include <iostream>&#include <fstream>&#include <algorithm>&using namespace std;&#define STR ?_?&#define TWO ofstream file;file.open (?Grace_kid.cpp?);string s(STR);char r = 38;char l = 10;char w = 63;char q = 34;std::replace(s.begin(),s.end(), r, l);std::replace(s.begin(),s.end(), w, q);s.replace(107, 1, STR, strlen(STR));file << s << endl;file.close();return (0);&#define ONE int main(void){TWO}&ONE"
#define TWO ofstream file;file.open ("Grace_kid.cpp");string s(STR);char r = 38;char l = 10;char w = 63;char q = 34;std::replace(s.begin(),s.end(), r, l);std::replace(s.begin(),s.end(), w, q);s.replace(107, 1, STR, strlen(STR));file << s << endl;file.close();return (0);
#define ONE int main(void){TWO}
ONE
