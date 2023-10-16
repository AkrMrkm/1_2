/**
* @file doublyLinkedList.h
* @brief 双方向リストクラス
* @author 村上輝
* @date 2023/10/16/11:00
* @details 課題1_2「双方向リストの再実装」
*/

#pragma once

#include <assert.h>

/**
* @brief 成績データ
*/
struct RecordData
{
	//! スコア
	int m_score;

	//! 名前
	std::string m_name; 
};

/**
* @brief 双方向リストクラス
*/
class DoublyLinkedList
{
private:

	/**
	* @brief ノード
	*/
	struct Node
	{
		//! 前ノード
		Node* m_prev;

		//! 次ノード
		Node* m_next;

		//! 成績データ
		RecordData m_data;

		/**
		* @brief コンストラクタ
		*/
		Node() : m_prev(nullptr), m_next(nullptr), m_data() {}
		Node(RecordData data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

public:

	/**
	* @brief コンストイテレータクラス
	* @details 双方向リストクラスのインナークラス
	*/
	class ConstIterator 
	{
	public:
		//! ノードへのポインタ
		Node* m_Node;

		//! リストのポインタ
		const DoublyLinkedList* m_List;

		/**
		* @brief コンストラクタ
		*/
		ConstIterator() : m_Node(nullptr), m_List(nullptr) {}
		ConstIterator(Node* node, const DoublyLinkedList* list) : m_Node(node), m_List(list) {}

		/**
		* @brief イテレータの先頭に向かってひとつ進める(前置)
		* @return 先頭にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		ConstIterator& operator--()
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode->m_next);
			m_Node = m_Node->m_prev;
			return *this;
		}

		/**
		* @brief イテレータの先頭に向かってひとつ進める(後置)
		* @return 先頭にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		ConstIterator operator--(int)
		{
			assert(this->m_Node != nullptr); // ノードの参照が無かったらassert
			assert(this->m_Node != m_List->m_DummyNode); // リストが空orダミーノードであったら
			ConstIterator ci = *this;
			m_Node = m_Node->m_prev;
			return ci;
		}

		/**
		* @brief イテレータの末尾に向かってひとつ進める(前置)
		* @return 末尾にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		ConstIterator& operator++()
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode);
			m_Node = m_Node->m_next;
			return *this;
		}

		/**
		* @brief イテレータの末尾に向かってひとつ進める(後置)
		* @return 末尾にひとつ進めたイテレータを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		ConstIterator operator++(int)
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode);
			ConstIterator ci = *this;
			m_Node = m_Node->m_next;
			return ci;
		}

		/**
		* @brief イテレータの指す要素を取得する(const)
		* @return イテレータの指す成績データを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		const RecordData& operator*() const 
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode);
			return this->m_Node->m_data; 
		}

		/**
		* @brief コピーコンストラクタ
		*/
		ConstIterator(const ConstIterator& ci) : m_Node(ci.m_Node), m_List(ci.m_List){}

		/**
		* @brief 代入を行う* 
		* @param[in] ci 代入するイテレータ
		* @details イテレータのノードを代入する
		*/
		ConstIterator& operator=(const ConstIterator& ci)
		{
			m_Node = ci.m_Node;
			return *this;
		}

		/**
		* @brief 同一か比較する
		* @param[in] ci 同一か比較するイテレータ
		* @return イテレータの指す要素が同一であればtrueを返す
		*/
		bool operator==(const ConstIterator& ci)
		{
			return (m_Node == ci.m_Node);
		}

		/**
		* @brief 異なるか比較する
		* @param[in] ci 異なるか比較するイテレータ
		* @return イテレータの指す要素が異なればtrueを返す
		*/
		bool operator!=(const ConstIterator& ci)
		{
			return (m_Node != ci.m_Node);
		}
	};

	/**
	* @brief イテレータクラス
	* @details コンストイテレータクラスの派生クラス
	*/
	class Iterator : public ConstIterator
	{
	public:
		/**
		* @brief コンストラクタ
		*/
		Iterator() : ConstIterator() {}
		Iterator(Node* n, DoublyLinkedList* list) : ConstIterator(n, list) {}

		/**
		* @brief イテレータの指す要素を取得する(非const)
		* @return イテレータの指す成績データを返す
		* @details ノードの参照が無かったらorダミーノードであったらassert
		*/
		RecordData& operator*() 
		{
			assert(this->m_Node != nullptr);
			assert(this->m_Node != m_List->m_DummyNode);
			return this->m_Node->m_data; 
		}
	};


	/**
	* @brief 双方向リストクラスのコンストラクタ
	* @details データ数、ダミーノードを初期化\n
			   リストが空の場合、ダミーノードの前後はダミーノード自身を参照\n
	*/
	DoublyLinkedList() : m_DataNum(0) 
	{
		m_DummyNode = new Node();
		m_DummyNode->m_next = m_DummyNode;
		m_DummyNode->m_prev = m_DummyNode;
	}

	/**
	* @brief 双方向リストクラスのデストラクタ
	* @details 先頭から末尾までdelete
	*/
	virtual ~DoublyLinkedList()
	{
		if (m_DataNum == 0) return;
		while(m_DataNum > 0)
		{
			Node* temp = m_DummyNode;
			m_DummyNode = m_DummyNode->m_next;
			delete temp;
			m_DataNum--;
		}
	}

	/**
	* @brief データ数の取得
	* @return リストのデータの総数を返す
	*/
	int GetDataNum() const
	{
		return m_DataNum;
	}

	/**
	* @brief データの挿入
	* @param[in] it 挿入したい位置のイテレータ
	* @param[in] data 挿入したい成績データ
	* @return bool(挿入が成功すればtrue、失敗すればfalse)
	* @details イテレータの指すノードの前に挿入する
	*/
	bool Insert(ConstIterator& it, RecordData& data)
	{
		Node* newNode = new Node(data); // 新ノード

		if (m_DataNum == 0) // 要素数が０であったら
		{
			// ダミーノードを一つ目のノードと繋げる
			newNode->m_prev = m_DummyNode;
			newNode->m_next = m_DummyNode;

			m_DummyNode->m_next = newNode;
			m_DummyNode->m_prev = newNode;

			// データ数を増やす
			m_DataNum++;

			return true;
		}

		if (it.m_List != this) return false; // イテレータが別のリストの要素を指すイテレータであったらreturn

		Node* itNode = it.m_Node; // イテレータの指すノード

		// 新ノードの前ノードをイテレータの指す前ノードに。
		newNode->m_prev = itNode->m_prev;

		// 新ノードの次ノードをイテレータの指すノードに。
		newNode->m_next = itNode;
		
		// イテレータの指すノードの前ノードの次のノードに新ノードを格納
		// (イテレータノードと前ノードの間に格納)
		itNode->m_prev->m_next = newNode;

		// イテレータの指すノードの前ノードに新ノードを格納、これでデータが繋がる
		itNode->m_prev = newNode;

		// データ数を増やす
		m_DataNum++;

		return true;
	}

	/**
	* @brief データの追加
	* @param[in] data 追加したい成績データ
	* @details 末尾にデータの追加
	*/
	void PushBack(RecordData& data)
	{
		Node* newNode = new Node(data);

		// リストが空っぽだったら
		if (m_DataNum == 0)
		{
			// ダミーノードを一つ目のノードと繋げる
			newNode->m_prev = m_DummyNode;
			newNode->m_next = m_DummyNode;

			m_DummyNode->m_next = newNode;
			m_DummyNode->m_prev = newNode;

			m_DataNum++;
			return;
		}

		newNode->m_prev = m_DummyNode->m_prev;
		newNode->m_next = m_DummyNode;
		newNode->m_prev->m_next = newNode;
		m_DummyNode->m_prev = newNode;

		m_DataNum++;

		return;
	}

	/**
	* @brief データの削除
	* @param[in] it 削除したい位置のイテレータ
	* @return 削除に失敗したらfalse、成功したらtrueを返す
	* @details イテレータの指すノードを削除\n
				データ数が0、イテレータの指すノードがダミーノード、別リストを指すイテレータであれば何も行わない\n
	*/
	bool Remove(ConstIterator& it)
	{
		Node* itNode = it.m_Node; // イテレータの指すノード
		if (m_DataNum == 0) return false;
		if (itNode == m_DummyNode) return false;
		if (it.m_List != this) return false; // イテレータが別のリストの要素を指すイテレータであったらreturn


		itNode->m_prev->m_next = itNode->m_next;
		itNode->m_next->m_prev = itNode->m_prev;

		delete itNode;
		m_DataNum--;
		return true;
	}

	/**
	* @brief 先頭イテレータ取得
	* @return ダミーノードの次のノード(先頭のイテレータを返す)
	*/
	Iterator GetBegin() 
	{
		return Iterator(m_DummyNode->m_next, this);
	}

	/**
	* @brief 先頭コンストイテレータ取得
	* @return ダミーノードの次のノード(先頭のコンストイテレータを返す)
	*/
	ConstIterator GetCBegin() const
	{
		return ConstIterator(m_DummyNode->m_next, this);
	}

	/**
	* @brief 末尾イテレータ取得
	* @return ダミーノードを返す
	*/
	Iterator GetEnd() 
	{
		return Iterator(m_DummyNode, this);
	}

	/**
	* @brief 末尾コンストイテレータ取得
	* @return ダミーノードを返す
	*/
	 ConstIterator GetCEnd() const
	{
		return ConstIterator(m_DummyNode, this);
	}

private:

	//! ダミーノード
	Node* m_DummyNode;

	//! データ数
	int m_DataNum{};
};