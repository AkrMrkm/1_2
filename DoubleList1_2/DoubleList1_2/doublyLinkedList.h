#pragma once
//==========================
//�o�������X�g�Ď���
//==========================
//2023/10/06/17:00
//�쐬��:����P

// ���уf�[�^
struct RecordData
{
	int m_score; // �X�R�A
	std::string m_name; // ���O
};

//�o�������X�g
class DoublyLinkedList
{
private:
	// �m�[�h
	struct Node
	{
		Node* m_prev; // �O�m�[�h
		Node* m_next; // ���m�[�h
		RecordData m_data; //���уf�[�^

		Node(RecordData data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

public:

	//�R���X�g�C�e���[�^�N���X
	class ConstIterator 
	{
	public:
		Node* m_Node; //�m�[�h�ւ̃|�C���^
	public:

		ConstIterator(Node* node) : m_Node(node) {}

		//�C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�
		ConstIterator& operator--()
		{
			m_Node = m_Node->m_prev;
			return *this;
		}

		ConstIterator operator--(int) // ��u
		{
			ConstIterator ci = *this;
			m_Node = m_Node->m_prev;
			return ci;
		}

		//�C�e���[�^�̖����Ɍ������ĂЂƂi�߂�
		ConstIterator& operator++()
		{
			m_Node = m_Node->m_next;
			return *this;
		}

		ConstIterator operator++(int) // ��u
		{
			ConstIterator ci = *this;
			m_Node = m_Node->m_next;
			return ci;
		}

		//�C�e���[�^�̎w���v�f���擾����(const)
		const RecordData& operator*() const { return this->m_Node->m_data; }

		//�R�s�[�R���X�g���N�^
		ConstIterator(const ConstIterator& ci) : m_Node(ci.m_Node){}

		//������s��
		ConstIterator& operator=(const ConstIterator& ci)
		{
			m_Node = ci.m_Node;
			return *this;
		}

		//���ꂩ��r����
		bool operator==(const ConstIterator& ci)
		{
			return (m_Node == ci.m_Node);
		}

		//�قȂ邩��r����
		bool operator!=(const ConstIterator& ci)
		{
			return (m_Node == ci.m_Node);
		}
	};

	//�C�e���[�^�N���X
	class Iterator : public ConstIterator
	{
	public:
		// �R���X�g���N�^
		Iterator(Node* n) : ConstIterator(n) {}

		// �C�e���[�^�̎w���v�f���擾����(��const)
		const RecordData& operator*() { return this->m_Node->m_data; }
	};

	//�o�������X�g�̃R���X�g���N�^
	DoublyLinkedList() : m_DummyNode(nullptr), m_DataNum(0) {}

	//�f�X�g���N�^
	virtual ~DoublyLinkedList() // �擪���疖���܂�delete
	{
		while (m_DummyNode != nullptr)
		{
			Node* temp = m_DummyNode;
			m_DummyNode = m_DummyNode->m_next;
			delete temp;
		}
	}

	//�f�[�^���̎擾
	int GetDataNum() const { return m_DataNum; }
	
	// �f�[�^�̑}��(�C�e���[�^�̎w���m�[�h�̑O�ɑ}��)
	bool Insert(ConstIterator& it, RecordData& data)
	{
		Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h

		if (itNode == nullptr) // �C�e���[�^��null��������v�b�V���o�b�N
		{
			PushBack(data);
			return true;
		}

		Node* newNode = new Node(data); // �V�m�[�h
		newNode->m_prev = itNode->m_prev; // �V�m�[�h�̑O�m�[�h���C�e���[�^�̎w���O�m�[�h�ɁB
		newNode->m_next = itNode; // �V�m�[�h�̎��m�[�h���C�e���[�^�̎w���m�[�h�ɁB

		 // �C�e���[�^�̎w���m�[�h���擪�ł͂Ȃ�������
		if (itNode->m_prev != nullptr)
		{
			// �C�e���[�^�̎w���m�[�h�̑O�m�[�h�̎��̃m�[�h�ɐV�m�[�h���i�[
			// (�C�e���[�^�m�[�h�ƑO�m�[�h�̊ԂɊi�[)
			itNode->m_prev->m_next = newNode;
		}

		// �C�e���[�^�̎w���m�[�h�̑O�m�[�h�ɐV�m�[�h���i�[�A����Ńf�[�^���q����
		itNode->m_prev = newNode;

		// �f�[�^���𑝂₷
		m_DataNum++;

		return true;
	}

	// �f�[�^�̒ǉ�
	bool PushBack(RecordData& data)
	{
		Node* newNode = new Node(data);

		// ���X�g������ۂ�������_�~�[�m�[�h�ɐV�����m�[�h������
		if (m_DataNum == 0)
		{
			m_DummyNode = newNode;
			m_DataNum++;

			return true;
		}

		// ���X�g�̖����ɐV�����m�[�h������
		DoublyLinkedList::Iterator it = GetEnd();
		Node* tail = it.m_Node;

		tail->m_next = newNode;
		newNode->m_prev = tail;
		tail = newNode;

		m_DataNum++;
		return true;
	}

	// �f�[�^�̍폜
	bool Remove(ConstIterator& it)
	{
		if (it == nullptr) return false;

		Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h

		// �����m�[�h��������return
		if (itNode->m_prev != nullptr && itNode->m_next == nullptr) return false;

		//�f�[�^���ЂƂ����Ȃ������炻�̃f�[�^���폜
		if (itNode->m_prev == nullptr && itNode->m_next == nullptr)
		{
			m_DummyNode = nullptr;
			delete itNode;
			m_DataNum--;
			return true;
		}

		// �擪�C�e���[�^�ł͂Ȃ�������O�m�[�h�Ǝ��m�[�h������
		if (itNode->m_prev != nullptr)
		{
			itNode->m_prev->m_next = itNode->m_next;
		}
		else // �擪�C�e���[�^�ł�������擪�C�e���[�^�����m�[�h�ɕύX
		{
			m_DummyNode = itNode->m_next;
		}

		// �����C�e���[�^�ł͂Ȃ�������
		if (itNode->m_next != nullptr)
		{
			itNode->m_next->m_prev = itNode->m_prev;
		}
		else
		{
			DoublyLinkedList::Iterator it = GetEnd();
			Node* tail = it.m_Node;

			tail = itNode->m_prev;
		}

		delete itNode;
		m_DataNum--;
		return true;
	}

	// �擪�C�e���[�^�擾
	Iterator GetBegin() 
	{
		Node* begin = m_DummyNode;
		if (begin == nullptr) return Iterator(nullptr);
		while (begin->m_prev != nullptr)
		{
			begin = begin->m_prev;
		}
		return Iterator(begin);
	}

	// �擪�R���X�g�C�e���[�^�擾
	ConstIterator GetCBegin() const
	{
		Node* begin = m_DummyNode;
		if (begin == nullptr) return Iterator(nullptr);
		while (begin->m_prev != nullptr)
		{
			begin = begin->m_prev;
		}
		return Iterator(begin);
	}

	// �����C�e���[�^�擾
	Iterator GetEnd() 
	{
		Node* end = m_DummyNode;
		if (end == nullptr) return Iterator(nullptr);
		while (end->m_next != nullptr)
		{
			end = end->m_next;
		}
		return Iterator(end);
	}

	// �����R���X�g�C�e���[�^�擾
	ConstIterator GetCEnd() const
	{
		Node* end = m_DummyNode;
		if (end == nullptr) return ConstIterator(nullptr);
		while (end->m_next != nullptr)
		{
			end = end->m_next;
		}
		return ConstIterator(end);
	}

	// �S�f�[�^���i�[���ɕ`��
	bool Draw()
	{
		if (m_DataNum == 0)
		{
			std::cout << "���̃��X�g�Ƀf�[�^�͂���܂���B" << std::endl;
			return false;
		}

		Node* current = m_DummyNode; // �C�e���[�^�̎w���m�[�h
		while (current != nullptr)
		{
			std::cout << " score : " << current->m_data.m_score << "   name : " << current->m_data.m_name << std::endl;
			current = current->m_next;
		}
		return true;
	}

private:

	Node* m_DummyNode; // �_�~�[�m�[�h
	int m_DataNum{}; // �f�[�^��
};