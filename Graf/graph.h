#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <exception>
#include <map>

#ifndef UNTITLED2_GRAPH_H
#define UNTITLED2_GRAPH_H


using namespace std;

class graph {
public:
    graph() = default;

    void findPath(const string& fromVertexName, const string& toVertexName);

    bool isDirected() const;

    bool isWeight() const;

    bool isPseudo() const;

    bool isEmpty() const;

    const vector<string>& getVertexNames() const;

    const vector<vector<int>>& getAdjacencyMatrix() const;

    friend istream& operator>>(istream& is, graph& graph);

    friend ostream& operator<<(ostream& os, const graph& graph);

private:
    vector<vector<int>> _findPaths(int from, int to);

    void _normalizeNames();

    static bool vectorContains(const vector<int>& vector, int value);

    vector<vector<int>> _tracing(vector<vector<int>> paths, int to);

    void _printPath(vector<int> path);

    int _getPathWeight(vector<int> path);

    string _getVertexNamesString() const;

    string _getEdgeString(int from, int to, bool useWeight, bool useDirected) const;

    void _checkDirected();

    void _checkWeight();

    void _checkPseudo();

    vector<vector<int>> _adjacencyMatrix = vector<vector<int>>(0, vector<int>(0));
    vector<string> _vertexNames = vector<string>(0);
    bool empty = true;
    bool directed = false;
    bool weight = false;
    bool pseudo = false;
};

#endif
