#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <malloc.h>

// 全局变量
int choice;
int Ch;
char emailWeb[100];

// 结构体
typedef struct contactPerson{
    long long stuNum;            // 学号
    char name[10];               // 姓名
    char sex[10];                // 性别
    char academic[20];           // 院系
    char major[30];              // 专业
    char province[100];          // 籍贯
    char address[100];           // 家庭住址
    long long phoneNum;          // 电话号码
    char emailNum[100];          // 邮箱
    struct contactPerson *pNext; // 指向下一节点的指针
}Contact_Person;
Contact_Person *head = NULL;

// 其他
bool isValidStudentNumber(long long num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit < 0 || digit > 9) {
            return false;  // 存在非数字的情况
        }
        num /= 10;
    }
    return true;  // 所有位都是数字
}       // 学号输入限制（仅数字）

// 定义函数
int isStuNumExists(Contact_Person* head, long long stuNum) {
    Contact_Person* current = head;
    while (current != NULL) {
        if (current->stuNum == stuNum) {
            return 1; // 学号已存在
        }
        current = current->pNext;
    }
    return 0; // 学号不存在
}    // 用于检测学号是否重复

// void
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}                           // 清空输入缓冲区
void optionsList(){
    printf("   菜  单\n");               // 标题
    printf("1.学生信息录入\n");           // 数据录入
    printf("2.查询单个数据（详细信息）\n");  // 数据修改
    printf("3.学生数据删除\n");           // 数据删除
    printf("4.显示所有数据（仅基本信息）\n");// 显示所有数据
    printf("5.学生数据修改\n");           // 查询数据
    printf("6.数据保存\n");              // 数据保存
    printf("0.退出\n");                 // 退出
    printf("请输入序号:");
    scanf("%d", &choice);              // 存储输入的选项序号
}                                 // 选项列表
void luRu(){

    Contact_Person *p = head;                                                               // 声明指针,用于从链表头开始遍历
    Contact_Person *prev = NULL;                                                            // 声明指针,用于记录遍历过程中的前一个节点
    Contact_Person *newNode = (Contact_Person *) malloc(sizeof(Contact_Person));       // 在内存中分配一块空间放置新节点
    // 录入
    while (1) {
        printf("***学生成绩录入***\n");
        // 先输入学号，再进行检测，如果合法则传入链表，不合法则要求重新输入
        while (1) {
            long long inputNum;
            printf("请输入学生学号（11位）：");
            scanf("%lld", &inputNum);
            // 第一检测：检测学号是否满足11位要求
            if (inputNum >= 10000000000 && inputNum <= 99999999999) {
                // 第二检测：检测学号是否重复
                printf("开始检测学号是否重复...\n");
                if (isStuNumExists(head, inputNum)) {
                    printf("学号已存在，请重新输入。\n");
                    continue;
                }
                printf("学号未重复！\n");
                printf("学号合法！已录入。\n");
                newNode->stuNum = inputNum;
                break;
            } else {
                printf("非法学号！学号必须为11位数,请重新输入。\n");
                clearInputBuffer();
                continue;
            }
        }                                                // 录入学生学号
        printf("请输入学生姓名：");                                // 录入学生姓名
        scanf("%99s", newNode->name);
        // 先传入链表，再进行检测。
        while (1) {
            printf("请输入学生性别：");
            scanf("%99s", newNode->sex);
            if (strcmp(newNode->sex, "男") == 0 || strcmp(newNode->sex, "女") == 0) {  // 对比判断链表中的值进行检测;讲解：strcmp与strstr的区别
                printf("性别规则合法！（规则1）已录入。\n");
                break;
            } else {
                if (strcmp(newNode->sex, "其他") == 0) {
                    printf("请输入其他性别：");
                    scanf("%99s", newNode->sex);
                    printf("性别规则合法！（规则2）已录入。\n");
                    break;
                    // 规则1：限“男”“女”。 规则2：任意性别
                } else {
                    printf("无效性别！请重新输入。\n");
                    continue;                                                         // 规则都不满足则要求重新输入
                }
            }
        }                                                // 录入学生性别
        printf("请输入学生院系：");
        scanf("%99s", newNode->academic);
        printf("请输入学生专业：");
        scanf("%99s", newNode->major);
        printf("请输入学生籍贯：");
        scanf("%99s", newNode->province);
        printf("请输入学生家庭住址：");                            // Clion的BUG会导致运行框内自动换行
        scanf("%99s", newNode->address);
        while (1) {
            long long inputNum;
            printf("请输入学生电话号码（仅支持手机号）：");
            scanf("%lld", &inputNum);
            if (inputNum >= 10000000000 && inputNum <= 19999999999){  // 必须1为开头的11位手机号
                newNode -> phoneNum = inputNum;
                printf("号码字数合法！已录入\n");
                break;
            } else {
                printf("非法号码！请检查字数，请重新输入。\n");
                continue;
            }
        }                                               // 录入手机号码
        while (1) {
            char inputEmail[100];
            printf("请输入学生邮箱：");
            scanf("%99s", inputEmail);

            // 检测邮箱格式是否合法
            if (strstr(inputEmail,"@gmail.com") != NULL){
                printf("格式正确（gmail邮箱），已录入。\n");
//                newNode->emailNum = inputEmail;        // 错误
                strcpy(newNode->emailNum, inputEmail);   // 对于字符数组，不能通过简单的赋值来进行复制，应该使用字符串操作函数如 strcpy。
                break;
            } if (strstr(inputEmail,"@qq.com") != NULL) {
                printf("格式正确（QQ邮箱），已录入。\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } if(strstr(inputEmail,"@163.com") != NULL){
                printf("格式正确（网易邮箱），已录入。\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } if(strstr(inputEmail,"@outlook.com") != NULL){
                printf("格式正确（Outlook邮箱），已录入。\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } if(strstr(inputEmail,"@yahoo.com") != NULL){
                printf("格式正确（雅虎邮箱1），已录入。\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } if(strstr(inputEmail,"@myyahoo.com") != NULL){
                printf("格式正确（雅虎邮箱2），已录入。\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } else {
                printf("格式错误!可能是未受支持的邮箱格式，请重新输入\n");
                continue;
            }
        }                                               // 录入邮箱

        newNode->pNext = NULL;
        printf("数据录入完成\n");
        system("pause");

        if (!head || newNode->stuNum < head->stuNum) {
            newNode->pNext = head;                        // 如果链表为空或新学生的学号小于头节点的学号,则新节点指向当前的头节点
            head = newNode;                               // 让头指针指向新节点
            return;
        }
        // 如果链表不为空,并且新录入的学生学号比头节点的学号大,遍历链表,找到适当的位置插入新节点
        while (p && p->stuNum <= newNode->stuNum) {
            prev = p;                                   // 在移动到下一个节点之前,将当前节点存储在'prev'中
            p = p->pNext;                               // 移动到下一个节点
        }
        prev->pNext = newNode;                          // 找到比‘P’节点的学号小的位置,让前一个节点指向新节点
        newNode->pNext = p;                             // 新节点指向当前节点,即'p'
        return;
    }
}                                        // 录入成绩
void chaZhao(){
    int chooseNum;                  // 用户选择的编号
    char choice_name[100];          // 通过名字查找
    long long choice_stuNum;        // 通过学号查找
    long long choice_phoneNum;      // 通过电话号码查找
    char choice_emailNum[100];      // 通过邮箱查找

    // 可通过四种方式进行数据查找（四选一）
    printf("请选择查找方式：\n");
    printf("1.按名字查找\n");
    printf("2.按学号查找\n");
    printf("3.按电话号码查找\n");
    printf("4.按邮箱查找\n");
    printf("请输入序号：");
    scanf("%d",&chooseNum);

    // 查找方式选择
    switch (chooseNum) {
        case 1:
            printf("按名字查找\n");
            printf("请输入学生名字：");
            scanf("%99s",choice_name);               // 读取用户输入的名字

            Contact_Person  *temp = head;
            while(temp!=NULL){
                if(strcmp(temp->name, choice_name) == 0){   // 字符串的比较应该使用 strcmp 函数而不是 == 运算符
                    break;
                }
                temp = temp->pNext;
            }

            if(temp==NULL) {
                printf("没有找到学生");
                system("pause");
            } else {
                printf("已找到学生，成绩如下：\n");
                printf("学号：%lld        姓名：%s        性别：%s\n",temp->stuNum,temp->name,temp->sex);
                printf("院系：%s          专业：%s\n",temp->academic,temp->major);
                printf("籍贯：%s\n",temp->province);
                printf("家庭住址：%s\n",temp->address);
                printf("电话号码：%lld              邮箱：%s\n",temp->phoneNum,temp->emailNum);
                system("pause");
            }
            break;

        case 2:
            printf("按学号查找\n");
            printf("请输入学生学号：");
            scanf("%lld",&choice_stuNum);          // 读取用户输入的学号

            Contact_Person  *temp_stuNum = head;
            while(temp_stuNum!=NULL){
                if(temp_stuNum->stuNum == choice_stuNum){   // 字符串的比较应该使用 strcmp 函数而不是 == 运算符
                    break;
                }
                temp_stuNum = temp_stuNum->pNext;
            }

            if(temp_stuNum==NULL) {
                printf("没有找到学生");
                system("pause");
            } else {
                printf("已找到学生，成绩如下：\n");
                printf("学号：%lld        姓名：%s        性别：%s\n",temp_stuNum->stuNum,temp_stuNum->name,temp_stuNum->sex);
                printf("院系：%s          专业：%s\n",temp_stuNum->academic,temp_stuNum->major);
                printf("籍贯：%s\n",temp_stuNum->province);
                printf("家庭住址：%s\n",temp_stuNum->address);
                printf("电话号码：%lld              邮箱：%s\n",temp_stuNum->phoneNum,temp_stuNum->emailNum);
                system("pause");
            }
            break;

        case 3:
            printf("按电话号码查找\n");
            printf("请输入电话号码：");
            scanf("%lld",&choice_phoneNum);          // 读取用户输入的学号
            Contact_Person  *temp_phoneNum = head;
            while(temp_phoneNum!=NULL){
                if(temp_phoneNum->phoneNum == choice_phoneNum){   // 字符串的比较应该使用 strcmp 函数而不是 == 运算符
                    break;
                }
                temp_phoneNum = temp_phoneNum->pNext;
            }

            if(temp_phoneNum==NULL) {
                printf("没有找到学生");
                system("pause");
            } else {
                printf("已找到学生，成绩如下：\n");
                printf("学号：%lld        姓名：%s        性别：%s\n",temp_phoneNum->stuNum,temp_phoneNum->name,temp_phoneNum->sex);
                printf("院系：%s          专业：%s\n",temp_phoneNum->academic,temp_phoneNum->major);
                printf("籍贯：%s\n",temp_phoneNum->province);
                printf("家庭住址：%s\n",temp_phoneNum->address);
                printf("电话号码：%lld              邮箱：%s\n",temp_phoneNum->phoneNum,temp_phoneNum->emailNum);
                system("pause");
            }
            break;

        case 4:
            printf("按邮箱查找\n");
            printf("请输入邮箱地址：");
            scanf("%99s",choice_emailNum);                            // 读取用户输入的学号

            Contact_Person  *temp_emailNum = head;
            while(temp_emailNum!=NULL){
                if(strcmp(temp_emailNum->emailNum, choice_emailNum) == 0){   // 字符串的比较应该使用 strcmp 函数而不是 == 运算符
                    break;
                }
                temp_emailNum = temp_emailNum->pNext;
            }

            if(temp_emailNum==NULL) {
                printf("没有找到学生");
                system("pause");
            } else {
                printf("已找到学生，成绩如下：\n");
                printf("学号：%lld        姓名：%s        性别：%s\n",temp_emailNum->stuNum,temp_emailNum->name,temp_emailNum->sex);
                printf("院系：%s          专业：%s\n",temp_emailNum->academic,temp_emailNum->major);
                printf("籍贯：%s\n",temp_emailNum->province);
                printf("家庭住址：%s\n",temp_emailNum->address);
                printf("电话号码：%lld              邮箱：%s\n",temp_emailNum->phoneNum,temp_emailNum->emailNum);
                system("pause");
            }
            break;

    }




}                                     // 查找目标
void testAll(){
    printf("简单查询（仅显示基本信息）\n");
    Contact_Person *p = head;
    printf("学号\t\t姓名\t性别\n");
    while (p != NULL) {
        printf("%-16lld%-8s%-8s\n",p->stuNum,p->name,p->sex);
        p = p->pNext;
    }
    return;
}                                     // 测试
void deleteMessage(){

    long long stuNumber;
    char choose;

    // 声明一个指针从链表头开始遍历
    Contact_Person *p = head;
    // 声明一个指针记录遍历过程中的前一个节点
    Contact_Person *prev = NULL;

    printf("请输入要删除的学号:");
    scanf("%lld", &stuNumber);
    getchar();

    // 检查链表是否为空
    if (!head) {
        printf("链表为空。\n");
        return;
    }
    // 遍历链表查找要删除的学生
    while (p && p->stuNum != stuNumber) {
        // 在移动到下一个节点之前,将当前节点存储在'prev'中
        prev = p;
        // 移动到下一个节点
        p = p->pNext;
    }
    // 如果找到了要删除的学生
    if (p) {
        printf("找到的信息如下:\n");
        printf("学号:%lld,姓名:%s,性别:%s\n",p->stuNum, p->name, p->sex);
        printf("是否为您要删除的记录?(y/n)");
        choose = getchar();

        if (choose == 'y' || choose == 'Y') {
            //如果不是第一个节点
            if (prev) {
                //将前一个节点的指针指向下一个节点
                prev->pNext = p->pNext;
            } else {
                //将链表头指针指向下一个节点
                head = p->pNext;
            }
            //释放当前节点的内存
            free(p);
            //暂停程序
            system("pause");
        }
    } else {
        // 如果没有找到学生,打印提示信息
        printf("学号 %lld的学生未找到。\n", stuNumber);
    }
}                               // 删除数据
void xiuGai() {
    int chooseNum;
    long long stuNum;
    char choose;
    printf("请输入要修改的学号:");
    scanf("%lld", &stuNum);

    // 查找满足条件的记录
    Contact_Person *temp = head;             // 1.定义指针变量temp类型为Contact_Person自定义结构体，类型为，2.将temp赋值为head，使temp指向链表的第一个节点。
    while (temp != NULL) {
        if (temp->stuNum == stuNum){
            break;
        } else {
            temp = temp->pNext;
        }
    }
    if (temp == NULL){
        printf("没有符合条件的目录！");
    } else {
        printf("找到当前档案信息如下：\n");
        printf("*************************************************\n");
        printf("学号：%lld        姓名：%s        性别：%s\n",temp->stuNum,temp->name,temp->sex);
        printf("院系：%s          专业：%s\n",temp->academic,temp->major);
        printf("籍贯：%s\n",temp->province);
        printf("家庭住址：%s\n",temp->address);
        printf("电话号码：%lld              邮箱：%s\n",temp->phoneNum,temp->emailNum);
        printf("*************************************************\n");
        printf("是否为您要修改的记录?(y/n)");
        getchar();                                               // 检测输入的值
        choose = getchar();                                      // 给choose赋值
        if (choose == 'y' || choose == 'Y'){                     // 判断choose的值
            printf("\n");
            printf("*******修改菜单*******\n");
            printf("1.学号  2.姓名   3.性别\n");
            printf("4.院系  5.专业   6.籍贯\n");
            printf("7.家庭住址   8.电话号码   8.邮箱\n");
            printf("********************\n");
            printf("请输入要修改的数据的编号：");
            scanf("%d",&chooseNum);
            switch (chooseNum) {
                case 1: // 修改学号
                    printf("修改学号\n");
                    printf("原学号：%lld\n", temp->stuNum); // 显示原始学号

                    // 声明新的newData0用于暂存原始学号
                    long long newData0;

                    // 循环检查学号是否满足要求
                    do {
                        printf("请输入新的学号(必须为11位数，且只能包含数字1-9)：");
                        if (scanf("%lld", &newData0) != 1) {
                            // 在这里读取键盘                                                                                                                 输入数值newData!
                            // 如果成功读取了一个长长整型的值，返回值就是 1；如果没有成功读取，返回值就是 0。
                            // 输入非数字，清空输入缓冲区并提示重新输入
                            clearInputBuffer();
                            printf("ERROR:字符类型错误，学号仅能为数字！请检查录入的学号。\n");
                            continue; // 当 continue 语句执行时，它会跳过当前循环体内剩余的语句，直接进入下一次循环迭代。
                        }

                        // 检查学号是否为11位数
                        if (newData0 >= 10000000000 && newData0 <= 99999999999) {

                            // 检查学号是否只包含1-9的数字
                            if (isValidStudentNumber(newData0)) {
                                break;  // 学号符合条件，退出循环
                            }
                        } else {
                            printf("ERROR:超过11位数字上限！请检查录入的学号。\n");
                            while ((Ch = getchar()) != '\n' && Ch != EOF);// 消耗输入缓冲中的换行符。
                        }
                    } while (1);

                    printf("学号已修改!\n");
                    printf("新学号：%lld\n", newData0);     // 显示新学号
                    temp->stuNum = newData0;                     // 更新学号
                    break;



                case 2:         // 修改姓名
                    printf("修改姓名\n");
                    printf("原姓名：%s\n", temp->name);     // 显示原始姓名

                    // 声明新的newData1用于暂存原始姓名
                    char newData1[100];

                    printf("请输入新的姓名：");
                    scanf("%s", newData1);
                    printf("姓名已修改!\n");
                    printf("新姓名：%s\n", newData1);       // 显示新姓名
                    strcpy(temp->name, newData1);    // 更新姓名，%s使用strcpy函数
                    break;



                case 3:         // 修改性别
                    printf("修改性别\n");
                    printf("原性别：%s\n", temp->sex);     // 显示原始姓名

                    // 声明新的newData2用于暂存原始性别
                    char newData2[100];

                    printf("请输入新的性别：");
                    scanf("%s", newData2);
                    printf("性别已修改!\n");
                    printf("新性别：%s\n", newData2);       // 显示新性别
                    strcpy(temp->sex,  newData2);    // 更新性别，%s使用strcpy函数
                    break;



                case 4:         // 修改院系
                    printf("修改院系\n");
                    printf("原院系：%s\n", temp->academic);     // 显示原始院系

                    // 声明新的newData3用于暂存原始院系
                    char newData3[100];

                    printf("请输入新的院系：");
                    scanf("%s", newData3);
                    printf("院系已修改!\n");
                    printf("新院系：%s\n", newData3);       // 显示新院系
                    strcpy(temp->academic,  newData3);    // 更新院系，%s使用strcpy函数
                    break;



                case 5:         // 修改专业
                    printf("修改专业\n");
                    printf("原专业：%s\n", temp->major);     // 显示原始专业

                    // 声明新的newData4用于暂存原始专业
                    char newData4[100];

                    printf("请输入新的专业：");
                    scanf("%s", newData4);
                    printf("专业已修改!\n");
                    printf("新专业：%s\n", newData4);       // 显示新专业
                    strcpy(temp->major,  newData4);    // 更新专业，%s使用strcpy函数
                    break;




                case 6:         // 修改籍贯
                    printf("修改籍贯\n");
                    printf("原籍贯：%s\n", temp->province);     // 显示原始籍贯

                    // 声明新的newData5用于暂存原始籍贯
                    char newData5[100];

                    printf("请输入新的籍贯：");
                    scanf("%s", newData5);
                    printf("籍贯已修改!\n");
                    printf("新籍贯：%s\n", newData5);       // 显示新籍贯
                    strcpy(temp->province,  newData5);    // 更新籍贯，%s使用strcpy函数
                    break;




                case 7:         // 修改家庭住址
                    printf("修改家庭住址\n");
                    printf("原家庭住址：%s\n", temp->address);     // 显示原始家庭住址

                    // 声明新的newData6用于暂存原始家庭住址
                    char newData6[100];

                    printf("请输入新的家庭住址：");
                    scanf("%s", newData6);
                    printf("家庭住址已修改!\n");
                    printf("新家庭住址：%s\n", newData6);       // 显示新家庭住址
                    strcpy(temp->address,  newData6);    // 更新家庭住址，%s使用strcpy函数
                    break;




                case 8:         // 修改电话号码
                    printf("修改电话号码\n");
                    printf("原电话号码：%lld\n", temp->phoneNum); // 显示原始电话号码

                    // 声明新的newData7用于暂存原始电话号码
                    long long newData7;

                    printf("请输入新的电话号码：");
                    scanf("%lld", &newData7);
                    printf("电话号码已修改!\n");
                    printf("新电话号码：%lld\n", newData7);     // 显示新电话号码
                    temp->phoneNum = newData7;                     // 更新电话号码
                    break;



                case 9:         // 修改邮箱地址
                    printf("修改邮箱地址\n");
                    printf("原邮箱地址：%s\n", temp->emailNum);     // 显示原始邮箱地址

                    // 声明新的newData9用于暂存原始邮箱地址
                    char newData9[100];

                    printf("请输入新的邮箱地址：");
                    scanf("%s", newData9);
                    printf("邮箱地址已修改!\n");
                    printf("新邮箱地址：%s\n", newData9);       // 显示新邮箱地址
                    strcpy(temp->emailNum,  newData9);    // 更新邮箱地址，%s使用strcpy函数
                    break;




            }
            // 每次修改完显示修改后的完整数据
            printf("修改后信息:\n");
            printf("*************************************************\n");
            printf("学号：%lld           姓名：%s        性别：%s\n",temp->stuNum,temp->name,temp->sex);
            printf("院系：%s          专业：%s\n",temp->academic,temp->major);
            printf("籍贯：%s\n",temp->province);
            printf("家庭住址：%s\n",temp->address);
            printf("电话号码：%lld              邮箱：%s\n",temp->phoneNum,temp->emailNum);
            printf("*************************************************\n");
            system("pause");
        } else {
            if(choose == "N" || choose == "n"){

            }
            printf("已取消操作\n");
        }
    }
}                                     // 数据修改
void checkEmailDelay(const char *email) {
    // 构建ping命令
    printf("开始测试邮箱延迟...\n");
    char command[100];
    sprintf(command, "ping -n 1 %s", email);

    // 执行命令并获取输出
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    // 读取输出并显示
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // 查找包含 "time=" 的行，表示延迟信息
        if (strstr(buffer, "时间=") != NULL) {
            printf("%s", buffer);
        }
    }

    // 关闭文件流
    pclose(fp);
}           // 获取邮箱网站ping值


// main
int main(){
    int c;
    // do循环
    do {
        optionsList();                                // 选项列表

        switch (choice) {
            case 1:
            luRu_Start:
                luRu();                                               // 继续录入跳转（落点）编号：1

                // 询问是否继续输入
                while (1) {
                    char TFChoice[10];
                    clearInputBuffer();                               // 清空输入缓冲区
                    printf("是否继续录入成绩（T/F）：");
                    scanf("%9s", TFChoice);
                    if (strcmp(TFChoice, "F") == 0) {                 // strcmp 是一个用于比较两个字符串的函数。返回值为 0 表示两个字符串相等，否则返回非零值，表示两个字符串不相等。
                        printf("录入结束\n");
                        break;
                    } else {
                        if (strcmp(TFChoice, "T") == 0) {
                            printf("继续录入\n");
                            goto luRu_Start;                          // 继续录入跳转（起点）编号：1
                        } else {
                            printf("无效选择，重新选择\n");
                            continue;
                        }
                    }
                }

                // 测试ping值
                printf("开始测试与邮箱网站的连通性\n");

                const char *email = "qq.com";
                checkEmailDelay(email);
                printf("\n");

                testAll();
                clearInputBuffer();
                break;

            case 2:
                chaZhao();
                break;

            case 3:
                deleteMessage();
                break;

            case 4:
                testAll();
                break;

            case 5:
                xiuGai();
                break;

            case 6:
                // 测试ping值
                email= "qq.com";
                checkEmailDelay(email);
                printf("QQ延迟\n");

                email= "baidu.com";
                checkEmailDelay(email);
                printf("百度延迟\n");

                break;
        }
        printf("\n");
        while ((Ch = getchar()) != '\n' && Ch != EOF);// 消耗输入缓冲中的换行符。
    } while (choice !=0);                             // 当选择"0"则退出do循环
    return 0;
}

