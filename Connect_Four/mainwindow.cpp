#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(nullptr));
    //QMessageBox::information(this, tr("RAND_MAX"), tr(to_string(RAND_MAX).c_str()));
    for(short i = 0; i < 6; i++)
    {
        for(short j = 0; j < 7; j++)
        {
            Board[i][j] = '-';
        }
    }
    RedGo = true;
    ui->Title->setHidden(false);
    ui->SaveFile1->setHidden(false);
    ui->SaveFile2->setHidden(false);
    ui->SaveFile3->setHidden(false);
    ui->LoadSaveFile1->setHidden(false);
    ui->NewSaveFile1->setHidden(false);
    ui->DeleteSaveFile1->setHidden(false);
    ui->LoadSaveFile2->setHidden(false);
    ui->NewSaveFile2->setHidden(false);
    ui->DeleteSaveFile2->setHidden(false);
    ui->LoadSaveFile3->setHidden(false);
    ui->NewSaveFile3->setHidden(false);
    ui->DeleteSaveFile3->setHidden(false);
    ui->RedgoesFirst->setHidden(true);
    ui->Human->setHidden(true);
    ui->ArtificialIntelligence->setHidden(true);
    ui->Easy->setHidden(true);
    ui->Impossible->setHidden(true);
    ui->Red->setHidden(true);
    ui->Yellow->setHidden(true);
    ui->Back->setHidden(true);
    ui->CreateFile->setHidden(true);
    ui->Player->setHidden(true);
    ui->PlayerOutput->setHidden(true);
    ui->Difficulty->setHidden(true);
    ui->DifficultyOutput->setHidden(true);
    ui->Computer->setHidden(true);
    ui->ComputerOutput->setHidden(true);
    ui->Name->setHidden(true);
    ui->FileName->setHidden(true);
    ui->Board->setHidden(true);
    ui->Red00->setHidden(true);
    ui->Red10->setHidden(true);
    ui->Red20->setHidden(true);
    ui->Red30->setHidden(true);
    ui->Red40->setHidden(true);
    ui->Red50->setHidden(true);
    ui->Red01->setHidden(true);
    ui->Red11->setHidden(true);
    ui->Red21->setHidden(true);
    ui->Red31->setHidden(true);
    ui->Red41->setHidden(true);
    ui->Red51->setHidden(true);
    ui->Red02->setHidden(true);
    ui->Red12->setHidden(true);
    ui->Red22->setHidden(true);
    ui->Red32->setHidden(true);
    ui->Red42->setHidden(true);
    ui->Red52->setHidden(true);
    ui->Red03->setHidden(true);
    ui->Red13->setHidden(true);
    ui->Red23->setHidden(true);
    ui->Red33->setHidden(true);
    ui->Red43->setHidden(true);
    ui->Red53->setHidden(true);
    ui->Red04->setHidden(true);
    ui->Red14->setHidden(true);
    ui->Red24->setHidden(true);
    ui->Red34->setHidden(true);
    ui->Red44->setHidden(true);
    ui->Red54->setHidden(true);
    ui->Red05->setHidden(true);
    ui->Red15->setHidden(true);
    ui->Red25->setHidden(true);
    ui->Red35->setHidden(true);
    ui->Red45->setHidden(true);
    ui->Red55->setHidden(true);
    ui->Red06->setHidden(true);
    ui->Red16->setHidden(true);
    ui->Red26->setHidden(true);
    ui->Red36->setHidden(true);
    ui->Red46->setHidden(true);
    ui->Red56->setHidden(true);
    ui->Yellow00->setHidden(true);
    ui->Yellow10->setHidden(true);
    ui->Yellow20->setHidden(true);
    ui->Yellow30->setHidden(true);
    ui->Yellow40->setHidden(true);
    ui->Yellow50->setHidden(true);
    ui->Yellow01->setHidden(true);
    ui->Yellow11->setHidden(true);
    ui->Yellow21->setHidden(true);
    ui->Yellow31->setHidden(true);
    ui->Yellow41->setHidden(true);
    ui->Yellow51->setHidden(true);
    ui->Yellow02->setHidden(true);
    ui->Yellow12->setHidden(true);
    ui->Yellow22->setHidden(true);
    ui->Yellow32->setHidden(true);
    ui->Yellow42->setHidden(true);
    ui->Yellow52->setHidden(true);
    ui->Yellow03->setHidden(true);
    ui->Yellow13->setHidden(true);
    ui->Yellow23->setHidden(true);
    ui->Yellow33->setHidden(true);
    ui->Yellow43->setHidden(true);
    ui->Yellow53->setHidden(true);
    ui->Yellow04->setHidden(true);
    ui->Yellow14->setHidden(true);
    ui->Yellow24->setHidden(true);
    ui->Yellow34->setHidden(true);
    ui->Yellow44->setHidden(true);
    ui->Yellow54->setHidden(true);
    ui->Yellow05->setHidden(true);
    ui->Yellow15->setHidden(true);
    ui->Yellow25->setHidden(true);
    ui->Yellow35->setHidden(true);
    ui->Yellow45->setHidden(true);
    ui->Yellow55->setHidden(true);
    ui->Yellow06->setHidden(true);
    ui->Yellow16->setHidden(true);
    ui->Yellow26->setHidden(true);
    ui->Yellow36->setHidden(true);
    ui->Yellow46->setHidden(true);
    ui->Yellow56->setHidden(true);
    ui->Drop0->setHidden(true);
    ui->Drop1->setHidden(true);
    ui->Drop2->setHidden(true);
    ui->Drop3->setHidden(true);
    ui->Drop4->setHidden(true);
    ui->Drop5->setHidden(true);
    ui->Drop6->setHidden(true);
    ui->RedWins->setHidden(true);
    ui->YellowWins->setHidden(true);
    ui->ItsATie->setHidden(true);
    ui->PlayAgain->setHidden(true);
    ui->Exit->setHidden(true);
    ui->Loading->setHidden(true);
    connect(ui->LoadSaveFile1, SIGNAL(released()), this, SLOT(LoadSaveFile1()));
    connect(ui->NewSaveFile1, SIGNAL(released()), this, SLOT(NewSaveFile1()));
    connect(ui->DeleteSaveFile1, SIGNAL(released()), this, SLOT(DeleteSaveFile1()));
    connect(ui->LoadSaveFile2, SIGNAL(released()), this, SLOT(LoadSaveFile2()));
    connect(ui->NewSaveFile2, SIGNAL(released()), this, SLOT(NewSaveFile2()));
    connect(ui->DeleteSaveFile2, SIGNAL(released()), this, SLOT(DeleteSaveFile2()));
    connect(ui->LoadSaveFile3, SIGNAL(released()), this, SLOT(LoadSaveFile3()));
    connect(ui->NewSaveFile3, SIGNAL(released()), this, SLOT(NewSaveFile3()));
    connect(ui->DeleteSaveFile3, SIGNAL(released()), this, SLOT(DeleteSaveFile3()));
    connect(ui->Human, SIGNAL(released()), this, SLOT(HumanMode()));
    connect(ui->ArtificialIntelligence, SIGNAL(released()), this, SLOT(ArtificialIntelligenceMode()));
    connect(ui->Easy, SIGNAL(released()), this, SLOT(EasyMode()));
    connect(ui->Impossible, SIGNAL(released()), this, SLOT(ImpossibleMode()));
    connect(ui->Red, SIGNAL(released()), this, SLOT(RedMode()));
    connect(ui->Yellow, SIGNAL(released()), this, SLOT(YellowMode()));
    connect(ui->Back, SIGNAL(released()), this, SLOT(goBack()));
    connect(ui->CreateFile, SIGNAL(released()), this, SLOT(CreateSaveFile()));
    connect(ui->Drop0, SIGNAL(released()), this, SLOT(Drop0()));
    connect(ui->Drop1, SIGNAL(released()), this, SLOT(Drop1()));
    connect(ui->Drop2, SIGNAL(released()), this, SLOT(Drop2()));
    connect(ui->Drop3, SIGNAL(released()), this, SLOT(Drop3()));
    connect(ui->Drop4, SIGNAL(released()), this, SLOT(Drop4()));
    connect(ui->Drop5, SIGNAL(released()), this, SLOT(Drop5()));
    connect(ui->Drop6, SIGNAL(released()), this, SLOT(Drop6()));
    connect(ui->PlayAgain, SIGNAL(released()), this, SLOT(PlayAgain()));
    connect(ui->Exit, SIGNAL(released()), this, SLOT(Exit()));
    ifstream SaveFile;
    SaveFile.open("SaveFiles\\SaveFile1.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile1.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        ui->SaveFile1->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile1 creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if((((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties))) || (Player._Equal("N/A") && Difficulty._Equal("N/A") && Computer._Equal("N/A") && Wins._Equal("N/A") && Loses._Equal("N/A") && Ties._Equal("N/A")))
        {
            SaveFile.close();
            ui->SaveFile1->setText("Name: "+QString::fromStdString(Name)+" : Player: "+QString::fromStdString(Player)+" : Difficuly: "+QString::fromStdString(Difficulty)+" : Computer: "+QString::fromStdString(Computer)+"\nRed: "+QString::fromStdString(Wins)+" : Yellow: "+ QString::fromStdString(Loses)+" : Ties: "+QString::fromStdString(Ties));
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile1.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("SaveFile1 is corruptive, press the New button to create a new save."));
            ui->SaveFile1->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        }
    }
    SaveFile.open("SaveFiles\\SaveFile2.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile2.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        ui->SaveFile2->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile2 creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if((((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties))) || (Player._Equal("N/A") && Difficulty._Equal("N/A") && Computer._Equal("N/A") && Wins._Equal("N/A") && Loses._Equal("N/A") && Ties._Equal("N/A")))
        {
            SaveFile.close();
            ui->SaveFile2->setText("Name: "+QString::fromStdString(Name)+" : Player: "+QString::fromStdString(Player)+" : Difficuly: "+QString::fromStdString(Difficulty)+" : Computer: "+QString::fromStdString(Computer)+"\nRed: "+QString::fromStdString(Wins)+" : Yellow: "+ QString::fromStdString(Loses)+" : Ties: "+QString::fromStdString(Ties));
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile2.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("SaveFile2 is corruptive, press the New button to create a new save."));
            ui->SaveFile2->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        }
    }
    SaveFile.open("SaveFiles\\SaveFile3.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile3.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        ui->SaveFile3->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile3 creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if((((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties))) || (Player._Equal("N/A") && Difficulty._Equal("N/A") && Computer._Equal("N/A") && Wins._Equal("N/A") && Loses._Equal("N/A") && Ties._Equal("N/A")))
        {
            SaveFile.close();
            ui->SaveFile3->setText("Name: "+QString::fromStdString(Name)+" : Player: "+QString::fromStdString(Player)+" : Difficuly: "+QString::fromStdString(Difficulty)+" : Computer: "+QString::fromStdString(Computer)+"\nRed: "+QString::fromStdString(Wins)+" : Yellow: "+ QString::fromStdString(Loses)+" : Ties: "+QString::fromStdString(Ties));
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile3.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("SaveFile3 is corruptive, press the New button to create a new save."));
            ui->SaveFile3->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        }
    }
}

void MainWindow::HumanMode()
{
    ui->PlayerOutput->setText("Human");
    ui->Easy->setHidden(true);
    ui->Impossible->setHidden(true);
    ui->Red->setHidden(true);
    ui->Yellow->setHidden(true);
    ui->DifficultyOutput->setText("N/A");
    ui->ComputerOutput->setText("N/A");
}

void MainWindow::ArtificialIntelligenceMode()
{
    ui->PlayerOutput->setText("Artificial\nIntelligence");
    ui->Easy->setHidden(false);
    ui->Impossible->setHidden(false);
    ui->Red->setHidden(false);
    ui->Yellow->setHidden(false);
}

void MainWindow::EasyMode()
{
    ui->DifficultyOutput->setText("Easy");
}

void MainWindow::ImpossibleMode()
{
    ui->DifficultyOutput->setText("Impossible");
}

void MainWindow::RedMode()
{
    ui->ComputerOutput->setText("Red");
}

void MainWindow::YellowMode()
{
    ui->ComputerOutput->setText("Yellow");
}

void MainWindow::goBack()
{
    ui->FileName->setText("");
    ui->PlayerOutput->setText("N/A");
    ui->DifficultyOutput->setText("N/A");
    ui->ComputerOutput->setText("N/A");
    ui->Title->setHidden(false);
    ui->SaveFile1->setHidden(false);
    ui->SaveFile2->setHidden(false);
    ui->SaveFile3->setHidden(false);
    ui->LoadSaveFile1->setHidden(false);
    ui->NewSaveFile1->setHidden(false);
    ui->DeleteSaveFile1->setHidden(false);
    ui->LoadSaveFile2->setHidden(false);
    ui->NewSaveFile2->setHidden(false);
    ui->DeleteSaveFile2->setHidden(false);
    ui->LoadSaveFile3->setHidden(false);
    ui->NewSaveFile3->setHidden(false);
    ui->DeleteSaveFile3->setHidden(false);
    ui->RedgoesFirst->setHidden(true);
    ui->Human->setHidden(true);
    ui->ArtificialIntelligence->setHidden(true);
    ui->Easy->setHidden(true);
    ui->Impossible->setHidden(true);
    ui->Red->setHidden(true);
    ui->Yellow->setHidden(true);
    ui->Back->setHidden(true);
    ui->CreateFile->setHidden(true);
    ui->Player->setHidden(true);
    ui->PlayerOutput->setHidden(true);
    ui->Difficulty->setHidden(true);
    ui->DifficultyOutput->setHidden(true);
    ui->Computer->setHidden(true);
    ui->ComputerOutput->setHidden(true);
    ui->Name->setHidden(true);
    ui->FileName->setHidden(true);
}

void MainWindow::CreateGameBoard(ofstream &SaveFile)
{
    SaveFile << ui->FileName->toPlainText().toStdString() + '\n' + ui->PlayerOutput->text().toStdString() + '\n' + ui->DifficultyOutput->text().toStdString() + '\n' + ui->ComputerOutput->text().toStdString() + "\n0\n0\n0";
    if(ui->ComputerOutput->text().toStdString()._Equal("Red"))
    {
        ComputerRed = true;
    }
    else
    {
        ComputerRed = false;
    }
    if(ui->DifficultyOutput->text().toStdString()._Equal("Impossible"))
    {
        whichMode = 2;
        if(ui->ComputerOutput->text().toStdString()._Equal("Red"))
        {
            AIhardPick();
        }
    }
    else if(ui->DifficultyOutput->text().toStdString()._Equal("Easy"))
    {
        whichMode = 1;
        if(ui->ComputerOutput->text().toStdString()._Equal("Red"))
        {
            AIeasyPick();
        }
    }
    else
    {
        whichMode = 0;
    }

    ui->FileName->setText("");
    ui->PlayerOutput->setText("N/A");
    ui->DifficultyOutput->setText("N/A");
    ui->ComputerOutput->setText("N/A");
    ui->Name->setHidden(true);
    ui->Player->setHidden(true);
    ui->Difficulty->setHidden(true);
    ui->Computer->setHidden(true);
    ui->Human->setHidden(true);
    ui->ArtificialIntelligence->setHidden(true);
    ui->Easy->setHidden(true);
    ui->Impossible->setHidden(true);
    ui->Red->setHidden(true);
    ui->Yellow->setHidden(true);
    ui->RedgoesFirst->setHidden(true);
    ui->FileName->setHidden(true);
    ui->PlayerOutput->setHidden(true);
    ui->DifficultyOutput->setHidden(true);
    ui->ComputerOutput->setHidden(true);
    ui->Back->setHidden(true);
    ui->Board->setHidden(false);
    ui->Drop0->setHidden(false);
    ui->Drop1->setHidden(false);
    ui->Drop2->setHidden(false);
    ui->Drop3->setHidden(false);
    ui->Drop4->setHidden(false);
    ui->Drop5->setHidden(false);
    ui->Drop6->setHidden(false);
}

bool MainWindow::Drop(short loc)
{
    if(loc == 0)
    {
        short Prow;
        for(Prow = 5; Prow >= 0; Prow--)
        {
            if(Board[Prow][loc] == '-')
            {
                break;
            }
            if(Prow == 0)
                return false;
        }
        if(Prow == 5)
        {
            if(RedGo)
            {
                ui->Red50->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow50->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 4)
        {
            if(RedGo)
            {
                ui->Red40->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow40->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 3)
        {
            if(RedGo)
            {
                ui->Red30->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow30->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 2)
        {
            if(RedGo)
            {
                ui->Red20->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow20->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 1)
        {
            if(RedGo)
            {
                ui->Red10->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow10->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 0)
        {
            ui->Drop0->setHidden(true);
            if(RedGo)
            {
                ui->Red00->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow00->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something is trying to place a chip outside the board this program might crash."));
            return false;
        }
    }
    else if(loc == 1)
    {
        short Prow;
        for(Prow = 5; Prow >= 0; Prow--)
        {
            if(Board[Prow][loc] == '-')
                break;
            if(Prow == 0)
                return false;
        }
        if(Prow == 5)
        {
            if(RedGo)
            {
                ui->Red51->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow51->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 4)
        {
            if(RedGo)
            {
                ui->Red41->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow41->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 3)
        {
            if(RedGo)
            {
                ui->Red31->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow31->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 2)
        {
            if(RedGo)
            {
                ui->Red21->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow21->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 1)
        {
            if(RedGo)
            {
                ui->Red11->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow11->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 0)
        {
            ui->Drop1->setHidden(true);
            if(RedGo)
            {
                ui->Red01->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow01->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something is trying to place a chip outside the board this program might crash."));
            return false;
        }
    }
    else if(loc == 2)
    {
        short Prow;
        for(Prow = 5; Prow >= 0; Prow--)
        {
            if(Board[Prow][loc] == '-')
                break;
            if(Prow == 0)
                return false;
        }
        if(Prow == 5)
        {
            if(RedGo)
            {
                ui->Red52->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow52->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 4)
        {
            if(RedGo)
            {
                ui->Red42->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow42->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 3)
        {
            if(RedGo)
            {
                ui->Red32->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow32->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 2)
        {
            if(RedGo)
            {
                ui->Red22->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow22->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 1)
        {
            if(RedGo)
            {
                ui->Red12->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow12->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 0)
        {
            ui->Drop2->setHidden(true);
            if(RedGo)
            {
                ui->Red02->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow02->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something is trying to place a chip outside the board this program might crash."));
            return false;
        }
    }
    else if(loc == 3)
    {
        short Prow;
        for(Prow = 5; Prow >= 0; Prow--)
        {
            if(Board[Prow][loc] == '-')
                break;
            if(Prow == 0)
                return false;
        }
        if(Prow == 5)
        {
            if(RedGo)
            {
                ui->Red53->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow53->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 4)
        {
            if(RedGo)
            {
                ui->Red43->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow43->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 3)
        {
            if(RedGo)
            {
                ui->Red33->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow33->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 2)
        {
            if(RedGo)
            {
                ui->Red23->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow23->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 1)
        {
            if(RedGo)
            {
                ui->Red13->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow13->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 0)
        {
            ui->Drop3->setHidden(true);
            if(RedGo)
            {
                ui->Red03->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow03->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something is trying to place a chip outside the board this program might crash."));
            return false;
        }
    }
    else if(loc == 4)
    {
        short Prow;
        for(Prow = 5; Prow >= 0; Prow--)
        {
            if(Board[Prow][loc] == '-')
                break;
            if(Prow == 0)
                return false;
        }
        if(Prow == 5)
        {
            if(RedGo)
            {
                ui->Red54->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow54->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 4)
        {
            if(RedGo)
            {
                ui->Red44->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow44->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 3)
        {
            if(RedGo)
            {
                ui->Red34->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow34->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 2)
        {
            if(RedGo)
            {
                ui->Red24->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow24->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 1)
        {
            if(RedGo)
            {
                ui->Red14->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow14->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 0)
        {
            ui->Drop4->setHidden(true);
            if(RedGo)
            {
                ui->Red04->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow04->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something is trying to place a chip outside the board this program might crash."));
            return false;
        }
    }
    else if(loc == 5)
    {
        short Prow;
        for(Prow = 5; Prow >= 0; Prow--)
        {
            if(Board[Prow][loc] == '-')
                break;
            if(Prow == 0)
                return false;
        }
        if(Prow == 5)
        {
            if(RedGo)
            {
                ui->Red55->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow55->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 4)
        {
            if(RedGo)
            {
                ui->Red45->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow45->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 3)
        {
            if(RedGo)
            {
                ui->Red35->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow35->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 2)
        {
            if(RedGo)
            {
                ui->Red25->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow25->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 1)
        {
            if(RedGo)
            {
                ui->Red15->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow15->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 0)
        {
            ui->Drop5->setHidden(true);
            if(RedGo)
            {
                ui->Red05->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow05->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something is trying to place a chip outside the board this program might crash."));
            return false;
        }
    }
    else if(loc == 6)
    {
        short Prow;
        for(Prow = 5; Prow >= 0; Prow--)
        {
            if(Board[Prow][loc] == '-')
                break;
            if(Prow == 0)
                return false;
        }
        if(Prow == 5)
        {
            if(RedGo)
            {
                ui->Red56->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow56->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 4)
        {
            if(RedGo)
            {
                ui->Red46->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow46->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 3)
        {
            if(RedGo)
            {
                ui->Red36->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow36->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 2)
        {
            if(RedGo)
            {
                ui->Red26->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow26->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 1)
        {
            if(RedGo)
            {
                ui->Red16->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow16->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else if(Prow == 0)
        {
            ui->Drop6->setHidden(true);
            if(RedGo)
            {
                ui->Red06->setHidden(false);
                Board[Prow][loc] = 'R';
            }
            else
            {
                ui->Yellow06->setHidden(false);
                Board[Prow][loc] = 'Y';
            }
            return true;
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something is trying to place a chip outside the board this program might crash."));
            return false;
        }
    }
    else
    {
        QMessageBox::information(this, tr("ERROR"), tr("Something is trying to place a chip outside the board this program might crash."));
        return false;
    }
}

bool MainWindow::checkWin(short WWin)
{
    if(WWin == 1)
    {
        ui->Drop0->setHidden(true);
        ui->Drop1->setHidden(true);
        ui->Drop2->setHidden(true);
        ui->Drop3->setHidden(true);
        ui->Drop4->setHidden(true);
        ui->Drop5->setHidden(true);
        ui->Drop6->setHidden(true);
        ui->RedWins->setHidden(false);
        ui->PlayAgain->setHidden(false);
        ui->Exit->setHidden(false);
        ofstream Save;
        ifstream Data;
        if(whichSaveFile == 1)
        {
            Data.open("SaveFiles\\SaveFile1.txt");
            string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
            Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
            Data.close();
            Save.open("SaveFiles\\SaveFile1.txt");
            Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + to_string(1 + stoul(Wins)) + '\n' + Loses + '\n' + Ties;
            Save.close();
        }
        else if(whichSaveFile == 2)
        {
            Data.open("SaveFiles\\SaveFile2.txt");
            string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
            Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
            Data.close();
            Save.open("SaveFiles\\SaveFile2.txt");
            Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + to_string(1 + stoul(Wins)) + '\n' + Loses + '\n' + Ties;
            Save.close();
        }
        else if(whichSaveFile == 3)
        {
            Data.open("SaveFiles\\SaveFile3.txt");
            string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
            Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
            Data.close();
            Save.open("SaveFiles\\SaveFile3.txt");
            Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + to_string(1 + stoul(Wins)) + '\n' + Loses + '\n' + Ties;
            Save.close();
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something went wrong with Saving."));
        }
        return true;
    }
    else if(WWin == -1)
    {
        ui->Drop0->setHidden(true);
        ui->Drop1->setHidden(true);
        ui->Drop2->setHidden(true);
        ui->Drop3->setHidden(true);
        ui->Drop4->setHidden(true);
        ui->Drop5->setHidden(true);
        ui->Drop6->setHidden(true);
        ui->YellowWins->setHidden(false);
        ui->PlayAgain->setHidden(false);
        ui->Exit->setHidden(false);
        ofstream Save;
        ifstream Data;
        if(whichSaveFile == 1)
        {
            Data.open("SaveFiles\\SaveFile1.txt");
            string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
            Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
            Data.close();
            Save.open("SaveFiles\\SaveFile1.txt");
            Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + Wins + '\n' + to_string(1 + stoul(Loses)) + '\n' + Ties;
            Save.close();
        }
        else if(whichSaveFile == 2)
        {
            Data.open("SaveFiles\\SaveFile2.txt");
            string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
            Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
            Data.close();
            Save.open("SaveFiles\\SaveFile2.txt");
            Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + Wins + '\n' + to_string(1 + stoul(Loses)) + '\n' + Ties;
            Save.close();
        }
        else if(whichSaveFile == 3)
        {
            Data.open("SaveFiles\\SaveFile3.txt");
            string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
            Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
            Data.close();
            Save.open("SaveFiles\\SaveFile3.txt");
            Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + Wins + '\n' + to_string(1 + stoul(Loses)) + '\n' + Ties;
            Save.close();
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something went wrong with Saving."));
        }
        return true;
    }
    else
    {
        bool spacesLeft = false;
        for(short i = 0 ;i < 7; i++)
        {
            if(Board[0][i] == '-')
                spacesLeft = true;
        }
        if(!spacesLeft)
        {
            ui->Drop0->setHidden(true);
            ui->Drop1->setHidden(true);
            ui->Drop2->setHidden(true);
            ui->Drop3->setHidden(true);
            ui->Drop4->setHidden(true);
            ui->Drop5->setHidden(true);
            ui->Drop6->setHidden(true);
            ui->ItsATie->setHidden(false);
            ui->PlayAgain->setHidden(false);
            ui->Exit->setHidden(false);
            ofstream Save;
            ifstream Data;
            if(whichSaveFile == 1)
            {
                Data.open("SaveFiles\\SaveFile1.txt");
                string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
                Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
                Data.close();
                Save.open("SaveFiles\\SaveFile1.txt");
                Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + Wins + '\n' + Loses + '\n' + to_string(1 + stoul(Ties));
                Save.close();
            }
            else if(whichSaveFile == 2)
            {
                Data.open("SaveFiles\\SaveFile2.txt");
                string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
                Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
                Data.close();
                Save.open("SaveFiles\\SaveFile2.txt");
                Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + Wins + '\n' + Loses + '\n' + to_string(1 + stoul(Ties));
                Save.close();
            }
            else if(whichSaveFile == 3)
            {
                Data.open("SaveFiles\\SaveFile3.txt");
                string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
                Data >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
                Data.close();
                Save.open("SaveFiles\\SaveFile3.txt");
                Save << Name + '\n' + Player + '\n' + Difficulty + '\n' + Computer + '\n' + Wins + '\n' + Loses + '\n' + to_string(1 + stoul(Ties));
                Save.close();
            }
            else
            {
                QMessageBox::information(this, tr("ERROR"), tr("Something went wrong with Saving."));
            }
            return true;
        }
    }
    return false;
}

void MainWindow::Dropped(short loc)
{
    Drop(loc);
    bool ifstop = checkWin(WhoWin(loc));
    RedGo = !RedGo;
    if(!ifstop)
    {
        if(whichMode == 1)
        {
            AIeasyPick();
        }
        else if(whichMode == 2)
        {
            AIhardPick();
        }
    }
}

void MainWindow::Drop0()
{
    Dropped(0);
}

void MainWindow::Drop1()
{
    Dropped(1);
}

void MainWindow::Drop2()
{
    Dropped(2);
}

void MainWindow::Drop3()
{
    Dropped(3);
}

void MainWindow::Drop4()
{
    Dropped(4);
}

void MainWindow::Drop5()
{
    Dropped(5);
}

void MainWindow::Drop6()
{
    Dropped(6);
}

void MainWindow::PlayAgain()
{
    ui->Red00->setHidden(true);
    ui->Red10->setHidden(true);
    ui->Red20->setHidden(true);
    ui->Red30->setHidden(true);
    ui->Red40->setHidden(true);
    ui->Red50->setHidden(true);
    ui->Red01->setHidden(true);
    ui->Red11->setHidden(true);
    ui->Red21->setHidden(true);
    ui->Red31->setHidden(true);
    ui->Red41->setHidden(true);
    ui->Red51->setHidden(true);
    ui->Red02->setHidden(true);
    ui->Red12->setHidden(true);
    ui->Red22->setHidden(true);
    ui->Red32->setHidden(true);
    ui->Red42->setHidden(true);
    ui->Red52->setHidden(true);
    ui->Red03->setHidden(true);
    ui->Red13->setHidden(true);
    ui->Red23->setHidden(true);
    ui->Red33->setHidden(true);
    ui->Red43->setHidden(true);
    ui->Red53->setHidden(true);
    ui->Red04->setHidden(true);
    ui->Red14->setHidden(true);
    ui->Red24->setHidden(true);
    ui->Red34->setHidden(true);
    ui->Red44->setHidden(true);
    ui->Red54->setHidden(true);
    ui->Red05->setHidden(true);
    ui->Red15->setHidden(true);
    ui->Red25->setHidden(true);
    ui->Red35->setHidden(true);
    ui->Red45->setHidden(true);
    ui->Red55->setHidden(true);
    ui->Red06->setHidden(true);
    ui->Red16->setHidden(true);
    ui->Red26->setHidden(true);
    ui->Red36->setHidden(true);
    ui->Red46->setHidden(true);
    ui->Red56->setHidden(true);
    ui->Yellow00->setHidden(true);
    ui->Yellow10->setHidden(true);
    ui->Yellow20->setHidden(true);
    ui->Yellow30->setHidden(true);
    ui->Yellow40->setHidden(true);
    ui->Yellow50->setHidden(true);
    ui->Yellow01->setHidden(true);
    ui->Yellow11->setHidden(true);
    ui->Yellow21->setHidden(true);
    ui->Yellow31->setHidden(true);
    ui->Yellow41->setHidden(true);
    ui->Yellow51->setHidden(true);
    ui->Yellow02->setHidden(true);
    ui->Yellow12->setHidden(true);
    ui->Yellow22->setHidden(true);
    ui->Yellow32->setHidden(true);
    ui->Yellow42->setHidden(true);
    ui->Yellow52->setHidden(true);
    ui->Yellow03->setHidden(true);
    ui->Yellow13->setHidden(true);
    ui->Yellow23->setHidden(true);
    ui->Yellow33->setHidden(true);
    ui->Yellow43->setHidden(true);
    ui->Yellow53->setHidden(true);
    ui->Yellow04->setHidden(true);
    ui->Yellow14->setHidden(true);
    ui->Yellow24->setHidden(true);
    ui->Yellow34->setHidden(true);
    ui->Yellow44->setHidden(true);
    ui->Yellow54->setHidden(true);
    ui->Yellow05->setHidden(true);
    ui->Yellow15->setHidden(true);
    ui->Yellow25->setHidden(true);
    ui->Yellow35->setHidden(true);
    ui->Yellow45->setHidden(true);
    ui->Yellow55->setHidden(true);
    ui->Yellow06->setHidden(true);
    ui->Yellow16->setHidden(true);
    ui->Yellow26->setHidden(true);
    ui->Yellow36->setHidden(true);
    ui->Yellow46->setHidden(true);
    ui->Yellow56->setHidden(true);
    ui->PlayAgain->setHidden(true);
    ui->Exit->setHidden(true);
    ui->RedWins->setHidden(true);
    ui->YellowWins->setHidden(true);
    ui->ItsATie->setHidden(true);
    ui->Loading->setHidden(true);
    for(short i = 0; i < 6; i++)
    {
        for(short j = 0; j < 7; j++)
        {
            Board[i][j] = '-';
        }
    }
    ui->Drop0->setHidden(false);
    ui->Drop1->setHidden(false);
    ui->Drop2->setHidden(false);
    ui->Drop3->setHidden(false);
    ui->Drop4->setHidden(false);
    ui->Drop5->setHidden(false);
    ui->Drop6->setHidden(false);
    RedGo = true;
    if(ComputerRed)
    {
        if(whichMode == 1)
        {
            AIeasyPick();
        }
        else
        {
            AIhardPick();
        }
    }
}

void MainWindow::Exit()
{
    for(short i = 0; i < 6; i++)
    {
        for(short j = 0; j < 7; j++)
        {
            Board[i][j] = '-';
        }
    }
    RedGo = true;
    ui->Title->setHidden(false);
    ui->SaveFile1->setHidden(false);
    ui->SaveFile2->setHidden(false);
    ui->SaveFile3->setHidden(false);
    ui->LoadSaveFile1->setHidden(false);
    ui->NewSaveFile1->setHidden(false);
    ui->DeleteSaveFile1->setHidden(false);
    ui->LoadSaveFile2->setHidden(false);
    ui->NewSaveFile2->setHidden(false);
    ui->DeleteSaveFile2->setHidden(false);
    ui->LoadSaveFile3->setHidden(false);
    ui->NewSaveFile3->setHidden(false);
    ui->DeleteSaveFile3->setHidden(false);
    ui->RedgoesFirst->setHidden(true);
    ui->Human->setHidden(true);
    ui->ArtificialIntelligence->setHidden(true);
    ui->Easy->setHidden(true);
    ui->Impossible->setHidden(true);
    ui->Red->setHidden(true);
    ui->Yellow->setHidden(true);
    ui->Back->setHidden(true);
    ui->CreateFile->setHidden(true);
    ui->Player->setHidden(true);
    ui->PlayerOutput->setHidden(true);
    ui->Difficulty->setHidden(true);
    ui->DifficultyOutput->setHidden(true);
    ui->Computer->setHidden(true);
    ui->ComputerOutput->setHidden(true);
    ui->Name->setHidden(true);
    ui->FileName->setHidden(true);
    ui->Board->setHidden(true);
    ui->Red00->setHidden(true);
    ui->Red10->setHidden(true);
    ui->Red20->setHidden(true);
    ui->Red30->setHidden(true);
    ui->Red40->setHidden(true);
    ui->Red50->setHidden(true);
    ui->Red01->setHidden(true);
    ui->Red11->setHidden(true);
    ui->Red21->setHidden(true);
    ui->Red31->setHidden(true);
    ui->Red41->setHidden(true);
    ui->Red51->setHidden(true);
    ui->Red02->setHidden(true);
    ui->Red12->setHidden(true);
    ui->Red22->setHidden(true);
    ui->Red32->setHidden(true);
    ui->Red42->setHidden(true);
    ui->Red52->setHidden(true);
    ui->Red03->setHidden(true);
    ui->Red13->setHidden(true);
    ui->Red23->setHidden(true);
    ui->Red33->setHidden(true);
    ui->Red43->setHidden(true);
    ui->Red53->setHidden(true);
    ui->Red04->setHidden(true);
    ui->Red14->setHidden(true);
    ui->Red24->setHidden(true);
    ui->Red34->setHidden(true);
    ui->Red44->setHidden(true);
    ui->Red54->setHidden(true);
    ui->Red05->setHidden(true);
    ui->Red15->setHidden(true);
    ui->Red25->setHidden(true);
    ui->Red35->setHidden(true);
    ui->Red45->setHidden(true);
    ui->Red55->setHidden(true);
    ui->Red06->setHidden(true);
    ui->Red16->setHidden(true);
    ui->Red26->setHidden(true);
    ui->Red36->setHidden(true);
    ui->Red46->setHidden(true);
    ui->Red56->setHidden(true);
    ui->Yellow00->setHidden(true);
    ui->Yellow10->setHidden(true);
    ui->Yellow20->setHidden(true);
    ui->Yellow30->setHidden(true);
    ui->Yellow40->setHidden(true);
    ui->Yellow50->setHidden(true);
    ui->Yellow01->setHidden(true);
    ui->Yellow11->setHidden(true);
    ui->Yellow21->setHidden(true);
    ui->Yellow31->setHidden(true);
    ui->Yellow41->setHidden(true);
    ui->Yellow51->setHidden(true);
    ui->Yellow02->setHidden(true);
    ui->Yellow12->setHidden(true);
    ui->Yellow22->setHidden(true);
    ui->Yellow32->setHidden(true);
    ui->Yellow42->setHidden(true);
    ui->Yellow52->setHidden(true);
    ui->Yellow03->setHidden(true);
    ui->Yellow13->setHidden(true);
    ui->Yellow23->setHidden(true);
    ui->Yellow33->setHidden(true);
    ui->Yellow43->setHidden(true);
    ui->Yellow53->setHidden(true);
    ui->Yellow04->setHidden(true);
    ui->Yellow14->setHidden(true);
    ui->Yellow24->setHidden(true);
    ui->Yellow34->setHidden(true);
    ui->Yellow44->setHidden(true);
    ui->Yellow54->setHidden(true);
    ui->Yellow05->setHidden(true);
    ui->Yellow15->setHidden(true);
    ui->Yellow25->setHidden(true);
    ui->Yellow35->setHidden(true);
    ui->Yellow45->setHidden(true);
    ui->Yellow55->setHidden(true);
    ui->Yellow06->setHidden(true);
    ui->Yellow16->setHidden(true);
    ui->Yellow26->setHidden(true);
    ui->Yellow36->setHidden(true);
    ui->Yellow46->setHidden(true);
    ui->Yellow56->setHidden(true);
    ui->Drop0->setHidden(true);
    ui->Drop1->setHidden(true);
    ui->Drop2->setHidden(true);
    ui->Drop3->setHidden(true);
    ui->Drop4->setHidden(true);
    ui->Drop5->setHidden(true);
    ui->Drop6->setHidden(true);
    ui->RedWins->setHidden(true);
    ui->YellowWins->setHidden(true);
    ui->ItsATie->setHidden(true);
    ui->PlayAgain->setHidden(true);
    ui->Exit->setHidden(true);
    ui->Loading->setHidden(true);
    ifstream SaveFile;
    SaveFile.open("SaveFiles\\SaveFile1.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile1.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        ui->SaveFile1->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile1 creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if((((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties))) || (Player._Equal("N/A") && Difficulty._Equal("N/A") && Computer._Equal("N/A") && Wins._Equal("N/A") && Loses._Equal("N/A") && Ties._Equal("N/A")))
        {
            SaveFile.close();
            ui->SaveFile1->setText("Name: "+QString::fromStdString(Name)+" : Player: "+QString::fromStdString(Player)+" : Difficuly: "+QString::fromStdString(Difficulty)+" : Computer: "+QString::fromStdString(Computer)+"\nRed: "+QString::fromStdString(Wins)+" : Yellow: "+ QString::fromStdString(Loses)+" : Ties: "+QString::fromStdString(Ties));
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile1.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("SaveFile1 is corruptive, press the New button to create a new save."));
            ui->SaveFile1->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        }
    }
    SaveFile.open("SaveFiles\\SaveFile2.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile2.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        ui->SaveFile2->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile2 creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if((((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties))) || (Player._Equal("N/A") && Difficulty._Equal("N/A") && Computer._Equal("N/A") && Wins._Equal("N/A") && Loses._Equal("N/A") && Ties._Equal("N/A")))
        {
            SaveFile.close();
            ui->SaveFile2->setText("Name: "+QString::fromStdString(Name)+" : Player: "+QString::fromStdString(Player)+" : Difficuly: "+QString::fromStdString(Difficulty)+" : Computer: "+QString::fromStdString(Computer)+"\nRed: "+QString::fromStdString(Wins)+" : Yellow: "+ QString::fromStdString(Loses)+" : Ties: "+QString::fromStdString(Ties));
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile2.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("SaveFile2 is corruptive, press the New button to create a new save."));
            ui->SaveFile2->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        }
    }
    SaveFile.open("SaveFiles\\SaveFile3.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile3.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        ui->SaveFile3->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile3 creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if((((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties))) || (Player._Equal("N/A") && Difficulty._Equal("N/A") && Computer._Equal("N/A") && Wins._Equal("N/A") && Loses._Equal("N/A") && Ties._Equal("N/A")))
        {
            SaveFile.close();
            ui->SaveFile3->setText("Name: "+QString::fromStdString(Name)+" : Player: "+QString::fromStdString(Player)+" : Difficuly: "+QString::fromStdString(Difficulty)+" : Computer: "+QString::fromStdString(Computer)+"\nRed: "+QString::fromStdString(Wins)+" : Yellow: "+ QString::fromStdString(Loses)+" : Ties: "+QString::fromStdString(Ties));
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile3.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("SaveFile3 is corruptive, press the New button to create a new save."));
            ui->SaveFile3->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nRed: N/A : Yellow: N/A : Ties: N/A");
        }
    }
}

void MainWindow::AIhardPick()
{
    ui->Loading->setHidden(false);
    ui->Drop0->setHidden(true);
    ui->Drop1->setHidden(true);
    ui->Drop2->setHidden(true);
    ui->Drop3->setHidden(true);
    ui->Drop4->setHidden(true);
    ui->Drop5->setHidden(true);
    ui->Drop6->setHidden(true);
    short loc = 0; // will be AI des
    if(ComputerRed)
    {
        root = new TopNode(Board, true);
        loc = root->getColDecision();
        delete root;
    }
    else
    {
        root = new TopNode(Board, false);
        loc = root->getColDecision();
        delete root;
    }
    Drop(loc);
    ui->Loading->setHidden(true);
    ui->Drop0->setHidden(false);
    ui->Drop1->setHidden(false);
    ui->Drop2->setHidden(false);
    ui->Drop3->setHidden(false);
    ui->Drop4->setHidden(false);
    ui->Drop5->setHidden(false);
    ui->Drop6->setHidden(false);
    checkWin(WhoWin(loc));
    RedGo = !RedGo;
}

void MainWindow::AIeasyPick()
{
    bool temp = true;
    while(temp)
    {
        short loc = rand() % 7;
        if(Drop(loc))
        {
            checkWin(WhoWin(loc));
            temp = false;
        }
    }
    RedGo = !RedGo;
}

short MainWindow::WhoWin(short location)
{
    short Prow = 0;
    for(short i = 0; i < 6; i++)
    {
        if(Board[i][location] != '-')
        {
            Prow = i;
            i = 6;
        }
    }
    if(RedGo)
    {
        if((goLeft(Prow, location - 1) + goRight(Prow, location + 1)) > 2 || goUpLeft(Prow - 1, location - 1) + goDownRight(Prow + 1, location + 1) > 2 || goDownLeft(Prow + 1, location - 1) + goUpRight(Prow - 1, location + 1) > 2 || goDown(Prow + 1, location) > 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(goLeft(Prow, location - 1) + goRight(Prow, location + 1) > 2 || goUpLeft(Prow - 1, location - 1) + goDownRight(Prow + 1, location + 1) > 2 || goDownLeft(Prow + 1, location - 1) + goUpRight(Prow - 1, location + 1) > 2 || goDown(Prow + 1, location) > 2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

short MainWindow::goLeft(short row, short col)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(RedGo)
        {
            if(Board[row][col] == 'R')
            {
                return 1 + goLeft(row, col - 1);
            }
            else
                return 0;
        }
        else
        {
            if(Board[row][col] == 'Y')
            {
                return 1 + goLeft(row, col - 1);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short MainWindow::goRight(short row, short col)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(RedGo)
        {
            if(Board[row][col] == 'R')
            {
                return 1 + goRight(row, col + 1);
            }
            else
                return 0;
        }
        else
        {
            if(Board[row][col] == 'Y')
            {
                return 1 + goRight(row, col + 1);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short MainWindow::goDown(short row, short col)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(RedGo)
        {
            if(Board[row][col] == 'R')
            {
                return 1 + goDown(row + 1, col);
            }
            else
                return 0;
        }
        else
        {
            if(Board[row][col] == 'Y')
            {
                return 1 + goDown(row + 1, col);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short MainWindow::goUpRight(short row, short col)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(RedGo)
        {
            if(Board[row][col] == 'R')
            {
                return 1 + goUpRight(row - 1, col + 1);
            }
            else
                return 0;
        }
        else
        {
            if(Board[row][col] == 'Y')
            {
                return 1 + goUpRight(row - 1, col + 1);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short MainWindow::goUpLeft(short row, short col)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(RedGo)
        {
            if(Board[row][col] == 'R')
            {
                return 1 + goUpLeft(row - 1, col - 1);
            }
            else
                return 0;
        }
        else
        {
            if(Board[row][col] == 'Y')
            {
                return 1 + goUpLeft(row - 1, col - 1);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short MainWindow::goDownRight(short row, short col)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(RedGo)
        {
            if(Board[row][col] == 'R')
            {
                return 1 + goDownRight(row + 1, col + 1);
            }
            else
                return 0;
        }
        else
        {
            if(Board[row][col] == 'Y')
            {
                return 1 + goDownRight(row + 1, col + 1);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short MainWindow::goDownLeft(short row, short col)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(RedGo)
        {
            if(Board[row][col] == 'R')
            {
                return 1 + goDownLeft(row + 1, col - 1);
            }
            else
                return 0;
        }
        else
        {
            if(Board[row][col] == 'Y')
            {
                return 1 + goDownLeft(row + 1, col - 1);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

void MainWindow::CreateSaveFile()
{
    ofstream createSaveFile;
    if(ui->PlayerOutput->text() == "Human" || (ui->PlayerOutput->text() == "Artificial\nIntelligence" && (ui->DifficultyOutput->text() == "Easy" || ui->DifficultyOutput->text() == "Impossible") && (ui->ComputerOutput->text() == "Red" || ui->ComputerOutput->text() == "Yellow")))
    {
        QString temp = "";
        for(int i = 0; i < ui->FileName->toPlainText().length(); i++)
        {
            if(ui->FileName->toPlainText()[i] != ' ' && ui->FileName->toPlainText()[i] != '\\')
            {
                temp += ui->FileName->toPlainText()[i];
            }
        }
        ui->FileName->setText(temp);
        if(ui->FileName->toPlainText() == "")
        {
            ui->FileName->setText("SaveFile#");
        }
        if(ui->PlayerOutput->text() == "Artificial\nIntelligence")
        {
            ui->PlayerOutput->setText("AI");
        }
        if(whichSaveFile == 1)
        {
            DeleteSaveFile1();
            createSaveFile.open("SaveFiles\\SaveFile1.txt");
            CreateGameBoard(createSaveFile);
        }
        else if(whichSaveFile == 2)
        {
            DeleteSaveFile2();
            createSaveFile.open("SaveFiles\\SaveFile2.txt");
            CreateGameBoard(createSaveFile);
        }
        else if(whichSaveFile == 3)
        {
            DeleteSaveFile3();
            createSaveFile.open("SaveFiles\\SaveFile3.txt");
            CreateGameBoard(createSaveFile);
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("Something went wrong please restart the program."));
        }
    }
    else
    {
         QMessageBox::information(this, tr("ERROR"), tr("Please input parameters"));
    }
}

void MainWindow::LoadSaveFile1()
{
    ifstream SaveFile;
    SaveFile.open("SaveFiles\\SaveFile1.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile1.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if(((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties)))
        {
            SaveFile.close();
            whichSaveFile = 1;
            if(Computer._Equal("Red"))
            {
                ComputerRed = true;
            }
            else
            {
                ComputerRed = false;
            }
            if(Difficulty._Equal("Impossible"))
            {
                whichMode = 2;
                if(ComputerRed)
                {
                    AIhardPick();
                }
            }
            else if(Difficulty._Equal("Easy"))
            {
                whichMode = 1;
                if(ComputerRed)
                {
                    AIeasyPick();
                }
            }
            else
            {
                whichMode = 0;
            }
            ui->SaveFile1->setHidden(true);
            ui->SaveFile2->setHidden(true);
            ui->SaveFile3->setHidden(true);
            ui->LoadSaveFile1->setHidden(true);
            ui->LoadSaveFile2->setHidden(true);
            ui->LoadSaveFile3->setHidden(true);
            ui->NewSaveFile1->setHidden(true);
            ui->NewSaveFile2->setHidden(true);
            ui->NewSaveFile3->setHidden(true);
            ui->DeleteSaveFile1->setHidden(true);
            ui->DeleteSaveFile2->setHidden(true);
            ui->DeleteSaveFile3->setHidden(true);
            ui->Board->setHidden(false);
            ui->Drop0->setHidden(false);
            ui->Drop1->setHidden(false);
            ui->Drop2->setHidden(false);
            ui->Drop3->setHidden(false);
            ui->Drop4->setHidden(false);
            ui->Drop5->setHidden(false);
            ui->Drop6->setHidden(false);
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile1.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("This SaveFile is corruptive or you hadn\'t created a SaveFile in the first place, press the New button to create a new save."));
        }
    }
}

void MainWindow::NewSaveFile1()
{
    whichSaveFile = 1;
    ui->SaveFile1->setHidden(true);
    ui->SaveFile2->setHidden(true);
    ui->SaveFile3->setHidden(true);
    ui->LoadSaveFile1->setHidden(true);
    ui->NewSaveFile1->setHidden(true);
    ui->DeleteSaveFile1->setHidden(true);
    ui->LoadSaveFile2->setHidden(true);
    ui->NewSaveFile2->setHidden(true);
    ui->DeleteSaveFile2->setHidden(true);
    ui->LoadSaveFile3->setHidden(true);
    ui->NewSaveFile3->setHidden(true);
    ui->DeleteSaveFile3->setHidden(true);
    ui->RedgoesFirst->setHidden(false);
    ui->Back->setHidden(false);
    ui->CreateFile->setHidden(false);
    ui->Human->setHidden(false);
    ui->ArtificialIntelligence->setHidden(false);
    ui->Player->setHidden(false);
    ui->PlayerOutput->setHidden(false);
    ui->Difficulty->setHidden(false);
    ui->DifficultyOutput->setHidden(false);
    ui->Computer->setHidden(false);
    ui->ComputerOutput->setHidden(false);
    ui->Name->setHidden(false);
    ui->FileName->setHidden(false);
}

void MainWindow::DeleteSaveFile1()
{
    ofstream SaveFile;
    SaveFile.open("SaveFiles\\SaveFile1.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile1.txt");
        createSaveFile.close();
        SaveFile.open("SaveFiles\\SaveFile1.txt");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile creating new one."));
    }
    SaveFile << "N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
    SaveFile.close();
    ui->SaveFile1->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nWins: N/A : Loses: N/A : Ties: N/A");
}

void MainWindow::LoadSaveFile2()
{
    ifstream SaveFile;
    SaveFile.open("SaveFiles\\SaveFile2.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile2.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if(((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties)))
        {
            SaveFile.close();
            whichSaveFile = 2;
            if(((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties)))
            {
                SaveFile.close();
                whichSaveFile = 1;
                if(Computer._Equal("Red"))
                {
                    ComputerRed = true;
                }
                else
                {
                    ComputerRed = false;
                }
                if(Difficulty._Equal("Impossible"))
                {
                    whichMode = 2;
                    if(ComputerRed)
                    {
                        AIhardPick();
                    }
                }
                else if(Difficulty._Equal("Easy"))
                {
                    whichMode = 1;
                    if(ComputerRed)
                    {
                        AIeasyPick();
                    }
                }
                else
                {
                    whichMode = 0;
                }
                ui->SaveFile1->setHidden(true);
                ui->SaveFile2->setHidden(true);
                ui->SaveFile3->setHidden(true);
                ui->LoadSaveFile1->setHidden(true);
                ui->LoadSaveFile2->setHidden(true);
                ui->LoadSaveFile3->setHidden(true);
                ui->NewSaveFile1->setHidden(true);
                ui->NewSaveFile2->setHidden(true);
                ui->NewSaveFile3->setHidden(true);
                ui->DeleteSaveFile1->setHidden(true);
                ui->DeleteSaveFile2->setHidden(true);
                ui->DeleteSaveFile3->setHidden(true);
                ui->Board->setHidden(false);
                ui->Drop0->setHidden(false);
                ui->Drop1->setHidden(false);
                ui->Drop2->setHidden(false);
                ui->Drop3->setHidden(false);
                ui->Drop4->setHidden(false);
                ui->Drop5->setHidden(false);
                ui->Drop6->setHidden(false);
            }
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile2.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("This SaveFile is corruptive or you hadn\'t created a SaveFile in the first place, press the New button to create a new save."));
        }
    }
}

void MainWindow::NewSaveFile2()
{
    whichSaveFile = 2;
    ui->SaveFile1->setHidden(true);
    ui->SaveFile2->setHidden(true);
    ui->SaveFile3->setHidden(true);
    ui->LoadSaveFile1->setHidden(true);
    ui->NewSaveFile1->setHidden(true);
    ui->DeleteSaveFile1->setHidden(true);
    ui->LoadSaveFile2->setHidden(true);
    ui->NewSaveFile2->setHidden(true);
    ui->DeleteSaveFile2->setHidden(true);
    ui->LoadSaveFile3->setHidden(true);
    ui->NewSaveFile3->setHidden(true);
    ui->DeleteSaveFile3->setHidden(true);
    ui->RedgoesFirst->setHidden(false);
    ui->Back->setHidden(false);
    ui->CreateFile->setHidden(false);
    ui->Human->setHidden(false);
    ui->ArtificialIntelligence->setHidden(false);
    ui->Player->setHidden(false);
    ui->PlayerOutput->setHidden(false);
    ui->Difficulty->setHidden(false);
    ui->DifficultyOutput->setHidden(false);
    ui->Computer->setHidden(false);
    ui->ComputerOutput->setHidden(false);
    ui->Name->setHidden(false);
    ui->FileName->setHidden(false);

}

void MainWindow::DeleteSaveFile2()
{
    ofstream SaveFile;
    SaveFile.open("SaveFiles\\SaveFile2.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile2.txt");
        createSaveFile.close();
        SaveFile.open("SaveFiles\\SaveFile2.txt");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile creating new one."));
    }
    SaveFile << "N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
    SaveFile.close();
    ui->SaveFile2->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nWins: N/A : Loses: N/A : Ties: N/A");
}

void MainWindow::LoadSaveFile3()
{
    ifstream SaveFile;
    SaveFile.open("SaveFiles\\SaveFile3.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile3.txt");
        createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
        createSaveFile.close();
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile creating new one, press the New button to create a new save."));
    }
    else
    {
        string Name, Player, Difficulty, Computer, Wins, Loses, Ties;
        SaveFile >> Name >> Player >> Difficulty >> Computer >> Wins >> Loses >> Ties;
        if(((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties)))
        {
            SaveFile.close();
            whichSaveFile = 3;
            if(((Player._Equal("Human") && Difficulty._Equal("N/A") && Computer._Equal("N/A")) || (Player._Equal("AI") && (Difficulty._Equal("Easy") || Difficulty._Equal("Impossible")) && (Computer._Equal("Yellow") || Computer._Equal("Red")))) && (isParam(Wins) && isParam(Loses) && isParam(Ties)))
            {
                SaveFile.close();
                whichSaveFile = 1;
                if(Computer._Equal("Red"))
                {
                    ComputerRed = true;
                }
                else
                {
                    ComputerRed = false;
                }
                if(Difficulty._Equal("Impossible"))
                {
                    whichMode = 2;
                    if(ComputerRed)
                    {
                        AIhardPick();
                    }
                }
                else if(Difficulty._Equal("Easy"))
                {
                    whichMode = 1;
                    if(ComputerRed)
                    {
                        AIeasyPick();
                    }
                }
                else
                {
                    whichMode = 0;
                }
                ui->SaveFile1->setHidden(true);
                ui->SaveFile2->setHidden(true);
                ui->SaveFile3->setHidden(true);
                ui->LoadSaveFile1->setHidden(true);
                ui->LoadSaveFile2->setHidden(true);
                ui->LoadSaveFile3->setHidden(true);
                ui->NewSaveFile1->setHidden(true);
                ui->NewSaveFile2->setHidden(true);
                ui->NewSaveFile3->setHidden(true);
                ui->DeleteSaveFile1->setHidden(true);
                ui->DeleteSaveFile2->setHidden(true);
                ui->DeleteSaveFile3->setHidden(true);
                ui->Board->setHidden(false);
                ui->Drop0->setHidden(false);
                ui->Drop1->setHidden(false);
                ui->Drop2->setHidden(false);
                ui->Drop3->setHidden(false);
                ui->Drop4->setHidden(false);
                ui->Drop5->setHidden(false);
                ui->Drop6->setHidden(false);
            }
        }
        else
        {
            SaveFile.close();
            ofstream createSaveFile("SaveFiles\\SaveFile3.txt");
            createSaveFile<<"N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
            createSaveFile.close();
            QMessageBox::information(this, tr("ERROR"), tr("This SaveFile is corruptive or you hadn\'t created a SaveFile in the first place, press the New button to create a new save."));
        }
    }
}

void MainWindow::NewSaveFile3()
{
    whichSaveFile = 3;
    ui->SaveFile1->setHidden(true);
    ui->SaveFile2->setHidden(true);
    ui->SaveFile3->setHidden(true);
    ui->LoadSaveFile1->setHidden(true);
    ui->NewSaveFile1->setHidden(true);
    ui->DeleteSaveFile1->setHidden(true);
    ui->LoadSaveFile2->setHidden(true);
    ui->NewSaveFile2->setHidden(true);
    ui->DeleteSaveFile2->setHidden(true);
    ui->LoadSaveFile3->setHidden(true);
    ui->NewSaveFile3->setHidden(true);
    ui->DeleteSaveFile3->setHidden(true);
    ui->RedgoesFirst->setHidden(false);
    ui->Back->setHidden(false);
    ui->CreateFile->setHidden(false);
    ui->Human->setHidden(false);
    ui->ArtificialIntelligence->setHidden(false);
    ui->Player->setHidden(false);
    ui->PlayerOutput->setHidden(false);
    ui->Difficulty->setHidden(false);
    ui->DifficultyOutput->setHidden(false);
    ui->Computer->setHidden(false);
    ui->ComputerOutput->setHidden(false);
    ui->Name->setHidden(false);
    ui->FileName->setHidden(false);

}

void MainWindow::DeleteSaveFile3()
{
    ofstream SaveFile;
    SaveFile.open("SaveFiles\\SaveFile3.txt");
    if(SaveFile.fail())
    {
        SaveFile.close();
        ofstream createSaveFile("SaveFiles\\SaveFile3.txt");
        createSaveFile.close();
        SaveFile.open("SaveFiles\\SaveFile3.txt");
        QMessageBox::information(this, tr("ERROR"), tr("Could not find SaveFile creating new one."));
    }
    SaveFile << "N/A\nN/A\nN/A\nN/A\nN/A\nN/A\nN/A";
    SaveFile.close();
    ui->SaveFile3->setText("Name: N/A : Player: N/A : Difficuly: N/A : Computer: N/A\nWins: N/A : Loses: N/A : Ties: N/A");
}

bool MainWindow::isParam(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    bool a = *p == 0;
    if(a)
        return stoi(line) >= 0;
    else
        return a;
}

MainWindow::~MainWindow()
{
    delete ui;
}
