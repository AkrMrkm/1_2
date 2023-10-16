/**
* @file manualTest.cpp
* @brief �蓮�e�X�g
* @author ����P
* @date 2023/10/16/11:00
* @details �ۑ�1_2�u�o�������X�g�̍Ď����v
*/

#include "pch.h"
#include "manualTest.h"
#include "../DoubleList1_2/doublyLinkedList.h"


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
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList list;
	EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
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
#if defined TT_TEST_INSERT_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetCBegin();
	RecordData data{ 1, "a" };
	list.Insert(it, data);//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		��const�̃��\�b�h�ł��邩
	@details	ID:���X�g-22\

				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(RemoveTest, TestRemoveToWhenConst)
{
#if defined TT_TEST_REMOVE_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetCBegin();
	list.Remove(it); // �����ŃG���[
#endif //TT_TEST_REMOVE_WHEN_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	@details	ID:���X�g-28\n
				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(GetBegin, TestGetBeginItConst)
{
#if defined TT_TEST_BEGIN_WHEN_NO_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetBegin();// �����ŃG���[
#endif //TT_TEST_BEGIN_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��\�b�h�ł��邩
	@details	ID:���X�g-34\n
				�R���p�C�����ʂ�ΐ���\n
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
	@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	@details	ID:���X�g-40\n
				�R���p�C���G���[�Ő���\n
*//***********************************************************************************/
TEST(GetEndTest, TestGetEndItConst)
{
#if defined TT_TEST_END_WHEN_NO_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetEnd();// �����ŃG���[
#endif //TT_TEST_END_WHEN_NO_CONST
	SUCCEED();
}



/**********************************************************************************//**
	@brief		const�̃��\�b�h�ł��邩
	@details	ID:���X�g-46\n
				�R���p�C�����ʂ�ΐ���\n
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
	@brief		ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
	@details	ID:���X�g-2\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B\n
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



//===================================�C�e���[�^�̃R�s�[���s��===================================

/**********************************************************************************//**
	@brief		ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
	@details	ID:���X�g-17\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F����B�����e�X�g�����Ȃ��Ă悢�B\n
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




//===================================�C�e���[�^�̑�����s��===================================

/**********************************************************************************//**
	@brief		Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
	@details	ID:���X�g-19\n
				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F����B�����e�X�g�����Ȃ��Ă悢�B\n
*//***********************************************************************************/
TEST(IteratorAssignTest, TestConstError)
{
#if defined TT_TEST_ASSIGN_WHEN_CONST
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator cit = list.GetBegin();
	DoublyLinkedList::Iterator it = list.GetBegin();
	it = cit; // �����ŃG���[
#endif //TT_TEST_ASSIGN_WHEN_CONST
	SUCCEED();
}