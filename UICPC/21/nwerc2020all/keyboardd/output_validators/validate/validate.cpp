#include <bits/stdc++.h>
#include "validate.h"
using namespace std;

int main(int argc, char **argv) {
	init_io(argc,argv);

	string intended;
	string author;

	if(!getline(judge_ans, intended)) {
		judge_error("Empty answer file.\n");
	}

	if(!getline(author_out, author)) {
		wrong_answer("No output.\n");
	}

	sort(intended.begin(), intended.end());
	sort(author.begin(), author.end());

	if(intended != author) {
		wrong_answer("Wrong answer, expected \"%s\" but got \"%s\"\n", intended.c_str(), author.c_str());
	}

	string junk;
	if (author_out >> junk) {
		wrong_answer("Wrong answer: trailing output.\n");
	}

	accept();
}

