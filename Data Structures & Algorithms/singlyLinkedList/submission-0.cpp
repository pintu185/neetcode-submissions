
struct Node
{
    int data;
    struct Node * next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node *head;
public:
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {

        Node * temp = head;
        int pos = 0;
        while(temp)
        {    
            if(pos == index)
            {   
                return temp->data;
            }
            temp = temp->next;
            pos++;
        }
    return -1;
    }

    void insertHead(int val) {
        struct Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void insertTail(int val) {
        struct Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        
        struct Node *temp = head;
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    bool remove(int index) {
        struct Node *temp = head;
        int pos = 0;
        if(temp == nullptr)
            return false;

        if(index == pos)
        {
            head = head->next;
            delete temp;
            return true;
        }
        while (temp && pos < index - 1)
        {
            temp= temp->next;
            pos++;
        }       
         if(temp == nullptr || temp->next == nullptr)
            return false;

        Node* del = temp->next;
        temp->next = del->next;

        delete del;

        return true;
    }

    vector<int> getValues() {
        vector<int> result;

        Node* temp = head;

        while(temp)
        {
            result.push_back(temp->data);
            temp = temp->next;
        }

        return result;
    }
};
