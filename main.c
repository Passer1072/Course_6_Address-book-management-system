#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <malloc.h>

// ȫ�ֱ���
int choice;
int Ch;
char emailWeb[100];

// �ṹ��
typedef struct contactPerson{
    long long stuNum;            // ѧ��
    char name[10];               // ����
    char sex[10];                // �Ա�
    char academic[20];           // Ժϵ
    char major[30];              // רҵ
    char province[100];          // ����
    char address[100];           // ��ͥסַ
    long long phoneNum;          // �绰����
    char emailNum[100];          // ����
    struct contactPerson *pNext; // ָ����һ�ڵ��ָ��
}Contact_Person;
Contact_Person *head = NULL;

// ����
bool isValidStudentNumber(long long num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit < 0 || digit > 9) {
            return false;  // ���ڷ����ֵ����
        }
        num /= 10;
    }
    return true;  // ����λ��������
}       // ѧ���������ƣ������֣�

// ���庯��
int isStuNumExists(Contact_Person* head, long long stuNum) {
    Contact_Person* current = head;
    while (current != NULL) {
        if (current->stuNum == stuNum) {
            return 1; // ѧ���Ѵ���
        }
        current = current->pNext;
    }
    return 0; // ѧ�Ų�����
}    // ���ڼ��ѧ���Ƿ��ظ�

// void
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}                           // ������뻺����
void optionsList(){
    printf("   ��  ��\n");               // ����
    printf("1.ѧ����Ϣ¼��\n");           // ����¼��
    printf("2.��ѯ�������ݣ���ϸ��Ϣ��\n");  // �����޸�
    printf("3.ѧ������ɾ��\n");           // ����ɾ��
    printf("4.��ʾ�������ݣ���������Ϣ��\n");// ��ʾ��������
    printf("5.ѧ�������޸�\n");           // ��ѯ����
    printf("6.���ݱ���\n");              // ���ݱ���
    printf("0.�˳�\n");                 // �˳�
    printf("���������:");
    scanf("%d", &choice);              // �洢�����ѡ�����
}                                 // ѡ���б�
void luRu(){

    Contact_Person *p = head;                                                               // ����ָ��,���ڴ�����ͷ��ʼ����
    Contact_Person *prev = NULL;                                                            // ����ָ��,���ڼ�¼���������е�ǰһ���ڵ�
    Contact_Person *newNode = (Contact_Person *) malloc(sizeof(Contact_Person));       // ���ڴ��з���һ��ռ�����½ڵ�
    // ¼��
    while (1) {
        printf("***ѧ���ɼ�¼��***\n");
        // ������ѧ�ţ��ٽ��м�⣬����Ϸ������������Ϸ���Ҫ����������
        while (1) {
            long long inputNum;
            printf("������ѧ��ѧ�ţ�11λ����");
            scanf("%lld", &inputNum);
            // ��һ��⣺���ѧ���Ƿ�����11λҪ��
            if (inputNum >= 10000000000 && inputNum <= 99999999999) {
                // �ڶ���⣺���ѧ���Ƿ��ظ�
                printf("��ʼ���ѧ���Ƿ��ظ�...\n");
                if (isStuNumExists(head, inputNum)) {
                    printf("ѧ���Ѵ��ڣ����������롣\n");
                    continue;
                }
                printf("ѧ��δ�ظ���\n");
                printf("ѧ�źϷ�����¼�롣\n");
                newNode->stuNum = inputNum;
                break;
            } else {
                printf("�Ƿ�ѧ�ţ�ѧ�ű���Ϊ11λ��,���������롣\n");
                clearInputBuffer();
                continue;
            }
        }                                                // ¼��ѧ��ѧ��
        printf("������ѧ��������");                                // ¼��ѧ������
        scanf("%99s", newNode->name);
        // �ȴ��������ٽ��м�⡣
        while (1) {
            printf("������ѧ���Ա�");
            scanf("%99s", newNode->sex);
            if (strcmp(newNode->sex, "��") == 0 || strcmp(newNode->sex, "Ů") == 0) {  // �Ա��ж������е�ֵ���м��;���⣺strcmp��strstr������
                printf("�Ա����Ϸ���������1����¼�롣\n");
                break;
            } else {
                if (strcmp(newNode->sex, "����") == 0) {
                    printf("�����������Ա�");
                    scanf("%99s", newNode->sex);
                    printf("�Ա����Ϸ���������2����¼�롣\n");
                    break;
                    // ����1���ޡ��С���Ů���� ����2�������Ա�
                } else {
                    printf("��Ч�Ա����������롣\n");
                    continue;                                                         // ���򶼲�������Ҫ����������
                }
            }
        }                                                // ¼��ѧ���Ա�
        printf("������ѧ��Ժϵ��");
        scanf("%99s", newNode->academic);
        printf("������ѧ��רҵ��");
        scanf("%99s", newNode->major);
        printf("������ѧ�����᣺");
        scanf("%99s", newNode->province);
        printf("������ѧ����ͥסַ��");                            // Clion��BUG�ᵼ�����п����Զ�����
        scanf("%99s", newNode->address);
        while (1) {
            long long inputNum;
            printf("������ѧ���绰���루��֧���ֻ��ţ���");
            scanf("%lld", &inputNum);
            if (inputNum >= 10000000000 && inputNum <= 19999999999){  // ����1Ϊ��ͷ��11λ�ֻ���
                newNode -> phoneNum = inputNum;
                printf("���������Ϸ�����¼��\n");
                break;
            } else {
                printf("�Ƿ����룡�������������������롣\n");
                continue;
            }
        }                                               // ¼���ֻ�����
        while (1) {
            char inputEmail[100];
            printf("������ѧ�����䣺");
            scanf("%99s", inputEmail);

            // ��������ʽ�Ƿ�Ϸ�
            if (strstr(inputEmail,"@gmail.com") != NULL){
                printf("��ʽ��ȷ��gmail���䣩����¼�롣\n");
//                newNode->emailNum = inputEmail;        // ����
                strcpy(newNode->emailNum, inputEmail);   // �����ַ����飬����ͨ���򵥵ĸ�ֵ�����и��ƣ�Ӧ��ʹ���ַ������������� strcpy��
                break;
            } if (strstr(inputEmail,"@qq.com") != NULL) {
                printf("��ʽ��ȷ��QQ���䣩����¼�롣\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } if(strstr(inputEmail,"@163.com") != NULL){
                printf("��ʽ��ȷ���������䣩����¼�롣\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } if(strstr(inputEmail,"@outlook.com") != NULL){
                printf("��ʽ��ȷ��Outlook���䣩����¼�롣\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } if(strstr(inputEmail,"@yahoo.com") != NULL){
                printf("��ʽ��ȷ���Ż�����1������¼�롣\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } if(strstr(inputEmail,"@myyahoo.com") != NULL){
                printf("��ʽ��ȷ���Ż�����2������¼�롣\n");
                strcpy(newNode->emailNum, inputEmail);
                break;
            } else {
                printf("��ʽ����!������δ��֧�ֵ������ʽ������������\n");
                continue;
            }
        }                                               // ¼������

        newNode->pNext = NULL;
        printf("����¼�����\n");
        system("pause");

        if (!head || newNode->stuNum < head->stuNum) {
            newNode->pNext = head;                        // �������Ϊ�ջ���ѧ����ѧ��С��ͷ�ڵ��ѧ��,���½ڵ�ָ��ǰ��ͷ�ڵ�
            head = newNode;                               // ��ͷָ��ָ���½ڵ�
            return;
        }
        // �������Ϊ��,������¼���ѧ��ѧ�ű�ͷ�ڵ��ѧ�Ŵ�,��������,�ҵ��ʵ���λ�ò����½ڵ�
        while (p && p->stuNum <= newNode->stuNum) {
            prev = p;                                   // ���ƶ�����һ���ڵ�֮ǰ,����ǰ�ڵ�洢��'prev'��
            p = p->pNext;                               // �ƶ�����һ���ڵ�
        }
        prev->pNext = newNode;                          // �ҵ��ȡ�P���ڵ��ѧ��С��λ��,��ǰһ���ڵ�ָ���½ڵ�
        newNode->pNext = p;                             // �½ڵ�ָ��ǰ�ڵ�,��'p'
        return;
    }
}                                        // ¼��ɼ�
void chaZhao(){
    int chooseNum;                  // �û�ѡ��ı��
    char choice_name[100];          // ͨ�����ֲ���
    long long choice_stuNum;        // ͨ��ѧ�Ų���
    long long choice_phoneNum;      // ͨ���绰�������
    char choice_emailNum[100];      // ͨ���������

    // ��ͨ�����ַ�ʽ�������ݲ��ң���ѡһ��
    printf("��ѡ����ҷ�ʽ��\n");
    printf("1.�����ֲ���\n");
    printf("2.��ѧ�Ų���\n");
    printf("3.���绰�������\n");
    printf("4.���������\n");
    printf("��������ţ�");
    scanf("%d",&chooseNum);

    // ���ҷ�ʽѡ��
    switch (chooseNum) {
        case 1:
            printf("�����ֲ���\n");
            printf("������ѧ�����֣�");
            scanf("%99s",choice_name);               // ��ȡ�û����������

            Contact_Person  *temp = head;
            while(temp!=NULL){
                if(strcmp(temp->name, choice_name) == 0){   // �ַ����ıȽ�Ӧ��ʹ�� strcmp ���������� == �����
                    break;
                }
                temp = temp->pNext;
            }

            if(temp==NULL) {
                printf("û���ҵ�ѧ��");
                system("pause");
            } else {
                printf("���ҵ�ѧ�����ɼ����£�\n");
                printf("ѧ�ţ�%lld        ������%s        �Ա�%s\n",temp->stuNum,temp->name,temp->sex);
                printf("Ժϵ��%s          רҵ��%s\n",temp->academic,temp->major);
                printf("���᣺%s\n",temp->province);
                printf("��ͥסַ��%s\n",temp->address);
                printf("�绰���룺%lld              ���䣺%s\n",temp->phoneNum,temp->emailNum);
                system("pause");
            }
            break;

        case 2:
            printf("��ѧ�Ų���\n");
            printf("������ѧ��ѧ�ţ�");
            scanf("%lld",&choice_stuNum);          // ��ȡ�û������ѧ��

            Contact_Person  *temp_stuNum = head;
            while(temp_stuNum!=NULL){
                if(temp_stuNum->stuNum == choice_stuNum){   // �ַ����ıȽ�Ӧ��ʹ�� strcmp ���������� == �����
                    break;
                }
                temp_stuNum = temp_stuNum->pNext;
            }

            if(temp_stuNum==NULL) {
                printf("û���ҵ�ѧ��");
                system("pause");
            } else {
                printf("���ҵ�ѧ�����ɼ����£�\n");
                printf("ѧ�ţ�%lld        ������%s        �Ա�%s\n",temp_stuNum->stuNum,temp_stuNum->name,temp_stuNum->sex);
                printf("Ժϵ��%s          רҵ��%s\n",temp_stuNum->academic,temp_stuNum->major);
                printf("���᣺%s\n",temp_stuNum->province);
                printf("��ͥסַ��%s\n",temp_stuNum->address);
                printf("�绰���룺%lld              ���䣺%s\n",temp_stuNum->phoneNum,temp_stuNum->emailNum);
                system("pause");
            }
            break;

        case 3:
            printf("���绰�������\n");
            printf("������绰���룺");
            scanf("%lld",&choice_phoneNum);          // ��ȡ�û������ѧ��
            Contact_Person  *temp_phoneNum = head;
            while(temp_phoneNum!=NULL){
                if(temp_phoneNum->phoneNum == choice_phoneNum){   // �ַ����ıȽ�Ӧ��ʹ�� strcmp ���������� == �����
                    break;
                }
                temp_phoneNum = temp_phoneNum->pNext;
            }

            if(temp_phoneNum==NULL) {
                printf("û���ҵ�ѧ��");
                system("pause");
            } else {
                printf("���ҵ�ѧ�����ɼ����£�\n");
                printf("ѧ�ţ�%lld        ������%s        �Ա�%s\n",temp_phoneNum->stuNum,temp_phoneNum->name,temp_phoneNum->sex);
                printf("Ժϵ��%s          רҵ��%s\n",temp_phoneNum->academic,temp_phoneNum->major);
                printf("���᣺%s\n",temp_phoneNum->province);
                printf("��ͥסַ��%s\n",temp_phoneNum->address);
                printf("�绰���룺%lld              ���䣺%s\n",temp_phoneNum->phoneNum,temp_phoneNum->emailNum);
                system("pause");
            }
            break;

        case 4:
            printf("���������\n");
            printf("�����������ַ��");
            scanf("%99s",choice_emailNum);                            // ��ȡ�û������ѧ��

            Contact_Person  *temp_emailNum = head;
            while(temp_emailNum!=NULL){
                if(strcmp(temp_emailNum->emailNum, choice_emailNum) == 0){   // �ַ����ıȽ�Ӧ��ʹ�� strcmp ���������� == �����
                    break;
                }
                temp_emailNum = temp_emailNum->pNext;
            }

            if(temp_emailNum==NULL) {
                printf("û���ҵ�ѧ��");
                system("pause");
            } else {
                printf("���ҵ�ѧ�����ɼ����£�\n");
                printf("ѧ�ţ�%lld        ������%s        �Ա�%s\n",temp_emailNum->stuNum,temp_emailNum->name,temp_emailNum->sex);
                printf("Ժϵ��%s          רҵ��%s\n",temp_emailNum->academic,temp_emailNum->major);
                printf("���᣺%s\n",temp_emailNum->province);
                printf("��ͥסַ��%s\n",temp_emailNum->address);
                printf("�绰���룺%lld              ���䣺%s\n",temp_emailNum->phoneNum,temp_emailNum->emailNum);
                system("pause");
            }
            break;

    }




}                                     // ����Ŀ��
void testAll(){
    printf("�򵥲�ѯ������ʾ������Ϣ��\n");
    Contact_Person *p = head;
    printf("ѧ��\t\t����\t�Ա�\n");
    while (p != NULL) {
        printf("%-16lld%-8s%-8s\n",p->stuNum,p->name,p->sex);
        p = p->pNext;
    }
    return;
}                                     // ����
void deleteMessage(){

    long long stuNumber;
    char choose;

    // ����һ��ָ�������ͷ��ʼ����
    Contact_Person *p = head;
    // ����һ��ָ���¼���������е�ǰһ���ڵ�
    Contact_Person *prev = NULL;

    printf("������Ҫɾ����ѧ��:");
    scanf("%lld", &stuNumber);
    getchar();

    // ��������Ƿ�Ϊ��
    if (!head) {
        printf("����Ϊ�ա�\n");
        return;
    }
    // �����������Ҫɾ����ѧ��
    while (p && p->stuNum != stuNumber) {
        // ���ƶ�����һ���ڵ�֮ǰ,����ǰ�ڵ�洢��'prev'��
        prev = p;
        // �ƶ�����һ���ڵ�
        p = p->pNext;
    }
    // ����ҵ���Ҫɾ����ѧ��
    if (p) {
        printf("�ҵ�����Ϣ����:\n");
        printf("ѧ��:%lld,����:%s,�Ա�:%s\n",p->stuNum, p->name, p->sex);
        printf("�Ƿ�Ϊ��Ҫɾ���ļ�¼?(y/n)");
        choose = getchar();

        if (choose == 'y' || choose == 'Y') {
            //������ǵ�һ���ڵ�
            if (prev) {
                //��ǰһ���ڵ��ָ��ָ����һ���ڵ�
                prev->pNext = p->pNext;
            } else {
                //������ͷָ��ָ����һ���ڵ�
                head = p->pNext;
            }
            //�ͷŵ�ǰ�ڵ���ڴ�
            free(p);
            //��ͣ����
            system("pause");
        }
    } else {
        // ���û���ҵ�ѧ��,��ӡ��ʾ��Ϣ
        printf("ѧ�� %lld��ѧ��δ�ҵ���\n", stuNumber);
    }
}                               // ɾ������
void xiuGai() {
    int chooseNum;
    long long stuNum;
    char choose;
    printf("������Ҫ�޸ĵ�ѧ��:");
    scanf("%lld", &stuNum);

    // �������������ļ�¼
    Contact_Person *temp = head;             // 1.����ָ�����temp����ΪContact_Person�Զ���ṹ�壬����Ϊ��2.��temp��ֵΪhead��ʹtempָ������ĵ�һ���ڵ㡣
    while (temp != NULL) {
        if (temp->stuNum == stuNum){
            break;
        } else {
            temp = temp->pNext;
        }
    }
    if (temp == NULL){
        printf("û�з���������Ŀ¼��");
    } else {
        printf("�ҵ���ǰ������Ϣ���£�\n");
        printf("*************************************************\n");
        printf("ѧ�ţ�%lld        ������%s        �Ա�%s\n",temp->stuNum,temp->name,temp->sex);
        printf("Ժϵ��%s          רҵ��%s\n",temp->academic,temp->major);
        printf("���᣺%s\n",temp->province);
        printf("��ͥסַ��%s\n",temp->address);
        printf("�绰���룺%lld              ���䣺%s\n",temp->phoneNum,temp->emailNum);
        printf("*************************************************\n");
        printf("�Ƿ�Ϊ��Ҫ�޸ĵļ�¼?(y/n)");
        getchar();                                               // ��������ֵ
        choose = getchar();                                      // ��choose��ֵ
        if (choose == 'y' || choose == 'Y'){                     // �ж�choose��ֵ
            printf("\n");
            printf("*******�޸Ĳ˵�*******\n");
            printf("1.ѧ��  2.����   3.�Ա�\n");
            printf("4.Ժϵ  5.רҵ   6.����\n");
            printf("7.��ͥסַ   8.�绰����   8.����\n");
            printf("********************\n");
            printf("������Ҫ�޸ĵ����ݵı�ţ�");
            scanf("%d",&chooseNum);
            switch (chooseNum) {
                case 1: // �޸�ѧ��
                    printf("�޸�ѧ��\n");
                    printf("ԭѧ�ţ�%lld\n", temp->stuNum); // ��ʾԭʼѧ��

                    // �����µ�newData0�����ݴ�ԭʼѧ��
                    long long newData0;

                    // ѭ�����ѧ���Ƿ�����Ҫ��
                    do {
                        printf("�������µ�ѧ��(����Ϊ11λ������ֻ�ܰ�������1-9)��");
                        if (scanf("%lld", &newData0) != 1) {
                            // �������ȡ����                                                                                                                 ������ֵnewData!
                            // ����ɹ���ȡ��һ���������͵�ֵ������ֵ���� 1�����û�гɹ���ȡ������ֵ���� 0��
                            // ��������֣�������뻺��������ʾ��������
                            clearInputBuffer();
                            printf("ERROR:�ַ����ʹ���ѧ�Ž���Ϊ���֣�����¼���ѧ�š�\n");
                            continue; // �� continue ���ִ��ʱ������������ǰѭ������ʣ�����䣬ֱ�ӽ�����һ��ѭ��������
                        }

                        // ���ѧ���Ƿ�Ϊ11λ��
                        if (newData0 >= 10000000000 && newData0 <= 99999999999) {

                            // ���ѧ���Ƿ�ֻ����1-9������
                            if (isValidStudentNumber(newData0)) {
                                break;  // ѧ�ŷ����������˳�ѭ��
                            }
                        } else {
                            printf("ERROR:����11λ�������ޣ�����¼���ѧ�š�\n");
                            while ((Ch = getchar()) != '\n' && Ch != EOF);// �������뻺���еĻ��з���
                        }
                    } while (1);

                    printf("ѧ�����޸�!\n");
                    printf("��ѧ�ţ�%lld\n", newData0);     // ��ʾ��ѧ��
                    temp->stuNum = newData0;                     // ����ѧ��
                    break;



                case 2:         // �޸�����
                    printf("�޸�����\n");
                    printf("ԭ������%s\n", temp->name);     // ��ʾԭʼ����

                    // �����µ�newData1�����ݴ�ԭʼ����
                    char newData1[100];

                    printf("�������µ�������");
                    scanf("%s", newData1);
                    printf("�������޸�!\n");
                    printf("��������%s\n", newData1);       // ��ʾ������
                    strcpy(temp->name, newData1);    // ����������%sʹ��strcpy����
                    break;



                case 3:         // �޸��Ա�
                    printf("�޸��Ա�\n");
                    printf("ԭ�Ա�%s\n", temp->sex);     // ��ʾԭʼ����

                    // �����µ�newData2�����ݴ�ԭʼ�Ա�
                    char newData2[100];

                    printf("�������µ��Ա�");
                    scanf("%s", newData2);
                    printf("�Ա����޸�!\n");
                    printf("���Ա�%s\n", newData2);       // ��ʾ���Ա�
                    strcpy(temp->sex,  newData2);    // �����Ա�%sʹ��strcpy����
                    break;



                case 4:         // �޸�Ժϵ
                    printf("�޸�Ժϵ\n");
                    printf("ԭԺϵ��%s\n", temp->academic);     // ��ʾԭʼԺϵ

                    // �����µ�newData3�����ݴ�ԭʼԺϵ
                    char newData3[100];

                    printf("�������µ�Ժϵ��");
                    scanf("%s", newData3);
                    printf("Ժϵ���޸�!\n");
                    printf("��Ժϵ��%s\n", newData3);       // ��ʾ��Ժϵ
                    strcpy(temp->academic,  newData3);    // ����Ժϵ��%sʹ��strcpy����
                    break;



                case 5:         // �޸�רҵ
                    printf("�޸�רҵ\n");
                    printf("ԭרҵ��%s\n", temp->major);     // ��ʾԭʼרҵ

                    // �����µ�newData4�����ݴ�ԭʼרҵ
                    char newData4[100];

                    printf("�������µ�רҵ��");
                    scanf("%s", newData4);
                    printf("רҵ���޸�!\n");
                    printf("��רҵ��%s\n", newData4);       // ��ʾ��רҵ
                    strcpy(temp->major,  newData4);    // ����רҵ��%sʹ��strcpy����
                    break;




                case 6:         // �޸ļ���
                    printf("�޸ļ���\n");
                    printf("ԭ���᣺%s\n", temp->province);     // ��ʾԭʼ����

                    // �����µ�newData5�����ݴ�ԭʼ����
                    char newData5[100];

                    printf("�������µļ��᣺");
                    scanf("%s", newData5);
                    printf("�������޸�!\n");
                    printf("�¼��᣺%s\n", newData5);       // ��ʾ�¼���
                    strcpy(temp->province,  newData5);    // ���¼��ᣬ%sʹ��strcpy����
                    break;




                case 7:         // �޸ļ�ͥסַ
                    printf("�޸ļ�ͥסַ\n");
                    printf("ԭ��ͥסַ��%s\n", temp->address);     // ��ʾԭʼ��ͥסַ

                    // �����µ�newData6�����ݴ�ԭʼ��ͥסַ
                    char newData6[100];

                    printf("�������µļ�ͥסַ��");
                    scanf("%s", newData6);
                    printf("��ͥסַ���޸�!\n");
                    printf("�¼�ͥסַ��%s\n", newData6);       // ��ʾ�¼�ͥסַ
                    strcpy(temp->address,  newData6);    // ���¼�ͥסַ��%sʹ��strcpy����
                    break;




                case 8:         // �޸ĵ绰����
                    printf("�޸ĵ绰����\n");
                    printf("ԭ�绰���룺%lld\n", temp->phoneNum); // ��ʾԭʼ�绰����

                    // �����µ�newData7�����ݴ�ԭʼ�绰����
                    long long newData7;

                    printf("�������µĵ绰���룺");
                    scanf("%lld", &newData7);
                    printf("�绰�������޸�!\n");
                    printf("�µ绰���룺%lld\n", newData7);     // ��ʾ�µ绰����
                    temp->phoneNum = newData7;                     // ���µ绰����
                    break;



                case 9:         // �޸������ַ
                    printf("�޸������ַ\n");
                    printf("ԭ�����ַ��%s\n", temp->emailNum);     // ��ʾԭʼ�����ַ

                    // �����µ�newData9�����ݴ�ԭʼ�����ַ
                    char newData9[100];

                    printf("�������µ������ַ��");
                    scanf("%s", newData9);
                    printf("�����ַ���޸�!\n");
                    printf("�������ַ��%s\n", newData9);       // ��ʾ�������ַ
                    strcpy(temp->emailNum,  newData9);    // ���������ַ��%sʹ��strcpy����
                    break;




            }
            // ÿ���޸�����ʾ�޸ĺ����������
            printf("�޸ĺ���Ϣ:\n");
            printf("*************************************************\n");
            printf("ѧ�ţ�%lld           ������%s        �Ա�%s\n",temp->stuNum,temp->name,temp->sex);
            printf("Ժϵ��%s          רҵ��%s\n",temp->academic,temp->major);
            printf("���᣺%s\n",temp->province);
            printf("��ͥסַ��%s\n",temp->address);
            printf("�绰���룺%lld              ���䣺%s\n",temp->phoneNum,temp->emailNum);
            printf("*************************************************\n");
            system("pause");
        } else {
            if(choose == "N" || choose == "n"){

            }
            printf("��ȡ������\n");
        }
    }
}                                     // �����޸�
void checkEmailDelay(const char *email) {
    // ����ping����
    printf("��ʼ���������ӳ�...\n");
    char command[100];
    sprintf(command, "ping -n 1 %s", email);

    // ִ�������ȡ���
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    // ��ȡ�������ʾ
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // ���Ұ��� "time=" ���У���ʾ�ӳ���Ϣ
        if (strstr(buffer, "ʱ��=") != NULL) {
            printf("%s", buffer);
        }
    }

    // �ر��ļ���
    pclose(fp);
}           // ��ȡ������վpingֵ


// main
int main(){
    int c;
    // doѭ��
    do {
        optionsList();                                // ѡ���б�

        switch (choice) {
            case 1:
            luRu_Start:
                luRu();                                               // ����¼����ת����㣩��ţ�1

                // ѯ���Ƿ��������
                while (1) {
                    char TFChoice[10];
                    clearInputBuffer();                               // ������뻺����
                    printf("�Ƿ����¼��ɼ���T/F����");
                    scanf("%9s", TFChoice);
                    if (strcmp(TFChoice, "F") == 0) {                 // strcmp ��һ�����ڱȽ������ַ����ĺ���������ֵΪ 0 ��ʾ�����ַ�����ȣ����򷵻ط���ֵ����ʾ�����ַ�������ȡ�
                        printf("¼�����\n");
                        break;
                    } else {
                        if (strcmp(TFChoice, "T") == 0) {
                            printf("����¼��\n");
                            goto luRu_Start;                          // ����¼����ת����㣩��ţ�1
                        } else {
                            printf("��Чѡ������ѡ��\n");
                            continue;
                        }
                    }
                }

                // ����pingֵ
                printf("��ʼ������������վ����ͨ��\n");

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
                // ����pingֵ
                email= "qq.com";
                checkEmailDelay(email);
                printf("QQ�ӳ�\n");

                email= "baidu.com";
                checkEmailDelay(email);
                printf("�ٶ��ӳ�\n");

                break;
        }
        printf("\n");
        while ((Ch = getchar()) != '\n' && Ch != EOF);// �������뻺���еĻ��з���
    } while (choice !=0);                             // ��ѡ��"0"���˳�doѭ��
    return 0;
}

