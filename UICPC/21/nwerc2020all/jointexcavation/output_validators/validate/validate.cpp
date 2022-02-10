#include <bits/stdc++.h>
#include "validate.h"

using namespace std;

long long safe_parse(const string& to_parse) {
  try {
    size_t idx;
    long long a = stoll(to_parse, &idx, 10);
    if(idx != to_parse.size())
      wrong_answer("Wrong answer: String contains non-digit characters (%s).\n", to_parse.data());
    return a;
  } catch(const invalid_argument& ia) {
    wrong_answer("Wrong answer: String contains non-digit characters (%s).\n", to_parse.data());
  } catch(const out_of_range& oor) {
    wrong_answer("Wrong answer: Integer is out of range (%s).\n", to_parse.data());
  }
  judge_error("Judge error: Something went wrong when parsing %s.\n", to_parse.data());
}

/**
 * Colors: 
 * 0 - none
 * 1 - path
 * 2 - Subnetwork A
 * 3 - Subnetwork B
 */
void fill_DFS(const vector<set<long long>> &graph, vector<char> &node_color, long long index, char color) {
	char my_col = node_color[index];
	if(my_col == color || my_col == 1) return;
	if(my_col)
		wrong_answer("Wrong answer: Subnetworks are not split by path (chamber %lld is in both subnetworks).\n", index);

	node_color[index] = color;
	for(long long next : graph[index]) {
		fill_DFS(graph, node_color, next, color);
	}
}

void check_solution(const vector<set<long long>> &graph, const vector<long long> &path, const unordered_set<long long> &sub_a, const unordered_set<long long> &sub_b) {
	vector<char> node_color(graph.size(), 0);
	// Check path
	if(!path.empty()) {
		long long cur_node = path[0];
		node_color[cur_node] = 1;
		for(auto it = path.begin() + 1; it != path.end(); ++it) {
			if(graph[cur_node].count(*it) == 0)
				wrong_answer("Wrong answer: Path described is invalid; no tunnel between chamber %lld and %lld.\n", cur_node, *it);
			cur_node = *it;
			node_color[cur_node] = 1;
		}
	}

	// Check disjunct
	for(long long node : sub_a) {
		fill_DFS(graph, node_color, node, 2);
	}	
	for(long long node : sub_b) {
		fill_DFS(graph, node_color, node, 3);
	}
}


int main(int argc, char **argv) {
	init_io(argc,argv);
	vector<set<long long>> graph;
	long long chambers, tunnels;
	judge_in >> chambers >> tunnels;
	graph.resize(chambers + 1);
	while(tunnels--) {
		long long a,b;
		judge_in >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	vector<long long> path;
	unordered_set<long long> sub_a;
	unordered_set<long long> sub_b;
	unordered_set<long long> all_chambers;

	string inp;
	long long p_inp;
	long long path_size, sub_size;

	// Read number of chambers in path and subnetworks
	if(!(author_out >> inp))
		wrong_answer("Wrong answer: Missing number of chambers in path.");
	p_inp = safe_parse(inp);
	if(p_inp < 1  || chambers < p_inp)
		wrong_answer("Wrong answer: Number of chambers for path is out of range (%lld)", p_inp);
	path_size = p_inp;
	if(!(author_out >> inp))
		wrong_answer("Wrong answer: Missing number of chambers in subnetworks.");
	p_inp = safe_parse(inp);
	if(p_inp < 0  || chambers < p_inp)
		wrong_answer("Wrong answer: Number of chambers for subnetwork is out of range (%lld)", p_inp);
	sub_size = p_inp;


	// Check if all chambers can be expected to be mentioned once
	if(2*sub_size + path_size != chambers)
		wrong_answer("Wrong answer: Number of described chambers is not equal to number of chambers in network (%lld described, %lld in network).\n", 2*sub_size + path_size, chambers);


	// Read chambers in path
	path.resize(path_size);
	for(size_t i = 0; i < path_size; ++i) {
		if(!(author_out >> inp))
			wrong_answer("Wrong answer: Unexpected end of output; still expecting chambers for path.\n");
		p_inp = safe_parse(inp);
		if(p_inp < 1  || chambers < p_inp)
			wrong_answer("Wrong answer: chamber ID for path is out of range (%lld).\n", p_inp);
		all_chambers.insert(p_inp);
		path[i] = p_inp;
	}

	// Check if no chamber appears twice in path (path must not intersect itself)
	if(all_chambers.size() != path_size)
		wrong_answer("Wrong answer: Path contains at least one chamber more than once.\n");


	// Read chambers for 1st subnetwork
	for(size_t i = 0; i < sub_size; ++i) {
		if(!(author_out >> inp))
			wrong_answer("Wrong answer: Unexpected end of output; still expecting chambers for 1st subnetwork.\n");
		p_inp = safe_parse(inp);
		if(p_inp < 1  || chambers < p_inp)
			wrong_answer("Wrong answer: chamber ID for 1st subnetwork is out of range (%lld).\n", p_inp);
		all_chambers.insert(p_inp);
		sub_a.insert(p_inp);
	}

	// Read chambers for 2nd subnetwork
	for(size_t i = 0; i < sub_size; ++i) {
		if(!(author_out >> inp))
			wrong_answer("Wrong answer: Unexpected end of output; still expecting chambers for 2nd subnetwork.\n");
		p_inp = safe_parse(inp);
		if(p_inp < 1  || chambers < p_inp)
			wrong_answer("Wrong answer: chamber ID for 2nd subnetwork is out of range (%lld).\n", p_inp);
		all_chambers.insert(p_inp);
		sub_b.insert(p_inp);
	}

	// Check if all IDs are unique
	if(all_chambers.size() != chambers)
		wrong_answer("Wrong answer: Duplicate chamber ID in input (%lld unique IDs found).\n", all_chambers.size());


	// Check solution
	check_solution(graph, path, sub_a, sub_b);

	// Extra ouput?
	char foo;
	if((author_out >> foo))
		wrong_answer("Wrong answer: More output than expected.\n");
	
	accept();
}

