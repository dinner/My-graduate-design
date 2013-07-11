#define Msg_Login 0         //登录消息
#define Msg_SToSer 1		//发送给服务器的消息
#define Msg_SToIn 2			//客户端之间通信 
#define Msg_SToAll 3		//群发
#define Msg_SOFF 4			//客户端下线通知
#define Msg_SON 5			//客户端上线通知
#define Msg_SState  6		//状态改变
#define Msg_SRegist 7		//注册信息
#define Login_Success 8		//登录成功
#define Login_Fail  9		//登录失败
#define State_ON	10		//在线上
#define State_Leave	11		//离开
#define State_UnDisturb	12	//勿扰
#define State_Busy	13		//隐身
#define On_Line		1
#define Off_Line	0

#define LEN sizeof(Pag)
#define MAX_BUFFER_SIZE 2048	