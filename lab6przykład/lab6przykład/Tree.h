#ifndef  TREE_H
#define TREE_H
#include <iostream>
#include <string>

class Tree
{
	std::string type;
	double diameter;
	int age;
public:
	Tree();
	void set_age(const int);
	std::string get_type() const;
	double get_diameter() const;
	int get_key() const;
	bool operator<(Tree &);
	bool operator>(Tree &);
	bool operator==(Tree &);
	void grow();
	friend std::ostream & operator<<(std::ostream &, Tree);
};

#endif // ! TREE_H