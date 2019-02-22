#include <iostream>
#include <string.h>
using namespace std;

class ShareVariables {
public:
	ShareVariables();
	~ShareVariables();

	void overloadMe(const char *a) {
		cout << a << endl;
		count++;
		return;
	}
	void overloadMe(const char *a, int b) {
		if (b > 0) {
			cout << a << endl;
			cout << count;
		}
		count++;
		return;
	}

private:
	int count;

};

ShareVariables::ShareVariables() {
	count = 0;
}

ShareVariables::~ShareVariables() {
}

int main(int argc, char **argv) {

	ShareVariables c;

	int count;
	char passMe[] = "Hello!";
	c.overloadMe(passMe);
	c.overloadMe(passMe);
	c.overloadMe(passMe);
	c.overloadMe(passMe);
	c.overloadMe(passMe);
	c.overloadMe(passMe, 2);

	cin.get(), cin.get();
}

