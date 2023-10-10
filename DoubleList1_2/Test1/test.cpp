//==========================
//�o�������X�g�Ď���
//==========================
//2023/10/10/14:00
//�쐬��:����P

#include "pch.h"
#include "../DoubleList1_2/doublyLinkedList.h"

namespace ex01_DataStructure
{
	namespace chapter1
	{
		//=================================== �f�[�^���̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-0\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenEmpty)
		{
			DoublyLinkedList list;
			EXPECT_EQ(0, list.GetDataNum()) << "���X�g����ł���ꍇ�̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-1\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�����Ă���ΐ����ł��B\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumEndPush)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			ASSERT_TRUE(list.PushBack(data));
			EXPECT_EQ(1, list.GetDataNum()) << "���X�g�����ւ̑}�����s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-2\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
		//*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumEndPushFailed)
		{
			// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-3\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumInsert)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			list.PushBack(data);
			EXPECT_EQ(1, list.GetDataNum()) << "�f�[�^�̑}�����s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}���Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-4\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/

		TEST(GetDataNumTest, TestGetDataNumInsertFailed)
		{
			// �}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-5\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�ŏ��Ƀf�[�^���ЂƂ}�����āA�폜���s���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDelete)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			list.PushBack(data);

			DoublyLinkedList::Iterator it = list.GetBegin();
			list.Remove(it);

			EXPECT_EQ(0, list.GetDataNum()) << list.GetDataNum() << "�f�[�^�̍폜���s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜�Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-6\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�ŏ��Ƀf�[�^���ЂƂ}�����āA�폜���s���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteFail)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };

			DoublyLinkedList::Iterator it = list.GetBegin();
			
			list.PushBack(data);

			list.Remove(it);

			EXPECT_EQ(1, list.GetDataNum()) << list.GetDataNum() << "�f�[�^�̍폜�Ɏ��s�����ۂ̃f�[�^�̎擾�Ɏ��s";
		}

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�Ƀf�[�^�̍폜�������ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-7\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^�����}�C�i�X�łȂ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteEmpty)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_FALSE(list.Remove(it));

			EXPECT_EQ(0, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-8(�蓮)\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
						TT_TEST_GET_DATA_NUM_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenConst)
		{
#define TT_TEST_GET_DATA_NUM_WHEN_CONST
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
			const DoublyLinkedList list;
			EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
			SUCCEED();
		}

		//=================================== �f�[�^�̑}�� ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA���X�g�����Ƀf�[�^��ǉ������ۂ̋����e�X�g
			@details	ID:���X�g-9\n
						���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�����ɗv�f���ǉ�����Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			RecordData data{ 1, "a" };

			EXPECT_EQ(true, list.Insert(it, data));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-10\n
						�擪�ɗv�f���}������A���X�擪�������v�f���Q�ԖڂɂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToBegin)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			DoublyLinkedList::Iterator it = list.GetBegin();

			list.Insert(it, data3);

			//�擪�������v�f����ԖڂɂȂ��Ă�����true
			it = list.GetBegin();
			RecordData itData = *it;

			EXPECT_EQ(3, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-11\n
						�C�e���[�^�̎w���ʒu�ɗv�f���}�������\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToEnd)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);

			DoublyLinkedList::Iterator it = list.GetEnd();

			list.Insert(it, data3);

			//���Ԃ�1,3,2�ɂȂ��Ă���ΐ���
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(3, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋����e�X�g
			@details	ID:���X�g-12\n
						TRUE�Ő���\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToOther)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			// 3�Ԗڂ̑O�ɓ����
			DoublyLinkedList::Iterator it = list.GetBegin();
			++it;
			++it;

			list.Insert(it, data4);

			//���Ԃ�1243�ɂȂ��Ă���TRUE
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(4, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(3, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		ConstIterator���w�肵�đ}���������ۂ̋����e�X�g
			@details	ID:���X�g-13\n
						TRUE�Ő���\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToOtherConst)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			// 3�Ԗڂ̑O�ɓ����
			DoublyLinkedList::ConstIterator it = list.GetBegin();
			++it;
			++it;

			list.Insert(it, data4);

			//���Ԃ�1243�ɂȂ��Ă���TRUE
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(4, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(3, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋����e�X�g
			@details	ID:���X�g-14\n
						���X�g�̎Q�Ƃ������C�e���[�^��n�����ۂ̋����Ȃ�\n
						�����N����Ȃ���ΐ���\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToUnknownIt)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			list.PushBack(data); // �v�f���ЂƂ}��

			//�擪�C�e���[�^���O�̃C�e���[�^�Ƃ����s���ȃC�e���[�^�����
			DoublyLinkedList::Iterator it = list.GetBegin();
			--it;
			list.Insert(it, data);
			//�f�[�^�����ς���Ă��Ȃ���ΐ���
			EXPECT_EQ(1, (list.GetDataNum()));


			//���X�g�Q�̃C�e���[�^�����X�g�P�ɓn���đ}�������Ƃ�(�ʂ̃��X�g���Q�Ƃ����Ƃ�)
			DoublyLinkedList list2;
			list2.PushBack(data2);
			it = list2.GetBegin();
			list.Insert(it, data2);
			//�f�[�^�����ς���Ă��Ȃ���ΐ���
			EXPECT_EQ(1, (list.GetDataNum()));
		}

		/**********************************************************************************//**
			@brief		���X�g�����̃f�[�^�ǉ��ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
			@details	ID:���X�g-15(�蓮)\n
						���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
						��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
						TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestInsertWhenConst)
		{
//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetCBegin();
			RecordData data{ 1, "a" };
			list.Insert(it, data);//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		//=================================== �f�[�^�̍폜 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
			@details	ID:���X�g-16\n
						FALSE�Ő���\n
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
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
			@details	ID:���X�g-17\n
						�擪�v�f�̍폜\n
						TRUE�Ő���\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToBegin)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			DoublyLinkedList::Iterator it = list.GetBegin();
			list.Remove(it);

			//�擪�v�f���Ȃ��Ȃ��Ă���ΐ���
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(2, (itData.m_score));
			++it;
			itData = *it;
			EXPECT_EQ(3, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
			@details	ID:���X�g-18\n
						�����ς��Ȃ����false�Ő���\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToEnd)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			int oldNum = list.GetDataNum();

			DoublyLinkedList::Iterator it = list.GetEnd();
			list.Remove(it);

			//�v�f�����ς���Ă��Ȃ���ΐ���
			EXPECT_EQ(false, (oldNum != list.GetDataNum())) << oldNum << list.GetDataNum();
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
			@details	ID:���X�g-19\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
						TRUE�Ő���\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToOther)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			DoublyLinkedList::Iterator it = list.GetBegin();
			++it;
			// 2�Ԗڂ��폜
			list.Remove(it);

			it = list.GetBegin();
			RecordData itData = *it;

			//���Ԃ�1,3�ɂȂ��Ă���ΐ���
			EXPECT_EQ(1, itData.m_score);
			++it;
			itData = *it;
			EXPECT_EQ(3, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		ConstIterator���w�肵�č폜���s�����ۂ̋���
			@details	ID:���X�g-20\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
						TRUE�Ő���\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToOtherConst)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			DoublyLinkedList::ConstIterator it = list.GetBegin();
			++it;
			// 2�Ԗڂ��폜
			list.Remove(it);

			it = list.GetBegin();
			RecordData itData = *it;

			//���Ԃ�1,3�ɂȂ��Ă���ΐ���
			EXPECT_EQ(1, itData.m_score);
			++it;
			itData = *it;
			EXPECT_EQ(3, itData.m_score);
		}
		/**********************************************************************************//**
			@brief		�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
			@details	ID:���X�g-21\n
						���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^��n�����ۂ̋����Ȃ�\n
						�����N����Ȃ�\n
						FALSE�Ő���\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToUnknown)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			int oldNum = list.GetDataNum();

			DoublyLinkedList::Iterator it = list.GetBegin();

			--it;

			list.Remove(it);

			//�f�[�^�̑������ς���Ă��Ȃ���ΐ���
			EXPECT_EQ(oldNum, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		��const�̃��\�b�h�ł��邩
			@details	ID:���X�g-22\
						
						�R���p�C���G���[�Ő���\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToWhenConst)
		{
			//#define TT_TEST_REMOVE_WHEN_CONST
#if defined TT_TEST_REMOVE_WHEN_CONST
			const DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetCBegin();
			list.Remove(it); // �����ŃG���[
#endif //TT_TEST_REMOVE_WHEN_CONST
			SUCCEED();
		}


		//=================================== �擪�C�e���[�^�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-23\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
		*//***********************************************************************************/
		TEST(GetBegin, TestGetBeginItEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			EXPECT_EQ(true, (it == nullptr));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-24\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
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
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-25\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
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
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-26\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
		*//***********************************************************************************/
		TEST(GetBegin, TestGetBeginItAfterInsert)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			//�f�[�^���ŏ��Ɉ�����
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData itData = *it;
			//data2��1�������Ă����OK
			EXPECT_EQ(1, (itData.m_score));

			//�擪�ɓ����
			it = list.GetBegin();
			list.Insert(it, data2);
			//data2��2�������Ă����OK
			it = list.GetBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//�擪����2�Ԗڂɓ����(����)
			it = list.GetBegin();
			++it;
			list.Insert(it, data3);
			itData = *it;
			//data2��2�������Ă����OK
			it = list.GetBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//�����ɓ����
			it = list.GetEnd();
			list.Insert(it, data4);
			
			it = list.GetBegin();
			itData = *it;

			//data2��2�������Ă����OK
			EXPECT_EQ(2, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-27\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����̗v�f�̍폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
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

			//�f�[�^���ŏ���5�����
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			list.PushBack(data4);
			list.PushBack(data5);

			//�擪�A�����A�����̗v�f���폜
			it = list.GetBegin();
			list.Remove(it);
			it = list.GetBegin();
			RecordData itData = *it;
			//data2��2�������Ă����OK
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);


			it = list.GetBegin();
			++it;
			list.Remove(it);
			it = list.GetBegin();
			itData = *it;
			//data2��2�������Ă����OK

			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);
			it = list.GetEnd();
			list.Remove(it);
			it = list.GetBegin();
			itData = *it;
			//data2��2�������Ă����OK
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);
		}

		/**********************************************************************************//**
			@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
			@details	ID:���X�g-28\n
						�R���p�C���G���[�Ő���\n
		*//***********************************************************************************/
		TEST(GetBegin, TestGetBeginItConst)
		{
			//#define TT_TEST_BEGIN_WHEN_NO_CONST
#if defined TT_TEST_BEGIN_WHEN_NO_CONST
			const DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();// �����ŃG���[
#endif //TT_TEST_BEGIN_WHEN_NO_CONST
			SUCCEED();
		}



		//=================================== �擪�R���X�g�C�e���[�^�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-29\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
		*//***********************************************************************************/
		TEST(GetBeginConst, TestGetBeginItEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetCBegin();

			EXPECT_EQ(true, (it == nullptr));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-30\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
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
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-31\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
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
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-32\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
		*//***********************************************************************************/
		TEST(GetBeginConst, TestGetBeginItAfterInsert)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			RecordData data4{ 4, "a" };

			//�f�[�^���ŏ��Ɉ�����
			list.PushBack(data);
			DoublyLinkedList::ConstIterator it = list.GetCBegin();
			RecordData itData = *it;
			//data2��1�������Ă����OK
			EXPECT_EQ(1, (itData.m_score));

			//�擪�ɓ����
			it = list.GetCBegin();
			list.Insert(it, data2);
			//data2��2�������Ă����OK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//�擪����2�Ԗڂɓ����(����)
			it = list.GetCBegin();
			++it;
			list.Insert(it, data3);
			itData = *it;
			//data2��2�������Ă����OK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//�����ɓ����
			it = list.GetCEnd();
			list.Insert(it, data4);

			it = list.GetCBegin();
			itData = *it;

			//data2��2�������Ă����OK
			EXPECT_EQ(2, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-33\n
						�擪�v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
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

			//�f�[�^���ŏ���5�����
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			list.PushBack(data4);
			list.PushBack(data5);

			//�擪�A�����A�����̗v�f���폜
			it = list.GetCBegin();
			list.Remove(it);
			it = list.GetCBegin();
			RecordData itData = *it;
			//data2��2�������Ă����OK
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);


			it = list.GetCBegin();
			++it;
			list.Remove(it);
			it = list.GetCBegin();
			itData = *it;
			//data2��2�������Ă����OK

			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);
			it = list.GetCEnd();
			list.Remove(it);
			it = list.GetCBegin();
			itData = *it;
			//data2��2�������Ă����OK
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);
		}

		/**********************************************************************************//**
			@brief		const�̃��\�b�h�ł��邩
			@details	ID:���X�g-34\n
						�R���p�C���G���[���ʂ�ΐ���\n
		*//***********************************************************************************/
		TEST(GetBeginConst, TestGetBeginItConst)
		{
#define TT_TEST_BEGIN_WHEN_CONST
#if defined TT_TEST_BEGIN_WHEN_CONST
			const DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetCBegin();// �����ŃG���[
#endif //TT_TEST_BEGIN_WHEN_CONST
			SUCCEED();
		}

		//=================================== �����C�e���[�^�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-35\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_EQ(true, (it == nullptr));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-36\n
						�����v�f���w���C�e���[�^���Ԃ�\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItOne)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };

			list.PushBack(data);

			DoublyLinkedList::Iterator it = list.GetEnd();
			RecordData itData = *it;

			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-37\n
						�����v�f���w���C�e���[�^���Ԃ�\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItAny)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };

			list.PushBack(data);
			list.PushBack(data2);

			DoublyLinkedList::Iterator it = list.GetEnd();
			RecordData itData = *it;

			EXPECT_EQ(2, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-38\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
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
			RecordData itData = *it;
			EXPECT_EQ(1, itData.m_score); // ������1�������琬��

			it = list.GetBegin(); // �擪�ɑ}��
			list.Insert(it, data2);
			it = list.GetEnd();
			itData = *it;
			EXPECT_EQ(1, itData.m_score); // ������1�������琬��

			it = list.GetBegin();// ���Ԃɑ}��
			++it;
			list.Insert(it, data3);
			it = list.GetEnd();
			itData = *it;
			EXPECT_EQ(1, itData.m_score); // ������1�������琬��


			it = list.GetEnd();// �����ɑ}��
			list.Insert(it, data4);
			it = list.GetEnd();
			itData = *it;
			EXPECT_EQ(1, itData.m_score); // ������3�������琬��
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-39\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
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

			DoublyLinkedList::Iterator it = list.GetBegin(); //�擪���폜
			list.Remove(it);
			it = list.GetEnd();
			RecordData itData = *it;
			EXPECT_EQ(4, itData.m_score);

			it = list.GetBegin(); //�擪����2�Ԗڂ��폜
			++it;
			list.Remove(it);
			it = list.GetEnd();
			itData = *it;
			EXPECT_EQ(4, itData.m_score);

			it = list.GetEnd(); //�������폜
			list.Remove(it);
			it = list.GetEnd();
			itData = *it;
			EXPECT_EQ(4, itData.m_score); // �����C�e���[�^���폜���Ă��ς��Ȃ�
		}

		/**********************************************************************************//**
			@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
			@details	ID:���X�g-40\n
						�R���p�C���G���[�Ő���\n
		*//***********************************************************************************/
		TEST(GetEndTest, TestGetEndItConst)
		{
			//#define TT_TEST_END_WHEN_NO_CONST
#if defined TT_TEST_END_WHEN_NO_CONST
			const DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();// �����ŃG���[
#endif //TT_TEST_END_WHEN_NO_CONST
			SUCCEED();
		}



		//=================================== �����R���X�g�C�e���[�^�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-41\n
						�_�~�[�m�[�h���w���C�e���[�^���Ԃ�\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetEnd();

			EXPECT_EQ(true, (it == nullptr));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-42\n
						�����v�f���w���C�e���[�^���Ԃ�\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItOne)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };

			list.PushBack(data);

			DoublyLinkedList::ConstIterator it = list.GetCEnd();
			const RecordData itData = *it;

			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-43\n
						�����v�f���w���C�e���[�^���Ԃ�\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItAny)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };

			list.PushBack(data);
			list.PushBack(data2);

			DoublyLinkedList::ConstIterator it = list.GetCEnd();
			const RecordData itData = *it;

			EXPECT_EQ(2, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-44\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
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
			RecordData itData = *it;
			EXPECT_EQ(1, itData.m_score); // ������1�������琬��

			it = list.GetCBegin(); // �擪�ɑ}��
			list.Insert(it, data2);
			it = list.GetCEnd();
			itData = *it;
			EXPECT_EQ(1, itData.m_score); // ������1�������琬��

			it = list.GetCBegin();// ���Ԃɑ}��
			++it;
			list.Insert(it, data3);
			it = list.GetCEnd();
			itData = *it;
			EXPECT_EQ(1, itData.m_score); // ������1�������琬��


			it = list.GetCEnd();// �����ɑ}��
			list.Insert(it, data4);
			it = list.GetCEnd();
			itData = *it;
			EXPECT_EQ(1, itData.m_score); // ������3�������琬��
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
			@details	ID:���X�g-45\n
						�����v�f���w���C�e���[�^���Ԃ�\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
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

			DoublyLinkedList::ConstIterator it = list.GetCBegin(); //�擪���폜
			list.Remove(it);
			it = list.GetCEnd();
			RecordData itData = *it;
			EXPECT_EQ(4, itData.m_score);

			it = list.GetCBegin(); //�擪����2�Ԗڂ��폜
			++it;
			list.Remove(it);
			it = list.GetCEnd();
			itData = *it;
			EXPECT_EQ(4, itData.m_score);

			it = list.GetCEnd(); //�������폜
			list.Remove(it);
			it = list.GetCEnd();
			itData = *it;
			EXPECT_EQ(4, itData.m_score); // �����C�e���[�^���폜���Ă��ς��Ȃ�
		}

		/**********************************************************************************//**
			@brief		const�̃��\�b�h�ł��邩
			@details	ID:���X�g-46\n
						�R���p�C�����ʂ�ΐ���\n
		*//***********************************************************************************/
		TEST(GetEndTestConst, TestGetEndItConst)
		{
#define TT_TEST_END_WHEN_CONST
#if defined TT_TEST_END_WHEN_CONST
			const DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetCEnd();
#endif //TT_TEST_END_WHEN_CONST
			SUCCEED();
		}

	}
	namespace chapter2
	{
		//===================================�C�e���[�^�̎w���v�f�̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-0\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestNoReference)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			RecordData itData = *it;

			EXPECT_EQ(true, it == nullptr) << "[Assert�����Ő���]";
		}

		/**********************************************************************************//**
			@brief		Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
			@details	ID:���X�g-1\n
						�����ɍēx�Ăяo���A�l���ύX����Ă��邱�Ƃ��m�F\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestAssignIt)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
			RecordData itData = *it;
			itData = data2;

			EXPECT_EQ(2, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
			@details	ID:���X�g-2\n
						�R���p�C���G���[�ɂȂ邱�Ƃ��`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestAssignItConst)
		{
		}
		TEST(GetEndTestConst, TestGetEndItConst)
		{
//#define TT_TEST_ITE_ASSIGN_CONST
#if defined TT_TEST_ITE_ASSIGN_CONST
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator it = list.GetBegin();
			RecordData data{ 1, "a" };
			*it = data;
#endif //TT_TEST_ITE_ASSIGN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-3\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestEmptyBegin)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			RecordData itData = *it;

			EXPECT_EQ(true, it == nullptr) << "[Assert�����Ő���]";
		}

		/**********************************************************************************//**
			@brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-4\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestEmptyEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			RecordData itData = *it;

			EXPECT_EQ(true, it == nullptr) << "[Assert�����Ő���]";
		}

		//===================================�C�e���[�^�����X�g�̖����Ɍ������ĂЂƂi�߂�===================================

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-5\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestNoReference)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			++it;
		}

		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-6\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestEmptyBegin)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			++it;
		}

		/**********************************************************************************//**
			@brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-7\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGoEndTest, TestEmptyEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();
			++it;
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
			@details	ID:���X�g-8\n
						���̗v�f���w��\n
						���X�g�̖�������擪�܂ŌĂяo�����s���A���҂���Ă���v�f���i�[����Ă��邩���m�F\n
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
			++it;
			itData = *it;
			EXPECT_EQ(2, itData.m_score);
			++it;
			itData = *it;
			EXPECT_EQ(3, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-9\n
						���̗v�f���w��\n
						�C���N�������g�Ăяo�����̒l�ƁA�C���N�������g���s��̒l�̗������m�F\n
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
			++it;
			itData = *it;
			EXPECT_EQ(2, itData.m_score);
			++it;
			itData = *it;
			EXPECT_EQ(3, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-10\n
						���̗v�f���w��\n
						�C���N�������g�Ăяo�����̒l�ƁA�C���N�������g���s��̒l�̗������m�F\n
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
			it++;
			itData = *it;
			EXPECT_EQ(2, itData.m_score);
			it++;
			itData = *it;
			EXPECT_EQ(3, itData.m_score);
		}


		//===================================�C�e���[�^�����X�g�̐擪�Ɍ������ĂЂƂi�߂�===================================

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
			@details	ID:���X�g-11\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestNoReference)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();
			--it;
		}

		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-12\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestEmptyBegin)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();
			--it;
		}

		/**********************************************************************************//**
			@brief		�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
			@details	ID:���X�g-13\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestEmptyEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();
			--it;
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
			@details	ID:���X�g-14\n
						�O�̗v�f���w��\n
						���X�g�̖�������擪�܂ŌĂяo�����s���A���҂���Ă���v�f���i�[����Ă��邩���m�F\n
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
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			--it;
			itData = *it;
			EXPECT_EQ(2, itData.m_score);
			--it; 
			itData = *it;
			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�O�u�C���N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-15\n
						���̗v�f���w��\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestPrefIncrement)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			DoublyLinkedList::Iterator it = list.GetEnd();
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			--it;
			itData = *it;
			EXPECT_EQ(2, itData.m_score);
			--it;
			itData = *it;
			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		��u�C���N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-16\n
						���̗v�f���w��\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F\n
		*//***********************************************************************************/
		TEST(IteratorGoBeginTest, TestBackIncrement)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			DoublyLinkedList::Iterator it = list.GetEnd();
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			it--;
			itData = *it;
			EXPECT_EQ(2, itData.m_score);
			it--;
			itData = *it;
			EXPECT_EQ(1, itData.m_score);
		}

		//===================================�C�e���[�^�̃R�s�[���s��===================================

		/**********************************************************************************//**
			@brief		ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
			@details	ID:���X�g-17\n
						�R���p�C���G���[�ɂȂ邱�Ƃ��m�F����B�����e�X�g�����Ȃ��Ă悢�B\n
		*//***********************************************************************************/
		TEST(IteratorCopyTest, TestConstError)
		{
			//#define TT_TEST_COPY_WHEN_CONST
#if defined TT_TEST_COPY_WHEN_CONST
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator cit = list.GetBegin();
			DoublyLinkedList::Iterator cit = cit;
#endif //TT_TEST_COPY_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
			@details	ID:���X�g-18\n
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


		//===================================�C�e���[�^�̑�����s��===================================

		/**********************************************************************************//**
			@brief		Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
			@details	ID:���X�g-19\n
						�R���p�C���G���[�ɂȂ邱�Ƃ��m�F����B�����e�X�g�����Ȃ��Ă悢�B\n
		*//***********************************************************************************/
		TEST(IteratorAssignTest, TestConstError)
		{
			//#define TT_TEST_ASSIGN_WHEN_CONST
#if defined TT_TEST_ASSIGN_WHEN_CONST
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator cit = list.GetBegin();
			DoublyLinkedList::Iterator it = list.GetBegin();
			it = cit; // �����ŃG���[
#endif //TT_TEST_ASSIGN_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
			@details	ID:���X�g-20\n
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


		//===================================�ӂ��̃C�e���[�^������̂��̂ł��邩��r===================================

		/**********************************************************************************//**
			@brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
			@details	ID:���X�g-21\n
						TRUE�Ő���\n
		*//***********************************************************************************/
		TEST(IteratorEqualTest, TestEqualEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = list.GetEnd();

			EXPECT_EQ(true, it == it2);
		}

		/**********************************************************************************//**
			@brief		����̃C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-22\n
						TRUE�Ő���\n
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
			@brief		�قȂ�C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-23\n
						FALSE�Ő���\n
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


		//===================================�ӂ��̃C�e���[�^���قȂ���̂ł��邩��r===================================

		/**********************************************************************************//**
			@brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
			@details	ID:���X�g-24\n
		*//***********************************************************************************/
		TEST(IteratorDiffTest, TestDiffEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = list.GetEnd();

			EXPECT_EQ(true, it != it2);
		}

		/**********************************************************************************//**
			@brief		����̃C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-25\n
		*//***********************************************************************************/
		TEST(IteratorDiffTest, TestDiff)
		{
			DoublyLinkedList list;
			RecordData data{ 1, "a" };
			list.PushBack(data);
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = list.GetBegin();

			EXPECT_EQ(true, it != it2);
		}

		/**********************************************************************************//**
			@brief		�قȂ�C�e���[�^���r�����ۂ̋���
			@details	ID:���X�g-26\n
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