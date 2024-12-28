#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class WordLadder {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (wordSet.find(endWord) == wordSet.end()) {
            return result; // End word not in wordList
        }

        unordered_map<string, vector<string>> neighbors;
        unordered_map<string, int> distances;
        bfs(beginWord, endWord, wordSet, neighbors, distances);

        vector<string> path;
        dfs(beginWord, endWord, neighbors, distances, path, result);

        return result;
    }

private:
    void bfs(const string& beginWord, const string& endWord, unordered_set<string>& wordSet, unordered_map<string, vector<string>>& neighbors, unordered_map<string, int>& distances) {
        for (const string& word : wordSet) {
            neighbors[word] = {};
        }
        neighbors[beginWord] = {};

        queue<string> q;
        q.push(beginWord);
        distances[beginWord] = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                string currentWord = q.front();
                q.pop();
                vector<string> nextWords = getNeighbors(currentWord, wordSet);

                for (const string& nextWord : nextWords) {
                    neighbors[currentWord].push_back(nextWord);
                    if (distances.find(nextWord) == distances.end()) {
                        distances[nextWord] = distances[currentWord] + 1;
                        q.push(nextWord);
                    }
                }
            }
        }
    }

    vector<string> getNeighbors(const string& word, const unordered_set<string>& wordSet) {
        vector<string> neighbors;
        string temp = word;

        for (size_t i = 0; i < word.size(); ++i) {
            char originalChar = temp[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == originalChar) continue;
                temp[i] = c;
                if (wordSet.find(temp) != wordSet.end()) {
                    neighbors.push_back(temp);
                }
            }
            temp[i] = originalChar;
        }

        return neighbors;
    }

    void dfs(const string& currentWord, const string& endWord, unordered_map<string, vector<string>>& neighbors, unordered_map<string, int>& distances, vector<string>& path, vector<vector<string>>& result) {
        path.push_back(currentWord);

        if (currentWord == endWord) {
            result.push_back(path);
        } else {
            for (const string& nextWord : neighbors[currentWord]) {
                if (distances[nextWord] == distances[currentWord] + 1) {
                    dfs(nextWord, endWord, neighbors, distances, path, result);
                }
            }
        }

        path.pop_back(); // Backtrack
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    WordLadder solver;
    vector<vector<string>> ladders = solver.findLadders(beginWord, endWord, wordList);

    cout << "All shortest transformation sequences:" << endl;
    for (const auto& ladder : ladders) {
        cout << "[";
        for (size_t i = 0; i < ladder.size(); ++i) {
            cout << ladder[i];
            if (i < ladder.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
