#pragma once
//==========================
//�o�������X�g�Ď���
//==========================
//2023/10/12/15:00
//�쐬��:����P
#include <assert.h>

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

		Node() : m_prev(nullptr), m_next(nullptr), m_data() {}
		Node(RecordData data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

public:

	//�R���X�g�C�e���[�^�N���X
	class ConstIterator 
	{
	public:
		Node* m_Node; //�m�[�h�ւ̃|�C���^

		ConstIterator() : m_Node(nullptr) {}
		ConstIterator(Node* node) : m_Node(node) {}

		//�C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�
		ConstIterator& operator--()
		{
			assert(this->m_Node != nullptr); // �m�[�h�̎Q�Ƃ�����������assert
			m_Node = m_Node->m_prev;
			return *this;
		}

		ConstIterator operator--(int) // ��u
		{
			assert(this->m_Node != nullptr); // �m�[�h�̎Q�Ƃ�����������assert
			ConstIterator ci = *this;
			m_Node = m_Node->m_prev;
			return ci;
		}

		//�C�e���[�^�̖����Ɍ������ĂЂƂi�߂�
		ConstIterator& operator++()
		{
			assert(this->m_Node != nullptr); // �m�[�h�̎Q�Ƃ�����������assert
			m_Node = m_Node->m_next;
			return *this;
		}

		ConstIterator operator++(int) // ��u
		{
			assert(this->m_Node != nullptr); // �m�[�h�̎Q�Ƃ�����������assert
			ConstIterator ci = *this;
			m_Node = m_Node->m_next;
			return ci;
		}

		//�C�e���[�^�̎w���v�f���擾����(const)
		const RecordData& operator*() const 
		{
			assert(this->m_Node != nullptr); // �m�[�h�̎Q�Ƃ�����������assert
			return this->m_Node->m_data; 
		}

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
			return (m_Node != ci.m_Node);
		}
	};

	//�C�e���[�^�N���X
	class Iterator : public ConstIterator
	{
	public:
		// �R���X�g���N�^
		Iterator() : ConstIterator() {}
		Iterator(Node* n) : ConstIterator(n) {}

		// �C�e���[�^�̎w���v�f���擾����(��const)
		RecordData& operator*() 
		{
			assert(this->m_Node != nullptr); // �m�[�h�̎Q�Ƃ�����������assert
			return this->m_Node->m_data; 
		}
	};


	//�o�������X�g�̃R���X�g���N�^
	DoublyLinkedList() : m_DummyNode(nullptr), m_DataNum(0) {}

	//�f�X�g���N�^
	virtual ~DoublyLinkedList() // �擪���疖���܂�delete
	{
		while (m_DummyNode != m_DummyNode)
		{
			Node* temp = m_DummyNode;
			m_DummyNode = m_DummyNode->m_next;
			delete temp;
		}
	}

	//�f�[�^���̎擾
	int GetDataNum() const
	{
		return m_DataNum;
	}
	
	// �f�[�^�̑}��(�C�e���[�^�̎w���m�[�h�̑O�ɑ}��)
	bool Insert(ConstIterator& it, RecordData& data)
	{
		Node* newNode = new Node(data); // �V�m�[�h

		if (m_DataNum == 0) // �v�f�����O�ł�������
		{
			// �_�~�[�m�[�h�����A��ڂ̃m�[�h�ƌq����
			m_DummyNode = new Node();

			newNode->m_prev = m_DummyNode;
			newNode->m_next = m_DummyNode;

			m_DummyNode->m_next = newNode;
			m_DummyNode->m_prev = newNode;

			// �f�[�^���𑝂₷
			m_DataNum++;

			return true;
		}

		if (!CheckThisData(it)) return false; // �C�e���[�^���ʂ̃��X�g�̗v�f���w���C�e���[�^�ł�������return

		Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h

		// �V�m�[�h�̑O�m�[�h���C�e���[�^�̎w���O�m�[�h�ɁB
		newNode->m_prev = itNode->m_prev;

		// �V�m�[�h�̎��m�[�h���C�e���[�^�̎w���m�[�h�ɁB
		newNode->m_next = itNode;

		// �C�e���[�^�̎w���m�[�h�̑O�m�[�h�̎��̃m�[�h�ɐV�m�[�h���i�[
		// (�C�e���[�^�m�[�h�ƑO�m�[�h�̊ԂɊi�[)
		itNode->m_prev->m_next = newNode;

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

		// ���X�g������ۂ�������
		if (m_DataNum == 0)
		{
			// �_�~�[�m�[�h�����A��ڂ̃m�[�h�ƌq����
			m_DummyNode = new Node();

			newNode->m_prev = m_DummyNode;
			newNode->m_next = m_DummyNode;

			m_DummyNode->m_next = newNode;
			m_DummyNode->m_prev = newNode;

			m_DataNum++;
			return true;
		}

		newNode->m_prev = m_DummyNode->m_prev;
		newNode->m_next = m_DummyNode;
		newNode->m_prev->m_next = newNode;
		m_DummyNode->m_prev = newNode;

		m_DataNum++;

		return true;
	}

	// �f�[�^�̍폜
	bool Remove(ConstIterator& it)
	{
		if (m_DataNum == 0) return false;
		if (it == m_DummyNode) return false;
		if (!CheckThisData(it)) return false; // �C�e���[�^���ʂ̃��X�g�̗v�f���w���C�e���[�^�ł�������return

		Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h

		itNode->m_prev->m_next = itNode->m_next;
		itNode->m_next->m_prev = itNode->m_prev;

		delete itNode;
		m_DataNum--;
		return true;
	}

	// �擪�C�e���[�^�擾
	Iterator GetBegin() 
	{
		if(m_DummyNode == nullptr)
			return Iterator(nullptr);
		return Iterator(m_DummyNode->m_next);
	}

	// �擪�R���X�g�C�e���[�^�擾
	ConstIterator GetCBegin() const
	{
		if (m_DummyNode == nullptr)
			return ConstIterator(nullptr);
		return ConstIterator(m_DummyNode->m_next);
	}

	// �����C�e���[�^�擾
	Iterator GetEnd() 
	{
		if (m_DummyNode == nullptr)
			return Iterator(nullptr);
		return Iterator(m_DummyNode);
	}

	// �����R���X�g�C�e���[�^�擾
	ConstIterator GetCEnd() const
	{
		if (m_DummyNode == nullptr)
			return ConstIterator(nullptr);
		return ConstIterator(m_DummyNode);
	}

	// �����̃C�e���[�^���w���v�f�����̃��X�g�ɑ��݂���v�f���ǂ����𔻕ʂ���
	bool CheckThisData(ConstIterator& it)
	{
		Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h

		Node* temp = m_DummyNode;

		while (temp != itNode)
		{
			temp = temp->m_next;
			if (temp == m_DummyNode)
				return false;
		}
		return true;
	}

private:

	Node* m_DummyNode; // �_�~�[�m�[�h
	int m_DataNum{}; // �f�[�^��
};