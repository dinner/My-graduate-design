/*��Ϣ����*/
#define Msg_Login 0         //��¼��Ϣ
#define Msg_SToSer 1		//���͸�����������Ϣ
#define Msg_SToIn 2			//�ͻ���֮��ͨ�� 
#define Msg_SToAll 3		//Ⱥ��
#define Msg_SOFF 4			//�ͻ�������֪ͨ
#define Msg_SON 5			//�ͻ�������֪ͨ
#define Msg_SState  6		//״̬�ı�
#define Msg_SRegist 7		//ע��
#define Login_Success 8		//��¼�ɹ�
#define Login_Fail  9		//��¼ʧ��
#define State_ON	10		//������
#define State_Leave	11		//�뿪
#define State_UnDisturb	12	//����
#define State_Busy	13		//����
#define On_Line		1		//��������
#define Off_Line	0		//���Ѳ�����

#define LEN sizeof(Pag)					//���Ĵ�С
#define MAX_BUFFER_SIZE 2048			//��Ƶ��������С
struct Pag								//���ݰ�Э��
{
	int nType;							//��Ϣ����
	char Msg[200];						//���͵���Ϣ
	int nBack;							//��¼ʱ�Ļط�����
	int ID;								//���ͷ��Ŀͻ��˵�ID��
	int FID;							//���ܷ��Ŀͻ��˵�ID��
	int nPass;							//��¼ʱ�ύ������
	int nReback;						//��¼����
	char cNick[50];						//���ͷ��Ŀͻ��˵��û��ǳ�
	char cFNick[50];					//���շ��Ŀͻ��˵��û��ǳ�
	char Sound_Buffer[MAX_BUFFER_SIZE];	//������Ϣ
	int nFNum;							//���Ѹ���
	char cFNickList[1024];				//�����б�
	int nState;							//״̬
	int nSound;							//�Ƿ�������
	int nAge;							//����
	int nSex;							//�Ա� 0Ϊ�� 1ΪŮ
	int nRegist;						//ע�ᷴ��
	char cFOnline[10];					//���ߺ��� 0Ϊ���� 1Ϊ����
};
