#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(void)
{
	int i = 5;
	if(i<0)return(2);
	if (i==5)i++;
	string cmd = "clang++ Sully_X.cpp -o Sully_X ; ./Sully_X";
	string name = "Sully_X.cpp";
	string str = "#include <iostream>&#include <fstream>&#include <algorithm>&#include <cstdlib>&using namespace std;&int main(void)&{&	int i = @;&	if(i<0)return(2);&	if (i==5)i++;&	string cmd = ?clang++ Sully_X.cpp -o Sully_X ; ./Sully_X?;&	string name = ?Sully_X.cpp?;&	string str = ?_?;&	char x = 88;&	char n = '0' + i;&	if (i==6)n--;&	char a = 64;&	char l = 10;&	char r = 38;&	char p = 63;&	char q = 34;&	string s = string(str);&	std::replace(cmd.begin(), cmd.end(), x, n);&	std::replace(name.begin(), name.end(), x, n);&	n--;&	string minus = ?-1?;&	int ind = 268;&	if(n>=48) std::replace(str.begin(), str.end(), a, n);&	else{ str.replace(126, 1, minus, 0);ind++;}&	std::replace(str.begin(), str.end(), r, l);&	std::replace(str.begin(), str.end(), p, q);&	str.replace(ind, 1, s, 0);&	ofstream file;&	file.open(name);&	file << str;&	file.close();&	system(cmd.c_str());&	return (0);&}&";
	char x = 88;
	char n = '0' + i;
	if (i==6)n--;
	char a = 64;
	char l = 10;
	char r = 38;
	char p = 63;
	char q = 34;
	string s = string(str);
	std::replace(cmd.begin(), cmd.end(), x, n);
	std::replace(name.begin(), name.end(), x, n);
	n--;
	string minus = "-1";
	int ind = 268;
	if(n>=48) std::replace(str.begin(), str.end(), a, n);
	else{ str.replace(126, 1, minus, 0);ind++;}
	std::replace(str.begin(), str.end(), r, l);
	std::replace(str.begin(), str.end(), p, q);
	str.replace(ind, 1, s, 0);
	ofstream file;
	file.open(name);
	file << str;
	file.close();
	system(cmd.c_str());
	return (0);
}
