#pragma once
/**
* @file manualTest.h
* @brief 手動テストヘッダー
* @author 村上輝
* @date 2023/10/16/11:00
* @details 課題1_2「双方向リストの再実装」
*/
#if !defined ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___
#define      ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___

//--------------------------------------------------------------------------------
// マクロ定義
//--------------------------------------------------------------------------------
// コンパイル関連手動テスト(リスト)

// リスト0-8
//コンパイルが通れば成功
#define TT_TEST_GET_DATA_NUM_WHEN_CONST

// リスト0-15
//コンパイルエラーで成功
//#define TT_TEST_INSERT_WHEN_CONST

// リスト0-22
//コンパイルエラーで成功
//#define TT_TEST_REMOVE_WHEN_CONST

// リスト0-28
//コンパイルエラーで成功
//#define TT_TEST_BEGIN_WHEN_NO_CONST

// リスト0-34
//コンパイルが通れば成功
#define TT_TEST_BEGIN_WHEN_CONST

// リスト0-40
//コンパイルエラーで成功
//#define TT_TEST_END_WHEN_NO_CONST

// リスト0-46
//コンパイルが通れば成功
#define TT_TEST_END_WHEN_CONST

// リスト1-2
//コンパイルエラーで成功
//#define TT_TEST_ITE_ASSIGN_CONST

// リスト1-17
//コンパイルエラーで成功
//#define TT_TEST_COPY_WHEN_CONST

// リスト1-19
//コンパイルエラーで成功
//#define TT_TEST_ASSIGN_WHEN_CONST



#endif // ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___