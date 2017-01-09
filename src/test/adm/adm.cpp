#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cassert>
#include <climits>

#define MAXV 9

struct Edge_Node {
	Edge_Node(int ny, int wt) : y(ny), weight(wt) {}
	int y;
	int weight;
};

struct Graph {
	Graph(unsigned count, bool dir)
	{
		edges.resize(count);
		color.resize(count, 2);
		fin.resize(count, 0);
		color[0] = 0;
		directed = dir;
	}

	void
	add_edge(int x, int y, int wt)
	{
		edges[x].emplace_front(y, wt);
		if (!directed)
			edges[y].emplace_front(x, wt);
	}

	std::vector<int>
	out_degrees()
	{
		std::vector<int> degs(edges.size(), 0);
		for (int i = 0; i < edges.size(); ++i) {
			for (auto e : edges[i])
				++degs[i];
		}
		return degs;
	}

	std::vector<int>
	in_degrees()
	{
		std::vector<int> degs(edges.size(), 0);
		for (auto el : edges) {
			for (auto e : el)
				++degs[e.y];
		}
		return degs;
	}
	
	Graph
	transpose()
	{
		Graph t(MAXV, false);
		for (int i = 0; i < edges.size(); ++i) {
			for (auto e : edges[i])
				t.add_edge(e.y, i, e.weight);
		}
		return t;
	}

	void
	bfs(int s)
	{
		std::vector<int> colors(edges.size(), 0);
		std::vector<int> dist(edges.size(), -1);
		std::vector<int> parent(edges.size(), -1);

		colors[s] = 1;
		dist[s] = 0;
		parent[s] = -1;

		std::queue<int> q;
		q.push(s);
		printf("%d\n", s);
		while(!q.empty()) {
			int i = q.front();
			q.pop();
			for (auto e : edges[i]) {
				printf("%d\n", e.y);
				process_edge(i, e.y);
				if (colors[e.y] == 0) {
					colors[e.y] = 1;
					dist[e.y] = dist[i] + 1;
					parent[e.y] = i;
					q.push(e.y);
				}
			}
			colors[i] = 2;
		}
	}

	void
	dfs()
	{
		std::vector<int> colors(edges.size(), 0);
		std::list<int> top;
		int count = 0;
		for (int i = 0; i < edges.size(); ++i) {
			if (colors[i] == 0) {
				colors[i] = 1;
				std::stack<int> stk;
				stk.push(i);
				while(!stk.empty()) {
					++count;
					int y = stk.top();
					//printf("entering: %d\n", i);
					for (auto e : edges[y]) {
						if (colors[e.y] == 0) {
							stk.push(e.y);
							colors[e.y] = 1;
						}
					}
					colors[y] = 2;
					while (!stk.empty() && colors[stk.top()] == 2) {
						fin[stk.top()] = count++;
						top.push_front(stk.top());
						stk.pop();
					}
				}
			}
		}
	}

	void
	dfs_mod()
	{
		std::vector<int> colors(edges.size(), 0);
		std::vector<int> ord(edges.size(), 0);
		for (int i = 0; i < edges.size(); ++i) {
			ord[i] = i;
		}
		std::sort(ord.begin(), ord.end(), [this](int x, int y) {
			return (fin[x] > fin[y]);
		});
		for (int z = 0; z < ord.size(); ++z) {
			int i = ord[z];
			if (colors[i] == 0) {
				printf("scc\n");
				colors[i] = 1;
				std::stack<int> stk;
				stk.push(i);
				while(!stk.empty()) {
					int y = stk.top();
					printf("%d\n", y);
					/*std::vector<int> pot(edges.size(), 0);
					for (auto e : edges[y]) {
						if (colors[e.y] == 0) pot.push_back(e.y);
					}
					std::sort(pot.begin(), pot.end(), [&fin](const int &x, const int &y) {
						return (fin[x] < fin[y]);
					});*/
					for (auto e : edges[y]) {
						if (colors[e.y] == 0) {
							stk.push(e.y);
							colors[e.y] = 1;
						}
					}
					colors[y] = 2;
					while (!stk.empty() && colors[stk.top()] == 2) {
						stk.pop();
					}
				}
			}
		}
	}
	void
	find_sccs()
	{
		dfs();
		int ind = 0;
		auto t = transpose();
		t.dfs_mod();
	}

	void
	process_edge(int x, int y)
	{
		if (color[x] == color[y])
			printf("not bipartite\n");
		else
			color[y] = !color[x];
	}

	int
	weight(int u, int v)
	{
		for (auto e : edges[u]) {
			if (e.y == v)
				return e.weight;
		}
		return 0;
	}

	std::vector<int>
	prim_mst()
	{
		std::vector<int> keys(edges.size(), INT_MAX);
		std::vector<int> parents(edges.size(), -1);
		std::vector<int> q;
		for (auto i = 0; i < edges.size(); ++i)
			q.push_back(i);
		keys[0] = 0;
		while (!q.empty()) {
			std::make_heap(q.begin(), q.end(), [&keys](int x, int y) {
				return keys[x] > keys[y];
			});
			std::pop_heap(q.begin(), q.end(), [&keys](int x, int y) {
				return keys[x] > keys[y];
			});
			int u = q.back();
			printf("u: %d\n", u);
			q.pop_back();
			for (auto e : edges[u]) {
				if (q.find(e.y) != q.end() && e.weight < keys[e.y]) {
					parents[e.y] = u;
					keys[e.y] = e.weight;
				}
			}
		}
		return parents;
	}

	std::vector<int>
	kruskal_mst()
	{
		
	}

	std::vector<int> color;
	std::vector<int> fin;
	std::vector<std::list<Edge_Node>> edges;
	bool directed;
};

struct B_Node {
	B_Node(bool is_leaf, size_t num_nodes) : n(num_nodes), leaf(is_leaf) {}
	std::vector<int> keys;
	std::vector<B_Node> children;
	size_t n;
	bool leaf;
};

struct B_Tree {
	B_Tree(size_t min_branch) : root(true, 0), t(min_branch) {}
	B_Node root;
	size_t t;
};

struct RB_Node {
	RB_Node *l;
	RB_Node *r;
	RB_Node *p;
	int key;
	bool color;
};

#define black false
#define red true

struct RB_Tree {
	bool
	is_red(RB_Node *n)
	{
		return (n->color == red);
	}

	bool
	is_black(RB_Node *n)
	{
		return (n->color == black || !n);
	}

	size_t
	assert_bh(RB_Node *n)
	{
		if (!n)
			return 1;
		size_t lbh = 0, rbh = 0;
		lbh = assert_bh(n->l);
		rbh = assert_bh(n->r);
		assert(lbh == rbh);
		return is_black(n) ? lbh+1 : lbh;
	}

	void
	assert_rb(RB_Node *n)
	{
		if (!n)
			return;
		if (is_red(n)) {
			assert(is_black(n->l));
			assert(is_black(n->r));
		}
		assert_rb(n->l);
		assert_rb(n->r);
	}

	void
	assert_invariants()
	{
		assert(is_black(root));
		assert_rb(root);
		assert_bh(root);
	}

	void
	lrot(RB_Node *x)
	{
		RB_Node *y = x->r;
		x->r = y->l;
		if (y->l)
			y->l->p = x;
		if (!x->p)
			root = y;
		else if (x == x->p->l)
			x->p->l = y;
		else
			x->p->r = y;
		y->l = x;
		x->p = y;
	}

	void
	rrot(RB_Node *y)
	{
		RB_Node *x = y->l;
		y->l = x->r;
		if (x->r)
			x->r->p = y;
		if (!y->p)
			root = x;
		else if (y == y->p->l)
			y->p->l = x;
		else
			y->p->r = x;
		x->r = y;
		y->p = x;
	}

	void
	fixup(RB_Node *n)
	{
		if (n == root) {
			n->color = black;
			return;
		}
		while (n->p->color == red) {
			if (n->p == n->p->p->l) {
				RB_Node *uncle = n->p->p->r;
				if (uncle->color == red) {
					n->p->color = black;
					uncle->color = black;
					n->p->p->color = red;
					n = n->p->p;
				} else {
					if (n == n->p->r) {
						n = n->p;
						lrot(n);
					}
					n->p->color = black;
					n->p->p->color = red;
					rrot(n->p->p);
				}
			} else {
				RB_Node *uncle = n->p->p->l;
				if (uncle->color == red) {
					n->p->color = black;
					uncle->color = black;
					n->p->p->color = red;
					n = n->p->p;
				} else {
					if (n == n->p->l) {
						n = n->p;
						rrot(n);
					}
					n->p->color = black;
					n->p->p->color = red;
					lrot(n->p->p);
				}
			}
		}
		root->color = black;
	}

	void
	insert(int key)
	{
		RB_Node *y = NULL;
		RB_Node *x = root;
		while (x) {
			y = x;
			if (key < x->key)
				x = x->l;
			else
				x = x->r;
		}
		x = new RB_Node;
		x->p = y;
		x->key = key;
		if (!y)
			root = x;
		else if (key < y->key)
			y->l = x;
		else
			y->r = x;
		x->l = x->r = NULL;
		x->color = red;
		fixup(x);
	}

	RB_Node *root;
};

void
merge(std::vector<int> *q, int i, int k, int j)
{
	
}

void
sort(std::vector<int> *q, int i, int k, int j)
{
	if (i >= j)
		return;
	sort(q, i, (k-i)/2, k);
	sort(q, k+1, (j-k)/2, j);
	merge(q, i, k, j);
}

void
msort(std::vector<int> *q)
{
	sort(q, 0, q.size()/2 - 1, q.size()-1);
}

void
qsort(std::vector<int> q)
{

}

int
main(int argc, char *argv[])
{
	Graph g(MAXV, false);
	g.add_edge(0,1,4);
	g.add_edge(1,2,8);
	g.add_edge(2,3,7);
	g.add_edge(3,4,9);
	g.add_edge(4,5,10);
	g.add_edge(5,6,2);
	g.add_edge(6,7,1);
	g.add_edge(7,8,7);
	g.add_edge(7,0,8);
	g.add_edge(8,6,6);
	g.add_edge(8,2,2);
	g.add_edge(2,5,4);
	g.add_edge(3,5,14);
	g.add_edge(1,7,11);
	auto a = g.prim_mst();
	for (int i = 0; i < a.size(); ++i)
		printf("%d, %d\n", a[i], i);
	return 0;
}
