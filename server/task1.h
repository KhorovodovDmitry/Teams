#ifndef TASK1_H
#define TASK1_H

#include <QObject>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;
bool graf(const vector<vector<int>>& graph, const vector<int>& path);
vector<vector<int>> buildGraph(const string& input, const int& n);
vector<int> parsePath(const string& pathInput);
bool gg(QString var, QString answer, int n);

#endif // TASK1_H
