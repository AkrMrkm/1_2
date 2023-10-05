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

		ConstIterator(Node* node) : m_Node(node) {}
		virtual ~ConstIterator() { delete m_Node; }

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
		~Iterator() { delete m_Node; }
		// �C�e���[�^�̎w���v�f���擾����(��const)
		RecordData& operator*() { return this->m_Node->m_data; }
	};
	

	//�o�������X�g�̃R���X�g���N�^
	DoublyLinkedList() : m_Head(nullptr), m_DataNum(0) {}

	//�f�X�g���N�^
	virtual ~DoublyLinkedList() // �擪���疖���܂�delete
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
	bool Insert(Iterator& it, RecordData data);

	// �f�[�^�̒ǉ�
	bool PushBack(RecordData data);

	// �f�[�^�̍폜
	bool Remove(Iterator& it);

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
		return Iterator(nullptr);
	}

	// �����R���X�g�C�e���[�^�擾
	ConstIterator GetCEnd() const
	{
		return ConstIterator(nullptr);
	}

	// �S�f�[�^���i�[���ɕ`��
	void Draw();

private:

	Node* m_Head; // �_�~�[�m�[�h
	int m_DataNum{}; // �f�[�^��
};