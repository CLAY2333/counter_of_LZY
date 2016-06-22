#include <windows.h>

/******************************************
/ 功    能：设置控制台光标位置
/ 输入参数：nX		-- 光标X轴坐标
/			nY		-- 光标Y走坐标
/ 返回参数：无
/*作    者：AA
/*版    本：v1.0
/*修改日期：2005.09.27		
******************************************/
void MoveCursorTo(int nX, int nY);





/******************************************
/ 功    能：设置控制台文本显示颜色
/ 输入参数：nColorFront		--文本前景色
/			nColorBackGroup	--文本背景色	
/ 返回参数：无
/*作    者：AA
/*版    本：v1.0
/*修改日期：2005.09.27		
******************************************/
void SetTextColor(int nColorFront, int nColorBackGroup);



/******************************************
/ 功    能：建立一个简单的矩形窗口
/ 输入参数：Left  --- 窗口左上角x轴坐标
/           Top   --- 窗口左上角y轴坐标
/           Width --- 窗口宽度
/           Hight --- 窗口高度
/           nFrameTextColor ---- 窗口边框颜色
/           nFrameBkColor   ---- 窗口边框背景颜色
/			nWinTextColor	---- 窗口文字颜色
/			nWinBkColor     ---- 窗口背景色
/           title --- 窗口标题
/           Shadow ----窗口是否有阴影
/ 返回参数：无
/*作    者：AA
/*版    本：v1.0
/*修改日期：2005.09.29		
*******************************************/
void CreateSmWindow( int Left, int Top, int Width, int Hight, 
					int nFrameTextColor, 
					int nFrameBkColor,
					int nWinTextColor,
					int nWinBkColor,
					char title[]="",bool Shadow = false );

