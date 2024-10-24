#include "../include/inner_logic.h"
void Logic::AddNewBank(std::vector<QString>& CSequence) {
    auto size = CSequence.size();
    std::string name = CSequence[size - 5].toStdString();
    size_t limit = CSequence[size - 4].toInt();
    size_t credit_lim = CSequence[size - 3].toInt();
    size_t commission = CSequence[size - 2].toInt();
    size_t dep_period = CSequence[size - 1].toInt();
    this->BanksList.push_back(Bank(limit, credit_lim, commission, dep_period, name));
    this->BankNameBase[name] = &this->BanksList.back();
}
QString Logic::AddNewUser(std::vector<QString>& CSequence) {
    auto size = CSequence.size();
    std::string name = CSequence[size - 4].toStdString();
    std::string surname = CSequence[size - 3].toStdString();
    std::string address = CSequence[size - 2].toStdString();
    int id = CSequence[size - 1].toInt();
    UserName init_name(name, surname);
    User client(name, surname);
    if (address != "skip" && address != "Skip") {
      client.GetAdress(address);
    }
    if (id != -1) {
      client.GetPassportId(static_cast<size_t>(id));
    }
    this->UsersInit[UserName(name, surname)] = client;
    this->Users.push_back(client);
    return "Client added succesfully!\n";
}
QString Logic::GetBankList() {
    //this->ui->OutputWindow->setText("");
    QString str = "";
    if (this->BanksList.empty()) {
        return "No banks added yet.\n";
    }
    for (const auto& bank : this->BanksList) {
        str += QString::fromStdString(this->ShowBankInfo(bank));
        if (bank.client_base.empty()) {
            str += "No users in this bank\n";
        }
    }
    return str;
}
std::string Logic::ShowBankInfo(const Bank& bank) {
    std::string str = "";
    str += "Bank Name: " + bank.bank_name + "\n";
    str += "Bank Users:\n";
    for (const auto& user : bank.client_base) {
        GetSingleUserInfo(user, str);
    }
    return str;
}
void Logic::GetSingleUserInfo(const User& user, std::string& str) {
    str += "User's Name and Surname: " + user.client.name + " " + user.client.surname + "\nPassport ID: ";
    str += (user.HasId ? std::to_string(user.passport_id) : "Have not added yet") + "\nUser Address: ";
    str += (user.WasAdressed ? user.address + "\n" : "Have not added yet\n");
}
QString Logic::GetUserList() {
    std::string str = "User List:\n";
    if (this->Users.empty()) {
        //this->ui->OutputWindow->setText("No users added yet.\n");
        //this->StringCounter = 100;
        return "No users added yet.\n";
    }
    for (const auto& user : this->Users) {
        GetSingleUserInfo(user, str);
    }
    //this->ui->OutputWindow->setText(QString::fromStdString(str));
    //this->StringCounter = 100;
    return QString::fromStdString(str);
}
bool Logic::NamesAreCorrectCheck(std::vector<QString>& CSequence) {
    std::string name = (CSequence[CSequence.size() - 3]).toStdString();
    std::string surname = (CSequence[CSequence.size() - 2]).toStdString();
    std::string bank_name = (CSequence[CSequence.size() - 1]).toStdString();
    if (this->UsersInit.find({name, surname}) == this->UsersInit.end() ||
        this->BankNameBase.find(bank_name) == this->BankNameBase.end()) {
        return false;
    }
    return true;
}
QString Logic::AddUserToBank(std::vector<QString>& CSequence) {
    if (!NamesAreCorrectCheck(CSequence)) {
        return "Error! Names are incorrect!\n";
    }
    QString name = CSequence[CSequence.size() - 3];
    QString surname = CSequence[CSequence.size() - 2];
    QString bank_name = CSequence[CSequence.size() - 1];
    // немного не по кодстайлу, зато без лишних строк и переменных
    // если коротко, то тут по имени банка и двум полям пользователя
    // добавляется юзер в банк через несколько мап
    this->BankNameBase[bank_name.toStdString()]->client_base.insert(this->UsersInit[UserName(name.toStdString(), surname.toStdString())]);
    return "User added succesfully!\n";
}
Logic::Logic() = default;
Logic::~Logic() = default;

