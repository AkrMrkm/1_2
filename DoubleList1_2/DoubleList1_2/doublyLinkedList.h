/**
* @file doublyLinkedList.h
* @brief �o�������X�g�N���X
* @author ����P
* @date 2023/10/16/11:00
* @details �ۑ�1_2�u�o�������X�g�̍Ď����v
*/

#pragma once

#include <assert.h>

/**
* @brief ���уf�[�^
*/
struct RecordData
{
	//! �X�R�A
	int m_score;

	//! ���O
	std::string m_name; 
};

/**
* @brief �o�������X�g�N���X
*/
class DoublyLinkedList
{
private:

	/**
	* @brief �m�[�h
	*/
	struct Node
	{
		//! �O�m�[�h
		Node* m_prev;

		//! ���m�[�h
		Node* m_next;

		//! ���уf�[�^
		RecordData m_data;

		/**
		* @brief �R���X�g���N�^
		*/
		Node() : m_prev(nullptr), m_next(nullptr), m_data() {}
		Node(RecordData data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

public:

	/**
	* @brief �R���X�g�C�e���[�^�N���X
	* @details �o�������X�g�N���X�̃C���i�[�N���X
	*/
	class ConstIterator 
	{
	public:
		//! �m�[�h�ւ̃|�C���^
		Node* m_Node;

		//! ���X�g�̃|�C���^
		const DoublyLinkedList* m_List;

		/**
		* @brief �R���X�g���N�^
		*/
		ConstIterator() : m_Node(nullptr), m_List(nullptr) {}
		ConstIterator(Node* node, const DoublyLinkedList* list) : m_Node(node), m_List(list) {}

		/**
		* @brief �C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�(�O�u)
		* @return �擪�ɂЂƂi�߂��C�e���[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		ConstIterator& operator--()
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode->m_next);
			m_Node = m_Node->m_prev;
			return *this;
		}

		/**
		* @brief �C�e���[�^�̐擪�Ɍ������ĂЂƂi�߂�(��u)
		* @return �擪�ɂЂƂi�߂��C�e���[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		ConstIterator operator--(int)
		{
			assert(this->m_Node != nullptr); // �m�[�h�̎Q�Ƃ�����������assert
			assert(this->m_Node != m_List->m_DummyNode); // ���X�g����or�_�~�[�m�[�h�ł�������
			ConstIterator ci = *this;
			m_Node = m_Node->m_prev;
			return ci;
		}

		/**
		* @brief �C�e���[�^�̖����Ɍ������ĂЂƂi�߂�(�O�u)
		* @return �����ɂЂƂi�߂��C�e���[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		ConstIterator& operator++()
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode);
			m_Node = m_Node->m_next;
			return *this;
		}

		/**
		* @brief �C�e���[�^�̖����Ɍ������ĂЂƂi�߂�(��u)
		* @return �����ɂЂƂi�߂��C�e���[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		ConstIterator operator++(int)
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode);
			ConstIterator ci = *this;
			m_Node = m_Node->m_next;
			return ci;
		}

		/**
		* @brief �C�e���[�^�̎w���v�f���擾����(const)
		* @return �C�e���[�^�̎w�����уf�[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		const RecordData& operator*() const 
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode);
			return this->m_Node->m_data; 
		}

		/**
		* @brief �R�s�[�R���X�g���N�^
		*/
		ConstIterator(const ConstIterator& ci) : m_Node(ci.m_Node), m_List(ci.m_List){}

		/**
		* @brief ������s��* 
		* @param[in] ci �������C�e���[�^
		* @details �C�e���[�^�̃m�[�h��������
		*/
		ConstIterator& operator=(const ConstIterator& ci)
		{
			m_Node = ci.m_Node;
			return *this;
		}

		/**
		* @brief ���ꂩ��r����
		* @param[in] ci ���ꂩ��r����C�e���[�^
		* @return �C�e���[�^�̎w���v�f������ł����true��Ԃ�
		*/
		bool operator==(const ConstIterator& ci)
		{
			return (m_Node == ci.m_Node);
		}

		/**
		* @brief �قȂ邩��r����
		* @param[in] ci �قȂ邩��r����C�e���[�^
		* @return �C�e���[�^�̎w���v�f���قȂ��true��Ԃ�
		*/
		bool operator!=(const ConstIterator& ci)
		{
			return (m_Node != ci.m_Node);
		}
	};

	/**
	* @brief �C�e���[�^�N���X
	* @details �R���X�g�C�e���[�^�N���X�̔h���N���X
	*/
	class Iterator : public ConstIterator
	{
	public:
		/**
		* @brief �R���X�g���N�^
		*/
		Iterator() : ConstIterator() {}
		Iterator(Node* n, DoublyLinkedList* list) : ConstIterator(n, list) {}

		/**
		* @brief �C�e���[�^�̎w���v�f���擾����(��const)
		* @return �C�e���[�^�̎w�����уf�[�^��Ԃ�
		* @details �m�[�h�̎Q�Ƃ�����������or�_�~�[�m�[�h�ł�������assert
		*/
		RecordData& operator*() 
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode);
			return this->m_Node->m_data; 
		}
	};


	/**
	* @brief �o�������X�g�N���X�̃R���X�g���N�^
	* @details �f�[�^���A�_�~�[�m�[�h��������\n
			   ���X�g����̏ꍇ�A�_�~�[�m�[�h�̑O��̓_�~�[�m�[�h���g���Q��\n
	*/
	DoublyLinkedList() : m_DataNum(0) 
	{
		m_DummyNode = new Node();
		m_DummyNode->m_next = m_DummyNode;
		m_DummyNode->m_prev = m_DummyNode;
	}

	/**
	* @brief �o�������X�g�N���X�̃f�X�g���N�^
	* @details �擪���疖���܂�delete
	*/
	virtual ~DoublyLinkedList()
	{
		if (m_DataNum == 0) return;
		while(m_DataNum > 0)
		{
			Node* temp = m_DummyNode;
			m_DummyNode = m_DummyNode->m_next;
			delete temp;
			m_DataNum--;
		}
	}

	/**
	* @brief �f�[�^���̎擾
	* @return ���X�g�̃f�[�^�̑�����Ԃ�
	*/
	int GetDataNum() const
	{
		return m_DataNum;
	}

	/**
	* @brief �f�[�^�̑}��
	* @param[in] it �}���������ʒu�̃C�e���[�^
	* @param[in] data �}�����������уf�[�^
	* @return bool(�}�������������true�A���s�����false)
	* @details �C�e���[�^�̎w���m�[�h�̑O�ɑ}������
	*/
	bool Insert(ConstIterator& it, RecordData& data)
	{
		Node* newNode = new Node(data); // �V�m�[�h

		if (m_DataNum == 0) // �v�f�����O�ł�������
		{
			// �_�~�[�m�[�h����ڂ̃m�[�h�ƌq����
			newNode->m_prev = m_DummyNode;
			newNode->m_next = m_DummyNode;

			m_DummyNode->m_next = newNode;
			m_DummyNode->m_prev = newNode;

			// �f�[�^���𑝂₷
			m_DataNum++;

			return true;
		}

		if (it.m_List != this) return false; // �C�e���[�^���ʂ̃��X�g�̗v�f���w���C�e���[�^�ł�������return

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

	/**
	* @brief �f�[�^�̒ǉ�
	* @param[in] data �ǉ����������уf�[�^
	* @details �����Ƀf�[�^�̒ǉ�
	*/
	void PushBack(RecordData& data)
	{
		Node* newNode = new Node(data);

		// ���X�g������ۂ�������
		if (m_DataNum == 0)
		{
			// �_�~�[�m�[�h����ڂ̃m�[�h�ƌq����
			newNode->m_prev = m_DummyNode;
			newNode->m_next = m_DummyNode;

			m_DummyNode->m_next = newNode;
			m_DummyNode->m_prev = newNode;

			m_DataNum++;
			return;
		}

		newNode->m_prev = m_DummyNode->m_prev;
		newNode->m_next = m_DummyNode;
		newNode->m_prev->m_next = newNode;
		m_DummyNode->m_prev = newNode;

		m_DataNum++;

		return;
	}

	/**
	* @brief �f�[�^�̍폜
	* @param[in] it �폜�������ʒu�̃C�e���[�^
	* @return �폜�Ɏ��s������false�A����������true��Ԃ�
	* @details �C�e���[�^�̎w���m�[�h���폜\n
				�f�[�^����0�A�C�e���[�^�̎w���m�[�h���_�~�[�m�[�h�A�ʃ��X�g���w���C�e���[�^�ł���Ή����s��Ȃ�\n
	*/
	bool Remove(ConstIterator& it)
	{
		Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h
		if (m_DataNum == 0) return false;
		if (itNode == m_DummyNode) return false;
		if (it.m_List != this) return false; // �C�e���[�^���ʂ̃��X�g�̗v�f���w���C�e���[�^�ł�������return


		itNode->m_prev->m_next = itNode->m_next;
		itNode->m_next->m_prev = itNode->m_prev;

		delete itNode;
		m_DataNum--;
		return true;
	}

	/**
	* @brief �擪�C�e���[�^�擾
	* @return �_�~�[�m�[�h�̎��̃m�[�h(�擪�̃C�e���[�^��Ԃ�)
	*/
	Iterator GetBegin() 
	{
		return Iterator(m_DummyNode->m_next, this);
	}

	/**
	* @brief �擪�R���X�g�C�e���[�^�擾
	* @return �_�~�[�m�[�h�̎��̃m�[�h(�擪�̃R���X�g�C�e���[�^��Ԃ�)
	*/
	ConstIterator GetCBegin() const
	{
		return ConstIterator(m_DummyNode->m_next, this);
	}

	/**
	* @brief �����C�e���[�^�擾
	* @return �_�~�[�m�[�h��Ԃ�
	*/
	Iterator GetEnd() 
	{
		return Iterator(m_DummyNode, this);
	}

	/**
	* @brief �����R���X�g�C�e���[�^�擾
	* @return �_�~�[�m�[�h��Ԃ�
	*/
	 ConstIterator GetCEnd() const
	{
		return ConstIterator(m_DummyNode, this);
	}

private:

	//! �_�~�[�m�[�h
	Node* m_DummyNode;

	//! �f�[�^��
	int m_DataNum{};
};