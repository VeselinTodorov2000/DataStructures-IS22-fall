#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T> *left, *right;
};

template<typename T>
void insertElement(Node<T> *&root, T data, std::string path) {
    if (root == nullptr) {
        if (path.empty()) {
            root = new Node<T>{data, nullptr, nullptr};
        }
        return;
    }

    if (path[0] == 'L') {
        insertElement(root->left, data, path.substr(1));
    } else {
        insertElement(root->right, data, path.substr(1));
    }
}

template<typename T>
void findElement(Node<T> *&root, std::string path) {
    if (root == nullptr) {
        return;
    }

    if (path == "") {
        std::cout << root->data;
        return;
    }

    if (path[0] == 'L') {
        findElement(root->left, path.substr(1));
    } else {
        findElement(root->right, path.substr(1));
    }
}

template<typename T>
const T findMaxElement(Node<T> *root) {
    if (root == nullptr) {
        return INT_MIN;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    T leftMax = findMaxElement(root->left);
    T rightMax = findMaxElement(root->right);
    T maxLeftRight = leftMax >= rightMax ? leftMax : rightMax;
    return maxLeftRight >= root->data ? maxLeftRight : root->data;
}


template<typename T>
const T findMinElement(Node<T> *root) {
    if (root == nullptr) {
        return INT_MAX;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    T leftMin = findMinElement(root->left);
    T rightMin = findMinElement(root->right);
    T minLeftRight = leftMin <= rightMin ? leftMin : rightMin;
    return minLeftRight <= root->data ? minLeftRight : root->data;
}

template<typename T>
const size_t findNumberOfLevels(Node<T> *root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    int leftNumberOfLevels = findNumberOfLevels(root->left);
    int rightNumberOfLevels = findNumberOfLevels(root->right);
    return 1 + (leftNumberOfLevels >= rightNumberOfLevels ? leftNumberOfLevels : rightNumberOfLevels);
}

template<typename T>
const T sumOfTheElements(Node<T> *root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    return root->data + sumOfTheElements(root->left) + sumOfTheElements(root->right);
}

template<typename T>
const T numberOfTheElements(Node<T> *root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return 1 + numberOfTheElements(root->left) + numberOfTheElements(root->right);
}

template<typename T>
const size_t numberOfTheLeaves(Node<T> *root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return numberOfTheLeaves(root->left) + numberOfTheLeaves(root->right);
}

int main() {
    Node<int> *root = new Node<int>{17,
                                    new Node<int>{13,
                                                  new Node<int>{9,
                                                                nullptr,
                                                                nullptr},
                                                  new Node<int>{16, nullptr, nullptr}},
                                    new Node<int>{24, nullptr,
                                                  new Node<int>{63, nullptr, nullptr}}};
    std::cout << numberOfTheLeaves(root) << std::endl;
    return 0;
}
