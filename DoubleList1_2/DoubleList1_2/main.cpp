/**
* @file main.cpp
* @brief �o�������X�g�N���X
* @author ����P
* @date 2023/10/16/11:00
* @details �ۑ�1_2�u�o�������X�g�̍Ď����v
*/

#include <iostream>
#include <fstream>
#include <string>
#include "doublyLinkedList.h"

int main()
{
	std::ifstream inputFile("Scores.txt"); //!�t�@�C���ǂݍ���
	DoublyLinkedList list;

	if (inputFile.is_open())  //!�t�@�C���ǂݍ��ݐ���
	{
		std::cerr << "�t�@�C���̓ǂݍ��݂ɐ������܂����B" << std::endl;

		//! �t�@�C������ǂݍ��񂾒l���i�[����ϐ�
		int score;
		std::string name;

		//! �t�@�C������f�[�^��ǂݍ���Ń��X�g�ɒǉ�
		while (inputFile >> score >> name)
		{
			RecordData data = { score,name };
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
		}

		//! �t�@�C�������
		inputFile.close();

		//! ���X�g���i�[�������ŕ\��
		DoublyLinkedList::Iterator it = list.GetBegin();
		for(int i = 0; i < list.GetDataNum(); i++)
		{
			RecordData data = *it;
			std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
			++it;
		}
	}
	else //! �t�@�C���ǂݍ��ݎ��s
	{
		std::cerr << "�t�@�C�����J���܂���B" << std::endl;
	}

	getchar();

	return 0;
}