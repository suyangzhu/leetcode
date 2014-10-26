

class Entry {
public:
	Entry() {}
	Entry(string name, Directory directory = NULL):name(name) {
		parent = directory;
	}
	void Delete() {
		if (parent == NULL) return;
		parent.DeleteEntry();
	}
private:
	Directory parent;
	string name;
	Time created;
	Time lastUpdated;
	Time lastAccessed;
};

class File : public Entry {
public:
	File (string name, Directory directory, string contents) : Entry(name, directory), contents(contents) {}
private:
	string contents;
	int size;
};

class Directory : public Entry {
public:
	void DeleteEntry()
private: 
	vector<Entry> contents;

};
