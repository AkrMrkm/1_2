#pragma once
//==========================
//双方向リスト再実装
//==========================
//2023/10/12/15:00
//作成者:村上輝
#include <assert.h>

// 成績データ
struct RecordData
{
	int m_score; // スコア
	std::string m_name; // 名前
};

//双方向リスト
class DoublyLinkedList
{
private:
	// ノード
	struct Node
	{
		Node* m_prev; // 前ノード
		Node* m_next; // 次ノード
		RecordData m_data; //成績データ

		Node() : m_prev(nullptr), m_next(nullptr), m_data() {}
		Node(RecordData data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

public:

	//コンストイテレータクラス
	class ConstIterator 
	{
	public:
		Node* m_Node; //ノードへのポインタ

		ConstIterator() : m_Node(nullptr) {}
		ConstIterator(Node* node) : m_Node(node) {}

		//イテレータの先頭に向かってひとつ進める
		ConstIterator& operator--()
		{
			assert(this->m_Node != nullptr); // ノードの参照が無かったらassert
			m_Node = m_Node->m_prev;
			return *this;
		}

		ConstIterator operator--(int) // 後置
		{
			assert(this->m_Node != nullptr); // ノードの参照が無かったらassert
			ConstIterator ci = *this;
			m_Node = m_Node->m_prev;
			return ci;
		}

		//イテレータの末尾に向かってひとつ進める
		ConstIterator& operator++()
		{
			assert(this->m_Node != nullptr); // ノードの参照が無かったらassert
			m_Node = m_Node->m_next;
			return *this;
		}

		ConstIterator operator++(int) // 後置
		{
			assert(this->m_Node != nullptr); // ノードの参照が無かったらassert
			ConstIterator ci = *this;
			m_Node = m_Node->m_next;
			return ci;
		}

		//イテレータの指す要素を取得する(const)
		const RecordData& operator*() const 
		{
			assert(this->m_Node != nullptr); // ノードの参照が無かったらassert
			return this->m_Node->m_data; 
		}

		//コピーコンストラクタ
		ConstIterator(const ConstIterator& ci) : m_Node(ci.m_Node){}

		//代入を行う
		ConstIterator& operator=(const ConstIterator& ci)
		{
			m_Node = ci.m_Node;
			return *this;
		}

		//同一か比較する
		bool operator==(const ConstIterator& ci)
		{
			return (m_Node == ci.m_Node);
		}

		//異なるか比較する
		bool operator!=(const ConstIterator& ci)
		{
			return (m_Node != ci.m_Node);
		}
	};

	//イテレータクラス
	class Iterator : public ConstIterator
	{
	public:
		// コンストラクタ
		Iterator() : ConstIterator() {}
		Iterator(Node* n) : ConstIterator(n) {}

		// イテレータの指す要素を取得する(非const)
		RecordData& operator*() 
		{
			assert(this->m_Node != nullptr); // ノードの参照が無かったらassert
			return this->m_Node->m_data; 
		}
	};


	//双方向リストのコンストラクタ
	DoublyLinkedList() : m_DummyNode(nullptr), m_DataNum(0) {}

	//デストラクタ
	virtual ~DoublyLinkedList() // 先頭から末尾までdelete
	{
		while (m_DummyNode != m_DummyNode)
		{
			Node* temp = m_DummyNode;
			m_DummyNode = m_DummyNode->m_next;
			delete temp;
		}
	}

	//データ数の取得
	int GetDataNum() const
	{
		return m_DataNum;
	}
	
	// データの挿入(イテレータの指すノードの前に挿入)
	bool Insert(ConstIterator& it, RecordData& data)
	{
		Node* newNode = new Node(data); // 新ノード

		if (m_DataNum == 0) // 要素数が０であったら
		{
			// ダミーノードを作り、一つ目のノードと繋げる
			m_DummyNode = new Node();

			newNode->m_prev = m_DummyNode;
			newNode->m_next = m_DummyNode;

			m_DummyNode->m_next = newNode;
			m_DummyNode->m_prev = newNode;

			// データ数を増やす
			m_DataNum++;

			return true;
		}

		if (!CheckThisData(it)) return false; // イテレータが別のリストの要素を指すイテレータであったらreturn

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

	// データの追加
	bool PushBack(RecordData& data)
	{
		Node* newNode = new Node(data);

		// リストが空っぽだったら
		if (m_DataNum == 0)
		{
			// ダミーノードを作り、一つ目のノードと繋げる
			m_DummyNode = new Node();

			newNode->m_prev = m_DummyNode;
			newNode->m_next = m_DummyNode;

			m_DummyNode->m_next = newNode;
			m_DummyNode->m_prev = newNode;

			m_DataNum++;
			return true;
		}

		newNode->m_prev = m_DummyNode->m_prev;
		newNode->m_next = m_DummyNode;
		newNode->m_prev->m_next = newNode;
		m_DummyNode->m_prev = newNode;

		m_DataNum++;

		return true;
	}

	// データの削除
	bool Remove(ConstIterator& it)
	{
		if (m_DataNum == 0) return false;
		if (it == m_DummyNode) return false;
		if (!CheckThisData(it)) return false; // イテレータが別のリストの要素を指すイテレータであったらreturn

		Node* itNode = it.m_Node; // イテレータの指すノード

		itNode->m_prev->m_next = itNode->m_next;
		itNode->m_next->m_prev = itNode->m_prev;

		delete itNode;
		m_DataNum--;
		return true;
	}

	// 先頭イテレータ取得
	Iterator GetBegin() 
	{
		if(m_DummyNode == nullptr)
			return Iterator(nullptr);
		return Iterator(m_DummyNode->m_next);
	}

	// 先頭コンストイテレータ取得
	ConstIterator GetCBegin() const
	{
		if (m_DummyNode == nullptr)
			return ConstIterator(nullptr);
		return ConstIterator(m_DummyNode->m_next);
	}

	// 末尾イテレータ取得
	Iterator GetEnd() 
	{
		if (m_DummyNode == nullptr)
			return Iterator(nullptr);
		return Iterator(m_DummyNode);
	}

	// 末尾コンストイテレータ取得
	ConstIterator GetCEnd() const
	{
		if (m_DummyNode == nullptr)
			return ConstIterator(nullptr);
		return ConstIterator(m_DummyNode);
	}

	// 引数のイテレータが指す要素がこのリストに存在する要素かどうかを判別する
	bool CheckThisData(ConstIterator& it)
	{
		Node* itNode = it.m_Node; // イテレータの指すノード

		Node* temp = m_DummyNode;

		while (temp != itNode)
		{
			temp = temp->m_next;
			if (temp == m_DummyNode)
				return false;
		}
		return true;
	}

private:

	Node* m_DummyNode; // ダミーノード
	int m_DataNum{}; // データ数
};