#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"

PasswordProxy::PasswordProxy(AbstractFile* af, string password) :protectedFile_(af), password_(password) {}

PasswordProxy::~PasswordProxy() {
	delete protectedFile_;
}

string PasswordProxy::passwordPrompt() {
	string input;
	cout << "Please enter password: ";
	cin >> input;

	return input;
}

vector<char> PasswordProxy::read() {
	string password = PasswordProxy::passwordPrompt();
	if (password == this->password_) {
		return this->protectedFile_->read();
	}
	else {
		vector<char> empty;
		return empty;
	}
}



int PasswordProxy::write(vector<char> vc) {
	string password = PasswordProxy::passwordPrompt();
	if (password == this->password_) {
		return this->protectedFile_->write(vc);
	}
	else {
		return passwordWriteFail;
	}

}

int PasswordProxy::append(vector<char> vc) {
	string password = PasswordProxy::passwordPrompt();
	if (password == this->password_) {
		return this->protectedFile_->append(vc);
	}
	else {
		return passwordAppendFail;
	}
}


unsigned int PasswordProxy::getSize() {
	return this->protectedFile_->getSize();
}


string PasswordProxy::getName() {
	return this->protectedFile_->getName();
}
void PasswordProxy::accept(AbstractFileVisitor* afv) {
	string password = PasswordProxy::passwordPrompt();
	if (password == this->password_) {
		this->protectedFile_->accept(afv);
	}
}

AbstractFile* PasswordProxy::clone(string name) {
	return new PasswordProxy(protectedFile_->clone(name), this->password_);
}

