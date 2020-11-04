////
// Name: Alex Shepler
// Section: S
// Program Name: P2 MYString v1
//
// Description: This program I am making my own string class
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
		currentCount++;
		createdCount++;
	}

	~ASString() {
		currentCount--;
		if (MyStr)
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

	bool operator<(const ASString& argStr) {
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

		int j = 0;
		if (l > r)
			j = l;
		else
			j = r;

		for (int q = 0; j > q; q++) {
			if (MyStr[q] == argStr[q] || argStr[q] == '\n')
				return true;
		}
		return false;
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

	}

	DoubleLinkedList(const DoubleLinkedList& dll) {
		if (dll.head == nullptr) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = new Node;
			head = dll.head;

		}
	}

	~DoubleLinkedList() {

	}

	void operator=(const DoubleLinkedList& dll) {

	}

	friend ostream& operator<<(ostream& os, const DoubleLinkedList dll) {

	}

	bool insert(ASString& str) {
		Node* temp = new Node;
		temp->data = str;

		do {
			if (str == it->data) {
				return false;
			}
			else {
				it = it->next;
			}
		} while (hasMore());

		do {
			if(str < it->data && it->prev != nullptr && str > it->data){

			}
		} while (true);

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = tail->next;
		}

		return true;
	}

	bool remove(const ASString& str) {
	}

	int getCount() {
		int i;
		Node* temp = new Node;
		temp = head;
		while (temp != NULL) {
			i++;
		}
	}

	void resetIteration() {
		it = head;
	}

	ASString next() {
		ASString temp = it->data;
		if (hasMore) {
			it = it->next;
		}
		return temp;
	}

	bool hasMore() {
		if (it->next != NULL)
			return true;
		else
			return false;
	}
};

int ASString::currentCount = 0;
int ASString::createdCount = 0;

int main()
{
	/*
	ifstream file;
	file.open("C:/Users/ALEXJ/Downloads/infile3.txt");

	if (!file)
		cout << "Couldn't open file" << endl;

	vector<ASString> longStr;

	char temp[100] = { '\0' };
	ASString tempStr;
	ASString pushStr;
	tempStr = pushStr;
	int i = 0;
	while (file >> temp) {
		tempStr = tempStr + temp;
		i++;
		if (i > 4 || temp == nullptr) {
			longStr.push_back(tempStr);
			tempStr = *new ASString;
			i = 0;
		}
	}
	longStr.push_back(tempStr);

	bool sorted = true;
	do {
		int k = 0;
		sorted = true;
		while (k < longStr.size()-1) {
			if (longStr[k] > longStr[k + 1]) {
				sorted = false;
				ASString temp = longStr[k];
				longStr[k] = longStr[k + 1];
				longStr[k + 1] = temp;
			}
			k++;
		}
	} while (sorted == false);

	int j = 0;
	while (j < longStr.size()) {
		cout << longStr[j] << setw(13) << longStr[j].length() << ":" << longStr[j].cap << endl;
		j++;
	}
	cout << longStr[j - 1].getCreatedCount();
	*/
}