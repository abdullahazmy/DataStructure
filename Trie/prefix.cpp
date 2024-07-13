string prefix(TrieNode *root, const string &s)
{
    TrieNode *current_node = root;
    int idx = 0;
    for (auto i : s)
    {
        if (current_node->childNode[i - 'a'] == nullptr)
            return s;
        current_node = current_node->childNode[i - 'a'];
        if (current_node->wordEnd)
            return s.substr(0, idx + 1);
        idx++;
    }
    return s;
}
