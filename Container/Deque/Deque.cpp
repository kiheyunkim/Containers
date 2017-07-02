

void Deque::Assign(const Iterator& first, const Iterator& last)


void Deque::PushBack(Deque::ValueType val)


void Deque::PushFront(Deque::ValueType val)


void Deque::PopBack()
{
	if (Empty()) return;

	Node* cur = _rear->_GetPrevNode();
	cur->_GetNextNode()->_SetPrevNode(cur->_GetPrevNode());
	cur->_GetPrevNode()->_SetNextNode(cur->_GetNextNode());
	cur->_SetPrevNode(nullptr);
	cur->_SetNextNode(nullptr);
	
	delete cur;
}

void Deque::PopFront()


Deque::Iterator Deque::Insert(Deque::ConstIterator& position, Deque::ValueType val)


Deque::Iterator Deque::Erase(Deque::ConstIterator& position)


void Deque::Swap(Deque& deque)


void Deque::Clear()


Deque::Iterator Deque::Emplace(Deque::ConstIterator& position, Deque::ValueType val)


Deque::Iterator Deque::EmplaceBack(Deque::ValueType val)


Deque::Iterator Deque::EmplaceFront(Deque::ValueType val)


