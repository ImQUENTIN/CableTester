#ifndef __LISTVIEWDEMO_H
#define __LISTVIEWDEMO_H
//#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32������
//STemwin LISTVIEW�ؼ�ʹ��   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2016/3/23
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

//ѧ����Ϣ�ṹ��
typedef struct
{
    char name[20];    //����
    char num[20];     //ѧ��
    char score[4];    //����
    char grade;       //�ȼ�
}student_info;

void CreateListviewdemo(void); 
#endif
