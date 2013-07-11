/*消息类型*/
#define Msg_Login 0         //登录消息
#define Msg_SToSer 1		//发送给服务器的消息
#define Msg_SToIn 2			//客户端之间通信 
#define Msg_SToAll 3		//群发
#define Msg_SOFF 4			//客户端下线通知
#define Msg_SON 5			//客户端上线通知
#define Msg_SState  6		//状态改变
#define Msg_SRegist 7		//注册
#define Login_Success 8		//登录成功
#define Login_Fail  9		//登录失败
#define State_ON	10		//在线上
#define State_Leave	11		//离开
#define State_UnDisturb	12	//勿扰
#define State_Busy	13		//隐身
#define On_Line		1		//好友在线
#define Off_Line	0		//好友不在线

#define LEN sizeof(Pag)					//包的大小
#define MAX_BUFFER_SIZE 2048			//音频缓冲区大小
struct Pag								//数据包协议
{
	int nType;							//消息类型
	char Msg[200];						//发送的消息
	int nBack;							//登录时的回返参数
	int ID;								//发送方的客户端的ID号
	int FID;							//接受方的客户端的ID号
	int nPass;							//登录时提交的密码
	int nReback;						//登录反馈
	char cNick[50];						//发送方的客户端的用户昵称
	char cFNick[50];					//接收方的客户端的用户昵称
	char Sound_Buffer[MAX_BUFFER_SIZE];	//声音消息
	int nFNum;							//好友个数
	char cFNickList[1024];				//好友列表
	int nState;							//状态
	int nSound;							//是否传送语音
	int nAge;							//年龄
	int nSex;							//性别 0为男 1为女
	int nRegist;						//注册反馈
	char cFOnline[10];					//在线好友 0为离线 1为在线
};
