#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }

    Node(int f, Node *l, Node *r)
    {
        ch = '\0';
        freq = f;
        left = l;
        right = r;
    }
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void generateCodes(Node *root, string code, map<char, string> &codes)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        codes[root->ch] = code.empty() ? "0" : code;
        return;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

int main()
{
    cout << "Name           : Harsh Jatoliya\n";
    cout << "Enrollment No. : 13114803124\n";

    string text;
    cout << "Enter the string: ";
    getline(cin, text);

    if (text.empty())
    {
        cout << "String cannot be empty.";
        return 0;
    }

    // Frequency calculation
    map<char, int> freq;
    for (char c : text)
        freq[c]++;

    // Create Min Heap
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (auto x : freq)
        pq.push(new Node(x.first, x.second));

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node *a = pq.top();
        pq.pop();

        Node *b = pq.top();
        pq.pop();

        pq.push(new Node(a->freq + b->freq, a, b));
    }

    // Generate Codes
    map<char, string> codes;
    generateCodes(pq.top(), "", codes);

 cout << "\nCharacter Frequencies:\n";

for (auto x : freq)
{
    if (x.first == ' ')
        cout << "' '";
    else
        cout << x.first;

    cout << " : " << x.second << endl;
}

cout << "\nHuffman Codes:\n";

for (auto x : codes)
{
    if (x.first == ' ')
        cout << "' '";
    else
        cout << x.first;

    cout << " : " << x.second << endl;
}

    // Encoding
    string encoded;
    for (char c : text)
        encoded += codes[c];

    cout << "\nEncoded String: " << encoded << endl;

    int n = text.length();
    int k = freq.size();

    cout << "\nCOMPLEXITY ANALYSIS:\n";
    cout << "Input Size (n)          : " << n << endl;
    cout << "Distinct Characters(k)  : " << k << endl;

    cout << "\nTime Complexity:\n";
    cout << "1. Frequency Calculation    : O(n)\n";
    cout << "2. Building Initial Heap    : O(k)\n";
    cout << "3. Building Huffman Tree    : O(k log k)\n";
    cout << "4. Generating Huffman Codes : O(k)\n";
    cout << "5. Encoding String          : O(n)\n";

    cout << "\nBest Case              : O(n + k log k)\n";
    cout << "Worst Case             : O(n + k log k)\n";
    cout << "Overall Time Complexity: O(n + k log k)\n";
    cout << "Worst Case (k <= n)    : O(n log n)\n";
    cout << "Space Complexity       : O(n + k)\n\n";

    return 0;
}