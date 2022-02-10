#include <bits/stdc++.h>
#include "validate.h"
using namespace std;

char asciitolower(char c) {
    return tolower(c);
}

int main(int argc, char **argv) {
    init_io(argc,argv);

    int n;
    judge_in >> n;

    int ar, ac;
    judge_in >> ar >> ac;

    int br, bc;
    judge_in >> br >> bc;

    set<pair<int,int> > moves;
    for (int i = 0; i < n; i++) {
        int ri, ci;
        judge_in >> ri >> ci;
        moves.insert(make_pair(ri,ci));
    }

    string judge_answer;
    judge_ans >> judge_answer;

    string author_answer;
    if (!(author_out >> author_answer)) {
        wrong_answer("Author output is empty\n");
    }

    transform(judge_answer.begin(), judge_answer.end(), judge_answer.begin(), asciitolower);
    transform(author_answer.begin(), author_answer.end(), author_answer.begin(), asciitolower);

    if (author_answer != "tie" && author_answer != "alice" && author_answer != "bob") {
        wrong_answer("Expected one of 'tie', 'alice' or 'bob' in author output\n");
    }

    if (judge_answer != author_answer) {
        wrong_answer("Author claims '%s', but judge claims '%s'\n", author_answer.c_str(), judge_answer.c_str());
    }

    if (judge_answer == "tie") {

        if (!(author_out >> ar >> ac)) {
            wrong_answer("Author output did not contain coordinates after 'tie' keyword\n");
        }
        if (ar < 1 || ar > n || ac < 1 || ac > n) {
            wrong_answer("Author coordinates out of bounds\n");
        }
        if (ar == br && ac == bc) {
            wrong_answer("Author coordinates coincide with Bob's position\n");
        }

        bool can_capture = false;
        for (auto [ri,ci] : moves) {
            pair<int,int> b2(br + ri, bc + ci);
            if (1 <= b2.first && b2.first <= n && 1 <= b2.second && b2.second <= n) {
                pair<int,int> move(ar - b2.first, ac - b2.second);
                if (moves.find(move) != moves.end() || move == make_pair(0,0)) {
                    can_capture = true;
                    break;
                }
            }
        }

        if (can_capture) {
            wrong_answer("Bob can capture coordinates in author's output\n");
        }

    } else {
        string wins;
        if (!(author_out >> wins)) {
            wrong_answer("Trailing 'wins' keyword missing from author output\n");
        }
        transform(wins.begin(), wins.end(), wins.begin(), asciitolower);
        if (wins != "wins") {
            wrong_answer("Expected 'wins' keyword from author output, got '%s'\n", wins.c_str());
        }
    }

    string trailing;
    if (author_out >> trailing) {
        wrong_answer("Got unexpected trailing output from author: '%s'\n", trailing.c_str());
    }

    accept();
}

