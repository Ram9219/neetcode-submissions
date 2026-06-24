class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(begin(wordList), end(wordList));
        queue<pair<string, int>> q;
        if (!st.count(endWord)) {
            return 0;
        }
        q.push({beginWord, 1});  //{word,steps}

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
            if (word == endWord) return steps;
            for (int i = 0; i < word.size(); i++) {
                char org = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};
