#pragma once
//==========================
//双方向リスト再実装
//==========================
//2023/10/05/17:00
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

		ConstIterator(Node* node) : m_Node(node) {}
		virtual ~ConstIterator() { delete m_Node; }

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
		~Iterator() { delete m_Node; }
		// イテレータの指す要素を取得する(非const)
		RecordData& operator*() { return this->m_Node->m_data; }
	};
	

	//双方向リストのコンストラクタ
	DoublyLinkedList() : m_Head(nullptr), m_DataNum(0) {}

	//デストラクタ
	virtual ~DoublyLinkedList() // 先頭から末尾までdelete
	{
		while (m_Head != nullptr)
		{
			Node* temp = m_Head;
			m_Head = m_Head->m_next;
			delete temp;
		}
	}

	//データ数の取得
	int GetDataNum() const { return m_DataNum; }
	
	// データの挿入(イテレータの指すノードの前に挿入)
	bool Insert(Iterator& it, RecordData& data)
	{
		Node* itNode = it.m_Node; // イテレータの指すノード
		if (itNode == nullptr || itNode->m_next == nullptr)
		{
			PushBack(data);
			return true;
		}

		Node* newNode = new Node(data); // 新ノード
		newNode->m_prev = itNode->m_prev; // 新ノードの前ノードをイテレータの指す前ノードに。
		newNode->m_next = itNode; // 新ノードの次ノードをイテレータの指すノードに。

		 // イテレータの指すノードが先頭だったら
		if (itNode->m_prev == nullptr)
		{
			// 先頭に新ノードを格納
			m_Head = newNode;
		}
		else
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
		if (m_Head == nullptr)
		{
			m_Head = newNode;

			return true;
		}

		Node* tail = m_Head;
		while (tail->m_next != nullptr)
		{
			tail = tail->m_next;
		}

		tail->m_next = newNode;
		newNode->m_prev = tail;
		tail = newNode;

		m_DataNum++;
		return true;
	}

	// データの削除
	bool Remove(Iterator& it)
	{
		if (it == nullptr)
		{
			return false;
		}
		Node* itNode = it.m_Node; // イテレータの指すノード

		if (itNode->m_prev != nullptr)
		{
			itNode->m_prev->m_next = itNode->m_next;
		}
		else
		{
			m_Head = itNode->m_next;
		}

		if (itNode->m_next != nullptr)
		{
			itNode->m_next->m_prev = itNode->m_prev;
		}
		else {
			Node* tail = m_Head;
			while (tail->m_next == nullptr)
			{
				tail = tail->m_next;
			}
			tail = itNode->m_prev;
		}

		delete itNode;
		m_DataNum--;
		return true;
	}

	// 先頭イテレータ取得
	Iterator GetBegin() 
	{
		return Iterator(m_Head);
	}

	// 先頭コンストイテレータ取得
	ConstIterator GetCBegin() const
	{
		return ConstIterator(m_Head);
	}

	// 末尾イテレータ取得
	Iterator GetEnd() 
	{
		return Iterator(nullptr);
	}

	// 末尾コンストイテレータ取得
	ConstIterator GetCEnd() const
	{
		return ConstIterator(nullptr);
	}

	// 全データを格納順に描画
	void Draw()
	{
		Node* current = m_Head; // イテレータの指すノード
		while (current != nullptr)
		{
			std::cout << " score : " << current->m_data.m_score << "   name : " << current->m_data.m_name << std::endl;
			current = current->m_next;
		}
	}


private:

	Node* m_Head; // ダミーノード
	int m_DataNum{}; // データ数
};