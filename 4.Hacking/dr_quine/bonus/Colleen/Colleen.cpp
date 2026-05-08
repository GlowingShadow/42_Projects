#include <iostream>
#include <string>
using namespace std;
//comment 1
void func(void){}
int main(void)
{
	char q = 34;
	string l[] = {
"#include <iostream>",
"#include <string>",
"using namespace std;",
"//comment 1",
"void func(void){}",
"int main(void)",
"{",
"	char q = 34;",
"	string l[] = {",
"	};",
"	for(int i = 0; i <= 8; i++)",
"		cout << l[i] << endl;",
"	for(int i = 0; i <= 19; i++)",
"		cout << q + l[i] + q + ',' << endl;",
"	for(int i = 9; i <= 19; i++)",
"		cout << l[i] << endl;",
"	func();",
"	//comment 2",
"	return 0;",
"}",
	};
	for(int i = 0; i <= 8; i++)
		cout << l[i] << endl;
	for(int i = 0; i <= 19; i++)
		cout << q + l[i] + q + ',' << endl;
	for(int i = 9; i <= 19; i++)
		cout << l[i] << endl;
	func();
	//comment 2
	return 0;
}
