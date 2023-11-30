#include <iostream>
#include <vector>
#include <queue>

class HuffmanNode {
public:
    char character;
    int frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char character, int frequency) {
        this->character = character;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

struct CompareNode {
    bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2) {
        return n1->frequency > n2->frequency;
    }
};

void printHuffmanCode(HuffmanNode* root, std::string code) {
    if (root == nullptr) return;

    if (root->character != '#') {
        std::cout << root->character << " : " << code << std::endl;
    }

    printHuffmanCode(root->left, code + "0");
    printHuffmanCode(root->right, code + "1");
}

void buildHuffmanTree(const std::vector<char>& characters, const std::vector<int>& frequencies) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNode> minHeap;

    for (size_t i = 0; i < characters.size(); ++i) {
        minHeap.push(new HuffmanNode(characters[i], frequencies[i]));
    }

    while (minHeap.size() > 1) {
        HuffmanNode *left = minHeap.top(); minHeap.pop();
        HuffmanNode *right = minHeap.top(); minHeap.pop();

        HuffmanNode *node = new HuffmanNode('#', left->frequency + right->frequency);
        node->left = left;
        node->right = right;
        minHeap.push(node);
    }

    printHuffmanCode(minHeap.top(), "");
}

int main() {
    std::vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<int> frequencies = {5, 9, 12, 13, 16, 45};

    buildHuffmanTree(characters, frequencies);

    return 0;
}
