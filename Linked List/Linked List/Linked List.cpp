////
// Name: Alex Shepler
// Section: S
// Program Name: P4 Linked List
//
// Description: This program combines my previous string class that I made and linked lists
////

#include "Header.h"

using namespace std;

#pragma region ASString
class ASString {
public:
	static int currentCount;
	static int createdCount;


	char* MyStr = nullptr;
	int cap = 20;;
	int end;

	ASString() {
		MyStr = new char[cap];
		MyStr[0] = '\0';
		currentCount++;
		createdCount++;
	}

	ASString(const ASString& other)
	{
		cap = other.cap;
		MyStr = new char[cap];
		for (int i = 0; i < cap; ++i)
		{
			MyStr[i] = other.MyStr[i];
		}
	}

	ASString(const char* ArgMYStr) {
		int i = 0;
		int j = 0;
		while (ArgMYStr[j])
			j++;

		while (j >= cap)
			cap += 20;

		MyStr = new char[cap];
		while (ArgMYStr[i]) {
			MyStr[i] = ArgMYStr[i];
			i++;
		}
		MyStr[i] = '\0';
		end = i;
		currentCount++;
		createdCount++;
	}

	~ASString() {
		currentCount--;
		if (MyStr[0] != '\0')
			delete[]MyStr;
	}

	ASString& operator=(const ASString& argStr) {
		this->MyStr = new char[argStr.cap];
		for (int i = 0; i < argStr.cap; i++)
			this->MyStr[i] = argStr.MyStr[i];
		this->cap = argStr.cap;
		this->end = argStr.end;
		return *this;
	}
	//void setEqualTo(const ASString& argStr) {
	//	MyStr = argStr.MyStr;
	//	cap = argStr.cap;
	//	end = argStr.end;
	//}

#pragma region OLD CompareTo
	//int CompareTo(const ASString& argStr) {
	//	int i = 0;
	//	int l = len(MyStr);
	//	int r = 0;
	//	if (argStr.MyStr != nullptr)
	//		r = len(argStr);
	//	else
	//		return 2;
	//	int j = 0;

	//	if (l > r)
	//		j = l;
	//	else
	//		j = r;

	//	for (int q = 0; j > q; q++) {
	//		if (MyStr[q] > argStr.at(q) || argStr.at(q) == '\n')
	//			return 1;
	//		else if (MyStr[q] < argStr.at(q) || MyStr[q] == '\n')
	//			return -1;
	//	}

	//	return 0;
	//}
#pragma endregion

	char operator[](int index) const {
		try {
			return MyStr[index];
		}
		catch (exception ex) {
			return '\0';
		}
	}

	char at(int index) const {
		try {
			return MyStr[index];
		}
		catch (exception ex) {
			return '\0';
		}
	}

	bool operator>>(istream& istrm) {
		while (istrm.tellg() > cap)
			cap *= 2;
		istrm.read(MyStr, istrm.tellg());
		MyStr[length() - 1] = '\n';
		end = length() - 1;
		if (istrm)
			return true;
		return false;
	}

	//bool read(istream& istrm) {
	//	while (istrm.tellg() > cap)
	//		cap *= 2;
	//	istrm.read(MyStr, istrm.tellg());
	//	MyStr[length() - 1] = '\n';
	//	end = length() - 1;
	//	if (istrm)
	//		return true;
	//	return false;
	//}

	friend ostream& operator<<(ostream& os, const ASString& str) {
		return os.write(str.MyStr, str.length());
	}

	//void write(ostream& ostrm) {
	//	ostrm.write(MyStr, length());
	//}

	bool operator<(const ASString argStr) {
		int i = 0;
		int l = len(MyStr);
		int r = 0;
		if (argStr.MyStr != nullptr)
			r = len(argStr);
		else
			return false;

		int j = 0;
		if (l > r)
			j = l;
		else
			j = r;

		for (int q = 0; j > q; q++) {
			if (MyStr[q] < argStr[q] || argStr[q] == '\n')
				return true;
			else if (MyStr[q] > argStr[q])
				return false;
		}
		return false;
	}

	bool operator>(const ASString& argStr) {
		int i = 0;
		int l = len(MyStr);
		int r = 0;
		if (argStr.MyStr != nullptr)
			r = len(argStr);
		else
			return false;

		int j = 0;
		if (l > r)
			j = l;
		else
			j = r;

		for (int q = 0; j > q; q++) {
			if (MyStr[q] > argStr[q] || argStr[q] == '\n')
				return true;
			else if (MyStr[q] < argStr[q])
				return false;
		}
		return false;
	}

	bool operator==(const ASString& argStr) {
		int i = 0;
		int l = len(MyStr);
		int r = 0;
		if (argStr.MyStr != nullptr)
			r = len(argStr);
		else
			return false;
		bool isEqual = false;

		if (l == r) {
			isEqual = true;
			for (int q = 0; l > q; q++) {
				if (MyStr[q] != argStr[q])
					isEqual = false;
			}
		}
		return isEqual;
	}

	friend ASString operator+(const ASString& L, const ASString& R) {
		int l = L.length();
		int r = R.length();

		int cap = 20;
		while (l + r > cap)
			cap += 20;

		char* temp = new char[cap];

		int j = 0;
		for (int i = 0; i < l; i++) {
			temp[i] = L[i];
		}
		for (int i = 0; i < r; i++) {
			temp[i + l] = R[i];
		}
		temp[l + r] = '\0';

		//ASString rtn = temp;

		return  temp;
	}

	int length() const {
		int i = 0;
		while (MyStr[i])
			i++;
		return i;
	}

	int capacity() {
		return cap;
	}

	const char c_str() {
		return *MyStr;
	}

	int getCurrentCount() {
		return currentCount;
	}

	int getCreatedCount() {
		return createdCount;
	}
private:
	int len(ASString str) {
		return str.length();
	}
};
#pragma endregion

class Node {
public:
	ASString data;

	Node* prev;
	Node* next;

	Node() {
		/*data = nullptr;
		prev = nullptr;
		next = nullptr;*/
	}

	Node(ASString str) {
		data = str;
	}
};

class DoubleLinkedList {
public:
	Node* head;
	Node* tail;
	mutable Node* it;

	DoubleLinkedList() {
		head = nullptr;
		tail = nullptr;
		it = head;
	}

	DoubleLinkedList(const DoubleLinkedList& dll) {
		if (dll.head == nullptr) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = new Node;
			head = dll.head;
			dll.it = dll.head;
			it = head;
			for (auto it = dll.head; it->next != nullptr; it = it->next)
				insert(it->data);
		}
	}

	~DoubleLinkedList() {
		auto it = this->head;
		while (it != nullptr)
		{
			auto toDelete = it;
			it = it->next;
			delete toDelete;
		}
	}
	void operator=(const DoubleLinkedList& dll) {
		if (dll.head == nullptr) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = new Node;
			head = dll.head;
			dll.it = dll.head;
			it = head;
			for (auto it = dll.head; it->next != nullptr; it = it->next)
				insert(it->data);
		}
	}

	friend ostream& operator<<(ostream& os, const DoubleLinkedList dll) {
		ASString str;
		Node* n = dll.head;

		while (n != nullptr) {
			str = str + n->data;
			n = n->next;
		}

		return os.write(str.MyStr, str.length());
	}

	bool insert(ASString& str) {

		Node* temp = new Node;
		temp->data = str;

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {

			resetIteration();
			bool hasInserted = false;
			do {
				if (str < it->data) {
					if (it->prev == nullptr) {
						temp->next = it;
						it->prev = temp;
						hasInserted = true;
						head = temp;
					}
					else {
						temp->next = it;
						temp->prev = it->prev;
						temp->prev->next = temp;
						it->prev = temp;
						hasInserted = true;
					}
				}
				else if (str == it->data)
					return false;
				else if (it->next == nullptr) {
					tail->next = temp;
					temp->prev = tail;
					tail = tail->next;
				}
				else
					it = it->next;
			} while (hasInserted == false);

		}

		return true;
	}

	bool remove(const ASString& str) {
		resetIteration();
		do {
			if (it->data == str) {
				it->next->prev = it->prev;
				it->prev->next = it->next;
				it = nullptr;
				return true;
			}
			else {
				it = it->next;
			}
		} while (hasMore());

		return false;
	}

	int getCount() {
		int i = 0;
		Node* temp = new Node;
		temp = head;
		while (temp != nullptr) {
			i++;
			temp = temp->next;
		}
		return i;
	}

	void resetIteration() {
		it = head;
	}

	ASString next() {
		ASString temp = it->data;
		if (hasMore()) {
			it = it->next;
		}

		return temp;
	}

	bool hasMore() {
		if (it->next != nullptr)
			return true;
		else
			return false;
	}

};

int ASString::currentCount = 0;
int ASString::createdCount = 0;

int main()
{
	// ----- Creating the variables
	DoubleLinkedList List1;
	DoubleLinkedList List2;
	DoubleLinkedList modList1;
	DoubleLinkedList modList2;

	// ----- Reading and writing the variables from a file
	ifstream inFile1;
	ifstream inFile2;

	inFile1.open("C:/Users/ALEXJ/Downloads/infile1.txt");
	if (!inFile1)
		cout << "Couldn't open infile1.txt" << endl;

	inFile2.open("C:/Users/ALEXJ/Downloads/infile2.txt");
	if (!inFile2)
		cout << "Couldn't open infile2.txt" << endl;

	char temp[100] = { '\0' };
	ASString tempStr1;
	while (inFile1 >> temp) {
		tempStr1 = temp;
		List1.insert(tempStr1);
	}

	ASString tempStr2;
	while (inFile2 >> temp) {
		tempStr2 = temp;
		List2.insert(tempStr2);
	}

	// ----- Output the sizes of the lists
	cout << "Size of List1 " << List1.getCount() << endl;
	cout << "Size of List2 " << List2.getCount() << endl;
	cout << "Size of modList1 " << modList1.getCount() << endl;
	cout << "Size of modList2 " << modList2.getCount() << endl;

	// ----- Assign List to modList
	modList1 = List1;
	modList2 = List2;

	// ----- Output the sizes of the lists
	cout << "Size of List1 " << List1.getCount() << endl;
	cout << "Size of List2 " << List2.getCount() << endl;
	cout << "Size of modList1 " << modList1.getCount() << endl;
	cout << "Size of modList2 " << modList2.getCount() << endl;

	// ----- Removeing strings
	do {
		modList1.remove(List2.it->data);
		List2.it = List2.it->next;
	} while (List2.hasMore());

	do {
		modList2.remove(List1.it->data);
		List1.it = List1.it->next;
	} while (List1.hasMore());

	// ----- Output the sizes of the lists
	cout << "Size of List1 " << List1.getCount() << endl;
	cout << "Size of List2 " << List2.getCount() << endl;
	cout << "Size of modList1 " << modList1.getCount() << endl;
	cout << "Size of modList2 " << modList2.getCount() << endl;

	// ----- Ouput the created and current count
	cout << "Current ASString " << tempStr1.currentCount << endl;
	cout << "Created ASString " << tempStr1.createdCount << endl;

	// ----- Output the modLists to files
	ofstream output1;
	output1.open("outfile1.txt");

	ASString str1;
	modList1.resetIteration();
	for (int i = 0, j = modList1.getCount(); i < j; i++) {
		str1 = modList1.next();
		output1 << str1 << " ";
	}
	output1.close();


	ofstream output2;
	output2.open("outfile2.txt");

	ASString str2;
	modList2.resetIteration();
	for (int i = 0, j = modList2.getCount(); i < j; i++) {
		str2 = modList2.next();
		output2 << str2 << " ";
	}
	output2.close();
}
