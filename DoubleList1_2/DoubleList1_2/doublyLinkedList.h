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
public:
	// ノード
	struct Node
	{
		Node* m_prev; // 前ノード
		Node* m_next; // 次ノード
		RecordData m_data; //成績データ

		Node(RecordData data) : m_prev(nullptr), m_next(nullptr), m_data(data) {}
	};

	//コンストイテレータクラス
	class ConstIterator 
	{
	protected:
		Node* m_Node; //ノードへのポインタ

	public:
		ConstIterator(Node* node) : m_Node(node) {}

		//イテレータの先頭に向かってひとつ進める
		ConstIterator& operator--()
		{
			m_Node = m_Node->m_prev;
			return *this;
		}

		//イテレータの末尾に向かってひとつ進める
		ConstIterator& operator++()
		{
			m_Node = m_Node->m_next;
			return *this;
		}

		//イテレータの指す要素を取得する(const)
		const Node* operator*() const { return this->m_Node; }

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
		Node* operator*() { return m_Node; }
	};
	

	//双方向リストのコンストラクタ
	DoublyLinkedList() : m_Head(nullptr), m_Tail(nullptr), m_DataNum(0) {}

	//デストラクタ
	~DoublyLinkedList() // 先頭から末尾までdelete
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
	bool Insert(Iterator it, RecordData data)
	{
		Node* itNode = (*it); // イテレータの指すノード
		if(itNode == nullptr || itNode->m_next == nullptr)
		{
			Push_back(data);
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
	bool Push_back(RecordData data) 
	{
		Node* newNode = new Node(data);
		if (m_Head == nullptr) 
		{
			m_Head = m_Tail = newNode;
		}
		else 
		{
			m_Tail->m_next = newNode;
			newNode->m_prev = m_Tail;
			m_Tail = newNode;
		}

		m_DataNum++;
		return true;
	}

	// データの削除
	bool Remove(Iterator it)
	{
		if (it == nullptr || (it == m_Tail && m_Head != m_Tail))
		{
			return false;
		}
		Node* itNode = *it; // イテレータの指すノード

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
			m_Tail = itNode->m_prev;
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
		return Iterator(m_Tail);
	}

	// 末尾コンストイテレータ取得
	ConstIterator GetCEnd() const
	{
		return ConstIterator(m_Tail);
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

	Node* m_Head; // 先頭ノード
	Node* m_Tail; // 末尾ノード
	int m_DataNum{}; // データ数
};