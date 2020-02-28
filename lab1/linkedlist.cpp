struct note {
	int id;
	char name[30];
	char category[5];
	int deposit;
	char date[9];
};

class LinkedList {

private:
	struct Node {
		struct note data;
		Node *next;
		Node *prev;
	};

	int length = 0;
	Node *head = NULL;
	Node *current = NULL;
	Node *tail = NULL;

public:
	~LinkedList() {
		while (head != NULL) {
			current = head->next;
			delete head;
			head = current;
		}
	}

	int getLength() {
		return length;
	}

	void pushNode(struct note memo) {
		Node *tmp = new Node;
		tmp->data = memo;
		tmp->next = NULL;
		tmp->prev = NULL;

		if (head == NULL) {
			head = tail = tmp;
		} else {
			tail->next = tmp;
			tmp->prev = tail;
			tail = tail->next;
		}

		length++;
	}

	struct note getHead() {
		if (head == NULL) {
			throw std::out_of_range("List is empty");
		}
		return head->data;
	}

	struct note getTail() {
		if (tail == NULL) {
			throw std::out_of_range("List is empty");
		}
		return tail->data;
	}

	struct note next() {
		if (current == NULL || current == tail) {
			current = head;
			return current->data;
		}
		current = current->next;
		return current->data;
	}

	void clearIterator() {
		current = head;
	}

	void remove(int index) {
		if (index == 0) {
			
		}
		if (index < 1 || index >= length) {
			throw std::out_of_range("Index is out of range");
		}
		Node *cur = head;
		int currentIndex = 0;

		while (currentIndex++ < index) {
			cur = cur->next;
		}
		Node *prevEl = cur->prev;
		Node *nextEl = cur->next;

		prevEl->next = nextEl;
		nextEl->prev = prevEl;

		delete cur;
	}
};