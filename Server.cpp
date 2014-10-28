

class Server {
	unordered_map<int, Machine> machines;
	unordered_map<int, int> person2MachineId;
	Machine& GetMachine(int machineID) {
		return machines[machineID];
	}

	int GetMachineIDFromUser(int PersonID) {
		return person2MachineId[PersonID];
	}

	Person GetPersonWithID(int PersonID) {
		machineID = GetMachineIDFromUser(PersonID);
		Machine machine = GetMachine(machineID);
		return machine.GetPersonWithID(PersonID);
	}
};

class Person {
	list<Person> friends;
	int personID;
	void AddFriend(int id) {
		friends.insert(id);
	}
};

class Machine {
	unordered_map<int, Person> persons;
	Person GetPeronWithID(PersonID) {
		return persons[PersonID];
	}
};
