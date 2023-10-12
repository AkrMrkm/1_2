//==========================
//�o�������X�g�Ď���
//==========================
//2023/10/12/15:00
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
			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_TRUE(list.Insert(it, data));
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
			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_TRUE(list.Insert(it, data));
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

			list.PushBack(data);

			DoublyLinkedList::Iterator it = list.GetEnd();

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

		// 8�̓}�j���A���e�X�g

		//=================================== �f�[�^�̑}�� ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
			@details	ID:���X�g-9\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ����B\n
						�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N���邱��\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToEmpty)
		{
			RecordData data{ 1, "a" };
			// �擪�ɑ}��
			{
				DoublyLinkedList list;
				DoublyLinkedList::Iterator it = list.GetBegin();
				EXPECT_EQ(true, list.Insert(it, data));
				EXPECT_EQ(1, list.GetDataNum());
			}

			// �����ɑ}��
			{
				DoublyLinkedList list;
				DoublyLinkedList::Iterator it = list.GetEnd();
				EXPECT_EQ(true, list.Insert(it, data));
				EXPECT_EQ(1, list.GetDataNum());
			}
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

			ASSERT_TRUE(list.Insert(it, data3));

			//�擪�������v�f����ԖڂɂȂ��Ă����琬��(���Ԃ�3,1,2�ɂȂ��Ă����琬��)
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score);
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
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

			//���Ԃ�1,2,3�ɂȂ��Ă���ΐ���
			it = list.GetBegin();
			RecordData itData = *it;
			EXPECT_EQ(1, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(2, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(3, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋����e�X�g
			@details	ID:���X�g-12\n
						TRUE�Ő���\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩\n
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
			itData = *(++it);
			EXPECT_EQ(2, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(4, (itData.m_score));
			itData = *(++it);
			EXPECT_EQ(3, (itData.m_score));
		}

		/**********************************************************************************//**
			@brief		ConstIterator���w�肵�đ}���������ۂ̋����e�X�g
			@details	ID:���X�g-13\n
						TRUE�Ő���\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩�B\n
						�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���邱��\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToOtherConst)
		{
			DoublyLinkedList list;

			RecordData data{ 1, "a" };
			RecordData data2{ 2, "a" };
			RecordData data3{ 3, "a" };

			RecordData data4{ 0, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);

			// �擪�ɑ}��
			{
				DoublyLinkedList::ConstIterator it = list.GetBegin();
				list.Insert(it, data4);

				//���Ԃ�0123�ɂȂ��Ă���TRUE
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

			// 3�Ԗڂɑ}��
			{
				DoublyLinkedList::ConstIterator it = list.GetBegin();
				++it;
				++it;
				list.Insert(it, data4);
				//���Ԃ�01023�ɂȂ��Ă���TRUE
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

			// �����ɑ}��
			{
				DoublyLinkedList::ConstIterator it = list.GetEnd();
				list.Insert(it, data4);
				//���Ԃ�010230�ɂȂ��Ă���TRUE
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

			//���X�g�̎Q�Ƃ������C�e���[�^
			DoublyLinkedList::Iterator it;
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

		// 15�̓}�j���A���e�X�g

		//=================================== �f�[�^�̍폜 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
			@details	ID:���X�g-16\n
						FALSE�Ő���\n
						�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N���邱��\n
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
			itData = *(++it);
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
			itData = *(++it);
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
			RecordData data4{ 4, "a" };
			RecordData data5{ 5, "a" };

			//�v�f��}��
			list.PushBack(data);
			list.PushBack(data2);
			list.PushBack(data3);
			list.PushBack(data4);
			list.PushBack(data5);

			// �擪���폜
			{
				DoublyLinkedList::ConstIterator it = list.GetCBegin();
				list.Remove(it);

				it = list.GetBegin();
				RecordData itData = *it;

				//���Ԃ�2345�ɂȂ��Ă���ΐ���
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(3, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(5, itData.m_score);
			}

			// 2�Ԗڂ��폜
			{
				DoublyLinkedList::ConstIterator it = list.GetCBegin();
				++it;
				list.Remove(it);

				it = list.GetBegin();
				RecordData itData = *it;

				//���Ԃ�245�ɂȂ��Ă���ΐ���
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(5, itData.m_score);
			}

			// �������폜
			{
				DoublyLinkedList::ConstIterator it = list.GetCEnd();
				list.Remove(it);

				it = list.GetBegin();
				RecordData itData = *it;

				//���Ԃ�24�ɂȂ��Ă���ΐ���
				EXPECT_EQ(2, itData.m_score);
				itData = *(++it);
				EXPECT_EQ(4, itData.m_score);
			}
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

			// �Q�Ƃ̖����C�e���[�^��n�����Ƃ�
			{
				DoublyLinkedList::Iterator it;
				list.Remove(it);
				//�f�[�^�̑������ς���Ă��Ȃ���ΐ���
				EXPECT_EQ(oldNum, list.GetDataNum());
			}

			// �ʂ̃��X�g�̃C�e���[�^��n�����Ƃ�
			{
				DoublyLinkedList list2;
				list2.PushBack(data);
				DoublyLinkedList::Iterator it = list2.GetBegin();
				list.Remove(it);
				//�f�[�^�̑������ς���Ă��Ȃ���ΐ���
				EXPECT_EQ(oldNum, list.GetDataNum());
			}
		}

		// 22�̓}�j���A���e�X�g


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

			// �_�~�[�m�[�h�Ȃ̂ŁAnull�ł���ΐ���
			EXPECT_EQ(true, it == nullptr);
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
			//data2��2�������Ă����OK
			it = list.GetBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//�����ɓ����
			it = list.GetEnd();
			list.Insert(it, data4);
			
			//data2��2�������Ă����OK
			it = list.GetBegin();
			itData = *it;
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

		// 28�̓}�j���A���e�X�g


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

			// �_�~�[�m�[�h�Ȃ̂ŁAnull�ł���ΐ���
			EXPECT_EQ(true, it == nullptr);
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
			//data2��2�������Ă����OK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score));

			//�����ɓ����
			it = list.GetCEnd();
			list.Insert(it, data4);

			//data2��2�������Ă����OK
			it = list.GetCBegin();
			itData = *it;
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

			//�擪�̗v�f���폜
			it = list.GetCBegin();
			list.Remove(it);
			it = list.GetCBegin();
			RecordData itData = *it;
			//data2��2�������Ă����OK
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);

			//�����̗v�f���폜
			it = list.GetCBegin();
			++it;
			list.Remove(it);
			//data2��2�������Ă����OK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);

			//�����̗v�f���폜
			it = list.GetCEnd();
			list.Remove(it);
			//data2��2�������Ă����OK
			it = list.GetCBegin();
			itData = *it;
			EXPECT_EQ(2, (itData.m_score)) << (itData.m_score);
		}

		// 34�̓}�j���A���e�X�g


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

			// �_�~�[�m�[�h�Ȃ̂ŁAnull�ł���ΐ���
			EXPECT_EQ(true, it == nullptr);
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


			// �����C�e���[�^�̗v�f�f�[�^���ŏ��ɓ��ꂽ�f�[�^�ł͂Ȃ��A�����C�e���[�^�̑O�̗v�f���ŏ��ɓ��ꂽ�l�ł������琬��
			RecordData itData = *(it);
			EXPECT_NE(1, itData.m_score); // !=
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // ==
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

			// �����C�e���[�^�̗v�f�f�[�^���Ō�ɓ��ꂽ�f�[�^�ł͂Ȃ��A�����C�e���[�^�̑O�̗v�f���Ō�ɓ��ꂽ�l�ł������琬��
			RecordData itData = *(it);
			EXPECT_NE(1, itData.m_score); // !=
			EXPECT_NE(2, itData.m_score); // !=

			//�����C�e���[�^�̑O�͖����v�f���w��
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score); // ==
			//�����C�e���[�^�̌��͐擪�v�f���w��
			it = list.GetEnd();
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score); // ==
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
			RecordData itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��1�������琬��

			it = list.GetBegin(); // �擪�ɑ}��
			list.Insert(it, data2);
			it = list.GetEnd(); 
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��1�������琬��

			it = list.GetBegin();// ���Ԃɑ}��
			++it;
			list.Insert(it, data3);
			it = list.GetEnd();
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��1�������琬��


			it = list.GetEnd();// �����ɑ}��
			list.Insert(it, data4);
			it = list.GetEnd();
			itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
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
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��

			it = list.GetBegin(); //�擪����2�Ԗڂ��폜
			++it;
			list.Remove(it);
			it = list.GetEnd();
			itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��

			it = list.GetEnd(); //�������폜
			list.Remove(it);
			it = list.GetEnd();
			itData = *(--it); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			EXPECT_EQ(4, itData.m_score); // �����C�e���[�^�̓_�~�[�m�[�h�Ȃ̂ŕς��Ȃ�

			it = list.GetEnd(); //�����̂ЂƂO�̗v�f���폜
			list.Remove(--it);
			it = list.GetEnd();
			itData = *(--it); // �����̑O�v�f�f�[�^�̃X�R�A��2�������琬��
			EXPECT_EQ(2, itData.m_score);
		}

		//40�̓}�j���A���e�X�g


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

			// �_�~�[�m�[�h�Ȃ̂ŁAnull�ł���ΐ���
			EXPECT_EQ(true, it == nullptr);
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


			// �����C�e���[�^�̗v�f�f�[�^���ŏ��ɓ��ꂽ�f�[�^�ł͂Ȃ��A�����C�e���[�^�̑O�̗v�f���ŏ��ɓ��ꂽ�l�ł������琬��
			RecordData itData = *(it);
			EXPECT_NE(1, itData.m_score); // !=
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // ==
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

			// �����C�e���[�^�̗v�f�f�[�^���Ō�ɓ��ꂽ�f�[�^�ł͂Ȃ��A�����C�e���[�^�̑O�̗v�f���Ō�ɓ��ꂽ�l�ł������琬��
			RecordData itData = *(it);
			EXPECT_NE(1, itData.m_score); // !=
			EXPECT_NE(2, itData.m_score); // !=

			//�����C�e���[�^�̑O�͖����v�f���w��
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score); // ==
			//�����C�e���[�^�̌��͐擪�v�f���w��
			it = list.GetEnd();
			itData = *(++it);
			EXPECT_EQ(1, itData.m_score); // ==
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
			RecordData itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��1�������琬��

			it = list.GetCBegin(); // �擪�ɑ}��
			list.Insert(it, data2);
			it = list.GetCEnd();
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��1�������琬��

			it = list.GetCBegin();// ���Ԃɑ}��
			++it;
			list.Insert(it, data3);
			it = list.GetCEnd();
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��1�������琬��


			it = list.GetCEnd();// �����ɑ}��
			list.Insert(it, data4);
			it = list.GetCEnd();
			itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
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

			// �擪���폜
			DoublyLinkedList::ConstIterator it = list.GetCBegin();
			list.Remove(it);
			it = list.GetCEnd();
			RecordData itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��

			it = list.GetCBegin(); //�擪����2�Ԗڂ��폜
			++it;
			list.Remove(it);
			it = list.GetCEnd();
			itData = *(--it);
			EXPECT_EQ(4, itData.m_score); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��

			it = list.GetCEnd(); //�������폜
			list.Remove(it);
			it = list.GetCEnd();
			itData = *(--it); // �����̑O�v�f�f�[�^�̃X�R�A��4�������琬��
			EXPECT_EQ(4, itData.m_score); // �����C�e���[�^�̓_�~�[�m�[�h�Ȃ̂ŕς��Ȃ�

			it = list.GetCEnd(); //�����̂ЂƂO�̗v�f���폜
			list.Remove(--it);
			it = list.GetCEnd();
			itData = *(--it); // �����̑O�v�f�f�[�^�̃X�R�A��2�������琬��
			EXPECT_EQ(2, itData.m_score);
		}

		//46�̓}�j���A���e�X�g
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
			DoublyLinkedList::Iterator it;

			EXPECT_DEATH(*it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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

			*it = data2; // �ʂ̃f�[�^����
			RecordData itData = *it;

			EXPECT_EQ(2, itData.m_score);
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

			EXPECT_DEATH(*it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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

			EXPECT_DEATH(*it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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
			DoublyLinkedList::Iterator it;

			EXPECT_DEATH(++it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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

			EXPECT_DEATH(++it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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

			EXPECT_DEATH(++it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
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
			itData = *(++it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(++it);
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
			itData = *(it++);
			EXPECT_EQ(1, itData.m_score);
			itData = *(it++);
			EXPECT_EQ(2, itData.m_score);
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

			EXPECT_DEATH(--it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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

			EXPECT_DEATH(--it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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

			EXPECT_DEATH(--it, ".*"); // ���X�g����Ȃ̂ŃA�T�[�g���������ăv���O�������ُ�I�����邱�Ƃ��m�F
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
			--it;
			RecordData itData = *it;
			EXPECT_EQ(3, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(2, itData.m_score);
			itData = *(--it);
			EXPECT_EQ(1, itData.m_score);
		}

		/**********************************************************************************//**
			@brief		�O�u�C���N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-15\n
						���̗v�f���w��\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F\n
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
			@brief		��u�C���N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
			@details	ID:���X�g-16\n
						���̗v�f���w��\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F\n
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

		//17�̓}�j���A���e�X�g

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

		//19�̓}�j���A���e�X�g

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

			EXPECT_EQ(false, it != it2);
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

			EXPECT_EQ(false, it != it2);
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