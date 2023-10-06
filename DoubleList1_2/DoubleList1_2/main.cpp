//==========================
//�o�������X�g�Ď���
//==========================
//2023/10/05/17:00
//�쐬��:����P

#include <iostream>
#include <fstream>
#include <string>
#include "doublyLinkedList.h"

int main()
{
	std::ifstream inputFile("Scores.txt"); //�t�@�C���ǂݍ���
	DoublyLinkedList list;

	if (inputFile.is_open())  //�t�@�C���ǂݍ��ݐ���
	{
		std::cerr << "�t�@�C���̓ǂݍ��݂ɐ������܂����B" << std::endl;

		// �t�@�C������ǂݍ��񂾒l���i�[����ϐ�
		int score;
		std::string name;

		// �t�@�C������f�[�^��ǂݍ���Ń��X�g�ɒǉ�
		while (inputFile >> score >> name)
		{
			DoublyLinkedList::Iterator it = list.GetEnd();
			RecordData data = { score,name };
			list.Insert(it, data);
			//list.Push_back({ score, name });
		}

		// �t�@�C�������
		inputFile.close();

		//���X�g�\��
		list.Draw();
	}
	else // �t�@�C���ǂݍ��ݎ��s
	{
		std::cerr << "�t�@�C�����J���܂���B" << std::endl;
	}

	getchar();

	return 0;
}