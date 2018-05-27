#include "Tree.h"
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct unique_gen {
	int n = 1;
	unique_gen() { n = 1; }
	Tree operator()() {
		Tree tree;
		tree.set_age(n++);
		return tree;
	}
};

void grow_tree(Tree & tree) {
	tree.grow();
}

int main() {
	srand(time(NULL));
	Tree tree;
	cout << tree <<endl;
	vector<Tree> v;
	map<int, Tree> m;
	for (int i = 0; i < 10; i++) {
		Tree tree;
		v.push_back(tree);
		m[tree.get_key()] = tree;
	}
	cout << "Vector<Tree>: " << endl;
	auto it = v.begin();		//std::vector<Tree>::iterator it = v.begin();
	for (; it < v.end(); it++) {
		cout << *it << endl;
	}
	auto mit = m.begin();
	for (; mit != m.end(); mit++) {
		cout << mit->first <<" "<<mit->second<< endl;
	}
	v.clear();
	vector<Tree> trees (25);
	cout << endl << endl << "Generated: " << endl;
	generate(trees.begin(), trees.end(), unique_gen());
	it = trees.begin();
	for (; it < trees.end(); it++) {
		cout << *it << endl;
	}
	auto min = min_element(trees.begin(), trees.end());
	cout << "Min: " << *min;
	cout << endl<< "Give tree type to find them: ";
	string t;
	getline(cin, t);
	int counter = count_if(trees.begin(), trees.end(), [t](Tree tree) -> bool {return t == tree.get_type(); });
	cout << "Number of " << t << " trees: " << counter <<endl;
	auto after_rem = remove_if(trees.begin(), trees.end(), [](Tree tree) -> bool {return tree.get_diameter() > 1; });
	trees.erase(after_rem, trees.end());
	cout << "After erase and remove_if" << endl;
	it = trees.begin();
	for (; it < trees.end(); it++) {
		cout << *it << endl;
	}
	for_each(trees.begin(), trees.end(), grow_tree);
	cout << "After grow" << endl;
	it = trees.begin();
	for (; it < trees.end(); it++) {
		cout << *it << endl;
	}
	cin.get();
}
