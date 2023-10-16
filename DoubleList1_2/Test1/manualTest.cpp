/**
* @file manualTest.cpp
* @brief 手動テスト
* @author 村上輝
* @date 2023/10/16/11:00
* @details 課題1_2「双方向リストの再実装」
*/

#include "pch.h"
#include "manualTest.h"
#include "../DoubleList1_2/doublyLinkedList.h"


/**********************************************************************************//**
	@brief		データ数の取得機能について、constのメソッドであるかのテスト
	@details	ID:リスト-8(手動)\n
				データ数の取得機能のテストです。\n
				constのメソッドであるかを確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(GetDataNumTest, TestGetDataNumWhenConst)
{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList list;
	EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}


/**********************************************************************************//**
	@brief		リスト末尾のデータ追加について、非constが保障されているかのテスト
	@details	ID:リスト-15(手動)\n
				リスト末尾のデータ追加テストです。\n
				非constが保障されているかを確認しています。\n
				有効にしてコンパイルエラーになれば成功です。\n
				TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(ListManualTest, TestInsertWhenConst)
{
#if defined TT_TEST_INSERT_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetCBegin();
	RecordData data{ 1, "a" };
	list.Insert(it, data);//ここでエラー
#endif //TT_TEST_INSERT_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		非constのメソッドであるか
	@details	ID:リスト-22\

				コンパイルエラーで成功\n
*//***********************************************************************************/
TEST(RemoveTest, TestRemoveToWhenConst)
{
#if defined TT_TEST_REMOVE_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetCBegin();
	list.Remove(it); // ここでエラー
#endif //TT_TEST_REMOVE_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
	@details	ID:リスト-28\n
				コンパイルエラーで成功\n
*//***********************************************************************************/
TEST(GetBegin, TestGetBeginItConst)
{
#if defined TT_TEST_BEGIN_WHEN_NO_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetBegin();// ここでエラー
#endif //TT_TEST_BEGIN_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		constのメソッドであるか
	@details	ID:リスト-34\n
				コンパイルが通れば成功\n
*//***********************************************************************************/
TEST(GetBeginConst, TestGetBeginItConst)
{
#if defined TT_TEST_BEGIN_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetCBegin();
#endif //TT_TEST_BEGIN_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
	@details	ID:リスト-40\n
				コンパイルエラーで成功\n
*//***********************************************************************************/
TEST(GetEndTest, TestGetEndItConst)
{
#if defined TT_TEST_END_WHEN_NO_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetEnd();// ここでエラー
#endif //TT_TEST_END_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		constのメソッドであるか
	@details	ID:リスト-46\n
				コンパイルが通れば成功\n
*//***********************************************************************************/
TEST(GetEndTestConst, TestGetEndItConst)
{
#if defined TT_TEST_END_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetCEnd();
#endif //TT_TEST_END_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		ConstIteratorから取得した要素に対して、値の代入が行えるかをチェック
	@details	ID:リスト-2\n
				コンパイルエラーになることをチェック。自動テスト化しなくてよい。\n
*//***********************************************************************************/
TEST(IteratorGetTest, TestAssignItConst)
{
#if defined TT_TEST_ITE_ASSIGN_CONST
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetBegin();
	RecordData data{ 1, "a" };
	*it = data;
#endif //TT_TEST_ITE_ASSIGN_CONST
	SUCCEED();
}



//===================================イテレータのコピーを行う===================================

/**********************************************************************************//**
	@brief		ConstIteratorから、Iteratorのコピーが作成されないかをチェック
	@details	ID:リスト-17\n
				コンパイルエラーになることを確認する。自動テスト化しなくてよい。\n
*//***********************************************************************************/
TEST(IteratorCopyTest, TestConstError)
{
#if defined TT_TEST_COPY_WHEN_CONST
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cit = list.GetBegin();
	DoublyLinkedList::Iterator cit = cit;
#endif //TT_TEST_COPY_WHEN_CONST
	SUCCEED();
}




//===================================イテレータの代入を行う===================================

/**********************************************************************************//**
	@brief		IteratorにConstIteratorを代入できない事をチェック
	@details	ID:リスト-19\n
				コンパイルエラーになることを確認する。自動テスト化しなくてよい。\n
*//***********************************************************************************/
TEST(IteratorAssignTest, TestConstError)
{
#if defined TT_TEST_ASSIGN_WHEN_CONST
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cit = list.GetBegin();
	DoublyLinkedList::Iterator it = list.GetBegin();
	it = cit; // ここでエラー
#endif //TT_TEST_ASSIGN_WHEN_CONST
	SUCCEED();
}