#include <iostream>
#include <cstdlib>
#include <string.h>

class Singleton;

class SingletonA : public Singleton {
	friend Singleton;
public:
	void Show() {
		std::cout <<"A" <<std::endl;
	}
private:
	SingletonA();
};

class SingletonB :public Singleton {
	friend class Singleton;
public:
	void Show() {
		std::cout <<"B" <<std::endl;
	}
private:
	SingletonB();
};

class Singleton {
public:
	static Singleton* GetInstance(const char* name) {
		if (singleton == NULL) {
			if (strcmp(name, "A") == 0) 
				singleton = new SingletonA();
			else if (strcmp(name, "B") == 0) 
				singleton = new SingletonB();
			else 
				singleton = new Singleton();
		}
		return singleton;
	}
private:
	Singleton() {}
	static Singleton *singleton;
};

Singleton* Singleton::singleton = NULL;
int main() {
}
