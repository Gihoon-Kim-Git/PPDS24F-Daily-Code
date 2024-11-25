#include <cassert>
#include <map>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

using Elem = pair<int, char>;

string frequencySort(string s) {
  map<char, int> freq;
  for (char c : s) ++freq[c];

  priority_queue<Elem> pq;  // Maxheap by default
  for (auto it : freq) pq.push({it.second, it.first});

  ostringstream os;
  while (!pq.empty()) {
    os << string(pq.top().first, pq.top().second);
    pq.pop();
  }

  return os.str();
}

int main() {
  assert(frequencySort("tree") == "eert" || frequencySort("tree") == "eetr");
  assert(frequencySort("cccaaa") == "aaaccc" ||
         frequencySort("cccaaa") == "cccaaa");
  assert(frequencySort("Aabb") == "bbAa" || frequencySort("Aabb") == "bbaA");
}
