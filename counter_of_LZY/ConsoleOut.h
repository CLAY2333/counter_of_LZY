#include <windows.h>

/******************************************
/ ��    �ܣ����ÿ���̨���λ��
/ ���������nX		-- ���X������
/			nY		-- ���Y������
/ ���ز�������
/*��    �ߣ�AA
/*��    ����v1.0
/*�޸����ڣ�2005.09.27		
******************************************/
void MoveCursorTo(int nX, int nY);





/******************************************
/ ��    �ܣ����ÿ���̨�ı���ʾ��ɫ
/ ���������nColorFront		--�ı�ǰ��ɫ
/			nColorBackGroup	--�ı�����ɫ	
/ ���ز�������
/*��    �ߣ�AA
/*��    ����v1.0
/*�޸����ڣ�2005.09.27		
******************************************/
void SetTextColor(int nColorFront, int nColorBackGroup);



/******************************************
/ ��    �ܣ�����һ���򵥵ľ��δ���
/ ���������Left  --- �������Ͻ�x������
/           Top   --- �������Ͻ�y������
/           Width --- ���ڿ��
/           Hight --- ���ڸ߶�
/           nFrameTextColor ---- ���ڱ߿���ɫ
/           nFrameBkColor   ---- ���ڱ߿򱳾���ɫ
/			nWinTextColor	---- ����������ɫ
/			nWinBkColor     ---- ���ڱ���ɫ
/           title --- ���ڱ���
/           Shadow ----�����Ƿ�����Ӱ
/ ���ز�������
/*��    �ߣ�AA
/*��    ����v1.0
/*�޸����ڣ�2005.09.29		
*******************************************/
void CreateSmWindow( int Left, int Top, int Width, int Hight, 
					int nFrameTextColor, 
					int nFrameBkColor,
					int nWinTextColor,
					int nWinBkColor,
					char title[]="",bool Shadow = false );

