#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
	Node(void) : i(n++) { }
	Node(int a) : i(a) { }
	std::vector<Node *> other;
	static int n;
	int i;
};

int Node::n = 0;

std::vector<Node> vertices;
std::vector<Node *> loops;
int max_degree_index = 0;

std::vector<Node>
isolated_nodes(void)
{
	std::vector<Node> ret;
	for (const auto &n : vertices) {
		if (n.other.size() == 0) {
			ret.push_back(Node(n.i));
		}
	}
	return ret;
}

bool
graph_complete(void)
{
	/* ugly */
	for (const auto &n : vertices) {
		std::vector<int> is;
		for (const auto n2 : n.other)
			is.push_back(n2->i);
		/* remove loops */
		auto last = std::remove_if(is.begin(), is.end(), [n](int i) { return i == n.i; });
		/* remove duplicates */
		last = std::unique(is.begin(), last);
		/* check to see if number of arcs is one less than the number of vertices */
		if (last - is.begin() != vertices.size() - 1)
			return 0;
	}
	return 1;
}

int
main(void)
{
	char c;
	int i, nloops = 0;
	auto beg = vertices.begin(), end = beg;
	while (1) {

		std::cout << "Vertex with the highest degree: " << (vertices.empty() ? -1 : max_degree_index) << std::endl;
		std::cout << "Isolated vertices: ";
		auto isolated = isolated_nodes();
		for (const auto &v : isolated) {
			std::cout << v.i << ' ';
		}
		std::cout << std::endl;
		std::cout << "Loops: {" << nloops << "} ";
		for (const auto &p : loops)
			std::cout << p->i << ' ';
		std::cout << std::endl;
		std::cout << "Connected: " << (vertices.empty() ? "No" : isolated.empty() ? "Yes" : "No") << std::endl;
		std::cout << "Complete: " << (vertices.empty() ? "No" : graph_complete() ? "Yes" : "No") << std::endl;
		std::cout << std::endl;
		std::cout << "A) Add a vertice:" << std::endl;
		std::cout << "B) Add an arc: " << std::endl;
		std::cout << "Response: ";
		std::cin >> c;
		switch (toupper(c)) {
		case 'A':
			vertices.push_back(Node());
			std::cout << "Added node " << Node::n - 1 << std::endl;
			break;
		case 'B':
			if (vertices.empty())
				break;
			std::cout << "From point? " << std::endl;
			std::cin >> i;
			if (i < vertices.size())
				beg = vertices.begin() + i;
			else
				break;
			std::cout << "To point?" << std::endl;
			std::cin >> i;
			if (i < vertices.size())
				end = vertices.begin() + i;
			else
				break;
			beg->other.push_back(&*end);
			end->other.push_back(&*beg);
			if (beg == end) {
				++nloops;
				loops.push_back(&*beg);
			}
			if (beg->other.size() >(vertices.begin() + max_degree_index)->other.size())
				max_degree_index = beg->i;
			if (end->other.size() > (vertices.begin() + max_degree_index)->other.size())
				max_degree_index = end->i;


			break;
		}
	}

	return 0;
}