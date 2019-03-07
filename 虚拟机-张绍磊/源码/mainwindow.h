#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <QFile>
#include <time.h>
#include <QTime>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QDateTime>
#include "dialog.h"

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();





    //指令操作名称
    const char *CMD[37] = { "RUN", "STOP", "ECHO", "ADD", "SUB", "MUL", "DIV",
                            "MOL" ,"INC", "DEC", "CMP","AND","OR","NOT","SAL",
                            "SAR","MOV","LAD","STO","SET","SAVE","PUSH","POP",
                            "JMP","JG","JL","JE","EMP","CLR","EI","IRET","IN",
                            "LPSW","SPC","LPC","LIAR","SIAR"
                            };




    //测试程序指令条数
    int lines;
    //程序（汇编代码）存储区
    char code[105][20];

    //中断子程序指令条数
    int inter_lines;
    //中断子程序存储区
    char inter_code[105][20];

    //64位存储器 0x0000-0xFFFF
    //char memory[0xFFFF][16];

    //16个64位通用寄存器
    unsigned long long int reg[16];
    //用于中断时，保护现场的16个通用寄存器
    unsigned long long int reg_tmp[16];

    //程序计数器PC
    int PC;
    //地址寄存器
    int AR;
    //指令寄存器
    char IR[20];
    //中断地址寄存器
    int IAR;
    //栈地址寄存器
    int SP;
    //状态字寄存器 记录上一次CMP结果，1：大于 2：小于 3：等于
    int PSW;//运行前初始化为0表示从未执行过CMP
    //用于中断时，保护现场的状态字寄存器
    int PSW_tmp;
    //输入缓冲区
    int buffer[100];
    //输入缓冲区数据首地址
    int buffer_first;
    //输入缓冲区数据尾地址
    int buffer_last;


    int model;

    //指令编号
    int cmd;
    //指令中两个地址码
    char X[10], Y[10];
    //是否终止
    int terminated = 0;
    //是否中断
    int is_interrupt;
    //程序执行条数
    int count = 0;
    //主频
    int M;
    //测试程序文件名
    QString file_name;

    int state;
    //0:未开机
    //1:开机未加载程序
    //2:程序加载完成
    //3:程序运行中
    //4:中断中
    //5:停机

    int error;
    //0:程序运行正常
    //1:未加载程序时开始执行
    //2:指令包含非法操作数
    //3:寄存器超出规定数量
    //4:条件跳转时，未比较，但尝试跳转
    //5:在存储器中寻址时超出预设范围
    //6:弹栈时，堆栈里无数据
    //7:堆栈区溢出
    //8:陷入循环
    //9:中断中再次申请中断
    //10:未中断时，中断恢复
    //11:未中断时，手动输入指令
    //12:除数为0
    //13:用户模式下，执行特权指令



protected slots:



    void Run(); //运行程序
    void init();    //初始化
    void load();    //加载测试程序
    int read();    //读取指令
    int operate();  //执行指令
    void show_error();  //检错和异常显示
    void interrupt();   //中断请求
    void recover();   //中断恢复
    void show_reg();    //寄存器图形化显示
    void show_state();  //运行状态图形化显示
    void show_stack();  //堆栈图形化显示
    void sleep(int msec);   //延时函数
    void setValue(int x);   //修改主频
    void protect(); //中断保护现场

    unsigned long long int HEX_DEC(char *s, int n);    //16进制转10进制
    void DEC_HEX(unsigned long long n, char res[]); //10进制转16进制
    void DEC_BIN(unsigned long long n, int res[]);  //10进制转2进制
    unsigned long long int BIN_DEC(int res[]);  //2进制转10进制



private slots:

    void on_pushButton_START_clicked(); //开机
    void on_pushButton_STOP_clicked();  //停机
    void on_pushButton_LOAD_clicked();  //装载测试程序
    void on_pushButton_CONTINUOUS_clicked();    //连续执行
    void on_pushButton_STEP_clicked();  //单拍执行
    void on_pushButton_INTERRUPT_clicked(); //中断申请
    void on_pushButton_RECVER_clicked();    //中断恢复
    void on_pushButton_clear_clicked(); //清空输入区
    void on_pushButton_work_clicked();  //执行输入区指令
    void on_pushButton_quit_clicked();  //退出程序
    void on_pushButton_help_clicked();  //帮助
    void on_radioButton_user_clicked(); //切换用户模式
    void on_radioButton_kernel_clicked();   //切换内核模式
    void on_pushButton_clicked();   //输入

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
