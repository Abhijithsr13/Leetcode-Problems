class Node {
public:
    string val;
    Node* prev;
    Node* next;
    Node(string val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) { current = new Node(homepage); }

    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps) {
        while (steps > 0) {
            if (current->prev != NULL)
                current = current->prev;
            else
                break;
            steps--;
        }
        return current->val;
    }

    string forward(int steps) {
        while (steps > 0) {
            if (current->next != NULL)
                current = current->next;
            else
                break;
            steps--;
        }
        return current->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */