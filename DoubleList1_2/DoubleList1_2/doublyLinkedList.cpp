#include <iostream>
#include <string>
#include "doublyLinkedList.h"

bool DoublyLinkedList::Insert(Iterator& it, RecordData data)
{
	Node* itNode = it.m_Node; // イテレータの指すノード
	if (itNode == nullptr || itNode->m_next == nullptr)
	{
		PushBack(data);
		return true;
	}

	Node* newNode = new Node(data); // 新ノード
	newNode->m_prev = itNode->m_prev; // 新ノードの前ノードをイテレータの指す前ノードに。
	newNode->m_next = itNode; // 新ノードの次ノードをイテレータの指すノードに。

	 // イテレータの指すノードが先頭だったら
	if (itNode->m_prev == nullptr)
	{
		// 先頭に新ノードを格納
		m_Head = newNode;
	}
	else
	{
		// イテレータの指すノードの前ノードの次のノードに新ノードを格納
		// (イテレータノードと前ノードの間に格納)
		itNode->m_prev->m_next = newNode;
	}

	// イテレータの指すノードの前ノードに新ノードを格納、これでデータが繋がる
	itNode->m_prev = newNode;

	// データ数を増やす
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
	Node* itNode = it.m_Node; // イテレータの指すノード

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
	Node* current = m_Head; // イテレータの指すノード
	while (current != nullptr)
	{
		std::cout << " score : " << current->m_data.m_score << "   name : " << current->m_data.m_name << std::endl;
		current = current->m_next;
	}
}
