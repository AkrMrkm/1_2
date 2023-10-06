#pragma once
//==========================
//双方向リスト再実装
//==========================
//2023/10/06/17:00
//作成者:村上輝

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

		Node(RecordData data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

public:

	//コンストイテレータクラス
	class ConstIterator 
	{
	public:
		Node* m_Node; //ノードへのポインタ
	public:

		ConstIterator(Node* node) : m_Node(node) {}

		//イテレータの先頭に向かってひとつ進める
		ConstIterator& operator--()
		{
			m_Node = m_Node->m_prev;
			return *this;
		}

		ConstIterator operator--(int) // 後置
		{
			ConstIterator ci = *this;
			m_Node = m_Node->m_prev;
			return ci;
		}

		//イテレータの末尾に向かってひとつ進める
		ConstIterator& operator++()
		{
			m_Node = m_Node->m_next;
			return *this;
		}

		ConstIterator operator++(int) // 後置
		{
			ConstIterator ci = *this;
			m_Node = m_Node->m_next;
			return ci;
		}

		//イテレータの指す要素を取得する(const)
		const RecordData& operator*() const { return this->m_Node->m_data; }

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
			return (m_Node == ci.m_Node);
		}
	};

	//イテレータクラス
	class Iterator : public ConstIterator
	{
	public:
		// コンストラクタ
		Iterator(Node* n) : ConstIterator(n) {}

		// イテレータの指す要素を取得する(非const)
		const RecordData& operator*() { return this->m_Node->m_data; }
	};

	//双方向リストのコンストラクタ
	DoublyLinkedList() : m_DummyNode(nullptr), m_DataNum(0) {}

	//デストラクタ
	virtual ~DoublyLinkedList() // 先頭から末尾までdelete
	{
		while (m_DummyNode != nullptr)
		{
			Node* temp = m_DummyNode;
			m_DummyNode = m_DummyNode->m_next;
			delete temp;
		}
	}

	//データ数の取得
	int GetDataNum() const { return m_DataNum; }
	
	// データの挿入(イテレータの指すノードの前に挿入)
	bool Insert(ConstIterator& it, RecordData& data)
	{
		Node* itNode = it.m_Node; // イテレータの指すノード

		if (itNode == nullptr) // イテレータがnullだったらプッシュバック
		{
			PushBack(data);
			return true;
		}

		Node* newNode = new Node(data); // 新ノード
		newNode->m_prev = itNode->m_prev; // 新ノードの前ノードをイテレータの指す前ノードに。
		newNode->m_next = itNode; // 新ノードの次ノードをイテレータの指すノードに。

		 // イテレータの指すノードが先頭ではなかったら
		if (itNode->m_prev != nullptr)
		{
			// イテレータの指すノードの前ノードの次のノードに新ノードを格納
			// (イテレータノードと前ノードの間に格納)
			itNode->m_prev->m_next = newNode;
		}

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

		// リストが空っぽだったらダミーノードに新しいノードを入れる
		if (m_DataNum == 0)
		{
			m_DummyNode = newNode;
			m_DataNum++;

			return true;
		}

		// リストの末尾に新しいノードを入れる
		DoublyLinkedList::Iterator it = GetEnd();
		Node* tail = it.m_Node;

		tail->m_next = newNode;
		newNode->m_prev = tail;
		tail = newNode;

		m_DataNum++;
		return true;
	}

	// データの削除
	bool Remove(ConstIterator& it)
	{
		if (it == nullptr) return false;

		Node* itNode = it.m_Node; // イテレータの指すノード

		// 末尾ノードだったらreturn
		if (itNode->m_prev != nullptr && itNode->m_next == nullptr) return false;

		//データがひとつしかなかったらそのデータを削除
		if (itNode->m_prev == nullptr && itNode->m_next == nullptr)
		{
			m_DummyNode = nullptr;
			delete itNode;
			m_DataNum--;
			return true;
		}

		// 先頭イテレータではなかったら前ノードと次ノードを結ぶ
		if (itNode->m_prev != nullptr)
		{
			itNode->m_prev->m_next = itNode->m_next;
		}
		else // 先頭イテレータであったら先頭イテレータを次ノードに変更
		{
			m_DummyNode = itNode->m_next;
		}

		// 末尾イテレータではなかったら
		if (itNode->m_next != nullptr)
		{
			itNode->m_next->m_prev = itNode->m_prev;
		}
		else
		{
			DoublyLinkedList::Iterator it = GetEnd();
			Node* tail = it.m_Node;

			tail = itNode->m_prev;
		}

		delete itNode;
		m_DataNum--;
		return true;
	}

	// 先頭イテレータ取得
	Iterator GetBegin() 
	{
		Node* begin = m_DummyNode;
		if (begin == nullptr) return Iterator(nullptr);
		while (begin->m_prev != nullptr)
		{
			begin = begin->m_prev;
		}
		return Iterator(begin);
	}

	// 先頭コンストイテレータ取得
	ConstIterator GetCBegin() const
	{
		Node* begin = m_DummyNode;
		if (begin == nullptr) return Iterator(nullptr);
		while (begin->m_prev != nullptr)
		{
			begin = begin->m_prev;
		}
		return Iterator(begin);
	}

	// 末尾イテレータ取得
	Iterator GetEnd() 
	{
		Node* end = m_DummyNode;
		if (end == nullptr) return Iterator(nullptr);
		while (end->m_next != nullptr)
		{
			end = end->m_next;
		}
		return Iterator(end);
	}

	// 末尾コンストイテレータ取得
	ConstIterator GetCEnd() const
	{
		Node* end = m_DummyNode;
		if (end == nullptr) return ConstIterator(nullptr);
		while (end->m_next != nullptr)
		{
			end = end->m_next;
		}
		return ConstIterator(end);
	}

	// 全データを格納順に描画
	bool Draw()
	{
		if (m_DataNum == 0)
		{
			std::cout << "このリストにデータはありません。" << std::endl;
			return false;
		}

		Node* current = m_DummyNode; // イテレータの指すノード
		while (current != nullptr)
		{
			std::cout << " score : " << current->m_data.m_score << "   name : " << current->m_data.m_name << std::endl;
			current = current->m_next;
		}
		return true;
	}

private:

	Node* m_DummyNode; // ダミーノード
	int m_DataNum{}; // データ数
};