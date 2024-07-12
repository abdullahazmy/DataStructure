bool search_key(TrieNode *root, string &s)
{
    TrieNode *currentNode = root;
    for (auto c : s)
    {
        if (currentNode->childNode[c - 'a'] == nullptr)
            return false;
        currentNode = currentNode->childNode[c - 'a'];
    }
    return true;
}
