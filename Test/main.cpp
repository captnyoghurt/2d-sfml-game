#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Forme {
public:
	Forme() {};
	virtual void what() { cout << "Je suis une forme" << endl; };
};

class Triangle : public Forme {
public:
	virtual void what() { cout << "Je suis un triangle" << endl; };
};

class Carre : public Forme {
public:
	virtual void what() { cout << "Je suis un carre" << endl; };
};

int main(int argc, char **argv)
{
	vector<std::reference_wrapper<Forme>> vec;
	Forme f;
	Triangle t;
	Carre c;
	f.what();
	t.what();
	c.what();

	vec.push_back(f);
	vec.push_back(t);
	vec.push_back(c);
	vec.push_back(Carre());

	for (int i(0); i < vec.size(); ++i)	vec.at(i).get().what();

	getchar();

	return 0;
}