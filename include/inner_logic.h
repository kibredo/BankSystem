#include "bank.h"
#include <QMainWindow>
struct Logic {
    std::vector<Bank> BanksList;
    std::vector<User> Users;
    std::map<std::string, Bank*> BankNameBase;
    std::map<UserName, User> UsersInit;
    QString AddNewUser(std::vector<QString>& CSequence);
    void AddNewBank(std::vector<QString>& CSequence);
    QString GetBankList();
    QString GetUserList();
    QString AddUserToBank(std::vector<QString>& CSequence);
    void GetSingleUserInfo(const User& user, std::string& str);
    bool NamesAreCorrectCheck(std::vector<QString>& CSequence);
    std::string ShowBankInfo(const Bank& bank);
    Logic();
    ~Logic();
};
