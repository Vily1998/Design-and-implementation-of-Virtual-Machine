#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"

#include <QtGui>

#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Slider, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
}

//64位存储器 0000-FFFF
char memory[0xFFFF][16];

MainWindow::~MainWindow()
{
    delete ui;
}


//开机
void MainWindow::on_pushButton_START_clicked()
{
    Run();
}

//单拍
void MainWindow::on_pushButton_STEP_clicked()
{
    if(!terminated&&is_interrupt==0)
    {

        if(state==0||state==1)
        {
            error=1;
        }
        else
        {
            int e1,e2;
            e1=read();
            if(e1!=-1)
            {
                e2=operate();
            }
            if(e1==-1||e2==-1)
            {
                ui->textEdit->append("ERROR\n");
            }
            show_state();
            show_reg();
            show_stack();

        }
        PC++;

        show_error();
    }

}

//连续
void MainWindow::on_pushButton_CONTINUOUS_clicked()
{

    while(!terminated&&is_interrupt==0)
    {

        if(state==0||state==1)
        {
            error=1;
            break;
        }
        else
        {
            int e1,e2;
            e1=read();
            if(e1!=-1)
            {
                e2=operate();
            }
            if(e1==-1||e2==-1)
            {
                ui->textEdit->append("ERROR\n");
            }

            show_state();
            show_reg();

        }
        PC++;
        show_error();
        sleep(M);
        if(is_interrupt==1)
        {
            memset(reg_tmp, 0, sizeof(reg_tmp));
            IAR++;
            PSW_tmp=PSW;

            for(int i=0;i<16;i++)
            {
                reg_tmp[i]=reg[i];
            }
            PC=0xE000;
        }
        show_state();
        show_reg();
        show_stack();
    }

}

//停机
void MainWindow::on_pushButton_STOP_clicked()
{
    terminated=1;
    state=5;
    show_state();
    show_reg();
    show_error();
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_A->clear();
    ui->textEdit_B->clear();
    ui->textEdit_C->clear();
    ui->textEdit_D->clear();
    ui->textEdit_E->clear();
    ui->textEdit_F->clear();
    ui->textEdit_G->clear();
    ui->textEdit_H->clear();
    ui->textEdit_I->clear();
    ui->textEdit_J->clear();
    ui->textEdit_K->clear();
    ui->textEdit_L->clear();
    ui->textEdit_M->clear();
    ui->textEdit_N->clear();
    ui->textEdit_O->clear();
    ui->textEdit_P->clear();
    ui->textEdit_error->clear();
    ui->textEdit_IAR->clear();
    ui->textEdit_IN->clear();
    ui->textEdit_IR->clear();
    ui->textEdit_out->clear();
    ui->textEdit_PC->clear();
    ui->textEdit_PSW->clear();
    ui->textEdit_SP->clear();
    ui->textEdit_state->clear();
    ui->textEdit_count->clear();
    ui->textEdit_stack->clear();
}

//装载
void MainWindow::on_pushButton_LOAD_clicked()
{
    load();
    show_state();
    show_reg();
    show_error();
}

//中断请求
void MainWindow::on_pushButton_INTERRUPT_clicked()
{
    interrupt();
    show_state();
    show_reg();
    show_error();
}

//中断恢复
void MainWindow::on_pushButton_RECVER_clicked()
{
    recover();
    show_state();
    show_reg();
    show_error();
}

//输入区清空
void MainWindow::on_pushButton_clear_clicked()
{
    ui->textEdit_IN->clear();
}

//执行输入区指令
void MainWindow::on_pushButton_work_clicked()
{
    if(is_interrupt==1&&!terminated)
    {
        inter_lines=0;
        QString text = ui->textEdit_IN->toPlainText();
        QStringList number_list = text.split("\n");
        memset(inter_code, '\0', sizeof(inter_code));
        for (inter_lines = 0; inter_lines < number_list.size(); inter_lines++)
        {
            char*  ch;
            QByteArray ba = number_list.at(inter_lines).toLatin1(); // must
            ch=ba.data();
            for(int i=0;i<20;i++)
            {
                inter_code[inter_lines][i]=ch[i];
                memory[inter_lines+PC][i]=ch[i];

            }

            ui->textEdit_3->append(QString::number(PC+inter_lines,16)+"    "+QString(QLatin1String(inter_code[inter_lines])));

        }
        while(inter_lines--&&memory[PC][0]!='\0')
        {

            if(state==0||state==1)
            {
                error=1;
                break;
            }
            else
            {
                int e1,e2;
                e1=read();
                if(e1!=-1)
                {
                    e2=operate();
                }
                if(e1==-1||e2==-1)
                {
                    ui->textEdit->append("ERROR\n");
                }
                show_state();
                show_reg();
                show_stack();
            }
            PC++;
            show_error();
            //sleep(M);
        }
    }
    else
    {
        error=11;
        show_state();
        show_reg();
        show_stack();
        show_error();
    }
}

//帮助
void MainWindow::on_pushButton_help_clicked()
{
    Dialog *dd=new Dialog;//使用Qt Designer From Class新添加的类，需要#include"dialog.h"
        dd->show();
}


//退出程序
void MainWindow::on_pushButton_quit_clicked()
{
    qApp->quit();
}

//切换用户模式
void MainWindow::on_radioButton_user_clicked()
{
    model=0;
}

//切换内核模式
void MainWindow::on_radioButton_kernel_clicked()
{
    model=1;
}

//输入
void MainWindow::on_pushButton_clicked()
{

    QString text = ui->textEdit_INPUT->toPlainText();
    QStringList number_list = text.split(" ");
    for (int i = 0; i < number_list.size(); i++)
    {
        int tmp = number_list.at(i).toInt();
        buffer[buffer_last]=tmp;
        buffer_last++;
    }
    ui->textEdit_INPUT->clear();
}





//开机
void MainWindow::Run()
{
    init();
    state=1;
    show_state();
    show_reg();
    show_stack();
    show_error();
}

//初始化
void MainWindow::init()
{
    lines = 0;
    inter_lines=0;
    PC = 0;
    AR = 0;
    IAR = 0;
    SP = 0xC000;
    PSW = 0;
    PSW_tmp=0;
    terminated = 0;
    is_interrupt=0;
    model=0;
    state=0;
    cmd=-1;
    count=0;
    buffer_first=0;
    buffer_last=0;
    M=0;
    memset(buffer, 0, sizeof(buffer));
    memset(memory, '\0', sizeof(memory));
    memset(reg, 0, sizeof(reg));
    memset(code, '\0', sizeof(code));
    memset(inter_code, '\0', sizeof(inter_code));
}

//加载程序
void MainWindow::load()
{
    //初始化总行数，程序计数器为0
    lines = PC = 0;
    //括号里的参数分别是：指定父类、标题、默认打开后显示的目录、右下角的文件过滤器。
    file_name = QFileDialog::getOpenFileName(NULL,"选择测试文件",".","*.txt");
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qDebug()<<"Can't open the file!"<<endl;
        ui->textEdit->append("Can't open the file!");
    }
    lines=0;
    while(!file.atEnd())
    {
        QString line = file.readLine();
        QByteArray ba = line.toLatin1();
        char* ch;
        ch = ba.data();
        int i;
        for(i=0;ch[i]!='\r'&&ch[i]!='\n';i++)
        {
            code[lines][i]=ch[i];
            memory[lines][i]=ch[i];
        }
        ui->textEdit_2->append(QString::number(lines,16)+"    "+QString(QLatin1String(code[lines])));
        lines++;
    }
    state=2;
    ui->statusBar->showMessage("Test program is loaded", 1000);
}

//读取指令
int MainWindow::read()
{
    strcpy(IR, memory[PC]);
    ui->textEdit->append(QString::number(PC,16)+"    "+QString(QLatin1String(IR))+" :");
    QApplication::processEvents();
    //ui->textEdit->append(QString(QLatin1String(IR)));
    int len = strlen(IR);
    int blank = 0;
    int j = 0, k = len;
    memset(X,'\0',sizeof(X));
    memset(Y,'\0',sizeof(Y));
    cmd=-1;
    for (int i = 0; i < len; i++)
    {
        if (IR[i] == ' ' && blank == 0)
        {
            j = i;
            blank++;
        }
        else if (IR[i] == ' ' && blank == 1)
        {
            k = i;
            blank++;
        }
    }
    for (int i = 0; i < 37; i++)
    {
        //ui->textEdit->append("******\n");
        QApplication::processEvents();
        if (strstr(IR, CMD[i]) != NULL)
        {
            cmd = i;
            break;
        }
    }
    if(cmd==-1)
    {
        //ui->textEdit->append("!!!\n");
        QApplication::processEvents();
        error=2;
        return -1;
    }
    for (int i = 0; i < k - j - 1; i++)
    {
        X[i] = IR[j + i + 1];
        //printf("******\n");
    }
    for (int i = 0; i < len - k -  1; i++)
    {
        Y[i] = IR[k + i + 1];
    }

    if((X[0]>'P'||X[0]<'A')&&X[1]=='X')
    {
        error=3;
        return -1;
    }
    if((Y[0]>'P'||Y[0]<'A')&&Y[1]=='X')
    {
        error=3;
        return -1;
    }
    return 0;
    //ui->textEdit->append(QString::number(cmd));
    //ui->textEdit->append(QString(QLatin1String(X)));
    //ui->textEdit->append(QString(QLatin1String(Y)));
}

//执行指令
int MainWindow::operate()
{
    //PC++;
    int len_a,len_b;
    int ta, tb;	//两个操作数
    unsigned long long int a,b,c;
    if(!is_interrupt) state=3;
    int aa[64], bb[64], cc[64];
    char dd[16];
    ui->statusBar->showMessage("Instruction Executing", 500);
    switch (cmd)
    {
        case 0:	//RUN
            ui->textEdit->append("START\n");
            break;

        case 1:	//STOP
            terminated = 1;
            state=5;
            ui->textEdit->append("SHUT DOWN\n");
            break;

        case 2:	//ECHO
            ta = X[0] - 'A';
            //printf("%c %d ",X[0], ta);
            //printf("%llX\n", reg[ta]);
            ui->textEdit_out->append(QString::number(reg[ta]));
            ui->textEdit->append(QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");
            //printf("%llX\n", reg[0]);
            break;

        case 3:	//ADD
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            //printf("%llX + %llX = ", reg[ta], reg[tb]);
            a=reg[ta];
            b=reg[tb];
            c=a+b;
            reg[ta]=c;
            ui->textEdit->append(QString::number(a,16)+" + "+QString::number(b,16)+" = "+QString::number(c,16)+"\n");
            //printf("%llX\n", reg[ta]);
            break;

        case 4:	//SUB
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            //printf("%llX - %llX = ", reg[ta], reg[tb]);
            a=reg[ta];
            b=reg[tb];
            c=a-b;
            reg[ta]=c;
            ui->textEdit->append(QString::number(a,16)+" - "+QString::number(b,16)+" = "+QString::number(c,16)+"\n");
            //printf("%llX\n", reg[ta]);
            break;

        case 5:	//MUL
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            //printf("%llX * %llX = ", reg[ta], reg[tb]);
            a=reg[ta];
            b=reg[tb];
            c=a*b;
            reg[ta]=c;
            ui->textEdit->append(QString::number(a,16)+" * "+QString::number(b,16)+" = "+QString::number(c,16)+"\n");
            //printf("%llX\n", reg[ta]);
            break;

        case 6:	//DIV
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            //printf("%llX / %llX = ", reg[ta], reg[tb]);
            a=reg[ta];
            b=reg[tb];
            if(b==0)
            {
                error=12;
                return -1;
            }
            c=a/b;
            reg[ta]=c;
            ui->textEdit->append(QString::number(a,16)+" / "+QString::number(b,16)+" = "+QString::number(c,16)+"\n");
            //printf("%llX\n", reg[ta]);
            break;

        case 7:	//MOL
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            //printf("%llX / %llX = ", reg[ta], reg[tb]);
            a=reg[ta];
            b=reg[tb];
            if(b==0)
            {
                error=12;
                return -1;
            }
            c=a%b;
            reg[ta]=c;
            ui->textEdit->append(QString::number(a,16)+" MOL "+QString::number(b,16)+" = "+QString::number(c,16)+"\n");
            //printf("%llX\n", reg[ta]);
            break;



        case 8:	//INC
            ta = X[0] - 'A';
            //printf("%llX + 1 = ", reg[ta]);
            a=reg[ta];
            c=a+1;
            reg[ta]=c;
            ui->textEdit->append(QString::number(a,16)+" + 1"+" = "+QString::number(c,16)+"\n");
            //printf("%llX\n", reg[ta]);
            break;

        case 9:	//DEC
            ta = X[0] - 'A';
            //printf("%llX - 1 = ", reg[ta]);
            a=reg[ta];
            c=a-1;
            reg[ta]=c;
            ui->textEdit->append(QString::number(a,16)+" - 1"+" = "+QString::number(c,16)+"\n");
            //printf("%llX\n", reg[ta]);
            break;

        case 10:	//CMP
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            if (reg[ta] > reg[tb])
            {
                PSW = 1;
                //printf("%llX > %llX\n", reg[ta], reg[tb]);
                ui->textEdit->append(QString::number(reg[ta],16)+" > "+QString::number(reg[tb],16)+"\n");
            }
            else if (reg[ta] < reg[tb])
            {
                PSW = 2;
                //printf("%llX < %llX\n", reg[ta], reg[tb]);
                ui->textEdit->append(QString::number(reg[ta],16)+" < "+QString::number(reg[tb],16)+"\n");
            }
            else if (reg[ta] == reg[tb])
            {
                PSW = 3;
                //printf("%llX = %llX\n", reg[ta], reg[tb]);
                ui->textEdit->append(QString::number(reg[ta],16)+" = "+QString::number(reg[tb],16)+"\n");
            }
            break;

        case 11:	//AND
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            memset(aa, 0, sizeof(aa));
            memset(bb, 0, sizeof(bb));
            memset(cc, 0, sizeof(cc));
            DEC_BIN(reg[ta], aa);
            DEC_BIN(reg[tb], bb);
            for (int i = 0; i < 64; i++)
            {
                if (aa[i] == 1 && bb[i] == 1)
                {
                    cc[i] = 1;
                }
                else
                {
                    cc[i] = 0;
                }
            }

            c=BIN_DEC(cc);
            ui->textEdit->append(QString::number(reg[ta],2)+" AND "+QString::number(reg[tb],2)+" = "+QString::number(c,2)+"\n");
            reg[ta] = c;
            //ui->textEdit->append(QString::number(reg[ta],16));
            break;

        case 12:	//OR
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            memset(aa, 0, sizeof(aa));
            memset(bb, 0, sizeof(bb));
            memset(cc, 0, sizeof(cc));
            DEC_BIN(reg[ta], aa);
            DEC_BIN(reg[tb], bb);
            for (int i = 0; i < 64; i++)
            {
                if (aa[i] == 0 && bb[i] == 0)
                {
                    cc[i] = 0;
                }
                else
                {
                    cc[i] = 1;
                }
            }

            c=BIN_DEC(cc);
            ui->textEdit->append(QString::number(reg[ta],2)+" OR "+QString::number(reg[tb],2)+" = "+QString::number(c,2)+"\n");
            reg[ta] = c;
            //printf("%llX\n", reg[ta]);
            break;

        case 13:	//NOT
            ta = X[0] - 'A';
            memset(aa, 0, sizeof(aa));
            memset(bb, 0, sizeof(bb));
            memset(cc, 0, sizeof(cc));
            DEC_BIN(reg[ta], aa);
            for (int i = 0; i < 64; i++)
            {
                if (aa[i] == 1)
                {
                    cc[i] = 0;
                }
                else
                {
                    cc[i] = 1;
                }
            }
            c=BIN_DEC(cc);
            ui->textEdit->append("NOT "+QString::number(reg[ta],2)+" = "+QString::number(c,2)+"\n");
            reg[ta] = c;
            //printf("%llX\n", reg[ta]);
            break;

        case 14:	//SAL
            ta = X[0] - 'A';
            memset(aa, 0, sizeof(aa));
            memset(bb, 0, sizeof(bb));
            memset(cc, 0, sizeof(cc));
            DEC_BIN(reg[ta], aa);
            for (int i = 0; i < 64; i++)
            {
                cc[i] = aa[i + 1];
            }
            cc[63] = 0;


            c=BIN_DEC(cc);
            ui->textEdit->append(QString::number(reg[ta],2)+" SAL "+" = "+QString::number(c,2)+"\n");
            reg[ta] = c;
            //printf("%llX\n", reg[ta]);
            break;

        case 15:	//SAR
            ta = X[0] - 'A';
            memset(aa, 0, sizeof(aa));
            memset(bb, 0, sizeof(bb));
            memset(cc, 0, sizeof(cc));
            DEC_BIN(reg[ta], aa);
            cc[0] = 0;
            for (int i = 1; i < 64; i++)
            {
                cc[i] = aa[i - 1];
            }


            c=BIN_DEC(cc);
            ui->textEdit->append(QString::number(reg[ta],2)+" SAR "+" = "+QString::number(c,2)+"\n");
            reg[ta] = c;
            //printf("%llX\n", reg[ta]);
            break;

        case 16:	//MOV
            ta = X[0] - 'A';
            tb = Y[0] - 'A';
            reg[ta] = reg[tb];
            ui->textEdit->append("REGISTER "+QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");
            //printf("REGISTER %cX : %llX\n", X[0], reg[ta]);
            break;

        case 17:	//LAD
            ta = X[0] - 'A';
            tb = HEX_DEC(Y, 4);
            if(tb>0xFFFF)
            {
                error=5;
                PC++;
                return -1;
            }
            reg[ta] = HEX_DEC(memory[tb], 16);
            ui->textEdit->append("MEMORY->REGISTER "+QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");
            //printf("REGISTER %cX : %llX\n", X[0], reg[ta]);

            break;

        case 18:	//STO
            ta = HEX_DEC(X, 4);
            if(ta>0xFFFF)
            {
                error=5;
                PC++;
                return -1;
            }
            tb = Y[0] - 'A';
            memset(dd,'0',sizeof(dd));
            DEC_HEX(reg[tb], dd);
            for (int i = 0; i < 16; i++)
            {
                memory[ta][i] = dd[i];
            }
            ui->textEdit->append("REGISTER->MEMORY "+QString(X[0])+QString(X[1])+QString(X[2])+QString(X[3])+" : "+QString::number(reg[tb],16)+"\n");
            //ui->textEdit->append(QString(QLatin1String(dd)));
            //printf("MEMORY %c%c%c%c : %llX\n", X[0], X[1], X[2], X[3], reg[tb]);
            break;

        case 19:	//SET
            len_b=strlen(Y);
            ta = HEX_DEC(X, 4);
            if(ta>0xFFFF)
            {
                error=5;
                PC++;
                return -1;
            }
            tb = HEX_DEC(Y, len_b);
            memset(dd,'0',sizeof(dd));

            DEC_HEX(tb, dd);
            for (int i = 0; i < 16; i++)
            {
                memory[ta][i] = dd[i];
            }
            ui->textEdit->append("MEMORY "+QString(X[0])+QString(X[1])+QString(X[2])+QString(X[3])+" : "+QString::number(tb,16)+"\n");
            //printf("MEMORY %c%c%c%c : %llX\n", X[0], X[1], X[2], X[3], reg[tb]);
            break;

        case 20:	//SAVE
            len_b=strlen(Y);
            //ui->textEdit->append(QString(QLatin1String(Y))+QString::number(len_b)+"\n");
            ta = X[0] - 'A';
            tb = HEX_DEC(Y, len_b);
            reg[ta] = tb;
            ui->textEdit->append("REGISTER "+QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");
            //QApplication::processEvents();
            //printf("REGISTER %cX : %llX\n", X[0], reg[ta]);

            break;


        case 21:	//PUSH
            //printf("%llX**", SP);
            if(SP+1>0xDFFF)
            {
                error=7;
                PC++;
                return -1;
            }
            ta = X[0] - 'A';
            //printf("%llX**", reg[ta]);
            memset(dd,'0',sizeof(dd));
            DEC_HEX(reg[ta], dd);
            //ui->textEdit->append(QString(QLatin1String(dd)));
            for (int i = 0; i < 16; i++)
            {
                memory[SP][i] = dd[i];
                //ui->textEdit->append(QString(dd[i]));
            }
            ui->textEdit->append("STACK "+QString::number(SP,16)+" : "+QString::number(reg[ta],16)+"\n");
            //printf("STACK %X : %llX\n", IAR, reg[ta]);
            SP++;

            break;

        case 22:	//POP
            ta = X[0] - 'A';
            //ui->textEdit->append(QString::number(SP,16));
            //ui->textEdit->append(QString(QLatin1String(memory[SP])));
            if(SP==0xC000)
            {
                error=6;
                PC++;
                return -1;
            }
            SP--;
            reg[ta] = HEX_DEC(memory[SP], 16);
            ui->textEdit->append("REGISTER "+QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");
            //printf("REGISTER %cX : %llX\n", X[0], reg[ta]);

            memset(memory[SP], '0', sizeof(memory[SP]));

            break;

        case 23:	//JMP
            ta = HEX_DEC(X, 4);
            PC = ta - 1;
            ui->textEdit->append("JUMP to "+QString(X[0])+QString(X[1])+QString(X[2])+QString(X[3])+"\n");
            //printf("JUMP to : %c%c%c%c\n", X[0], X[1], X[2], X[3]);
            break;

        case 24:	//JG
            ta = HEX_DEC(X, 4);
            if(PSW==0)
            {
                error=4;
                //PC++;
                return -1;
            }
            else
            {
                if (PSW == 1)
                {
                    PC = ta - 1;
                    ui->textEdit->append("Successfully JUMP to "+QString(X[0])+QString(X[1])+QString(X[2])+QString(X[3])+"\n");
                    //printf("Successfully JUMP to : %c%c%c%c\n", X[0], X[1], X[2], X[3]);
                }
                else
                {
                    ui->textEdit->append("JUMP FAILED\n");
                    //printf("JUMP FAILED\n");
                }
            }

            break;

        case 25:	//JL
            ta = HEX_DEC(X, 4);
            if(PSW==0)
            {
                error=4;
                //PC++;
                return -1;
            }
            else
            {
                if (PSW == 2)
                {
                    PC = ta - 1;
                    ui->textEdit->append("Successfully JUMP to "+QString(X[0])+QString(X[1])+QString(X[2])+QString(X[3])+"\n");
                    //printf("Successfully JUMP to : %c%c%c%c\n", X[0], X[1], X[2], X[3]);
                }
                else
                {
                    ui->textEdit->append("JUMP FAILED\n");
                    //printf("JUMP FAILED\n");
                }
            }

            break;

        case 26:	//JE
            ta = HEX_DEC(X, 4);
            if(PSW==0)
            {
                error=4;
                //PC++;
                return -1;
            }
            else
            {
                if (PSW == 3)
                {
                    PC = ta - 1;
                    ui->textEdit->append("Successfully JUMP to "+QString(X[0])+QString(X[1])+QString(X[2])+QString(X[3])+"\n");
                    //printf("Successfully JUMP to : %c%c%c%c\n", X[0], X[1], X[2], X[3]);
                }
                else
                {
                    ui->textEdit->append("JUMP FAILED\n");
                    //printf("JUMP FAILED\n");
                }
            }

            break;

        case 27:	//EMP
            ui->textEdit->append("Empty Operation\n");
            break;

        case 28:    //CLR
            ta = X[0] - 'A';
            //printf("%c %d ",X[0], ta);
            //printf("%llX\n", reg[ta]);
            reg[ta]=0;
            ui->textEdit->append(QString::number(reg[ta],16)+"\n");
            //printf("%llX\n", reg[0]);
            break;

        case 29:    //EI
            //ta = HEX_DEC(X, 4);
            if(is_interrupt==0)
            {

                is_interrupt=1;
                state=4;
                memset(reg_tmp, 0, sizeof(reg_tmp));
                int tmp=IAR;
                IAR=PC+1;
                PSW_tmp=PSW;

                for(int i=0;i<16;i++)
                {
                    reg_tmp[i]=reg[i];
                }
                PC=tmp;
                ui->textEdit->append("Program have been interrupted\n");

                while(!terminated&&is_interrupt==1&&PC<0XE000)
                {

                    if(state==0||state==1)
                    {
                        error=1;
                        break;
                    }
                    else
                    {
                        int e1,e2;
                        e1=read();
                        if(e1!=-1)
                        {
                            e2=operate();
                        }
                        if(e1==-1||e2==-1)
                        {
                            ui->textEdit->append("ERROR\n");
                        }

                        show_state();
                        show_reg();
                        show_stack();

                    }
                    PC++;
                    show_error();
                    sleep(M);
                }
            }
            else
            {
                error=9;
                return -1;
            }
            break;

        case 30:    //IRET
            if(is_interrupt==1)
            {
                PC=IAR;
                IAR=0xE000;
                for(int i=0;i<16;i++)
                {
                    reg[i]=reg_tmp[i];
                }
                PSW=PSW_tmp;
                ui->textEdit_IN->clear();
                ui->textEdit_3->clear();
                is_interrupt=0;
                state=3;
                for(int i=0xE000;i<0xFFFF;i++)
                {
                    memset(memory[i],'\0',sizeof(memory[i]));
                }
                ui->textEdit->append("Program have recovered for being interrupted\n");
                on_pushButton_CONTINUOUS_clicked();
            }
            else
            {
                error=10;
                return -1;
            }
            break;
        case 31:
            ta = X[0] - 'A';
            if(buffer_last>buffer_first)
            {
                reg[ta] = buffer[buffer_first];
                ui->textEdit->append("IN "+QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");
                buffer_first++;
            }
            else
            {
                ui->textEdit->append("Waiting for input\n");
                PC--;
            }
            break;

        case 32:	//LPSW
            if(model==1)
            {
                ta = X[0] - 'A';
                reg[ta] = PSW;
                ui->textEdit->append("PSW->REGISTER "+QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");

            }
            else
            {
                error=13;
                return -1;
            }

            break;

        case 33:	//SPC
            if(model==1)
            {
                ta = HEX_DEC(X, 4);
                PC = ta;
                ui->textEdit->append("PC : "+QString::number(PC,16)+"\n");
                //QApplication::processEvents();
                //printf("REGISTER %cX : %llX\n", X[0], reg[ta]);

            }
            else
            {
                error=13;
                return -1;
            }

            break;

        case 34:	//LPC
            if(model==1)
            {
                ta = X[0] - 'A';
                reg[ta] = PC;
                ui->textEdit->append("PC->REGISTER "+QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");

            }
            else
            {
                error=13;
                return -1;
            }

            break;

        case 35:	//LIAR
            if(model==1)
            {
                ta = X[0] - 'A';
                reg[ta] = IAR;
                ui->textEdit->append("IAR->REGISTER "+QString(X[0])+"X"+" : "+QString::number(reg[ta],16)+"\n");

            }
            else
            {
                error=13;
                return -1;
            }

            break;

        case 36:	//SIAR
            if(model==1)
            {
                ta = HEX_DEC(X, 4);
                IAR = ta;
                ui->textEdit->append("IAR : "+QString::number(IAR,16)+"\n");

            }
            else
            {
                error=13;
                return -1;
            }

            break;

    }
    show_reg();
    show_state();
    QApplication::processEvents();
    //PC++;
    count++;
    if(count>1000000)
    {
        error=8;
        return -1;
    }
    return 0;
}

//延时函数,单位毫秒
void MainWindow::sleep(int msec)
{
    QDateTime last = QDateTime::currentDateTime();
    QDateTime now;
    while (1)
    {
        now = QDateTime::currentDateTime();
        if (last.msecsTo(now) >= msec)
        {
            break;
        }
    }
}

//显示寄存器
void MainWindow::show_reg()
{
    ui->textEdit_PC->setText("PC: "+QString::number(PC,16));
    ui->textEdit_IAR->setText("IAR: "+QString::number(IAR,16));
    ui->textEdit_SP->setText("SP: "+QString::number(SP,16));
    ui->textEdit_PSW->setText("PSW: "+QString::number(PSW));
    ui->textEdit_IR->setText("IR: "+QString(QLatin1String(IR)));
    ui->textEdit_A->setText("AX: "+QString::number(reg[0],16));
    ui->textEdit_B->setText("BX: "+QString::number(reg[1],16));
    ui->textEdit_C->setText("CX: "+QString::number(reg[2],16));
    ui->textEdit_D->setText("DX: "+QString::number(reg[3],16));
    ui->textEdit_E->setText("EX: "+QString::number(reg[4],16));
    ui->textEdit_F->setText("FX: "+QString::number(reg[5],16));
    ui->textEdit_G->setText("GX: "+QString::number(reg[6],16));
    ui->textEdit_H->setText("HX: "+QString::number(reg[7],16));
    ui->textEdit_I->setText("IX: "+QString::number(reg[8],16));
    ui->textEdit_J->setText("JX: "+QString::number(reg[9],16));
    ui->textEdit_K->setText("KX: "+QString::number(reg[10],16));
    ui->textEdit_L->setText("LX: "+QString::number(reg[11],16));
    ui->textEdit_M->setText("MX: "+QString::number(reg[12],16));
    ui->textEdit_N->setText("NX: "+QString::number(reg[13],16));
    ui->textEdit_O->setText("OX: "+QString::number(reg[14],16));
    ui->textEdit_P->setText("PX: "+QString::number(reg[15],16));
    ui->textEdit_count->setText(QString::number(count));
    //ui->textEdit_A->setText("AX: "+QString::number(reg[0],16));
    //ui->textEdit->append(QString(QLatin1String(Y)));
}

//显示状态
void MainWindow::show_state()
{
    if(state==0) ui->textEdit_state->setText("Computer is ready");
    else if(state==1) ui->textEdit_state->setText("unloaded program");
    else if(state==2) ui->textEdit_state->setText("Test program have been loaded");
    else if(state==3) ui->textEdit_state->setText("The program is operating");
    else if(state==4) ui->textEdit_state->setText("Test program have been interrupted");
    else if(state==5) ui->textEdit_state->setText("Computer is shut down");
    QApplication::processEvents();
}

//显示错误
void MainWindow::show_error()
{
    if(error==0) ui->textEdit_error->setText("No error");
    else if(error==1) ui->textEdit_error->setText("Start executing when program is not loaded");
    else if(error==2) ui->textEdit_error->setText("Instruction contains illegal operands");
    else if(error==3) ui->textEdit_error->setText("Register does not exist");
    else if(error==4) ui->textEdit_error->setText("When the condition jumps, no comparison, but try to jump");
    else if(error==5) ui->textEdit_error->setText("Exceeds the preset range when addressing in memory");
    else if(error==6) ui->textEdit_error->setText("No data in stack when popping stack");
    else if(error==7) ui->textEdit_error->setText("Stack area overflow");
    else if(error==8) ui->textEdit_error->setText("Program traps in a loop");
    else if(error==9) ui->textEdit_error->setText("Reapply interrupts during interrupts");
    else if(error==10) ui->textEdit_error->setText("Apply for interrupt recovery when not interrupted");
    else if(error==11) ui->textEdit_error->setText("When not interrupted, click to execute the interrupt subroutine");
    else if(error==12) ui->textEdit_error->setText("Devided by 0");
    else if(error==13) ui->textEdit_error->setText("Execute privileged instructions in user mode");
    QApplication::processEvents();
    error=0;
}

//显示堆栈
void MainWindow::show_stack()
{
    ui->textEdit_stack->clear();
    for(int i=0xC000;i<SP;i++)
    {
        ui->textEdit_stack->append(QString::number(i,16)+" : "+QString(memory[i][0])+QString(memory[i][1])+QString(memory[i][2])+QString(memory[i][3])+QString(memory[i][4])+QString(memory[i][5])+QString(memory[i][6])+QString(memory[i][7])+QString(memory[i][8])+QString(memory[i][9])+QString(memory[i][10])+QString(memory[i][11])+QString(memory[i][12])+QString(memory[i][13])+QString(memory[i][14])+QString(memory[i][15]));
        //QApplication::processEvents();
    }
}

//中断申请
void MainWindow::interrupt()
{
    if(is_interrupt==0)
    {
        is_interrupt=1;
        state=4;
        memset(reg_tmp, 0, sizeof(reg_tmp));

        int tmp=IAR;
        IAR=PC;
        PSW_tmp=PSW;

        for(int i=0;i<16;i++)
        {
            reg_tmp[i]=reg[i];
        }
        PC=tmp;
    }
    else
    {
        error=9;
    }
}

//中断恢复
void MainWindow::recover()
{
    if(is_interrupt==1)
    {
        PC=IAR;
        IAR=0xE000;
        for(int i=0;i<16;i++)
        {
            reg[i]=reg_tmp[i];
        }
        PSW=PSW_tmp;
        ui->textEdit_IN->clear();
        ui->textEdit_3->clear();
        is_interrupt=0;
        state=3;
        for(int i=0xE000;i<0xFFFF;i++)
        {
            memset(memory[i],'\0',sizeof(memory[i]));
        }
        //on_pushButton_CONTINUOUS_clicked();
    }
    else
    {
        error=10;
    }
}

//保护现场
void MainWindow::protect()
{
    memset(reg_tmp, 0, sizeof(reg_tmp));
    IAR=PC;
    PSW_tmp=PSW;

    for(int i=0;i<16;i++)
    {
        reg_tmp[i]=reg[i];
    }
    PC=0xE000;
}

//调整主频
void MainWindow::setValue(int x)
{
    M=x;
}




//16进制转10进制
unsigned long long int MainWindow::HEX_DEC(char *s, int n)
{
    unsigned long long int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A'&&s[i] <= 'F') res = (res << 4) | (s[i] - 'A' + 10);
        else if (s[i] >= '0'&&s[i] <= '9')res = (res << 4) | (s[i] - '0');
        else return -1;
    }
    return res;
}

//10进制转16进制
void MainWindow::DEC_HEX(unsigned long long int n, char res[])
{
    char tmp[16];
    int len = 0;
    memset(res, '0', sizeof(res));
    memset(tmp, '0', sizeof(tmp));
    for (int i = 0; n > 0; i++, n /= 16)
    {
        int ans;
        ans = n % 16;

        if (ans<10)
        {
            tmp[i] = '0' + ans;
        }
        else
        {
            tmp[i] = 'A' + ans - 10;
        }
        len++;
    }

    for (int i = 1; i <= len; i++)
    {
        res[16 - i] = tmp[i-1];
    }
}

//10进制转2进制
void MainWindow::DEC_BIN(unsigned long long n, int res[])
{


    int tmp[64];
    int count = 0;
    memset(res, 0, sizeof(res));
    memset(tmp, 0, sizeof(tmp));

    for (int i=0; n > 0; i++, n /= 2)
    {
        tmp[i] = n % 2;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        res[63 - i] = tmp[i];
    }
}

//2进制转10进制
unsigned long long int MainWindow::BIN_DEC(int res[])
{
    unsigned long long int ans=0;
    unsigned long long int comb = 1;
    for (int i = 63; i >= 0; i--)
    {
        ans =ans + comb * res[i];
        comb *= 2;
    }
    return ans;
}




