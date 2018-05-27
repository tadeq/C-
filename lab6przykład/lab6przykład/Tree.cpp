#include "Tree.h"

std::string tree_types[5] = { "Buk","Dab","Klon","Brzoza","Modrzew" };

Tree::Tree()
{
	type = tree_types[rand() % 5];
	diameter = ((double)(rand() % 20 + 1) / 10);
	age = rand() % 100 + 1;
}

void Tree::set_age(const int w)
{
	age = w;
}

std::string Tree::get_type() const
{
	return type;
}

double Tree::get_diameter() const
{
	return diameter;
}

int Tree::get_key() const
{
	int key = 0;
	for (int i = 0; i < type.length(); i++) {
		key += type[i];
	}
	return key + age;
}

bool Tree::operator<(Tree &d)
{
	return (this->diameter<d.diameter);
}

bool Tree::operator>(Tree &d)
{
	return (this->diameter > d.diameter);
}

bool Tree::operator==(Tree &d)
{
	return (this->get_key() == d.get_key());
}

void Tree::grow()
{
	diameter += 0.1;
}

std::ostream & operator<<(std::ostream & os, Tree d)
{
	os << "type: " << d.type << ", diameter: " << d.diameter << ", age: " << d.age;
	return os;
}
