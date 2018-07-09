#include <map>
#include <vector>
using namespace std;
#pragma once
extern "C" __declspec(dllexport) int countChar(const string &fileName);
extern "C" __declspec(dllexport) int countWord(const string &fileName);
extern "C" __declspec(dllexport) void countWordFrequency(const string &fileName, vector<pair<string, int>> &wordCounterVec, int top = 10);
extern "C" __declspec(dllexport) int lineCount(const string &fileName);
