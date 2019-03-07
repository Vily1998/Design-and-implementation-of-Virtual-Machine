/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_START;
    QTextEdit *textEdit_PC;
    QTextEdit *textEdit_IAR;
    QTextEdit *textEdit_SP;
    QTextEdit *textEdit_PSW;
    QTextEdit *textEdit_IR;
    QPushButton *pushButton_STEP;
    QPushButton *pushButton_CONTINUOUS;
    QTextEdit *textEdit_G;
    QTextEdit *textEdit_D;
    QTextEdit *textEdit_F;
    QTextEdit *textEdit_B;
    QTextEdit *textEdit_C;
    QTextEdit *textEdit_H;
    QTextEdit *textEdit_A;
    QTextEdit *textEdit_E;
    QPushButton *pushButton_STOP;
    QTextEdit *textEdit_N;
    QTextEdit *textEdit_I;
    QTextEdit *textEdit_K;
    QTextEdit *textEdit_P;
    QTextEdit *textEdit_J;
    QTextEdit *textEdit_M;
    QTextEdit *textEdit_O;
    QTextEdit *textEdit_L;
    QTextEdit *textEdit_state;
    QPushButton *pushButton_LOAD;
    QTextEdit *textEdit_out;
    QPushButton *pushButton_INTERRUPT;
    QPushButton *pushButton_RECVER;
    QTextEdit *textEdit_error;
    QTextEdit *textEdit_IN;
    QPushButton *pushButton_work;
    QPushButton *pushButton_clear;
    QSlider *Slider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_10;
    QTextEdit *textEdit_3;
    QLabel *label_11;
    QPushButton *pushButton_help;
    QPushButton *pushButton_quit;
    QTextEdit *textEdit_stack;
    QLabel *label_12;
    QGroupBox *groupBox;
    QRadioButton *radioButton_user;
    QRadioButton *radioButton_kernel;
    QTextEdit *textEdit_count;
    QLabel *label_13;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1600, 878);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(1060, 290, 521, 521));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 290, 341, 331));
        textEdit_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton_START = new QPushButton(centralWidget);
        pushButton_START->setObjectName(QStringLiteral("pushButton_START"));
        pushButton_START->setGeometry(QRect(400, 310, 191, 31));
        textEdit_PC = new QTextEdit(centralWidget);
        textEdit_PC->setObjectName(QStringLiteral("textEdit_PC"));
        textEdit_PC->setGeometry(QRect(970, 10, 161, 31));
        textEdit_IAR = new QTextEdit(centralWidget);
        textEdit_IAR->setObjectName(QStringLiteral("textEdit_IAR"));
        textEdit_IAR->setGeometry(QRect(1140, 10, 161, 31));
        textEdit_SP = new QTextEdit(centralWidget);
        textEdit_SP->setObjectName(QStringLiteral("textEdit_SP"));
        textEdit_SP->setGeometry(QRect(970, 50, 161, 31));
        textEdit_PSW = new QTextEdit(centralWidget);
        textEdit_PSW->setObjectName(QStringLiteral("textEdit_PSW"));
        textEdit_PSW->setGeometry(QRect(1140, 50, 161, 31));
        textEdit_IR = new QTextEdit(centralWidget);
        textEdit_IR->setObjectName(QStringLiteral("textEdit_IR"));
        textEdit_IR->setGeometry(QRect(800, 10, 161, 71));
        pushButton_STEP = new QPushButton(centralWidget);
        pushButton_STEP->setObjectName(QStringLiteral("pushButton_STEP"));
        pushButton_STEP->setGeometry(QRect(400, 410, 93, 31));
        pushButton_CONTINUOUS = new QPushButton(centralWidget);
        pushButton_CONTINUOUS->setObjectName(QStringLiteral("pushButton_CONTINUOUS"));
        pushButton_CONTINUOUS->setGeometry(QRect(500, 410, 93, 31));
        textEdit_G = new QTextEdit(centralWidget);
        textEdit_G->setObjectName(QStringLiteral("textEdit_G"));
        textEdit_G->setGeometry(QRect(970, 140, 161, 31));
        textEdit_D = new QTextEdit(centralWidget);
        textEdit_D->setObjectName(QStringLiteral("textEdit_D"));
        textEdit_D->setGeometry(QRect(1140, 100, 161, 31));
        textEdit_F = new QTextEdit(centralWidget);
        textEdit_F->setObjectName(QStringLiteral("textEdit_F"));
        textEdit_F->setGeometry(QRect(800, 140, 161, 31));
        textEdit_B = new QTextEdit(centralWidget);
        textEdit_B->setObjectName(QStringLiteral("textEdit_B"));
        textEdit_B->setGeometry(QRect(800, 100, 161, 31));
        textEdit_C = new QTextEdit(centralWidget);
        textEdit_C->setObjectName(QStringLiteral("textEdit_C"));
        textEdit_C->setGeometry(QRect(970, 100, 161, 31));
        textEdit_H = new QTextEdit(centralWidget);
        textEdit_H->setObjectName(QStringLiteral("textEdit_H"));
        textEdit_H->setGeometry(QRect(1140, 140, 161, 31));
        textEdit_A = new QTextEdit(centralWidget);
        textEdit_A->setObjectName(QStringLiteral("textEdit_A"));
        textEdit_A->setGeometry(QRect(630, 100, 161, 31));
        textEdit_E = new QTextEdit(centralWidget);
        textEdit_E->setObjectName(QStringLiteral("textEdit_E"));
        textEdit_E->setGeometry(QRect(630, 140, 161, 31));
        pushButton_STOP = new QPushButton(centralWidget);
        pushButton_STOP->setObjectName(QStringLiteral("pushButton_STOP"));
        pushButton_STOP->setGeometry(QRect(400, 550, 191, 31));
        textEdit_N = new QTextEdit(centralWidget);
        textEdit_N->setObjectName(QStringLiteral("textEdit_N"));
        textEdit_N->setGeometry(QRect(800, 220, 161, 31));
        textEdit_I = new QTextEdit(centralWidget);
        textEdit_I->setObjectName(QStringLiteral("textEdit_I"));
        textEdit_I->setGeometry(QRect(630, 180, 161, 31));
        textEdit_K = new QTextEdit(centralWidget);
        textEdit_K->setObjectName(QStringLiteral("textEdit_K"));
        textEdit_K->setGeometry(QRect(970, 180, 161, 31));
        textEdit_P = new QTextEdit(centralWidget);
        textEdit_P->setObjectName(QStringLiteral("textEdit_P"));
        textEdit_P->setGeometry(QRect(1140, 220, 161, 31));
        textEdit_J = new QTextEdit(centralWidget);
        textEdit_J->setObjectName(QStringLiteral("textEdit_J"));
        textEdit_J->setGeometry(QRect(800, 180, 161, 31));
        textEdit_M = new QTextEdit(centralWidget);
        textEdit_M->setObjectName(QStringLiteral("textEdit_M"));
        textEdit_M->setGeometry(QRect(630, 220, 161, 31));
        textEdit_O = new QTextEdit(centralWidget);
        textEdit_O->setObjectName(QStringLiteral("textEdit_O"));
        textEdit_O->setGeometry(QRect(970, 220, 161, 31));
        textEdit_L = new QTextEdit(centralWidget);
        textEdit_L->setObjectName(QStringLiteral("textEdit_L"));
        textEdit_L->setGeometry(QRect(1140, 180, 161, 31));
        textEdit_state = new QTextEdit(centralWidget);
        textEdit_state->setObjectName(QStringLiteral("textEdit_state"));
        textEdit_state->setGeometry(QRect(80, 70, 281, 71));
        textEdit_state->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton_LOAD = new QPushButton(centralWidget);
        pushButton_LOAD->setObjectName(QStringLiteral("pushButton_LOAD"));
        pushButton_LOAD->setGeometry(QRect(400, 360, 191, 31));
        textEdit_out = new QTextEdit(centralWidget);
        textEdit_out->setObjectName(QStringLiteral("textEdit_out"));
        textEdit_out->setGeometry(QRect(630, 290, 421, 221));
        textEdit_out->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton_INTERRUPT = new QPushButton(centralWidget);
        pushButton_INTERRUPT->setObjectName(QStringLiteral("pushButton_INTERRUPT"));
        pushButton_INTERRUPT->setGeometry(QRect(400, 500, 93, 31));
        pushButton_RECVER = new QPushButton(centralWidget);
        pushButton_RECVER->setObjectName(QStringLiteral("pushButton_RECVER"));
        pushButton_RECVER->setGeometry(QRect(500, 500, 93, 31));
        textEdit_error = new QTextEdit(centralWidget);
        textEdit_error->setObjectName(QStringLiteral("textEdit_error"));
        textEdit_error->setGeometry(QRect(80, 150, 281, 51));
        textEdit_error->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        textEdit_IN = new QTextEdit(centralWidget);
        textEdit_IN->setObjectName(QStringLiteral("textEdit_IN"));
        textEdit_IN->setGeometry(QRect(630, 540, 421, 231));
        textEdit_IN->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton_work = new QPushButton(centralWidget);
        pushButton_work->setObjectName(QStringLiteral("pushButton_work"));
        pushButton_work->setGeometry(QRect(910, 780, 93, 28));
        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(800, 780, 93, 28));
        Slider = new QSlider(centralWidget);
        Slider->setObjectName(QStringLiteral("Slider"));
        Slider->setGeometry(QRect(400, 450, 191, 31));
        Slider->setMaximum(5000);
        Slider->setSingleStep(100);
        Slider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 0, 251, 61));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 70);\n"
"font: 28pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 20, 141, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(670, 10, 141, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 70, 131, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 150, 131, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 260, 131, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(630, 260, 131, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(630, 510, 131, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1060, 260, 131, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(630, 70, 161, 31));
        label_10->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(20, 650, 341, 161));
        textEdit_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 620, 131, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        pushButton_help = new QPushButton(centralWidget);
        pushButton_help->setObjectName(QStringLiteral("pushButton_help"));
        pushButton_help->setGeometry(QRect(400, 600, 191, 31));
        pushButton_quit = new QPushButton(centralWidget);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(400, 650, 191, 31));
        textEdit_stack = new QTextEdit(centralWidget);
        textEdit_stack->setObjectName(QStringLiteral("textEdit_stack"));
        textEdit_stack->setGeometry(QRect(1320, 40, 261, 211));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(1320, 10, 161, 31));
        label_12->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(410, 110, 171, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(14);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral(""));
        radioButton_user = new QRadioButton(groupBox);
        radioButton_user->setObjectName(QStringLiteral("radioButton_user"));
        radioButton_user->setGeometry(QRect(30, 30, 141, 41));
        radioButton_user->setMinimumSize(QSize(20, 20));
        radioButton_user->setSizeIncrement(QSize(0, 0));
        radioButton_user->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        radioButton_user->setFont(font1);
        radioButton_user->setCursor(QCursor(Qt::ArrowCursor));
        radioButton_user->setAutoFillBackground(false);
        radioButton_user->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        radioButton_user->setIconSize(QSize(20, 20));
        radioButton_kernel = new QRadioButton(groupBox);
        radioButton_kernel->setObjectName(QStringLiteral("radioButton_kernel"));
        radioButton_kernel->setGeometry(QRect(30, 70, 131, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(12);
        radioButton_kernel->setFont(font2);
        radioButton_kernel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        textEdit_count = new QTextEdit(centralWidget);
        textEdit_count->setObjectName(QStringLiteral("textEdit_count"));
        textEdit_count->setGeometry(QRect(150, 220, 211, 31));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 220, 141, 31));
        label_13->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_START->setText(QApplication::translate("MainWindow", "\345\274\200\346\234\272", Q_NULLPTR));
        pushButton_STEP->setText(QApplication::translate("MainWindow", "\345\215\225\346\213\215", Q_NULLPTR));
        pushButton_CONTINUOUS->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255", Q_NULLPTR));
        pushButton_STOP->setText(QApplication::translate("MainWindow", "\345\201\234\346\234\272", Q_NULLPTR));
        pushButton_LOAD->setText(QApplication::translate("MainWindow", "\350\243\205\350\275\275", Q_NULLPTR));
        pushButton_INTERRUPT->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\255\350\257\267\346\261\202", Q_NULLPTR));
        pushButton_RECVER->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\255\346\201\242\345\244\215", Q_NULLPTR));
        pushButton_work->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\350\231\232\346\213\237\346\234\272 V5.0", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\342\200\224\342\200\224\345\274\240\347\273\215\347\243\212", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\211\271\346\256\212\345\257\204\345\255\230\345\231\250\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\274\202\345\270\270\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\347\250\213\345\272\217\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\214\272\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\276\223\345\205\245\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\351\200\232\347\224\250\345\257\204\345\255\230\345\231\250\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\255\345\255\220\347\250\213\345\272\217\357\274\232", Q_NULLPTR));
        pushButton_help->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        pushButton_quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\345\240\206\346\240\210\357\274\232", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217\351\200\211\346\213\251", Q_NULLPTR));
        radioButton_user->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\346\250\241\345\274\217", Q_NULLPTR));
        radioButton_kernel->setText(QApplication::translate("MainWindow", "\345\206\205\346\240\270\346\250\241\345\274\217", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214\346\214\207\344\273\244\346\225\260\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
