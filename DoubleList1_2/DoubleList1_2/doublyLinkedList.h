#pragma once
//==========================
//�o�������X�g�Ď���
//==========================
//2023/10/05/17:00
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
public:
	// �m�[�h
	struct Node
	{
		Node* m_prev; // �O�m�[�h
		Node* m_next; // ���m�[�h
		RecordData m_data; //���уf�[�^

		Node(RecordData data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

	//�R���X�g�C�e���[�^�N���X
	class ConstIterator 
	{
	protected:
		Node* m_Node; //�m�[�h�ւ̃|�C���^

	public:
		ConstIterator(Node* node) : m_Node(node) {}

		//�C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�
		ConstIterator& operator--()
		{
			m_Node = m_Node->m_prev;
			return *this;
		}

		//�C�e���[�^�̖����Ɍ������ĂЂƂi�߂�
		ConstIterator& operator++()
		{
			m_Node = m_Node->m_next;
			return *this;
		}

		//�C�e���[�^�̎w���v�f���擾����(const)
		const Node* operator*() const { return this->m_Node; }

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
		Node* operator*() { return m_Node; }
	};
	

	//�o�������X�g�̃R���X�g���N�^
	DoublyLinkedList() : m_Head(nullptr), m_Tail(nullptr), m_DataNum(0) {}

	//�f�X�g���N�^
	~DoublyLinkedList() // �擪���疖���܂�delete
	{
		while (m_Head != nullptr)
		{
			Node* temp = m_Head;
			m_Head = m_Head->m_next;
			delete temp;
		}
	}

	//�f�[�^���̎擾
	int GetDataNum() const { return m_DataNum; }
	
	// �f�[�^�̑}��(�C�e���[�^�̎w���m�[�h�̑O�ɑ}��)
	bool Insert(Iterator it, RecordData data)
	{
		Node* itNode = (*it); // �C�e���[�^�̎w���m�[�h
		if(itNode == nullptr || itNode->m_next == nullptr)
		{
			Push_back(data);
			return true;
		}

		Node* newNode = new Node(data); // �V�m�[�h
		newNode->m_prev = itNode->m_prev; // �V�m�[�h�̑O�m�[�h���C�e���[�^�̎w���O�m�[�h�ɁB
		newNode->m_next = itNode; // �V�m�[�h�̎��m�[�h���C�e���[�^�̎w���m�[�h�ɁB

		 // �C�e���[�^�̎w���m�[�h���擪��������
		if (itNode->m_prev == nullptr)
		{
			// �擪�ɐV�m�[�h���i�[
			m_Head = newNode;
		}
		else
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
	bool Push_back(RecordData data) 
	{
		Node* newNode = new Node(data);
		if (m_Head == nullptr) 
		{
			m_Head = m_Tail = newNode;
		}
		else 
		{
			m_Tail->m_next = newNode;
			newNode->m_prev = m_Tail;
			m_Tail = newNode;
		}

		m_DataNum++;
		return true;
	}

	// �f�[�^�̍폜
	bool Remove(Iterator it)
	{
		if (it == nullptr || (it == m_Tail && m_Head != m_Tail))
		{
			return false;
		}
		Node* itNode = *it; // �C�e���[�^�̎w���m�[�h

		if (itNode->m_prev != nullptr) 
		{
			itNode->m_prev->m_next = itNode->m_next;
		}
		else 
		{
			m_Head = itNode->m_next;
		}

		if (itNode->m_next != nullptr)
		{
			itNode->m_next->m_prev = itNode->m_prev;
		}
		else {
			m_Tail = itNode->m_prev;
		}

		delete itNode;
		m_DataNum--;
		return true;
	}

	// �擪�C�e���[�^�擾
	Iterator GetBegin() 
	{
		return Iterator(m_Head);
	}

	// �擪�R���X�g�C�e���[�^�擾
	ConstIterator GetCBegin() const
	{
		return ConstIterator(m_Head);
	}

	// �����C�e���[�^�擾
	Iterator GetEnd() 
	{
		return Iterator(m_Tail);
	}

	// �����R���X�g�C�e���[�^�擾
	ConstIterator GetCEnd() const
	{
		return ConstIterator(m_Tail);
	}

	// �S�f�[�^���i�[���ɕ`��
	void Draw()
	{
		Node* current = m_Head; // �C�e���[�^�̎w���m�[�h
		while (current != nullptr)
		{
			std::cout << " score : " << current->m_data.m_score << "   name : " << current->m_data.m_name << std::endl;
			current = current->m_next;
		}
	}
private:

	Node* m_Head; // �擪�m�[�h
	Node* m_Tail; // �����m�[�h
	int m_DataNum{}; // �f�[�^��
};