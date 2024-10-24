#include "../include/mainwindow.h"
#include "../include/ui_mainwindow.h"
#include "deque"

void MainWindow::DoTheThing() {
    this->CQueue.push_back(this->LastCommand);
    this->CSequence.push_back(this->ui->InputLine->text());
    switch(this->LastCommand) {
        case BankAdded:
            ++this->Operations[BankAdded];
            this->SetOutText(this->AddBankConnection[this->Operations[BankAdded]]);
            if (this->Operations[BankAdded] == 6) {
                this->Operations[BankAdded] = 0;
                this->BankSystem.AddNewBank(this->CSequence);
                this->LastCommand = NothingHappened;
                this->SetOutText("Bank Added Succesfully!");
            }
            this->ui->InputLine->setText("");
            break;
        case UserAdded:
            ++this->Operations[UserAdded];
            this->SetOutText(this->AddUserConnection[this->Operations[UserAdded]]);
            if (this->Operations[UserAdded] == 5) {
                this->Operations[UserAdded] = 0;
                this->SetOutText(this->BankSystem.AddNewUser(this->CSequence));
                this->LastCommand = NothingHappened;
                this->SetOutText("User Added Succesfully!");
            }
            this->ui->InputLine->setText("");
            break;
        case UserListRequested:
            this->ui->InputLine->setText("");
            break;
        case BankListRequested:
            break;
            this->ui->InputLine->setText("");
        case UserAddedToBank:
            ++this->Operations[UserAddedToBank];
            if (this->Operations[UserAddedToBank] == 1) {
                this->ui->InputLine->setText("");
                this->SetOutText("Now type user's surname:\n");
            } else if (this->Operations[UserAddedToBank] == 3) {
                this->Operations[UserAddedToBank] = 0;
                this->SetOutText(this->BankSystem.AddUserToBank(this->CSequence));
                this->ui->InputLine->setText("");
            } else {
                this->SetOutText("Now enter the bank name:\n");
                this->ui->InputLine->setText("");
            }
            break;
        case NothingHappened:
            this->SetOutText("Choose the command type first!\n");
            this->ui->InputLine->setText("");
    }
}
void MainWindow::NewBankButtonPressed() {
    this->SetLastCommand(BankAdded);
    QString str = "Lets Add New Bank:\n";
    str += "You need to type five things:\n";
    this->ui->OutputWindow->setText("");
    str += "1) Type the name of the bank:\n";
    str += "2) The bank's credit limit:\n";
    str += "3) The bank's credit commission:\n";
    str += "4) The bank's deposit period:\n";
    str += "5) And finally, bank's unidentified user's transfer limit:\n";
    str += "Type Enter to start\n";
    this->StringCounter = 7;
    this->ui->OutputWindow->setText(str);
}
void MainWindow::GetBanksListPressed() {
    this->SetLastCommand(BankListRequested);
    this->SetOutText(this->BankSystem.GetBankList());
}
void MainWindow::NewUserButtonPressed() {
    this->SetLastCommand(UserAdded);
    QString str = "Lets Add New User:\n";
    str += "You need to type four things:\n";
    this->ui->OutputWindow->setText("");
    str += "1) Type the name of the user:\n";
    str += "2) His surname:\n";
    str += "3) His address:\n";
    str += "4) And his passport ID:\n";
    str += "Type Enter to start\n";
    this->StringCounter = 6;
    this->ui->OutputWindow->setText(str);
}
void MainWindow::GetUsersListPressed() {
    this->LastCommand = UserListRequested;
    this->SetOutText(this->BankSystem.GetUserList());
}
void MainWindow::ClientAddButtonPressed() {
    this->LastCommand = UserAddedToBank;
    this->ui->OutputWindow->setText("");
    this->StringCounter = 0;
    this->SetOutText("Enter user's name:\n");
}
void MainWindow::SetLastCommand(const Command& com) {
    this->LastCommand = com;
}
void MainWindow::SetOutText(const QString& str) {
    ++this->StringCounter;
    auto ans = this->ui->OutputWindow->toPlainText();
    if (this->StringCounter > 20) {
        ans = "";
        this->StringCounter = 0;
    }
    ans += str;
    this->ui->OutputWindow->setText(ans);
}
void MainWindow::SetUpBankMap() {
    this->AddBankConnection[1] = "Type bank's Name:\n";
    this->AddBankConnection[2] = "Done!\nAdd bank's user limit:\n";
    this->AddBankConnection[3] = "Done!\nAnd Bank's credit limit\n";
    this->AddBankConnection[4] = "Done!\nAdd bank commision per cent:\n";
    this->AddBankConnection[5] = "Done!\nAnd finally, deposit period:\n";
}
void MainWindow::SetUpUserMap() {
    this->AddUserConnection[1] = "Type User Name:\n";
    this->AddUserConnection[2] = "Done!\nType User Surname:\n";
    this->AddUserConnection[3] = "Done!\nType address ('skip' to skip):\n";
    this->AddUserConnection[4] = "Done!\nType passport ID (integer or '-1' to skip):\n";
}
void MainWindow::SetUpColors() {
    this->setStyleSheet("background-color: black;");
    this->ui->AddBankButton->setStyleSheet("QPushButton {background-color: white; color: black; border: yellow}");
    this->ui->AddUserButton->setStyleSheet("QPushButton {background-color: white; color: black; border: yellow}");
    this->ui->GetUserButton->setStyleSheet("QPushButton {background-color: white; color: black; border: yellow}");
    this->ui->GetBankButton->setStyleSheet("QPushButton {background-color: white; color: black; border: yellow}");
    this->ui->OpenBankAccountButton->setStyleSheet("QPushButton {background-color: white; color: black; border: yellow}");
    this->ui->OutputWindow->setStyleSheet("QTextBrowser {background-color: white; color: black; border: yellow}");
    this->ui->InputLine->setStyleSheet("QLineEdit {background-color: white; color: black; border: yellow}");
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QString str = "";
    this->SetUpBankMap();
    this->SetUpUserMap();
    this->SetUpColors();
    connect(this->ui->AddBankButton, &QPushButton::pressed, this, &MainWindow::NewBankButtonPressed);
    connect(this->ui->AddUserButton, &QPushButton::pressed, this, &MainWindow::NewUserButtonPressed);
    connect(this->ui->GetBankButton, &QPushButton::pressed, this, &MainWindow::GetBanksListPressed);
    connect(this->ui->GetUserButton, &QPushButton::pressed, this, &MainWindow::GetUsersListPressed);
    connect(this->ui->OpenBankAccountButton, &QPushButton::pressed, this, &MainWindow::ClientAddButtonPressed);
    connect(this->ui->InputLine, &QLineEdit::returnPressed, this, &MainWindow::DoTheThing);
}

MainWindow::~MainWindow() {
    delete ui;
}

