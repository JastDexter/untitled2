#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <exception>
#include <map>
#include "Graf/graph.h"

using namespace std;


int main(int argc, char* argv[]) {
    auto g = graph();
    //    cout << "input vertex names and adjacency matrix:" << endl;
    //    while (g.isEmpty()) {
    //        try { cin >> g; }
    //        catch (exception &ex) {
    //            cout << ex.what() << ". Please try again." << endl;
    //        }
    //    }

    string filename = argc > 1 ? argv[1] : "data.txt";
    ifstream fin(filename);
    fin >> g;
    cout << g;

    string user_input;
    if (fin.is_open())
    while ((cout << "Go find path? Please say yes(y)!: " && cin >> user_input)
        && (user_input == "yes" || user_input == "y")) {
        try {
            string from;
            string to;
            cout << "from: ";
            cin >> from;
            cout << "to: ";
            cin >> to;
            cout << endl << "find minimal path..." << endl;
            g.findPath(from, to);
        }
        catch (exception& ex) {
            cout << ex.what() << ".Please try again." << endl;
        }
    }

    return 0;
}
