#include <iostream>
#include <string>
#include "doublyLinkedList.h"

bool DoublyLinkedList::Insert(Iterator& it, RecordData data)
{
	Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h
	if (itNode == nullptr || itNode->m_next == nullptr)
	{
		PushBack(data);
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

bool DoublyLinkedList::PushBack(RecordData data)
{
	Node* newNode = new Node(data);
	if (m_Head == nullptr)
	{
		m_Head = newNode;

		return true;
	}

	Node* tail = m_Head;
	while (tail->m_next != nullptr)
	{
		tail = tail->m_next;
	}

	tail->m_next = newNode;
	newNode->m_prev = tail;
	tail = newNode;

	m_DataNum++;
	return true;
}

bool DoublyLinkedList::Remove(Iterator& it)
{
	if (it == nullptr)
	{
		return false;
	}
	Node* itNode = it.m_Node; // �C�e���[�^�̎w���m�[�h

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
		Node* tail = m_Head;
		while (tail->m_next == nullptr)
		{
			tail = tail->m_next;
		}
		tail = itNode->m_prev;
	}

	delete itNode;
	m_DataNum--;
	return true;
}

void DoublyLinkedList::Draw()
{
	Node* current = m_Head; // �C�e���[�^�̎w���m�[�h
	while (current != nullptr)
	{
		std::cout << " score : " << current->m_data.m_score << "   name : " << current->m_data.m_name << std::endl;
		current = current->m_next;
	}
}
