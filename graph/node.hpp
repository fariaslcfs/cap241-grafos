#ifndef __NODE_HPP__
#define __NODE_HPP__

class Node 
{
    public:
    Node(int id, float weight, Node *next);
    ~Node();
    
    int getId() { return this->id; };
    float getWeight() { return this->weight; };
    Node *getNext() { return this->next; };
    void setNext(Node *next) { this->next = next; };

    private:
    int id;
    float weight;
    Node *next;
};

Node::Node(int id, float weight, Node *next) {
    this->id = id;
    this->weight = weight;
    this->next = next;
}

Node::~Node() {
    if (this->next) {
        delete this->next;
    }
}

#endif //__NODE_HPP__