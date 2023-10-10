//==========================
//双方向リスト再実装
//==========================
//2023/10/10/14:00
//作成者:村上輝

#include <iostream>
#include <fstream>
#include <string>
#include "doublyLinkedList.h"

int main()
{
	std::ifstream inputFile("Scores.txt"); //ファイル読み込み
	DoublyLinkedList list;

	if (inputFile.is_open())  //ファイル読み込み成功
	{
		std::cerr << "ファイルの読み込みに成功しました。" << std::endl;

		// ファイルから読み込んだ値を格納する変数
		int score;
		std::string name;

		// ファイルからデータを読み込んでリストに追加
		while (inputFile >> score >> name)
		{
			RecordData data = { score,name };
			list.PushBack(data);
		}

		// ファイルを閉じる
		inputFile.close();

		// リストを格納した順で表示
		DoublyLinkedList::Iterator it = list.GetBegin();
		for(int i = 0; i < list.GetDataNum(); i++)
		{
			RecordData data = *it;
			std::cout << " score : " << data.m_score << "   name : " << data.m_name << std::endl;
			++it;
		}
	}
	else // ファイル読み込み失敗
	{
		std::cerr << "ファイルを開けません。" << std::endl;
	}

	getchar();

	return 0;
}