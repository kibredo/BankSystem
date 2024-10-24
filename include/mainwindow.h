#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inner_logic.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum Command : char {
        BankAdded,
        UserAdded,
        BankListRequested,
        UserListRequested,
        UserAddedToBank,
        NothingHappened
    };
    Logic BankSystem;
    std::vector<Command> CQueue;
    std::vector<QString> CSequence;
    size_t OperationIndex = 0;
    size_t StringCounter = 0;
    std::map<Command, int> Operations;
    Command LastCommand = NothingHappened;
    std::map<int, QString> AddBankConnection;
    std::map<int, QString> AddUserConnection;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetOutText(const QString& str);
    void SetLastCommand(const Command& com);
    void SetUpBankMap();
    void SetUpUserMap();
    void SetUpColors();
    std::string ShowBankInfo(const Bank& bank);

private:
    Ui::MainWindow *ui;
public slots:
    void DoTheThing();
    void NewBankButtonPressed();
    void GetBanksListPressed();
    void NewUserButtonPressed();
    void GetUsersListPressed();
    void ClientAddButtonPressed();
};
#endif // MAINWINDOW_H
