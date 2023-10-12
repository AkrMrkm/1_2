//==========================
//双方向リスト再実装
//==========================
//2023/10/12/15:00
//作成者:村上輝

#include "pch.h"
#include "../DoubleList1_2/doublyLinkedList.h"

namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== データ数の取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合のデータ数の取得テスト
			@details	ID:リスト-0\n
						データ数の取得機能のテストです。\n
						リストが空である場合の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenEmpty)
		{
			DoublyLinkedList list;
			EXPECT_EQ(0, list.GetDataNum()) << "リストが空である場合のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-1\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入を行った際の戻り値を確認しています。\n
						データ数が1増えていれば成功です。\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumEndPush)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_TRUE(list.Insert(it, data));
			EXPECT_EQ(1, list.GetDataNum()) << "リスト末尾への挿入を行った際のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
			@details	ID:リスト-2\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
						データ数が増えていなければ成功です。\n
		//*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumEndPushFailed)
		{
			// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-3\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が1であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumInsert)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_TRUE(list.Insert(it, data));
			EXPECT_EQ(1, list.GetDataNum()) << "データの挿入を行った際のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		データの挿入に失敗した際のデータ数の取得テスト
			@details	ID:リスト-4\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/

		TEST(GetDataNumTest, TestGetDataNumInsertFailed)
		{
			// 挿入失敗はメモリ確保失敗時のためここではスキップ
		}

		/**********************************************************************************//**
			@brief		データの削除を行った際のデータ数の取得テスト
			@details	ID:リスト-5\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						最初にデータをひとつ挿入して、削除を行っています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDelete)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			list.PushBack(data);

			DoublyLinkedList::Iterator it = list.GetBegin();
			list.Remove(it);

			EXPECT_EQ(0, list.GetDataNum()) << list.GetDataNum() << "データの削除を行った際のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		データの削除に失敗した際のデータ数の取得テスト
			@details	ID:リスト-6\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						最初にデータをひとつ挿入して、削除を行っています。\n
						データ数が1であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteFail)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };

			list.PushBack(data);

			DoublyLinkedList::Iterator it = list.GetEnd();

			list.Remove(it);

			EXPECT_EQ(1, list.GetDataNum()) << list.GetDataNum() << "データの削除に失敗した際のデータの取得に失敗";
		}

		/**********************************************************************************//**
			@brief		リストが空である場合にデータの削除をした際のデータ数の取得テスト
			@details	ID:リスト-7\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						データ数がマイナスでなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteEmpty)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_FALSE(list.Remove(it));

			EXPECT_EQ(0, list.GetDataNum());
		}

		// 8はマニュアルテスト

		//=================================== データの挿入 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、挿入した際の挙動
			@details	ID:リスト-9\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれる。\n
						先頭イテレータ、末尾イテレータを引数で渡した場合について、個別に挙動をチェックすること\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToEmpty)
		{
			RecordData data{ 1, "a" };
			// 先頭に挿入
			{
				DoublyLinkedList list;
				DoublyLinkedList::Iterator it = list.GetBegin();
				EXPECT_EQ(true, list.Insert(it, data));
				EXPECT_EQ(1, list.GetDataNum());
			}

			// 末尾に挿入
			{
				DoublyLinkedList list;
				DoublyLinkedList::Iterator it = list.GetEnd();
				EXPECT_EQ(true, list.Insert(it, data));
				EXPECT_EQ(1, list.GetDataNum());
			}
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動テスト
			@details	ID:リスト-10\n
						先頭に要素が挿入され、元々先頭だった要素が２番目になれば成功です。\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToBegin)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			DoublyLinkedList::Iterator it = list.GetBegin();

			ASSERT_TRUE(list.Insert(it, data3));

			//先頭だった要素が二番目になっていたら成功(順番が3,1,2になっていたら成功)
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動テスト
			@details	ID:リスト-11\n
						イテレータの指す位置に要素が挿入される\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToEnd)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);

			DoublyLinkedList::Iterator it = list.GetEnd();

			list.Insert(it, data3);

			//順番が1,2,3になっていれば成功
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(2, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(3, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動テスト
			@details	ID:リスト-12\n
						TRUEで成功\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToOther)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			// 3番目の前に入れる
			DoublyLinkedList::Iterator it = list.GetBegin();
			++it;
			++it;

			list.Insert(it, data4);

			//順番が1243になってたらTRUE
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(2, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(4, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(3, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		ConstIteratorを指定して挿入をした際の挙動テスト
			@details	ID:リスト-13\n
						TRUEで成功\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか。\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToOtherConst)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			RecordData data4{ 0, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			// 先頭に挿入
			{
				DoublyLinkedList::ConstIterator it = list.GetBegin();
				list.Insert(it, data4);

				//順番が0123になってたらTRUE
				it = list.GetBegin();
				RecordData itData = *it;
				EXPECT_EQ(0, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(1, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(2, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(3, (itData.m_score));
			}

			// 3番目に挿入
			{
				DoublyLinkedList::ConstIterator it = list.GetBegin();
				++it;
				++it;
				list.Insert(it, data4);
				//順番が01023になってたらTRUE
				it = list.GetBegin();
				RecordData itData = *it;
				EXPECT_EQ(0, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(1, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(0, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(2, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(3, (itData.m_score));
			}

			// 末尾に挿入
			{
				DoublyLinkedList::ConstIterator it = list.GetEnd();
				list.Insert(it, data4);
				//順番が010230になってたらTRUE
				it = list.GetBegin();
				RecordData itData = *it;
				EXPECT_EQ(0, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(1, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(0, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(2, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(3, (itData.m_score));
				itData = *(++it);
				EXPECT_EQ(0, (itData.m_score));
			}
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡して、挿入した場合の挙動テスト
			@details	ID:リスト-14\n
						リストの参照が無いイテレータを渡した際の挙動など\n
						何も起こらなければ成功\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToUnknownIt)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			list.PushBack(data); // 要素をひとつ挿入

			//リストの参照が無いイテレータ
			DoublyLinkedList::Iterator it;
			list.Insert(it, data);
			//データ数が変わっていなければ成功
			EXPECT_EQ(1, (list.GetDataNum()));

			//リスト２のイテレータをリスト１に渡して挿入したとき(別のリストを参照したとき)
			DoublyLinkedList list2;
			list2.PushBack(data2);
			it = list2.GetBegin();
			list.Insert(it, data2);
			//データ数が変わっていなければ成功
			EXPECT_EQ(1, (list.GetDataNum()));
		}

		// 15はマニュアルテスト

		//=================================== データの削除 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、削除を行った際の挙動
			@details	ID:リスト-16\n
						FALSEで成功\n
						先頭イテレータ、末尾イテレータを引数で渡した場合について、個別に挙動をチェックすること\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToEmpty)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();
			EXPECT_EQ(false, list.Remove(it));

			it = list.GetEnd();
			EXPECT_EQ(false, list.Remove(it));
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
			@details	ID:リスト-17\n
						先頭要素の削除\n
						TRUEで成功\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToBegin)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			DoublyLinkedList::Iterator it = list.GetBegin();
			list.Remove(it);

			//先頭要素がなくなっていれば成功
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(2, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(3, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
			@details	ID:リスト-18\n
						何も変わらなければfalseで成功\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToEnd)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			int oldNum = list.GetDataNum();

			DoublyLinkedList::Iterator it = list.GetEnd();
			list.Remove(it);

			//要素数が変わっていなければ成功
			EXPECT_EQ(false, (oldNum != list.GetDataNum())) << oldNum << list.GetDataNum();
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
			@details	ID:リスト-19\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか\n
						TRUEで成功\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToOther)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			DoublyLinkedList::Iterator it = list.GetBegin();
			++it;
			// 2番目を削除
			list.Remove(it);

			it = list.GetBegin();
			RecordData itData = *it;

			//順番が1,3になっていれば成功
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		ConstIteratorを指定して削除を行った際の挙動
			@details	ID:リスト-20\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか\n
						TRUEで成功\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToOtherConst)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };
			RecordData data5{ 5, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			list.PushBack(data4);
			list.PushBack(data5);

			// 先頭を削除
			{
				DoublyLinkedList::ConstIterator it = list.GetCBegin();
				list.Remove(it);

				it = list.GetBegin();
				RecordData itData = *it;

				//順番が2345になっていれば成功
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(5, itData.m_score);
			}

			// 2番目を削除
			{
				DoublyLinkedList::ConstIterator it = list.GetCBegin();
				++it;
				list.Remove(it);

				it = list.GetBegin();
				RecordData itData = *it;

				//順番が245になっていれば成功
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(5, itData.m_score);
			}

			// 末尾を削除
			{
				DoublyLinkedList::ConstIterator it = list.GetCEnd();
				list.Remove(it);

				it = list.GetBegin();
				RecordData itData = *it;

				//順番が24になっていれば成功
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}
		}
		/**********************************************************************************//**
			@brief		不正なイテレータを渡して、削除した場合の挙動
			@details	ID:リスト-21\n
						リストの参照がないイテレータ、別リストの要素を指すイテレータを渡した際の挙動など\n
						何も起こらない\n
						FALSEで成功\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToUnknown)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//要素を挿入
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			int oldNum = list.GetDataNum();

			// 参照の無いイテレータを渡したとき
			{
				DoublyLinkedList::Iterator it;
				list.Remove(it);
				//データの総数が変わっていなければ成功
				EXPECT_EQ(oldNum, list.GetDataNum());
			}

			// 別のリストのイテレータを渡したとき
			{
				DoublyLinkedList list2;
				list2.PushBack(data);
				DoublyLinkedList::Iterator it = list2.GetBegin();
				list.Remove(it);
				//データの総数が変わっていなければ成功
				EXPECT_EQ(oldNum, list.GetDataNum());
			}
		}

		// 22はマニュアルテスト


		//=================================== 先頭イテレータの取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動
			@details	ID:リスト-23\n
						ダミーノードを指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetBegin, TestGetBeginItEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			// ダミーノードなので、nullであれば成功
			EXPECT_EQ(true, it == nullptr);
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動
			@details	ID:リスト-24\n
						先頭要素を指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetBegin, TestGetBeginItOne)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			list.PushBack(data);

			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData itData = *it;

			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
			@details	ID:リスト-25\n
						先頭要素を指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetBegin, TestGetBeginItAny)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };

			list.PushBack(data);
			list.PushBack(data2);

			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData itData = *it;

			EXPECT_EQ(1, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った後に、呼び出した際の挙動
			@details	ID:リスト-26\n
						先頭要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(GetBegin, TestGetBeginItAfterInsert)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			//データを最初に一つ入れる
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData itData = *it;
			//data2の1が入っていればOK
			EXPECT_EQ(1, (itData.m_score));

			//先頭に入れる
			it = list.GetBegin();
			list.Insert(it, data2);
			//data2の2が入っていればOK
			it = list.GetBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//先頭から2番目に入れる(中央)
			it = list.GetBegin();
			++it;
			list.Insert(it, data3);
			//data2の2が入っていればOK
			it = list.GetBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//末尾に入れる
			it = list.GetEnd();
			list.Insert(it, data4);
			
			//data2の2が入っていればOK
			it = list.GetBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		データの削除を行った後に、呼び出した際の挙動
			@details	ID:リスト-27\n
						先頭要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾の要素の削除を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(GetBegin, TestGetBeginItAfterRemove)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };
			RecordData data5{ 5, "a" };

			//データを最初に5つ入れる
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			list.PushBack(data4);
			list.PushBack(data5);

			//先頭、中央、末尾の要素を削除
			it = list.GetBegin();
			list.Remove(it);
			it = list.GetBegin();
			RecordData itData = *it;
			//data2の2が入っていればOK
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);


			it = list.GetBegin();
			++it;
			list.Remove(it);
			it = list.GetBegin();
			itData = *it;
			//data2の2が入っていればOK

			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);
			it = list.GetEnd();
			list.Remove(it);
			it = list.GetBegin();
			itData = *it;
			//data2の2が入っていればOK
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);
		}

		// 28はマニュアルテスト


		//=================================== 先頭コンストイテレータの取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動
			@details	ID:リスト-29\n
						ダミーノードを指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetBeginConst, TestGetBeginItEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetCBegin();

			// ダミーノードなので、nullであれば成功
			EXPECT_EQ(true, it == nullptr);
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動
			@details	ID:リスト-30\n
						先頭要素を指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetBeginConst, TestGetBeginItOne)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };

			list.PushBack(data);
			DoublyLinkedList::ConstIterator it = list.GetCBegin();
			const RecordData itData = *it;

			EXPECT_EQ(1, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
			@details	ID:リスト-31\n
						先頭要素を指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetBeginConst, TestGetBeginItAny)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };

			list.PushBack(data);
			list.PushBack(data2);

			DoublyLinkedList::ConstIterator it = list.GetCBegin();
			const RecordData itData = *it;

			EXPECT_EQ(1, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った後に、呼び出した際の挙動
			@details	ID:リスト-32\n
						先頭要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(GetBeginConst, TestGetBeginItAfterInsert)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			//データを最初に一つ入れる
			list.PushBack(data);
			DoublyLinkedList::ConstIterator it = list.GetCBegin();
			RecordData itData = *it;
			//data2の1が入っていればOK
			EXPECT_EQ(1, (itData.m_score));

			//先頭に入れる
			it = list.GetCBegin();
			list.Insert(it, data2);
			//data2の2が入っていればOK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//先頭から2番目に入れる(中央)
			it = list.GetCBegin();
			++it;
			list.Insert(it, data3);
			//data2の2が入っていればOK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//末尾に入れる
			it = list.GetCEnd();
			list.Insert(it, data4);

			//data2の2が入っていればOK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		データの削除を行った後に、呼び出した際の挙動
			@details	ID:リスト-33\n
						先頭要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(GetBeginConst, TestGetBeginItAfterRemove)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetCBegin();

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };
			RecordData data5{ 5, "a" };

			//データを最初に5つ入れる
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			list.PushBack(data4);
			list.PushBack(data5);

			//先頭の要素を削除
			it = list.GetCBegin();
			list.Remove(it);
			it = list.GetCBegin();
			RecordData itData = *it;
			//data2の2が入っていればOK
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);

			//中央の要素を削除
			it = list.GetCBegin();
			++it;
			list.Remove(it);
			//data2の2が入っていればOK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);

			//末尾の要素を削除
			it = list.GetCEnd();
			list.Remove(it);
			//data2の2が入っていればOK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);
		}

		// 34はマニュアルテスト


		//=================================== 末尾イテレータの取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動
			@details	ID:リスト-35\n
						ダミーノードを指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			// ダミーノードなので、nullであれば成功
			EXPECT_EQ(true, it == nullptr);
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動
			@details	ID:リスト-36\n
						末尾要素を指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItOne)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };

			list.PushBack(data);

			DoublyLinkedList::Iterator it = list.GetEnd();


			// 末尾イテレータの要素データが最初に入れたデータではなく、末尾イテレータの前の要素が最初に入れた値であったら成功
			RecordData itData = *(it);
			EXPECT_NE(1, itData.m_score); // !=
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // ==
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
			@details	ID:リスト-37\n
						末尾要素を指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItAny)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };

			list.PushBack(data);
			list.PushBack(data2);

			DoublyLinkedList::Iterator it = list.GetEnd();

			// 末尾イテレータの要素データが最後に入れたデータではなく、末尾イテレータの前の要素が最後に入れた値であったら成功
			RecordData itData = *(it);
			EXPECT_NE(1, itData.m_score); // !=
			EXPECT_NE(2, itData.m_score); // !=

			//末尾イテレータの前は末尾要素を指す
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score); // ==
			//末尾イテレータの後ろは先頭要素を指す
			it = list.GetEnd();
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score); // ==
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った後に、呼び出した際の挙動
			@details	ID:リスト-38\n
						末尾要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItAfterInsert)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			list.Insert(it, data);
			it = list.GetEnd();
			RecordData itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // 末尾の前要素データのスコアが1だったら成功

			it = list.GetBegin(); // 先頭に挿入
			list.Insert(it, data2);
			it = list.GetEnd(); 
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // 末尾の前要素データのスコアが1だったら成功

			it = list.GetBegin();// 中間に挿入
			++it;
			list.Insert(it, data3);
			it = list.GetEnd();
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // 末尾の前要素データのスコアが1だったら成功


			it = list.GetEnd();// 末尾に挿入
			list.Insert(it, data4);
			it = list.GetEnd();
			itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功
		}

		/**********************************************************************************//**
			@brief		データの削除を行った後に、呼び出した際の挙動
			@details	ID:リスト-39\n
						末尾要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItAfterRemove)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			list.PushBack(data4);

			DoublyLinkedList::Iterator it = list.GetBegin(); //先頭を削除
			list.Remove(it);
			it = list.GetEnd();
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功

			it = list.GetBegin(); //先頭から2番目を削除
			++it;
			list.Remove(it);
			it = list.GetEnd();
			itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功

			it = list.GetEnd(); //末尾を削除
			list.Remove(it);
			it = list.GetEnd();
			itData = *(--it); // 末尾の前要素データのスコアが4だったら成功
			EXPECT_EQ(4, itData.m_score); // 末尾イテレータはダミーノードなので変わらない

			it = list.GetEnd(); //末尾のひとつ前の要素を削除
			list.Remove(--it);
			it = list.GetEnd();
			itData = *(--it); // 末尾の前要素データのスコアが2だったら成功
			EXPECT_EQ(2, itData.m_score);
		}

		//40はマニュアルテスト


		//=================================== 末尾コンストイテレータの取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動
			@details	ID:リスト-41\n
						ダミーノードを指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetEnd();

			// ダミーノードなので、nullであれば成功
			EXPECT_EQ(true, it == nullptr);
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動
			@details	ID:リスト-42\n
						末尾要素を指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItOne)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };

			list.PushBack(data);

			DoublyLinkedList::ConstIterator it = list.GetCEnd();


			// 末尾イテレータの要素データが最初に入れたデータではなく、末尾イテレータの前の要素が最初に入れた値であったら成功
			RecordData itData = *(it);
			EXPECT_NE(1, itData.m_score); // !=
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // ==
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
			@details	ID:リスト-43\n
						末尾要素を指すイテレータが返る\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItAny)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };

			list.PushBack(data);
			list.PushBack(data2);

			DoublyLinkedList::ConstIterator it = list.GetCEnd();

			// 末尾イテレータの要素データが最後に入れたデータではなく、末尾イテレータの前の要素が最後に入れた値であったら成功
			RecordData itData = *(it);
			EXPECT_NE(1, itData.m_score); // !=
			EXPECT_NE(2, itData.m_score); // !=

			//末尾イテレータの前は末尾要素を指す
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score); // ==
			//末尾イテレータの後ろは先頭要素を指す
			it = list.GetEnd();
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score); // ==
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った後に、呼び出した際の挙動
			@details	ID:リスト-44\n
						末尾要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItAfterInsert)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetCEnd();

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			list.Insert(it, data);
			it = list.GetCEnd();
			RecordData itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // 末尾の前要素データのスコアが1だったら成功

			it = list.GetCBegin(); // 先頭に挿入
			list.Insert(it, data2);
			it = list.GetCEnd();
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // 末尾の前要素データのスコアが1だったら成功

			it = list.GetCBegin();// 中間に挿入
			++it;
			list.Insert(it, data3);
			it = list.GetCEnd();
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // 末尾の前要素データのスコアが1だったら成功


			it = list.GetCEnd();// 末尾に挿入
			list.Insert(it, data4);
			it = list.GetCEnd();
			itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功
		}

		/**********************************************************************************//**
			@brief		データの削除を行った後に、呼び出した際の挙動
			@details	ID:リスト-45\n
						末尾要素を指すイテレータが返る\n
						要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックすること\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItAfterRemove)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			list.PushBack(data4);

			// 先頭を削除
			DoublyLinkedList::ConstIterator it = list.GetCBegin();
			list.Remove(it);
			it = list.GetCEnd();
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功

			it = list.GetCBegin(); //先頭から2番目を削除
			++it;
			list.Remove(it);
			it = list.GetCEnd();
			itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // 末尾の前要素データのスコアが4だったら成功

			it = list.GetCEnd(); //末尾を削除
			list.Remove(it);
			it = list.GetCEnd();
			itData = *(--it); // 末尾の前要素データのスコアが4だったら成功
			EXPECT_EQ(4, itData.m_score); // 末尾イテレータはダミーノードなので変わらない

			it = list.GetCEnd(); //末尾のひとつ前の要素を削除
			list.Remove(--it);
			it = list.GetCEnd();
			itData = *(--it); // 末尾の前要素データのスコアが2だったら成功
			EXPECT_EQ(2, itData.m_score);
		}

		//46はマニュアルテスト
	}
	namespace chapter2
	{
		//===================================イテレータの指す要素の取得 ===================================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動
			@details	ID:リスト-0\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestNoReference)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it;

			EXPECT_DEATH(*it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		/**********************************************************************************//**
			@brief		Iteratorから取得した要素に対して、値の代入が行えるかをチェック
			@details	ID:リスト-1\n
						代入後に再度呼び出し、値が変更されていることを確認\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestAssignIt)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();

			*it = data2; // 別のデータを代入
			RecordData itData = *it;

			EXPECT_EQ(2, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動
			@details	ID:リスト-3\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestEmptyBegin)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			EXPECT_DEATH(*it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動
			@details	ID:リスト-4\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestEmptyEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_DEATH(*it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		//===================================イテレータをリストの末尾に向かってひとつ進める===================================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動
			@details	ID:リスト-5\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestNoReference)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it;

			EXPECT_DEATH(++it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動
			@details	ID:リスト-6\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestEmptyBegin)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			EXPECT_DEATH(++it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動
			@details	ID:リスト-7\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestEmptyEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_DEATH(++it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
			@details	ID:リスト-8\n
						次の要素を指す\n
						リストの末尾から先頭まで呼び出しを行い、期待されている要素が格納されているかを確認\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestAny)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
			@details	ID:リスト-9\n
						次の要素を指す\n
						インクリメント呼び出し時の値と、インクリメント実行後の値の両方を確認\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestPrefIncrement)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(3, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
			@details	ID:リスト-10\n
						次の要素を指す\n
						インクリメント呼び出し時の値と、インクリメント実行後の値の両方を確認\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestBackIncrement)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(1, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(2, itData.m_score);
		}


		//===================================イテレータをリストの先頭に向かってひとつ進める===================================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動
			@details	ID:リスト-11\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestNoReference)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_DEATH(--it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、末尾イテレータに対して呼び出した際の挙動
			@details	ID:リスト-12\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestEmptyBegin)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_DEATH(--it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		/**********************************************************************************//**
			@brief		先頭イテレータに対して呼び出した際の挙動
			@details	ID:リスト-13\n
						Assert発生\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestEmptyEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_DEATH(--it, ".*"); // リストが空なのでアサートが発生してプログラムが異常終了することを確認
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
			@details	ID:リスト-14\n
						前の要素を指す\n
						リストの末尾から先頭まで呼び出しを行い、期待されている要素が格納されているかを確認\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestAny)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			DoublyLinkedList::Iterator it = list.GetEnd();
			--it;
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		前置インクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
			@details	ID:リスト-15\n
						次の要素を指す\n
						デクリメント呼び出し時の値と、デクリメント実行後の値の両方を確認\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestPrefDecrement)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			DoublyLinkedList::Iterator it = list.GetEnd();
			--it;
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		後置インクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
			@details	ID:リスト-16\n
						次の要素を指す\n
						デクリメント呼び出し時の値と、デクリメント実行後の値の両方を確認\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestBackDecrement)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			DoublyLinkedList::Iterator it = list.GetEnd();
			--it;
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(3, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(2, itData.m_score);
			itData = *(it--);
			EXPECT_EQ(1, itData.m_score);
		}

		//17はマニュアルテスト

		/**********************************************************************************//**
			@brief		コピーコンストラクト後の値がコピー元と等しいことをチェック
			@details	ID:リスト-18\n
		*//***********************************************************************************/
		TEST(IteratorCopyTest, TestCopyEqual)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData data{ 1, "a" };
			list.PushBack(data);
			it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = it;
			RecordData itData = *it;
			RecordData itData2 = *it2;

			EXPECT_EQ(true, itData.m_score == itData2.m_score);
		}

		//19はマニュアルテスト

		/**********************************************************************************//**
			@brief		代入後の値がコピー元と等しいことをチェック
			@details	ID:リスト-20\n
		*//***********************************************************************************/
		TEST(IteratorAssignTest, TestAssignEqual)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData data{ 1, "a" };
			list.PushBack(data);
			it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = list.GetBegin();
			it2 = it;
			RecordData itData = *it;
			RecordData itData2 = *it2;

			EXPECT_EQ(true, itData.m_score == itData2.m_score);
		}


		//===================================ふたつのイテレータが同一のものであるか比較===================================

		/**********************************************************************************//**
			@brief		リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
			@details	ID:リスト-21\n
						TRUEで成功\n
		*//***********************************************************************************/
		TEST(IteratorEqualTest, TestEqualEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = list.GetEnd();

			EXPECT_EQ(true, it == it2);
		}

		/**********************************************************************************//**
			@brief		同一のイテレータを比較した際の挙動
			@details	ID:リスト-22\n
						TRUEで成功\n
		*//***********************************************************************************/
		TEST(IteratorEqualTest, TestEqual)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = list.GetBegin();

			EXPECT_EQ(true, it == it2);
		}

		/**********************************************************************************//**
			@brief		異なるイテレータを比較した際の挙動
			@details	ID:リスト-23\n
						FALSEで成功\n
		*//***********************************************************************************/
		TEST(IteratorEqualTest, TestEqualDiff)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
			list.PushBack(data2);
			DoublyLinkedList::Iterator it2 = list.GetEnd();

			EXPECT_EQ(false, it == it2);
		}


		//===================================ふたつのイテレータが異なるものであるか比較===================================

		/**********************************************************************************//**
			@brief		リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
			@details	ID:リスト-24\n
		*//***********************************************************************************/
		TEST(IteratorDiffTest, TestDiffEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = list.GetEnd();

			EXPECT_EQ(false, it != it2);
		}

		/**********************************************************************************//**
			@brief		同一のイテレータを比較した際の挙動
			@details	ID:リスト-25\n
		*//***********************************************************************************/
		TEST(IteratorDiffTest, TestDiff)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = list.GetBegin();

			EXPECT_EQ(false, it != it2);
		}

		/**********************************************************************************//**
			@brief		異なるイテレータを比較した際の挙動
			@details	ID:リスト-26\n
		*//***********************************************************************************/
		TEST(IteratorDiffTest, TestDiffDiff)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
			list.PushBack(data2);
			DoublyLinkedList::Iterator it2 = list.GetBegin();
			it2++;

			EXPECT_EQ(true, it != it2);
		}
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}